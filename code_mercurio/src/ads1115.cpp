#include <Wire.h>
#include <Adafruit_ADS1015.h>
 
Adafruit_ADS1115 ads;
const float multiplier = 0.1875F;
 
void setup(void) 
{
  Serial.begin(9600);
  ads.setGain(GAIN_SIXTEEN);
  ads.begin();
}
 
void loop(void) 
{
  int16_t adc0;
 
  
  adc0 = ads.readADC_SingleEnded(0);
  Serial.print("AIN0: "); Serial.println(adc0 * multiplier);
  delay(1000);
}