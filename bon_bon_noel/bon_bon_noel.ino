#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define NOTE_G 1400 
#define NOTE_D 1870 
#define NOTE_F 1580 
#define NOTE_F1 1700 
#define NOTE_E 1670


/*  The MIT License (MIT)
 *  
 *  Copyright (c) 2015 Andy Tran
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 *  
 *  
 *  File Generated with help from the Midi to Arduino Converter     
 *   - Andy Tran (extramaster), 2015 
 *  https://www.extramaster.net/tools/midiToArduino/
 *  
 *  Process:
 *  Midi -> Midi tracks -> Note mappings -> Frequency
 *  
 *  
 *  There's 4 tracks here:
 *  You can check them out using the following link:
 *     https://www.extramaster.net/tools/midiToArduino/processFile/?url=http://www.jump-gate.com/christmas/music/midi/joyworld.mid&track=1
 *     https://www.extramaster.net/tools/midiToArduino/processFile/?url=http://www.jump-gate.com/christmas/music/midi/wewishu2.mid&track=3
 *     https://www.extramaster.net/tools/midiToArduino/processFile/?url=http://www.jump-gate.com/christmas/music/midi/rudolf.mid&track=1
 *     https://www.extramaster.net/tools/midiToArduino/processFile/?url=http://www.jump-gate.com/christmas/music/midi/jingbell.mid&track=1
 *  Note that the songs featured in the piece of code below have been truncated in order to fit with the Ardunio's RAM restriction
 *  
 *  
 *  Uses the protothread library. See: http://dunkels.com/adam/pt/index.html for more about protothreads
 *  
 *  Copyright (c) 2004-2005, Swedish Institute of Computer Science.
 *  Copyright (c) 2004-2005, Adam Dunkels.
 *  All rights reserved.
 * 
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met: 
 *  1. Redistributions of source code must retain the above copyright 
 *  notice, this list of conditions and the following disclaimer. 
 *  2. Redistributions in binary form must reproduce the above copyright 
 *  notice, this list of conditions and the following disclaimer in the 
 *  documentation and/or other materials provided with the distribution. 
 *  3. Neither the name of the Institute nor the names of its contributors 
 *  may be used to endorse or promote products derived from this software 
 *  without specific prior written permission. 
 * 
 *  THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS `AS IS' AND 
 *  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE 
 *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
 *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS 
 *  OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY 
 *  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF 
 *  SUCH DAMAGE.
 */
//#include "pt.h"
#include "timer.h"

// The current variable keeps track of the song to be played.
// Currently, as there are 4 tracks in the repertoire, the range of the current variable is from 0 to 3.
// Track 0: Joy to the World
// Track 1: We Wish you a Merry Christmas
// Track 2: Rudolf the Red Nosed Reindeer
// Track 3: Jingle Bells

int current = 0;

// Set this to be the pin that your buzzer resides in. (Note that you can only have one buzzer actively using the PWM signal at a time).
int tonePin = 11;

// Define the protothreads, and also the flags that terminate the respective protothread
// Could be abstracted into an array/stack
boolean enablePtJoyToTheWorld = true;
static struct pt ptJoyToTheWorld;
boolean enablePtWeWishYouAMerry = true;
static struct pt ptWeWishYouAMerry;
boolean enablePtRudolfTheRedNosed = true;
static struct pt ptRudolfTheRedNosed;
boolean enablePtJingleBells = true;
static struct pt ptJingleBells;

// Controller's controller is the function that changes the currently playing tone
static struct pt ptControllerController;
static struct pt ptFlashLights;

void setup() {
  // Setup the Protothread Variables
  PT_INIT(&ptJoyToTheWorld);  
  PT_INIT(&ptWeWishYouAMerry);
  PT_INIT(&ptRudolfTheRedNosed);
  PT_INIT(&ptJingleBells);
  PT_INIT(&ptControllerController);

  // Add a little bit of Christmas Festive Flare
  PT_INIT(&ptFlashLights);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}


/*************************************************
 ************* START MUSIC FUNCTIONS *************
 *************************************************/

