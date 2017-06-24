# uMacro
Simple, lightweight four-button USB HID keyboard emulator based on Digispark Pro

Sends Alt-F1, Alt-F2, Alt-F3, and Alt-F5 when pins 9, 10, 11, and 12 (respectively) are brought low. This implementation uses a four button membrane keypad (https://www.adafruit.com/product/1332).

Pins 9 and 10 fire once on press. Pins 11 and 12 will fire on press and again on release for push-to-mute. Use-case is starting/stopping OBS stream, muting/deafening specific audio/microphones. Keypad is adhered to the side of an HTC Vive and the Digispark Pro is plugged into the spare USB port on the headset. 

Not provided here are the DigisparkKeyboard library:
https://github.com/digistump/DigistumpArduino/tree/master/digistump-avr/libraries

and the Digistump board manager:
http://digistump.com/package_digistump_index.json

Both are required. Enter the Digistump board manager URL into 'Additional Board Manager URLs" found in Preferences>Settings tab, then select the correct board from the Tools menu. The DigisparkKeyboard library must be installed according to instructions found here:
https://www.arduino.cc/en/Guide/Libraries

License:

The DigisparkKeyboard library includes V-USB under the terms of the GNU General Public License Version 2:
https://www.obdev.at/products/vusb/index.html

The Digispark Pro bootloader is based on Micronucleus, licensed under GNU GPL version 2:
https://github.com/micronucleus/micronucleus
