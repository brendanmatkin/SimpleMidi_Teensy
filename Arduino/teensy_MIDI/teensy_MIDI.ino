/* USB MIDI AnalogControlChange Example
 
 You must select MIDI from the "Tools > USB Type" menu
 http://www.pjrc.com/teensy/td_midi.html
 
 This example code is in the public domain.
 */

#include <Bounce.h>

// the MIDI channel number to send messages
const int channel = 1;

// create the Bounce objects (for each button)
const int time = 5; // debounce time in ms
Bounce b0 = Bounce(0,time);
Bounce b1 = Bounce(1,time);
Bounce b2 = Bounce(2,time);
Bounce b3 = Bounce(3,time);
Bounce b4 = Bounce(4,time);
Bounce b5 = Bounce(5,time);
Bounce b6 = Bounce(6,time);
Bounce b7 = Bounce(7,time);
Bounce b8 = Bounce(8,time);
Bounce b9 = Bounce(9,time);
Bounce b10 = Bounce(10,time);
Bounce b11 = Bounce(11,time);
Bounce b12 = Bounce(12,time);
Bounce b13 = Bounce(13,time);
Bounce b14 = Bounce(24,time);
Bounce b15 = Bounce(25,time);
Bounce b16 = Bounce(31,time);
Bounce b17 = Bounce(32,time);
Bounce b18 = Bounce(33,time);

// MIDI note for each digital button input 
const int bD0 = 21;
const int bD1 = 22;
const int bD2 = 23;
const int bD3 = 24;
const int bD4 = 25;
const int bD5 = 26;
const int bD6 = 27;
const int bD7 = 28;
const int bD8 = 29;
const int bD9 = 30;
const int bD10 = 31;
const int bD11 = 32;
const int bD12 = 33;
const int bD13 = 34;
const int bD14 = 35;
const int bD15 = 36;
const int bD16 = 37;
const int bD17 = 38;
const int bD18 = 39;

// the MIDI continuous controller for each analog input
const int cA0 = 1;
const int cA1 = 2;
const int cA2 = 3;
const int cA3 = 4;
const int cA4 = 5;
const int cA5 = 6;
const int cA6 = 7;
const int cA7 = 8;
const int cA8 = 9;
const int cA9 = 10;
const int cA10 = 11;
const int cA11 = 12;
const int cA12 = 13;
const int cA13 = 14;
const int cA14 = 15;
const int cA15 = 16;
const int cA16 = 17;
const int cA17 = 18;
const int cA18 = 19;
const int cA19 = 20;






void setup() {
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);  // LED - may need 1k resistor?
  pinMode(24, INPUT_PULLUP);
  pinMode(25, INPUT_PULLUP);
  pinMode(31, INPUT_PULLUP);
  pinMode(32, INPUT_PULLUP);
  pinMode(33, INPUT_PULLUP);
  delay(100);
}

// store previously sent analog values, to detect changes
int prevA0 = -1;
int prevA1 = -1;
int prevA2 = -1;
int prevA3 = -1;
int prevA4 = -1;
int prevA5 = -1;
int prevA6 = -1;
int prevA7 = -1;
int prevA8 = -1;
int prevA9 = -1;
int prevA10 = -1;
int prevA11 = -1;
int prevA12 = -1;
int prevA13 = -1;
int prevA14 = -1;
int prevA15 = -1;
int prevA16 = -1;
int prevA17 = -1;
int prevA18 = -1;
int prevA19 = -1;

elapsedMillis msec = 0;


void loop() {
  buttons();
  faders();

  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  while (usbMIDI.read()) {
    // ignore incoming messages
  }
  delay(15);
}