// Sounds spectacularly similar to another infamous tune...
static PT_THREAD(protothreadJoyToTheWorld(struct pt *pt)) {
  static struct timer tJoyToTheWorld;
  PT_BEGIN(pt);
  while (enablePtJoyToTheWorld) {
    tone(tonePin, 587, 450.0);
    timer_set(&tJoyToTheWorld, 500.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 554, 337.5);
    timer_set(&tJoyToTheWorld, 375.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 493, 112.5);
    timer_set(&tJoyToTheWorld, 125.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 440, 675.0);
    timer_set(&tJoyToTheWorld, 750.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 391, 225.0);
    timer_set(&tJoyToTheWorld, 250.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 369, 450.0);
    timer_set(&tJoyToTheWorld, 500.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 329, 450.0);
    timer_set(&tJoyToTheWorld, 500.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 293, 675.0);
    timer_set(&tJoyToTheWorld, 750.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 440, 225.0);
    timer_set(&tJoyToTheWorld, 250.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 493, 670.3125);
    timer_set(&tJoyToTheWorld, 744.791666667); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    timer_set(&tJoyToTheWorld, 5.20833333333); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 493, 225.0);
    timer_set(&tJoyToTheWorld, 250.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 554, 670.3125);
    timer_set(&tJoyToTheWorld, 744.791666667); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    timer_set(&tJoyToTheWorld, 5.20833333333); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 554, 225.0);
    timer_set(&tJoyToTheWorld, 250.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 587, 670.3125);
    timer_set(&tJoyToTheWorld, 744.791666667); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    timer_set(&tJoyToTheWorld, 5.20833333333); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 587, 220.3125);
    timer_set(&tJoyToTheWorld, 244.791666667); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    timer_set(&tJoyToTheWorld, 5.20833333333); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 587, 225.0);
    timer_set(&tJoyToTheWorld, 250.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 554, 225.0);
    timer_set(&tJoyToTheWorld, 250.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 493, 225.0);
    timer_set(&tJoyToTheWorld, 250.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 440, 220.3125);
    timer_set(&tJoyToTheWorld, 244.791666667); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    timer_set(&tJoyToTheWorld, 5.20833333333); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 440, 337.5);
    timer_set(&tJoyToTheWorld, 375.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 391, 112.5);
    timer_set(&tJoyToTheWorld, 125.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 369, 225.0);
    timer_set(&tJoyToTheWorld, 250.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 587, 220.3125);
    timer_set(&tJoyToTheWorld, 244.791666667); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    timer_set(&tJoyToTheWorld, 5.20833333333); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 587, 225.0);
    timer_set(&tJoyToTheWorld, 250.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 554, 225.0);
    timer_set(&tJoyToTheWorld, 250.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 493, 225.0);
    timer_set(&tJoyToTheWorld, 250.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 440, 220.3125);
    timer_set(&tJoyToTheWorld, 244.791666667); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    timer_set(&tJoyToTheWorld, 5.20833333333); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 440, 337.5);
    timer_set(&tJoyToTheWorld, 375.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 391, 112.5);
    timer_set(&tJoyToTheWorld, 125.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 369, 220.3125);
    timer_set(&tJoyToTheWorld, 244.791666667); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    timer_set(&tJoyToTheWorld, 5.20833333333); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 369, 220.3125);
    timer_set(&tJoyToTheWorld, 244.791666667); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    timer_set(&tJoyToTheWorld, 5.20833333333); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 369, 220.3125);
    timer_set(&tJoyToTheWorld, 244.791666667); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    timer_set(&tJoyToTheWorld, 5.20833333333); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 369, 220.3125);
    timer_set(&tJoyToTheWorld, 244.791666667); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    timer_set(&tJoyToTheWorld, 5.20833333333); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 369, 220.3125);
    timer_set(&tJoyToTheWorld, 244.791666667); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    timer_set(&tJoyToTheWorld, 5.20833333333); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 369, 112.5);
    timer_set(&tJoyToTheWorld, 125.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 391, 112.5);
    timer_set(&tJoyToTheWorld, 125.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 440, 675.0);
    timer_set(&tJoyToTheWorld, 750.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 391, 112.5);
    timer_set(&tJoyToTheWorld, 125.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 369, 112.5);
    timer_set(&tJoyToTheWorld, 125.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 329, 220.3125);
    timer_set(&tJoyToTheWorld, 244.791666667); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    timer_set(&tJoyToTheWorld, 5.20833333333); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 329, 220.3125);
    timer_set(&tJoyToTheWorld, 244.791666667); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    timer_set(&tJoyToTheWorld, 5.20833333333); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 329, 220.3125);
    timer_set(&tJoyToTheWorld, 244.791666667); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    timer_set(&tJoyToTheWorld, 5.20833333333); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 329, 112.5);
    timer_set(&tJoyToTheWorld, 125.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 369, 112.5);
    timer_set(&tJoyToTheWorld, 125.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 391, 675.0);
    timer_set(&tJoyToTheWorld, 750.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 369, 112.5);
    timer_set(&tJoyToTheWorld, 125.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 329, 112.5);
    timer_set(&tJoyToTheWorld, 125.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 293, 225.0);
    timer_set(&tJoyToTheWorld, 250.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 587, 450.0);
    timer_set(&tJoyToTheWorld, 500.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 493, 225.0);
    timer_set(&tJoyToTheWorld, 250.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 440, 337.5);
    timer_set(&tJoyToTheWorld, 375.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 391, 112.5);
    timer_set(&tJoyToTheWorld, 125.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 369, 225.0);
    timer_set(&tJoyToTheWorld, 250.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 391, 225.0);
    timer_set(&tJoyToTheWorld, 250.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 369, 450.0);
    timer_set(&tJoyToTheWorld, 500.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));
    tone(tonePin, 329, 450.0);
    timer_set(&tJoyToTheWorld, 500.0); PT_WAIT_UNTIL(pt, timer_expired(&tJoyToTheWorld));

    }
  PT_END(pt);
  startNextSong();
}

