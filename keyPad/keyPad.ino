#include <Key.h>
#include <Keypad.h>

char keys[4][4] = {{'1','2','3','A'}, {'4', '5', '6', 'B'}, {'7', '8', '9', 'C'}, {'*', '0', '#', 'D'}};
byte lignePin[4] = {5, 4, 3, 2};
byte colonnePin[4] = {9, 8, 7, 6};

Keypad keypad = Keypad(makeKeymap(keys), lignePin, colonnePin, 4, 4);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  if(key){
    Serial.println(key);
  }

}
