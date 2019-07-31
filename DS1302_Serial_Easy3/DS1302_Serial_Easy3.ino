// DS1302_Serial_Easy 
// Copyright (C)2015 Rinky-Dink Electronics, Henning Karlsen. All right reserved
// web: http://www.RinkyDinkElectronics.com/
//
// A quick demo of how to use my DS1302-library to 
// quickly send time and date information over a serial link
//
// I assume you know how to connect the DS1302.
// DS1302:  CE pin    -> Arduino Digital 2
//          I/O pin   -> Arduino Digital 3
//          SCLK pin  -> Arduino Digital 4

#include <DS1302.h>

// Init the DS1302
DS1302 monRtc(2, 3, 4);

void setup()
{

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
  
  // Set the clock to run-mode, and disable the write protection
  rtc.halt(false);
  rtc.writeProtect(false);
  
  // Setup Serial connection
  Serial.begin(9600);

  // The following lines can be commented out to use the values already stored in the DS1302
  rtc.setDOW(FRIDAY);        // Set Day-of-Week to FRIDAY
  rtc.setTime(12, 0, 0);     // Set the time to 12:00:00 (24hr format)
  rtc.setDate(6, 8, 2010);   // Set the date to August 6th, 2010
}

void loop()
{
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
