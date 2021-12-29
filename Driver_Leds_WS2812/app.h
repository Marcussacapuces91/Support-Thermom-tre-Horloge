
#pragma once
#include <FastLED.h>

/**
 * Courbes de compensation de la sensisibilité de l'oeil, sans scramble, avec 2 bits et avec 4 bits. 
 */
static const uint8_t CIEL4[256] PROGMEM = { 0,0,0,0,1,1,1,0,1,1,1,1,2,2,1,1,2,2,2,2,3,2,2,2,3,3,3,3,4,3,3,3,4,4,4,4,5,5,5,4,6,6,5,5,7,6,6,6,8,7,7,7,9,8,8,8,10,10,9,9,11,11,10,10,12,12,12,11,14,13,13,13,15,15,15,14,17,17,16,16,19,18,18,17,21,20,20,19,23,22,22,21,25,24,24,23,27,26,26,25,29,29,28,28,32,31,31,30,34,34,33,32,37,37,36,35,40,39,39,38,43,43,42,41,47,46,45,44,50,49,48,47,54,53,52,51,57,56,55,54,61,60,59,58,65,64,63,62,70,68,67,66,74,73,72,71,79,77,76,75,83,82,81,80,88,87,86,85,94,92,91,90,99,98,96,95,105,103,102,100,110,109,108,106,116,115,113,112,123,121,120,118,129,128,126,124,136,134,132,131,143,141,139,138,150,148,146,145,157,155,154,152,165,163,161,159,173,171,169,167,181,179,177,175,189,187,185,183,198,196,193,191,207,204,202,200,216,214,211,209,225,223,220,218,235,232,230,228,245,242,240,237,255,252,250,247 };
static const uint8_t CIEL2[256] PROGMEM = { 0,0,0,0,1,0,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,2,3,3,3,3,3,3,4,3,4,4,4,4,5,4,5,5,5,5,6,6,6,6,7,6,7,7,8,7,8,8,9,8,9,9,10,10,10,10,11,11,12,11,12,12,13,13,14,13,15,14,15,15,16,16,17,17,18,17,19,18,20,19,21,20,22,21,23,22,24,23,25,24,26,25,27,26,28,28,29,29,31,30,32,31,33,32,34,34,36,35,37,37,39,38,40,39,42,41,43,43,45,44,47,46,48,47,50,49,52,51,54,53,55,54,57,56,59,58,61,60,63,62,65,64,67,66,70,68,72,71,74,73,76,75,79,77,81,80,83,82,86,85,88,87,91,90,94,92,96,95,99,98,102,100,105,103,108,106,110,109,113,112,116,115,120,118,123,121,126,124,129,128,132,131,136,134,139,138,143,141,146,145,150,148,154,152,157,155,161,159,165,163,169,167,173,171,177,175,181,179,185,183,189,187,193,191,198,196,202,200,207,204,211,209,216,214,220,218,225,223,230,228,235,232,240,237,245,242,250,247,255,252 };
static const uint8_t CIEL[256] PROGMEM = { 0,0,0,0,0,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,5,5,5,5,5,6,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,10,10,10,10,11,11,11,12,12,12,13,13,13,14,14,15,15,15,16,16,17,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25,25,26,26,27,28,28,29,29,30,31,31,32,32,33,34,34,35,36,37,37,38,39,39,40,41,42,43,43,44,45,46,47,47,48,49,50,51,52,53,54,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,70,71,72,73,74,75,76,77,79,80,81,82,83,85,86,87,88,90,91,92,94,95,96,98,99,100,102,103,105,106,108,109,110,112,113,115,116,118,120,121,123,124,126,128,129,131,132,134,136,138,139,141,143,145,146,148,150,152,154,155,157,159,161,163,165,167,169,171,173,175,177,179,181,183,185,187,189,191,193,196,198,200,202,204,207,209,211,214,216,218,220,223,225,228,230,232,235,237,240,242,245,247,250,252,255 };

/**
 * 1/2 fonction normale.
 */
