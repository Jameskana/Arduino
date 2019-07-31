#include <virtuabotixRTC.h> //Library used
//Wiring SCLK -> 12, I/O -> 10, CE -> 8
//Or CLK -> 12 , DAT -> 10, Reset -> 8

virtuabotixRTC myRTC(12, 10, 8); //If you change the wiring change the pins here also

void setup() {
 Serial.begin(9600);

// Set the current date, and time in the following format:
 // seconds, minutes, hours, day of the week, day of the month, month, year
 myRTC.setDS1302Time(17, 46, 17, 1, 11, 11, 2018); //Here you write your actual time/date as shown above 
 //but remember to "comment/remove" this function once you're done
 //The setup is done only one time and the module will continue counting it automatically
}

void loop() {
 // This allows for the update of variables for time or accessing the individual elements.
 myRTC.updateTime();

// Start printing elements as individuals
 Serial.print("Current Date / Time: ");
 Serial.print(myRTC.dayofmonth); //You can switch between day and month if you're using American system
 Serial.print("/");
 Serial.print(myRTC.month);
 Serial.print("/");
 Serial.print(myRTC.year);
 Serial.print(" ");
 Serial.print(myRTC.hours);
 Serial.print(":");
 Serial.print(myRTC.minutes);
 Serial.print(":");
 Serial.println(myRTC.seconds);

// Delay so the program doesn't print non-stop
 delay(1000);
}
