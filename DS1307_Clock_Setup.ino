// Dependencies
#include <ds1307.h>
#include <Wire.h>
ds1307 DS1307;
uint8_t buffer[7]; // receiving buffer

// Setup
void setup(){
  Serial.begin(9600);
  Wire.begin();
  Serial.println("Real Time Clock module with DS1307 setup");
  DS1307.standby();
  DS1307.setYear(16);
  DS1307.setMonth(4);
  DS1307.setDow(6);
  DS1307.setData(2);
  DS1307.setHours(14);
  DS1307.setMinutes(30);
  DS1307.setSeconds(00);
  DS1307.resume();
}

// Loop
void loop(){
  // Test
  DS1307.getDate(buffer);
  Serial.print("Date(dd:mm:yy) ");
  Serial.print(buffer[4], DEC);    // day
  Serial.print(':');
  Serial.print(buffer[5], DEC);    // month
  Serial.print(':');
  Serial.print(buffer[6], DEC);    // year
  Serial.print(':');
  Serial.print(" Time(hh:mm:ss) ");
  Serial.print(buffer[2], DEC);    // hours
  Serial.print(':');
  Serial.print(buffer[1], DEC);    // minutes
  Serial.print(':');
  Serial.println(buffer[0], DEC);  // seconds
  
  // Wait
  delay(1000);
}