void buttons() {
  // update Bounce class
  b0.update();
  b1.update();
  b2.update();
  b3.update();
  b4.update();
  b5.update();
  b6.update();
  b7.update();
  b8.update();
  b9.update();
  b10.update();
  b11.update();
  b12.update();
  b13.update();
  b14.update();
  b15.update();
  b16.update();
  b17.update();
  b18.update();

  if (b0.fallingEdge()) {
    usbMIDI.sendNoteOn(bD0, 127, channel);
  }
  if (b1.fallingEdge()) {
    usbMIDI.sendNoteOn(bD1, 127, channel);
  }
  if (b2.fallingEdge()) {
    usbMIDI.sendNoteOn(bD2, 127, channel);
  }
  if (b3.fallingEdge()) {
    usbMIDI.sendNoteOn(bD3, 127, channel);
  }
  if (b4.fallingEdge()) {
    usbMIDI.sendNoteOn(bD4, 127, channel);
  }
  if (b5.fallingEdge()) {
    usbMIDI.sendNoteOn(bD5, 127, channel);
  }
  if (b6.fallingEdge()) {
    usbMIDI.sendNoteOn(bD6, 127, channel);
  }
  if (b7.fallingEdge()) {
    usbMIDI.sendNoteOn(bD7, 127, channel);
  }
  if (b8.fallingEdge()) {
    usbMIDI.sendNoteOn(bD8, 127, channel);
  }
  if (b9.fallingEdge()) {
    usbMIDI.sendNoteOn(bD9, 127, channel);
  }
  if (b10.fallingEdge()) {
    usbMIDI.sendNoteOn(bD10, 127, channel);
  }
  if (b11.fallingEdge()) {
    usbMIDI.sendNoteOn(bD11, 127, channel);
  }
  if (b12.fallingEdge()) {
    usbMIDI.sendNoteOn(bD12, 127, channel);
  }
  if (b13.fallingEdge()) {
    usbMIDI.sendNoteOn(bD13, 127, channel);
  }
  if (b14.fallingEdge()) {
    usbMIDI.sendNoteOn(bD14, 127, channel);
  }
  if (b15.fallingEdge()) {
    usbMIDI.sendNoteOn(bD15, 127, channel);
  }
  if (b16.fallingEdge()) {
    usbMIDI.sendNoteOn(bD16, 127, channel);
  }
  if (b17.fallingEdge()) {
    usbMIDI.sendNoteOn(bD17, 127, channel);
  }
  if (b18.fallingEdge()) {
    usbMIDI.sendNoteOn(bD18, 127, channel);
  }  


  //************************//

  if (b0.risingEdge()) {
    usbMIDI.sendNoteOff(bD0, 127, channel);
  }
  if (b1.risingEdge()) {
    usbMIDI.sendNoteOff(bD1, 127, channel);
  }
  if (b2.risingEdge()) {
    usbMIDI.sendNoteOff(bD2, 127, channel);
  }
  if (b3.risingEdge()) {
    usbMIDI.sendNoteOff(bD3, 127, channel);
  }
  if (b4.risingEdge()) {
    usbMIDI.sendNoteOff(bD4, 127, channel);
  }
  if (b5.risingEdge()) {
    usbMIDI.sendNoteOff(bD5, 127, channel);
  }
  if (b6.risingEdge()) {
    usbMIDI.sendNoteOff(bD6, 127, channel);
  }
  if (b7.risingEdge()) {
    usbMIDI.sendNoteOff(bD7, 127, channel);
  }
  if (b8.risingEdge()) {
    usbMIDI.sendNoteOff(bD8, 127, channel);
  }
  if (b9.risingEdge()) {
    usbMIDI.sendNoteOff(bD9, 127, channel);
  }
  if (b10.risingEdge()) {
    usbMIDI.sendNoteOff(bD10, 127, channel);
  }
  if (b11.risingEdge()) {
    usbMIDI.sendNoteOff(bD11, 127, channel);
  }
  if (b12.risingEdge()) {
    usbMIDI.sendNoteOff(bD12, 127, channel);
  }
  if (b13.risingEdge()) {
    usbMIDI.sendNoteOff(bD13, 127, channel);
  }
  if (b14.risingEdge()) {
    usbMIDI.sendNoteOff(bD14, 127, channel);
  }
  if (b15.risingEdge()) {
    usbMIDI.sendNoteOff(bD15, 127, channel);
  }
  if (b16.risingEdge()) {
    usbMIDI.sendNoteOff(bD16, 127, channel);
  }
  if (b17.risingEdge()) {
    usbMIDI.sendNoteOff(bD17, 127, channel);
  }
  if (b18.risingEdge()) {
    usbMIDI.sendNoteOff(bD18, 127, channel);
  }
}

