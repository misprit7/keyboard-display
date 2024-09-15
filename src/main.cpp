#include <Arduino.h>
#include "usb_keyboard.h"
/*#include <Keyboard.h>*/

#include "video.h"

const int display_width = 32;
const int display_height = 24;

void setup() {
  Keyboard.begin();
  pinMode(0, INPUT_PULLUP);
}

void loop(){
  if(!digitalRead(0)){
    for(;;);
  }

  for(int _ = 0; _ < 5; ++_)
    Keyboard.write('\n');
  for(int i = 0; i < display_height; ++i){
    String to_print = "";
    for(int j = 0; j < display_width; j++){
      to_print += 'o';
    }
    Keyboard.print(to_print + '\n');
  }

  delay(5'000);

}

#if 0
void setup() {
  Keyboard.begin();
  usb_keyboard_configure();
  delay(1000);
  /*int start_time = millis();*/
  /*int i = 0;*/
  /*while(millis() - start_time < 1000){*/
  /*  if(i%50 == 0){*/
  /*    Keyboard.print("\n");*/
  /*    Keyboard.print(i);*/
  /*  } else {*/
  /*    Keyboard.print("aa");*/
  /*  }*/
  /*  ++i;*/
  /*}*/
}

void delete_all(){
  /*Keyboard.press(KEY_ESC);*/
  /*Keyboard.release(KEY_ESC);*/
  /*Keyboard.print("ggdGi");*/
  Keyboard.press(MODIFIERKEY_CTRL);
  Keyboard.print("A");
  Keyboard.release(MODIFIERKEY_CTRL);
  Keyboard.press(KEY_DELETE);
}

void sendEscapeSequence() {
  Keyboard.write(27);  // Send the Escape character (ASCII 27)
  Keyboard.print("[2J");  // Clear the screen
  Keyboard.write(27);  // Send the Escape character (ASCII 27) again
  Keyboard.print("[H");  // Move the cursor to the top-left
}

static uint8_t keycode_to_key(KEYCODE_TYPE keycode)
{
	uint8_t key = keycode & 0x3F;
	#ifdef KEY_NON_US_100
	if (key == KEY_NON_US_100) key = 100;
	#endif
	return key;
}

int t = 0;
int n = 20;

void loop() {
  /*delete_all();*/
  /*sendEscapeSequence();*/
  /*Keyboard.print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");*/
  usb_keyboard_press_keycode(KEY_ENTER);
  usb_keyboard_press_keycode(KEY_ENTER);
  usb_keyboard_press_keycode(KEY_ENTER);
  for(int i = 0; i < n; ++i){
    /*String to_print = "";*/
    for(int j = 0; j < n; j+=6){
      for(int k = 0; k < 6; ++k){
        /*keyboard_keys[k] = keycode_to_key(keycodes_ascii[((j+k) == t%n ? KEY_EQUAL : KEY_O)-0x20]);*/
        usb_keyboard_write((j+k) == t%n ? '|' : 'o');
      }
      /*usb_keyboard_send();*/
      /*usb_keyboard_release_all();*/
      /*to_print += j == t%n ? '|' : 'o';*/
      /*Keyboard.write(j == t%n ? '|' : 'o');*/

    }
    /*Keyboard.write('\n');*/
    usb_keyboard_press_keycode(KEY_ENTER);
    /*Keyboard.print(to_print + '\n');*/
  }
  delay(200);
  t++;
  if(t == 5){
    for(;;);
  }
}

#endif
