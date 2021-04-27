/*
  Keyboard Message test

  For the Arduino Leonardo and Micro.

  Sends a text string when a button is pressed.

  The circuit:
  - pushbutton attached from pin 4 to +5V
  - 10 kilohm resistor attached from pin 4 to ground

  created 24 Oct 2011
  modified 27 Mar 2012
  by Tom Igoe
  modified 11 Nov 2013
  by Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/KeyboardMessage
*/

#include "Keyboard.h"

const int f13_switch = 2;
const int f14_switch = 3;
const int f15_switch = 4;
const int f16_switch = 5;

const int num_switches = 4;

const int pressed_state = LOW;
const int poll_rate = 5;
const int switch_pins[4] = {f13_switch, f14_switch, f15_switch, f16_switch};
const int switch_keys[4] = {KEY_F13, KEY_F14, KEY_F15, KEY_F16};
bool is_pressed[4] = {false, false, false, false};

void setup() {
  // make the pushButton pin an input:
  for(int i = 0; i < num_switches; i++)
  {
    pinMode(switch_pins[i], INPUT);
  }
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  // read the pushbuttons:
  for(int i = 0; i < num_switches; i++)
  {
    int button_state = digitalRead(switch_pins[i]);
    if (button_state == pressed_state)
    {
      is_pressed[i] = true;
      Keyboard.press(switch_keys[i]);
    }
    else if(is_pressed[i])
    {
      is_pressed[i] = false;
      Keyboard.release(switch_keys[i]);
    }
  }
  delay(poll_rate);
}