static PT_THREAD(protothreadWeWishYouAMerry(struct pt *pt)) {
  static struct timer tWeWishYouAMerry;
  PT_BEGIN(pt);
  while (enablePtWeWishYouAMerry) {
    timer_set(&tWeWishYouAMerry, 86.8054166667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 311, 312.4995);    
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 415, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 415, 156.24975);
    timer_set(&tWeWishYouAMerry, 173.610833333); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 466, 156.24975);
    timer_set(&tWeWishYouAMerry, 173.610833333); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 415, 156.24975);
    timer_set(&tWeWishYouAMerry, 173.610833333); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 391, 156.24975);
    timer_set(&tWeWishYouAMerry, 173.610833333); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 349, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 349, 234.374625);
    timer_set(&tWeWishYouAMerry, 260.41625); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    timer_set(&tWeWishYouAMerry, 86.8054166667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 349, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 466, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 466, 156.24975);
    timer_set(&tWeWishYouAMerry, 173.610833333); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 523, 156.24975);
    timer_set(&tWeWishYouAMerry, 173.610833333); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 466, 156.24975);
    timer_set(&tWeWishYouAMerry, 173.610833333); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 415, 156.24975);
    timer_set(&tWeWishYouAMerry, 173.610833333); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 391, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 311, 234.374625);
    timer_set(&tWeWishYouAMerry, 260.41625); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    timer_set(&tWeWishYouAMerry, 86.8054166667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 311, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 523, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 523, 156.24975);
    timer_set(&tWeWishYouAMerry, 173.610833333); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 554, 156.24975);
    timer_set(&tWeWishYouAMerry, 173.610833333); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 523, 156.24975);
    timer_set(&tWeWishYouAMerry, 173.610833333); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 466, 156.24975);
    timer_set(&tWeWishYouAMerry, 173.610833333); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 415, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 349, 234.374625);
    timer_set(&tWeWishYouAMerry, 260.41625); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    timer_set(&tWeWishYouAMerry, 86.8054166667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 311, 156.24975);
    timer_set(&tWeWishYouAMerry, 173.610833333); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 311, 156.24975);
    timer_set(&tWeWishYouAMerry, 173.610833333); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 349, 234.374625);
    timer_set(&tWeWishYouAMerry, 260.41625); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    timer_set(&tWeWishYouAMerry, 86.8054166667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 466, 234.374625);
    timer_set(&tWeWishYouAMerry, 260.41625); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    timer_set(&tWeWishYouAMerry, 86.8054166667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 391, 234.374625);
    timer_set(&tWeWishYouAMerry, 260.41625); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    timer_set(&tWeWishYouAMerry, 86.8054166667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 415, 546.874125);
    timer_set(&tWeWishYouAMerry, 607.637916667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    timer_set(&tWeWishYouAMerry, 86.8054166667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 311, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 415, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 415, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 415, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 391, 624.999);
    timer_set(&tWeWishYouAMerry, 694.443333333); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 391, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 415, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 391, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 349, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 311, 546.874125);
    timer_set(&tWeWishYouAMerry, 607.637916667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    timer_set(&tWeWishYouAMerry, 86.8054166667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 466, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 523, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 466, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 415, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 622, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 311, 312.4995);
    timer_set(&tWeWishYouAMerry, 347.221666667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 311, 156.24975);
    timer_set(&tWeWishYouAMerry, 173.610833333); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 311, 156.24975);
    timer_set(&tWeWishYouAMerry, 173.610833333); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 349, 234.374625);
    timer_set(&tWeWishYouAMerry, 260.41625); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    timer_set(&tWeWishYouAMerry, 86.8054166667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 466, 234.374625);
    timer_set(&tWeWishYouAMerry, 260.41625); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    timer_set(&tWeWishYouAMerry, 86.8054166667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 391, 234.374625);
    timer_set(&tWeWishYouAMerry, 260.41625); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    timer_set(&tWeWishYouAMerry, 86.8054166667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    tone(tonePin, 415, 546.874125);
    timer_set(&tWeWishYouAMerry, 607.637916667); PT_WAIT_UNTIL(pt, timer_expired(&tWeWishYouAMerry));
    }
  PT_END(pt);
  startNextSong();
}
static PT_THREAD(protothreadRudolfTheRedNosed(struct pt *pt)) {
  static struct timer tRudolfTheRedNosed;
  PT_BEGIN(pt);
  while (enablePtRudolfTheRedNosed) {
    timer_set(&tRudolfTheRedNosed, 3.74699652778); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 329, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 523, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 967.849203125);
    timer_set(&tRudolfTheRedNosed, 1075.38800347); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    timer_set(&tRudolfTheRedNosed, 3.74699652778); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 523, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 493, 1294.962);
    timer_set(&tRudolfTheRedNosed, 1438.84666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 349, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 349, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 293, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 493, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 967.849203125);
    timer_set(&tRudolfTheRedNosed, 1075.38800347); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    timer_set(&tRudolfTheRedNosed, 3.74699652778); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 329, 1294.962);
    timer_set(&tRudolfTheRedNosed, 1438.84666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 329, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 523, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 967.849203125);
    timer_set(&tRudolfTheRedNosed, 1075.38800347); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    timer_set(&tRudolfTheRedNosed, 3.74699652778); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 523, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 493, 1294.962);
    timer_set(&tRudolfTheRedNosed, 1438.84666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 349, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 349, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 293, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 493, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 967.849203125);
    timer_set(&tRudolfTheRedNosed, 1075.38800347); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    timer_set(&tRudolfTheRedNosed, 3.74699652778); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 587, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 523, 1294.962);
    timer_set(&tRudolfTheRedNosed, 1438.84666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 320.368203125);
    timer_set(&tRudolfTheRedNosed, 355.964670139); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    timer_set(&tRudolfTheRedNosed, 3.74699652778); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 523, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 329, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 647.481);
    timer_set(&tRudolfTheRedNosed, 719.423333333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 349, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 349, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 329, 1294.962);
    timer_set(&tRudolfTheRedNosed, 1438.84666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 293, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 329, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 493, 320.368203125);
    timer_set(&tRudolfTheRedNosed, 355.964670139); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    timer_set(&tRudolfTheRedNosed, 3.74699652778); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 493, 320.368203125);
    timer_set(&tRudolfTheRedNosed, 355.964670139); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    timer_set(&tRudolfTheRedNosed, 3.74699652778); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 493, 647.481);
    timer_set(&tRudolfTheRedNosed, 719.423333333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 523, 320.368203125);
    timer_set(&tRudolfTheRedNosed, 355.964670139); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    timer_set(&tRudolfTheRedNosed, 3.74699652778); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 523, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 493, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 349, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 293, 809.35125);
    timer_set(&tRudolfTheRedNosed, 899.279166667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 329, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 523, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 967.849203125);
    timer_set(&tRudolfTheRedNosed, 1075.38800347); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    timer_set(&tRudolfTheRedNosed, 3.74699652778); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 523, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 493, 1294.962);
    timer_set(&tRudolfTheRedNosed, 1438.84666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 349, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 349, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 293, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 493, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 967.849203125);
    timer_set(&tRudolfTheRedNosed, 1075.38800347); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    timer_set(&tRudolfTheRedNosed, 3.74699652778); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 440, 161.87025);
    timer_set(&tRudolfTheRedNosed, 179.855833333); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 391, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 587, 323.7405);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    tone(tonePin, 523, 971.2215);
    timer_set(&tRudolfTheRedNosed, 359.711666667); PT_WAIT_UNTIL(pt, timer_expired(&tRudolfTheRedNosed));
    }
  PT_END(pt);
  startNextSong();
}
static PT_THREAD(protothreadJingleBells(struct pt *pt)) {
  static struct timer tJingleBells;
  PT_BEGIN(pt);
  while (enablePtJingleBells) {
    tone(tonePin, 493, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 416.6655);
    timer_set(&tJingleBells, 462.961666667); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 416.6655);
    timer_set(&tJingleBells, 462.961666667); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 587, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 391, 312.499125);
    timer_set(&tJingleBells, 347.22125); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 440, 104.166375);
    timer_set(&tJingleBells, 115.740416667); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 833.331);
    timer_set(&tJingleBells, 925.923333333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 523, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 523, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 523, 312.499125);
    timer_set(&tJingleBells, 347.22125); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 523, 104.166375);
    timer_set(&tJingleBells, 115.740416667); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 523, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 104.166375);
    timer_set(&tJingleBells, 115.740416667); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 104.166375);
    timer_set(&tJingleBells, 115.740416667); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 440, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 440, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 440, 416.6655);
    timer_set(&tJingleBells, 462.961666667); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 587, 416.6655);
    timer_set(&tJingleBells, 462.961666667); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 416.6655);
    timer_set(&tJingleBells, 462.961666667); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 416.6655);
    timer_set(&tJingleBells, 462.961666667); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 587, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 391, 312.499125);
    timer_set(&tJingleBells, 347.22125); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 440, 104.166375);
    timer_set(&tJingleBells, 115.740416667); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 833.331);
    timer_set(&tJingleBells, 925.923333333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 523, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 523, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 523, 312.499125);
    timer_set(&tJingleBells, 347.22125); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 523, 104.166375);
    timer_set(&tJingleBells, 115.740416667); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 523, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 104.166375);
    timer_set(&tJingleBells, 115.740416667); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 493, 104.166375);
    timer_set(&tJingleBells, 115.740416667); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 587, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 587, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 523, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 440, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 391, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 587, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    tone(tonePin, 783, 208.33275);
    timer_set(&tJingleBells, 231.480833333); PT_WAIT_UNTIL(pt, timer_expired(&tJingleBells));
    }
  PT_END(pt);
  startNextSong();
}
/*************************************************
 ************** END MUSIC FUNCTIONS **************
 *************************************************/