static const uint8_t NORMALE[256] PROGMEM = { 255,255,255,255,255,254,254,254,253,253,253,252,252,251,250,250,249,248,247,246,245,245,244,242,241,240,239,238,237,235,234,233,231,230,228,227,225,224,222,221,219,217,216,214,212,210,208,207,205,203,201,199,197,195,193,191,189,187,185,183,181,179,177,175,173,171,168,166,164,162,160,158,156,153,151,149,147,145,143,141,139,136,134,132,130,128,126,124,122,120,118,116,114,112,110,108,106,104,102,100,98,96,95,93,91,89,87,86,84,82,81,79,77,76,74,72,71,69,68,66,65,63,62,60,59,58,56,55,54,52,51,50,48,47,46,45,44,43,42,40,39,38,37,36,35,34,33,33,32,31,30,29,28,27,27,26,25,24,24,23,22,22,21,20,20,19,18,18,17,17,16,16,15,15,14,14,13,13,12,12,12,11,11,10,10,10,9,9,9,8,8,8,8,7,7,7,7,6,6,6,6,5,5,5,5,5,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };



template <byte NB_LED>
class Application {
public:
  Application() {
    
  }

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
  
/**
 * 
 */
  void printCIEL() {
    for (auto lum = 0; lum < 256; ++lum) {
      auto yMin = 0.0;
      auto yMax = 1.0;
      while (true) {
        const auto y = (yMin + yMax) / 2.0;
        if ((yMax - yMin) < 0.00001) {
          Serial.print(round(y*255));
          Serial.print(',');
          break;
        }
        const auto r = 255 * ciel(y) / 100;
        if (r < (lum^0x00)) yMin = y; else yMax = y;
      }
    }
    Serial.println();  
  }
  
/**
 * 
 */
void printNormale() {
  const auto ro = 0.283;
  const auto m = fNormale(0, 0, ro);
  for (auto x = 0; x < 256; ++x) {
    Serial.print(",");
    Serial.print(round(255 * fNormale(x / 256.0, 0, ro) / m));
  }
  Serial.println();
}

protected:
/**
 * Courbe log de l'éclairement (CIE Lightness lookup table function)
 * 5 bit CIE Lightness to 8 bit PWM conversion :
 *    L* = 116(Y/Yn)^1/3 - 16 , Y/Yn > 0.008856
 *    L* = 903.3(Y/Yn), Y/Yn <= 0.008856
 */
  float ciel(const float& y) {
    return y <= 0.008856 ? 903.3*y : 116*pow(y, 1/3.0) - 16;
  }
  
/**
 *
 */
  float fNormale(const float& x, const float& mu = 0, const float& ro = 1) {
    return exp(-0.5*pow((x-mu)/ro, 2)) / (ro*sqrt(2*PI));
  }

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
    for (auto t = -500; t < 256; t+=2) {
      for (auto i = 0; i < NB_LED; ++i) {
        const auto j = t + 50 * i;
        const byte v = j < -255 ? 0 : (j <= 0 ? pgm_read_byte_near(NORMALE - j) : ( j <= 255 ? pgm_read_byte_near(NORMALE + j) : 0) );
        leds[i].setRGB(0, pgm_read_byte_near(CIEL + v), 0);
      }
      FastLED.show(2);
      delay(wait);
    }
  }
  
private:
  CRGB leds[NB_LED];
  static const uint8_t CIEL4[] PROGMEM;
  static const uint8_t CIEL2[] PROGMEM;
  static const uint8_t CIEL[] PROGMEM;
  static const uint8_t NORMALE[] PROGMEM;
  
};

template<byte NB_LED>
const uint8_t Application<NB_LED>::CIEL4[] PROGMEM = { 0,0,0,0,1,1,1,0,1,1,1,1,2,2,1,1,2,2,2,2,3,2,2,2,3,3,3,3,4,3,3,3,4,4,4,4,5,5,5,4,6,6,5,5,7,6,6,6,8,7,7,7,9,8,8,8,10,10,9,9,11,11,10,10,12,12,12,11,14,13,13,13,15,15,15,14,17,17,16,16,19,18,18,17,21,20,20,19,23,22,22,21,25,24,24,23,27,26,26,25,29,29,28,28,32,31,31,30,34,34,33,32,37,37,36,35,40,39,39,38,43,43,42,41,47,46,45,44,50,49,48,47,54,53,52,51,57,56,55,54,61,60,59,58,65,64,63,62,70,68,67,66,74,73,72,71,79,77,76,75,83,82,81,80,88,87,86,85,94,92,91,90,99,98,96,95,105,103,102,100,110,109,108,106,116,115,113,112,123,121,120,118,129,128,126,124,136,134,132,131,143,141,139,138,150,148,146,145,157,155,154,152,165,163,161,159,173,171,169,167,181,179,177,175,189,187,185,183,198,196,193,191,207,204,202,200,216,214,211,209,225,223,220,218,235,232,230,228,245,242,240,237,255,252,250,247 };

