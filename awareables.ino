#include <Adafruit_NeoPixel.h>

const int DATA_PIN = 10;  // pin on FLORA
const int PIXEL_NUM = 124; // number of neopixels in chain

int BRIGHTNESS =15;
const int WAIT = 10; // delay transitioning colors

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_NUM, DATA_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(DATA_PIN, INPUT);
  digitalWrite(DATA_PIN, HIGH);
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
}

void loop() {
  colorWipe(strip.Color(255, 0, 0), WAIT*0.8*6); // Red
  colorWipe(strip.Color(255, 255, 255), WAIT*0.6*6); // light blue
  colorWipe(strip.Color(51, 102, 204), WAIT*0.1*6); // Blue
  colorWipe(strip.Color(172, 255, 168), WAIT*0.3*6); // light green
  colorWipe( strip.Color(0, 255, 0), WAIT*0.5*6); //green
  colorWipe(strip.Color(255, 0, 255), WAIT*0.7*6); // pink/magenta
  colorWipe(strip.Color(255, 182, 0), WAIT*0.9*6); // yellow
  colorWipe( strip.Color(0, 0, 0), WAIT); // shutting off
  
}

// Fill the neopixels one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    //strip.setBrightness(BRIGHTNESS/(i+1));
    strip.show();
    delay(wait);
  }
  //delay(wait);
}