/*************************************************
 ************* START UTILE FUNCTIONS *************
 *************************************************/
// The Controller checks the "current" variable and updates the protothread that should be ran as expected
// The Controller also terminates any active Protothread Functions (asides from the Controller's Controller - "protothreadControllerController")
void controller() {
  if (current != 0) {
    enablePtJoyToTheWorld = false;
  } else {
    enablePtJoyToTheWorld = true;
  }
  if (current != 1) {
    enablePtWeWishYouAMerry = false;
  } else {
    enablePtWeWishYouAMerry = true;
  }
  if (current != 2) {
    enablePtRudolfTheRedNosed = false;
  } else {
    enablePtRudolfTheRedNosed = true;
  }
  if (current != 3) {
    enablePtJingleBells = false;
  } else {
    enablePtJingleBells = true;
  }
}

// Start Next Song doesn't play the song in a blocking fashion. It continuously recalls the protothread song function.
void startNextSong() {
  controller();
  switch(current) {
     case 0:
        protothreadJoyToTheWorld(&ptJoyToTheWorld); // Schedule the protothread
        break;
     case 1:
        protothreadWeWishYouAMerry(&ptWeWishYouAMerry); // Schedule the protothread
        break;
     case 2:
        protothreadRudolfTheRedNosed(&ptRudolfTheRedNosed); // Schedule the protothread
        break;
     case 3:
        protothreadJingleBells(&ptJingleBells); // Schedule the protothread
        break;
  }
}

