//
// sends Alt-F1, Alt-F2, Alt-F3, and Alt-F5 when pins 9, 10, 11, and 12 (respectively) are brought low
// pins 11 and 12 will fire on press and again on release for push-to-mute
//
// Kevin McGlynn
// 7evinmcg@gmail.com

#include "DigiKeyboard.h"

const int debounceDelay = 10;

const int pinButton[] = {       // corresponding pins for buttons 1, 2, 3, and 4

  9, 10, 11, 12
};

int buttonState[] = {           // current state of the button

  1, 1, 1, 1
};

int lastButtonState[] = {       // previous state of the button

  1, 1, 1, 1
};

const int payloadHex[] = {      // bytes recognized by host as USB HID keys

  58, 59, 60, 62                // F1 through F5, skipping F4
};

void setup() {
  for (int i = 0; i < 4; i++) {

    pinMode(pinButton[i], INPUT_PULLUP);
  }
}

void loop() {

  DigiKeyboard.sendKeyStroke(0);            // good practice. os may time out device according to documentation
  
  for (int i = 0; i < 4; i++) {

    buttonState[i] = digitalRead(pinButton[i]);

    if (buttonState[i] != lastButtonState[i]) {
      if (buttonState[i] == LOW) {

        DigiKeyboard.sendKeyStroke(payloadHex[i], MOD_ALT_RIGHT);
        DigiKeyboard.sendKeyStroke(0);      // ensures one keystroke is sent then released
      } else {

        switch (i) {                        // buttons on pins 2 and 3 will be push-to-mute. continuously sending keystroke isn't working
          case 2:                           // instead this will send a keystroke on press as well as release. macro is a 2 position switch

            DigiKeyboard.sendKeyStroke(payloadHex[i], MOD_ALT_RIGHT);
            DigiKeyboard.sendKeyStroke(0);
            break;
          case 3:

            DigiKeyboard.sendKeyStroke(payloadHex[i], MOD_ALT_RIGHT);
            DigiKeyboard.sendKeyStroke(0);
            break;
          default:

            break;
        }
      }

      DigiKeyboard.delay(debounceDelay);               //debounce delay, but spams empty keystroke to ensure device stays connected
    }

    lastButtonState[i] = buttonState[i];
  }
}






