#include <Wire.h>
#include <RTClib.h>

RTC_DS1307 monRtc;


void setup() {
  Wire.begin();
  monRtc.begin();
  Serial.begin(57600);
  if( ! monRtc.isrunning()){
    Serial.print("RTC Is not running");
    monRtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
   // monRtc.adjust(DateTime(2018, 11, 11, 14, 25, 00));
      // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  // rtc.adjust(DateTime(yyyy, mm, dd, hh, mm, ss));
  }else{
    Serial.print("RTC Is running");
  }
}

void loop() {
  DateTime now = monRtc.now();
  DateTime futur = (now + TimeSpan(7, 12, 30, 6));
  Serial.println("");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC );

  Serial.println("");
  Serial.print(futur.hour(), DEC);
  Serial.print(':');
  Serial.print(futur.minute(), DEC);
  Serial.print(':');
  Serial.print(futur.second(), DEC );
  delay(1000);
}