// Increment Song changes the currently playing song
void incrementSong() {
  current = (current + 1) % 4;
  controller();
}


static PT_THREAD(protothreadControllerController(struct pt *pt)) {
  static struct timer tControllerController;
  PT_BEGIN(pt);

  // The controller should always check to see if the currently playing song should be incremented
  while (1) {

    // Analog Pin 0 is where our button is situated
    // When it is pressed, the desired outcome is for the currently playing song to change  
    PT_WAIT_UNTIL(pt, analogRead(A0) > 1000);
    incrementSong();

    // This is the exception to the delay rule below.
    // We want this blocking delay to stop music playback entirely, else a seamless transition will make things awkward.

    // Firet, we want to turn off the festive lights in order to prevent them from being stuck mid-state
    //    digitalWrite(8, LOW);
    //    digitalWrite(9, LOW);
    //    digitalWrite(10, LOW);

    delay(1000);
    // timer_set(&tControllerController, 1000); PT_WAIT_UNTIL(pt, timer_expired(&tControllerController));

    // Reset the timings on the music protothreads
    PT_INIT(&ptJoyToTheWorld);  
    PT_INIT(&ptWeWishYouAMerry);
    PT_INIT(&ptRudolfTheRedNosed);
    PT_INIT(&ptJingleBells);
  }
  PT_END(pt);
}

static PT_THREAD(protothreadFlashLights(struct pt *pt)) {
  static struct timer tFlashLights;
  PT_BEGIN(pt);
  while (1) {

    // Flash festive lights
    digitalWrite(8, LOW);
    digitalWrite(10, HIGH);
    timer_set(&tFlashLights, 500); PT_WAIT_UNTIL(pt, timer_expired(&tFlashLights));
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    timer_set(&tFlashLights, 500); PT_WAIT_UNTIL(pt, timer_expired(&tFlashLights));
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    timer_set(&tFlashLights, 500); PT_WAIT_UNTIL(pt, timer_expired(&tFlashLights));  
  }
  PT_END(pt);
}

/*************************************************
 ************** END UTILE FUNCTIONS **************
 *************************************************/

// This is the loop that controls how time flows for the Arduino
// Nowhere in this code should the old-fashioned delay should be run, unless the entire Arduino is meant to be stopped entirely

boolean initalPress = false;
void loop() {
  if (analogRead(A0) > 1000 || initalPress) {
    initalPress = true;
    protothreadControllerController(&ptControllerController); // schedule the controller
    startNextSong();
    protothreadFlashLights(&ptFlashLights); // schedule the alternatingly flashing lights
  }
}
