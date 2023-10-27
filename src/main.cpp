#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 25 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

// Function prototypes
void SetPixels(int red, int green, int blue);

void setup()
{
  Serial.begin(115200);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop()
{
  Serial.println("Clearing pixels");
  pixels.clear(); // Set all pixel colors to 'off'
  int red = 0;
  int green = 0;
  int blue = 0;

  for (red = 1; red <= 255; red++)
  {
    SetPixels(red, green, blue);
  }

  for (green = 1; green <= 255; green++)
  {
    red--;
    if (red < 0) { red = 0; }
    SetPixels(red, green, blue);
  }

  for (blue = 1; blue <= 255; blue++)
  {
    green--;
    if (green < 0) { green = 0; }
    SetPixels(red, green, blue);
  }

  for (red = 1; red <= 255; red++)
  {
    green = red;
    SetPixels(red, green, blue);
  }


  // for (int red = 1; red <= 255; red+=10)
  // {
  //   for (int green = 1; green <= 255; green+=10)
  //   {
  //     for (int blue = 1; blue <= 255; blue+=10)
  //     {
  //       SetPixels(red, green, blue);
  //     } //for (int blue = 1; blue <= 255; blue++)
  //   } // for (int green = 1; green <= 255; green++)
  // } // for (int red = 1; red <= 255; red++)
}

void SetPixels(int red, int green, int blue)
{
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for (int i = 0; i < NUMPIXELS; i++)
  { 
    // For each pixel...
    Serial.printf("Processing pixel %d. ",i);
    Serial.printf("   red:%d, green:%d, blue:%d\n", red, green, blue);

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    // pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.setPixelColor(i, pixels.Color(red, green, blue));

    pixels.show(); // Send the updated pixel colors to the hardware.

    // delay(DELAYVAL); // Pause before next pass through loop
  } // for (int i = 0; i < NUMPIXELS; i++)
}

