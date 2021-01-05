double Temp;

#include <math.h>

double Thermistor(int RawADC) {
//Connection 5V - Thermistor - AI - 10k - GND
  Temp = log(10000.0 * ((1024.0 / RawADC - 1)));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp )) * Temp );
  Temp = Temp - 273.15;            // Convert Kelvin to Celcius
}

void setup() {
  Serial.begin(19200);
}

void loop() {
  Thermistor(analogRead(2));
  Serial.print(Temp); Serial.print(" °C "); // display Celcius

  Temp = (Temp * 1.8) + 32.0; // Convert Celcius to Fahrenheit return Temp;
  Serial.print(Temp); Serial.println(" °F"); // display Fahrenheit
  delay(2000);
}
