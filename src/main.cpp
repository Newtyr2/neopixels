#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN_1 26
#define LED_PIN_2 25
#define LED_PIN_3 27

#define LED_COUNT_1 16

#define LED_COUNT_2 7

// hi

Adafruit_NeoPixel strip1(LED_COUNT_1, LED_PIN_1, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel strip2(LED_COUNT_2, LED_PIN_2, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel strip3(LED_COUNT_1, LED_PIN_3, NEO_GRB + NEO_KHZ800);


// put function definitions here:


void setup() {
  // put your setup code here, to run once:

  strip1.begin();  
  strip1.show();         // INITIALIZE NeoPixel strip object (REQUIRED)         // Turn OFF all pixels ASAP
  strip1.setBrightness(50);

  strip2.begin();  
  strip2.show();         // INITIALIZE NeoPixel strip object (REQUIRED)         // Turn OFF all pixels ASAP
  strip2.setBrightness(50);

  strip3.begin();  
  strip3.show();         // INITIALIZE NeoPixel strip object (REQUIRED)         // Turn OFF all pixels ASAP
  strip3.setBrightness(50);
}

void loop() {
  // put your main code here, to run repeatedly:
  //strip.setPixelColor(0,10,10,10); 
  for (int i = 0; i < LED_COUNT_1; i++)
  {
    strip1.setPixelColor(i, i*20, 10, 10);
  }

  strip1.show(); 
  // delay(25); 
  // strip.setPixelColor(0,0,0,0);

  for (int i = 0; i < LED_COUNT_2; i++)
  {
    strip2.setPixelColor(i, i*20, 10, 10);
  }

  strip2.show(); 

  for (int i = 0; i < LED_COUNT_1; i++)
  {
    strip3.setPixelColor(i, i*20, 10, 10);
  }

  strip3.show(); 

  printf("Hello World \n");
}

