#include "app.h"


static const byte NB_LED = 4;

auto app = Application<NB_LED>();

/**
 * Lancée une fois à l'initialisation.
 */
void setup() {
  delay(1000);
  Serial.begin(115200);
  while (!Serial);
  Serial.println(F(__FILE__ " compiled " __DATE__ " " __TIME__));
  Serial.println(F("Copyright (c) 2021 par Marc SIBERT"));
  Serial.println();

  if (!app.setup()) {
    Serial.println("Erreur d'initialisation ! Arrêt !");
    exit(1);
  }
}

/**
 * Lancée itérativement.
 */
void loop() {
  if (!app.loop()) {
    Serial.println("Erreur d'exécution ! Arrêt !");
    exit(1);
  }
}