void faders() {
  // only check the analog inputs 50 times per second,
  // to prevent a flood of MIDI messages
  if (msec >= 20) {
    msec = 0;
    int n0 = analogRead(A0) / 8;
    int n1 = analogRead(A1) / 8;
    int n2 = analogRead(A2) / 8;
    int n3 = analogRead(A3) / 8;
    int n4 = analogRead(A4) / 8;
    int n5 = analogRead(A5) / 8;
    int n6 = analogRead(A6) / 8;
    int n7 = analogRead(A7) / 8;
    int n8 = analogRead(A8) / 8;
    int n9 = analogRead(A9) / 8;
    int n10 = analogRead(A10) / 8;
    int n11 = analogRead(A11) / 8;
    int n12 = analogRead(A12) / 8;
    int n13 = analogRead(A13) / 8;
    int n14 = analogRead(A14) / 8;
    int n15 = analogRead(A15) / 8;
    int n16 = analogRead(A16) / 8;
    int n17 = analogRead(A17) / 8;
    int n18 = analogRead(A18) / 8;
    int n19 = analogRead(A19) / 8;

    // only transmit MIDI messages if analog input changed
    if (n0 != prevA0) {
      usbMIDI.sendControlChange(cA0, n0, channel);
      prevA0 = n0;
    }
    if (n1 != prevA1) {
      usbMIDI.sendControlChange(cA1, n1, channel);
      prevA1 = n1;
    }
    if (n2 != prevA2) {
      usbMIDI.sendControlChange(cA2, n2, channel);
      prevA2 = n2;
    }
    if (n3 != prevA3) {
      usbMIDI.sendControlChange(cA3, n3, channel);
      prevA3 = n3;
    }
    if (n4 != prevA4) {
      usbMIDI.sendControlChange(cA4, n4, channel);
      prevA4 = n4;
    }
    if (n5 != prevA5) {
      usbMIDI.sendControlChange(cA5, n5, channel);
      prevA5 = n5;
    }
    if (n6 != prevA6) {
      usbMIDI.sendControlChange(cA6, n6, channel);
      prevA6 = n6;
    }
    if (n7 != prevA7) {
      usbMIDI.sendControlChange(cA7, n7, channel);
      prevA7 = n7;
    }
    if (n8 != prevA8) {
      usbMIDI.sendControlChange(cA8, n8, channel);
      prevA8 = n8;
    }
    if (n9 != prevA9) {
      usbMIDI.sendControlChange(cA9, n9, channel);
      prevA9 = n9;
    }
    if (n10 != prevA10) {
      usbMIDI.sendControlChange(cA10, n10, channel);
      prevA10 = n10;
    }
    if (n11 != prevA11) {
      usbMIDI.sendControlChange(cA11, n11, channel);
      prevA11 = n11;
    }
    if (n12 != prevA12) {
      usbMIDI.sendControlChange(cA12, n12, channel);
      prevA12 = n12;
    }
    if (n13 != prevA13) {
      usbMIDI.sendControlChange(cA13, n13, channel);
      prevA13 = n13;
    }
    if (n14 != prevA14) {
      usbMIDI.sendControlChange(cA14, n14, channel);
      prevA14 = n14;
    }
    if (n15 != prevA15) {
      usbMIDI.sendControlChange(cA15, n15, channel);
      prevA15 = n15;
    }
    if (n16 != prevA16) {
      usbMIDI.sendControlChange(cA16, n16, channel);
      prevA16 = n16;
    }
    if (n17 != prevA17) {
      usbMIDI.sendControlChange(cA17, n17, channel);
      prevA17 = n17;
    }
    if (n18 != prevA18) {
      usbMIDI.sendControlChange(cA18, n18, channel);
      prevA18 = n18;
    }
    if (n19 != prevA19) {
      usbMIDI.sendControlChange(cA19, n19, channel);
      prevA19 = n19;
    }
  }
}

