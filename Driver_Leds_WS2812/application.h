/**
 * Copyright 2021 Marc SIBERT
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 *     
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once
#include <FastLED.h>

#include "abstract.h"


template <byte NB_LED, byte PIN_LEDS, byte PIN_LDR>
class Application : Abstract {
public:
/**
 * Lancée une fois à l'initialisation.
 */
  bool setup() {
    FastLED.addLeds<WS2812Controller800Khz, PIN_LEDS>(leds, NB_LED);
    pinMode(PIN_LDR, INPUT_PULLUP);
    return true;
  }

/**
 * Lancée itérativement.
 */
  bool loop() {
    const auto a = analogRead(PIN_LDR);
    const auto c = max(0, min((a-200)/2, 255)); 
    Serial.print(a);  
    Serial.print(',');  
    Serial.println(c);  
    normale(1, c);
    return true;
  }
  
protected:
/**
 * Luminosité en triangle sur toute la barette (homogène).
 */
void triangle(const byte wait = 5) {
  for (auto t = 0; true; ++t) {
    for (auto i = 0; i < NB_LED; ++i) {
      const byte v = (t % 512) < 256 ? t % 256 : 255 - t % 256;
      leds[i].setRGB(pgm_read_byte_near(CIEL2 + v), 0, 0);
    }
    FastLED.show();
    delay(wait);
  }
}

/**
 * Courbe de sinus glissant.
 */
  void sinus(const byte wait = 5) {
    for (auto t = 0; true; ++t) {
      for (auto i = 0; i < NB_LED; ++i) {
        static const auto MAX = 50;
        const byte v = round(sin(2*PI*t/256+i) * MAX/2.0 + MAX/2.0);
          leds[i].setRGB(pgm_read_byte_near(CIEL2 + v), 0, 0);
      }
      FastLED.show();
      delay(wait);
    }
  }

  void normale(const byte wait = 1, const byte lum = 16) {
    static auto c = 0;
    
    for(auto sens = -1; sens <= 1; sens += 2) {
      for (auto t = -900; t < 900; ++t) {
        for (auto i = 0; i < NB_LED; ++i) {
          const auto j = sens*t + 40 * (i - NB_LED/2);
          const byte v = j < -255 ? 0 : (j <= 0 ? pgm_read_byte_near(NORMALE - j) : ( j <= 255 ? pgm_read_byte_near(NORMALE + j) : 0) );
          leds[i] = CHSV(c % 256, 255, pgm_read_byte_near(CIEL + v));
        }
        FastLED.show(lum);
        delay(wait);
      }
    }
    c += 5;
  }
  
private:
  CRGB leds[NB_LED];

};
