#include <FastLED.h>


#define NUM_LEDS 8
#define DATA_PIN 11
#define CLOCK_PIN 13
CRGB leds[NUM_LEDS];

int datafromUser;

void setup() {
  Serial.begin(115200); //устанавливаем скорость монитора порта
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
  if (Serial.available() > 0) //если пришли данные в мониторе порта
  {
    datafromUser = Serial.read(); //присваиваем переменной данные с монитора порта

    if (datafromUser == '1') {
      leds[1] = CRGB::White;
      FastLED.show();
    }
    else if (datafromUser == '2') {
      leds[2] = CRGB::White;
      FastLED.show();
    }
    else if (datafromUser == '3') {
      leds[3] = CRGB::White;
      FastLED.show();
    }
    else if (datafromUser == '4') {
      for (int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
        leds[whiteLed] = CRGB::White;
        FastLED.show();
        delay(25);
        leds[whiteLed] = CRGB::Black;
      }
    }
    else if (datafromUser == '5') {
      leds[1] = CRGB::Black;
      leds[2] = CRGB::Black;
      leds[3] = CRGB::Black;
      FastLED.show();
    }
  }
}