template<byte NB_LED>
const uint8_t Application<NB_LED>::CIEL2[] PROGMEM = { 0,0,0,0,1,0,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,2,3,3,3,3,3,3,4,3,4,4,4,4,5,4,5,5,5,5,6,6,6,6,7,6,7,7,8,7,8,8,9,8,9,9,10,10,10,10,11,11,12,11,12,12,13,13,14,13,15,14,15,15,16,16,17,17,18,17,19,18,20,19,21,20,22,21,23,22,24,23,25,24,26,25,27,26,28,28,29,29,31,30,32,31,33,32,34,34,36,35,37,37,39,38,40,39,42,41,43,43,45,44,47,46,48,47,50,49,52,51,54,53,55,54,57,56,59,58,61,60,63,62,65,64,67,66,70,68,72,71,74,73,76,75,79,77,81,80,83,82,86,85,88,87,91,90,94,92,96,95,99,98,102,100,105,103,108,106,110,109,113,112,116,115,120,118,123,121,126,124,129,128,132,131,136,134,139,138,143,141,146,145,150,148,154,152,157,155,161,159,165,163,169,167,173,171,177,175,181,179,185,183,189,187,193,191,198,196,202,200,207,204,211,209,216,214,220,218,225,223,230,228,235,232,240,237,245,242,250,247,255,252 };

template<byte NB_LED>
const uint8_t Application<NB_LED>::CIEL[] PROGMEM = { 0,0,0,0,0,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,5,5,5,5,5,6,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,10,10,10,10,11,11,11,12,12,12,13,13,13,14,14,15,15,15,16,16,17,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25,25,26,26,27,28,28,29,29,30,31,31,32,32,33,34,34,35,36,37,37,38,39,39,40,41,42,43,43,44,45,46,47,47,48,49,50,51,52,53,54,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,70,71,72,73,74,75,76,77,79,80,81,82,83,85,86,87,88,90,91,92,94,95,96,98,99,100,102,103,105,106,108,109,110,112,113,115,116,118,120,121,123,124,126,128,129,131,132,134,136,138,139,141,143,145,146,148,150,152,154,155,157,159,161,163,165,167,169,171,173,175,177,179,181,183,185,187,189,191,193,196,198,200,202,204,207,209,211,214,216,218,220,223,225,228,230,232,235,237,240,242,245,247,250,252,255 };

template<byte NB_LED>
const uint8_t Application<NB_LED>::NORMALE[] PROGMEM = { 255,255,255,255,255,254,254,254,253,253,253,252,252,251,250,250,249,248,247,246,245,245,244,242,241,240,239,238,237,235,234,233,231,230,228,227,225,224,222,221,219,217,216,214,212,210,208,207,205,203,201,199,197,195,193,191,189,187,185,183,181,179,177,175,173,171,168,166,164,162,160,158,156,153,151,149,147,145,143,141,139,136,134,132,130,128,126,124,122,120,118,116,114,112,110,108,106,104,102,100,98,96,95,93,91,89,87,86,84,82,81,79,77,76,74,72,71,69,68,66,65,63,62,60,59,58,56,55,54,52,51,50,48,47,46,45,44,43,42,40,39,38,37,36,35,34,33,33,32,31,30,29,28,27,27,26,25,24,24,23,22,22,21,20,20,19,18,18,17,17,16,16,15,15,14,14,13,13,12,12,12,11,11,10,10,10,9,9,9,8,8,8,8,7,7,7,7,6,6,6,6,5,5,5,5,5,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
