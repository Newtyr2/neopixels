#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN_1 26
#define LED_PIN_2 25
#define LED_PIN_3 27

#define LED_COUNT_1 16

#define LED_COUNT_2 7

// 

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

/* void progress bar(int variable)

// This shows a bar that grows in size in relation to a variable. Occurs on strip 0.

  int minValue = 0;
  int maxValue = 1023; // or whatever the max of the variable is, can be adjusted idk

  float scaledValue = (float)(variable - minValue) / (maxValue - minValue) * 8.0;
  scaledValue = constrain(scaledValue, 0, 8);

  int barHeight = (int)scaledValue;
  float fraction = scaledValue - barHeight;

  // Clear strip first
  strip0.clear();

  for (int i = 0; i < barHeight; i++) {
    strip0.setPixelColor(i, 0, 255, 0);
  }

  if (barHeight < 8 && fraction > 0) {
    uint8_t brightness = fraction * 255;
    strip1.setPixelColor(barHeight, 0, brightness, 0);
  }

  strip0.show();
*/

void bar(int variable){
  // This shows a bar that grows in size in relation to a variable 

  int minValue = 0;
  int maxValue = 1023;
  float partial = 0;

  int barHeight = map(variable, minValue, maxValue, 0, LED_COUNT_1 / 2);
  barHeight = constrain(barHeight, 0, LED_COUNT_1 / 2);
  
  partial = variable / 8;

  for (int i = 0; i < barHeight; i++)
  {
  int ledIndex = (LED_COUNT_1 - 1) - i;   // bottom (7) -> top (0)
  strip1.setPixelColor(ledIndex, 0, 255, 0);
  if (int(partial) != partial)
    strip1.setPixelColor(ledIndex + 1, 0, (partial - int(partial)) * 255, 0);
  }

  strip1.show();

}
// idle
void showAll()
{
  strip1.show();
  strip2.show();
  strip3.show();
  // strip4.show();
  // strip5.show();
}

void idle()
{
  strip1.clear();
  strip2.clear();
  strip3.clear();
  // strip4.clear();
  // strip5.clear();
  showAll();
  }

void precharge()
{
  strip1.fill(strip1.Color(255, 255, 0));
  strip2.fill(strip2.Color(255, 255, 0));
  strip3.fill(strip3.Color(255, 255, 0));
  // strip4.fill(strip4.Color(255, 255, 0));
  // strip5.fill(strip5.Color(255, 255, 0));
  showAll();
}

void drive()
{
  strip1.fill(strip1.Color(0, 255, 0));
  strip2.fill(strip2.Color(0, 255, 0));
  strip3.fill(strip3.Color(0, 255, 0));
  // strip4.fill(strip4.Color(0, 255, 0));
  // strip5.fill(strip5.Color(0, 255, 0));
  showAll();
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

  delay(1000);
  strip1.clear();
 
  int variable = 0;
  while (variable < 1023)
  {
    variable += 100;
    bar(variable);
    delay(500);
  }
  

  /* 
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

  */
}

