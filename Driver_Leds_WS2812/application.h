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


template <byte NB_LED>
class Application : Abstract {
public:
/**
 * Lancée une fois à l'initialisation.
 */
  bool setup() {
    FastLED.addLeds<WS2812Controller800Khz, 8>(leds, NB_LED);
    return true;
  }

/**
 * Lancée itérativement.
 */
  bool loop() {
    normale();
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

  void normale(const byte wait = 1) {
    for (auto c = 0; c < 256; c += 10) {
      for(auto sens = -1; sens <= 1; sens += 2) {
        for (auto t = -400; t < 256; ++t) {
          for (auto i = 0; i < NB_LED; ++i) {
            const auto j = sens*t + 40 * (i - NB_LED/2);
            const byte v = j < -255 ? 0 : (j <= 0 ? pgm_read_byte_near(NORMALE - j) : ( j <= 255 ? pgm_read_byte_near(NORMALE + j) : 0) );
            leds[i] = CHSV(c, 255, pgm_read_byte_near(CIEL + v));
          }
          FastLED.show();
          delay(wait);
        }
      }
    }
  }
  
private:
  CRGB leds[NB_LED];

};
