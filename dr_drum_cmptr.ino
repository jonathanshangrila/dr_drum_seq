// #include "pitches.h"

const int button1Pin = 6;  // pushbutton 1 pin
const int button2Pin = 7;  // pushbutton 2 pin
const int ledPin1 =  0;    // LED pin
const int ledPin2 =  1;    // LED pin

const int buttonPin1 = 30;
const int buttonPin2 = 31;
const int buttonPin3 = 32;
const int buttonPin4 = 33;
const int buttonPin5 = 34;
const int buttonPin6 = 35;
const int buttonPin7 = 36;
const int buttonPin8 = 37;  

const int buttonPinPause = 38;
const int buttonPinStartStop = 39;

// const int ledPin1 =
// const int ledPin2 =
// const int ledPin3 =
// const int ledPin4 =
// const int ledPin5 =
// const int ledPin6 =
// const int ledPin7 =
// const int ledPin8 =

// const int ledPinPause =
// const int ledPinStartStop = 

int datapin = 2; 
int clockpin = 3;
int latchpin = 4;

byte data = 0;

int button1State, button2State, button3State, button4State, button5State, button6State, button7State, button8State;
int button9State, button10State;
// int button1State, button2State;  // variables to hold the pushbutton states

#include <LiquidCrystal.h>

// LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// // notes in melody
// int melody[] = {

//   NOTE_C2, NOTE_C2, NOTE_C2, NOTE_C2, NOTE_C2, NOTE_C2, NOTE_C2, NOTE_C2, NOTE_C2, NOTE_C2, NOTE_C2, NOTE_C2,
// };

// // note durations: 4 = quarter note, 8 = eighth note, etc.:
// int noteDurations[] = {

//   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
// };

void (* resetFunc) (void) = 0; // declare reset function at address 0

void setup()
{

  lcd.begin(16, 2);

  lcd.clear();

  lcd.print("dr drum computer");
  
  // Set up the pushbutton pins to be an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);

  // Set up the LED pin to be an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);      

  // Set the three SPI pins to be outputs:

  pinMode(datapin, OUTPUT);
  pinMode(clockpin, OUTPUT);  
  pinMode(latchpin, OUTPUT);

}

void loop()
{

  // lcd screen output 
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);

  // 8 LED light emitting diodes in multiple ON OFF patterns  

  // oneAfterAnother();      // All on, all off
  oneOnAtATime();       // Scroll down the line
  // pingPong();           // Like above, but back and forth
  // randomLED();          // Blink random LEDs
  // marquee();
  // binaryCount();        // Bit patterns from 0 to 255

  // declare button1 and button2 on breadboard

  // Caution because this might pause the program if not employing use of interrupts

  // button1State = digitalRead(button1Pin);
  // button2State = digitalRead(button2Pin);  

  button1State = digitalRead(buttonPin1);
  button2State = digitalRead(buttonPin2);
  button3State = digitalRead(buttonPin3);
  button4State = digitalRead(buttonPin4);
  button5State = digitalRead(buttonPin5);
  button6State = digitalRead(buttonPin6);
  button7State = digitalRead(buttonPin7);
  button8State = digitalRead(buttonPin8);

  button10State = digitalRead(buttonPinStartStop);

  // WARNING THIS PART OF THE PROGRAM PAUSES THE MAIN LOOP SO THAT THE ABOVE CODE WILL NOT RUN ON THE NEXT 
  // DETERMINE HOW TO INCORPORATE POLLING OR MAKE USE OF TIMER INTERRUPTS OR MANUAL ON OFF INTERRUPT TO ACCEPT
  // EXTERNAL INPUT

  // // if button1 or button 2 are pressed (but not both)
  // if (((button1State == LOW) && (button2State == HIGH)) || ((button1State == HIGH) && (button2State == LOW)))
  // {
  //   digitalWrite(ledPin, HIGH);  // turn the LED on
  // }
  // else
  // {
  //   digitalWrite(ledPin, LOW);  // turn the LED off
  // }

  if (button1State == LOW) {
    //digitalWrite(ledPin1, HIGH);
    shiftWrite(0, HIGH);	// turn LED on
  }
  else if (button2State == LOW) {
    //digitalWrite(ledPin2, HIGH);
    shiftWrite(1, HIGH);	// turn LED on
  }
  else if (button3State == LOW) {
    //digitalWrite(ledPin3, HIGH);
    shiftWrite(2, HIGH);	// turn LED on
  }
  else if (button4State == LOW) {
    //digitalWrite(ledPin4, HIGH);
    shiftWrite(3, HIGH);	// turn LED on
  }
  else if (button5State == LOW) {
    //digitalWrite(ledPin5, HIGH);
    shiftWrite(4, HIGH);	// turn LED on
  }
  else if (button6State == LOW) {
    //digitalWrite(ledPin6, HIGH);
    shiftWrite(5, HIGH);	// turn LED on
  }
  else if (button7State == LOW) {
    //digitalWrite(ledPin7, HIGH);
    shiftWrite(6, HIGH);	// turn LED on
  }
  else if (button8State == LOW) {
    //digitalWrite(ledPin8, HIGH);
    shiftWrite(7, HIGH);	// turn LED on
  }
  else {
    // digitalWrite(ledPin1, LOW);  // turn the LED off
    // digitalWrite(ledPin2, LOW);  // turn the LED off
    // digitalWrite(ledPin3, LOW);  // turn the LED off
    // digitalWrite(ledPin4, LOW);  // turn the LED off
    // digitalWrite(ledPin5, LOW);  // turn the LED off
    // digitalWrite(ledPin6, LOW);  // turn the LED off
    // digitalWrite(ledPin7, LOW);  // turn the LED off
    // digitalWrite(ledPin8, LOW);  // turn the LED off
      for (int index = 0; index <= 7; index++) {
        shiftWrite(index, LOW);	// turn LED on
        // delay(delayTime);       
      }
    
  }

  if (button9State == LOW) {
    digitalWrite(ledPin1, HIGH);
      //resetFunc();
  }
  if (button10State == LOW) {
    digitalWrite(ledPin2, HIGH);
      exit(1);
  }
  else {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }

  //playNotes();
  
}

// void playNotes() {

//   for (int thisNote = 0; thisNote < 12; thisNote++) {
//     // to calculate the note duration, take one second divided by the note type.
//     //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
//     int noteDuration = 1000 / noteDurations[thisNote];
//     tone(13, melody[thisNote], noteDuration);
//     // to distinguish the notes, set a minimum time between them.
//     // the note's duration + 30% seems to work well:
//     int pauseBetweenNotes = noteDuration * 1.30;
//     delay(pauseBetweenNotes);
//     // stop the tone playing:
//     noTone(8);
//   }

// }

void shiftWrite(int desiredPin, boolean desiredState)
{
// This function lets you make the shift register outputs
// HIGH or LOW in exactly the same way that you use digitalWrite().

  bitWrite(data,desiredPin,desiredState); //Change desired bit to 0 or 1 in "data"
  
  // Now we'll actually send that data to the shift register.
  // The shiftOut() function does all the hard work of
  // manipulating the data and clock pins to move the data
  // into the shift register:

  shiftOut(datapin, clockpin, MSBFIRST, data); //Send "data" to the shift register

  //Toggle the latchPin to make "data" appear at the outputs
  digitalWrite(latchpin, HIGH); 
  digitalWrite(latchpin, LOW); 
}


void oneAfterAnother()
{
// This function will turn on all the LEDs, one-by-one,
// and then turn them off all off, one-by-one. 

  int index;
  int delayTime = 100; // Time (milliseconds) to pause between LEDs
                       // Make this smaller for faster switching

  // Turn all the LEDs on
  for(index = 0; index <= 7; index++)
  {
    shiftWrite(index, HIGH);
    delay(delayTime);                
  }

  // Turn all the LEDs off
  for(index = 7; index >= 0; index--)
  {
    shiftWrite(index, LOW);
    delay(delayTime);
  }
}


void oneOnAtATime()
{
// This function will turn the LEDs on and off, one-by-one. 
  int index;
  int delayTime = 100; // Time (milliseconds) to pause between LEDs
                       // Make this smaller for faster switching
  
  // step through the LEDs, from 0 to 7
  
  for(index = 0; index <= 7; index++)
  {
    shiftWrite(index, HIGH);	// turn LED on
    delay(delayTime);		// pause to slow down the sequence
    shiftWrite(index, LOW);	// turn LED off
  }
}

void pingPong()
{
// This function turns on the LEDs, one at a time, in both directions. 
  int index;
  int delayTime = 250; // time (milliseconds) to pause between LEDs
                       // make this smaller for faster switching
  
  // step through the LEDs, from 0 to 7
  
  for(index = 0; index <= 7; index++)
  {
    shiftWrite(index, HIGH);	// turn LED on
    delay(delayTime);		// pause to slow down the sequence
    shiftWrite(index, LOW);	// turn LED off
  }

  // step through the LEDs, from 7 to 0
  
  for(index = 7; index >= 0; index--)
  {
    shiftWrite(index, HIGH);	// turn LED on
    delay(delayTime);		// pause to slow down the sequence
    shiftWrite(index, LOW);	// turn LED off
  }
}

void randomLED()
{
// This function will randomly turn on and off LEDs. 
  int index;
  int delayTime = 100; // time (milliseconds) to pause between LEDs
                       // make this smaller for faster switching
  
  index = random(8);	// pick a random number between 0 and 7
  
  shiftWrite(index, HIGH);	// turn LED on
  delay(delayTime);		// pause to slow down the sequence
  shiftWrite(index, LOW);	// turn LED off
}

void marquee()
{
// This function will mimic "chase lights" like those around signs.
  int index;
  int delayTime = 200; // Time (milliseconds) to pause between LEDs
                       // Make this smaller for faster switching
  
  // Step through the first four LEDs
  // (We'll light up one in the lower 4 and one in the upper 4)
  
  for(index = 0; index <= 3; index++)
  {
    shiftWrite(index, HIGH);    // Turn a LED on
    shiftWrite(index+4, HIGH);  // Skip four, and turn that LED on
    delay(delayTime);		// Pause to slow down the sequence
    shiftWrite(index, LOW);	// Turn both LEDs off
    shiftWrite(index+4, LOW);
  }
}


void binaryCount()
{
// This function creates a visual representation of the on/off pattern
// of bits in a byte. 

  int delayTime = 1000; // time (milliseconds) to pause between LEDs
                        // make this smaller for faster switching
  
  // Send the data byte to the shift register:

  shiftOut(datapin, clockpin, MSBFIRST, data);

  // Toggle the latch pin to make the data appear at the outputs:

  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);
  
  // Add one to data, and repeat!
  // (Because a byte type can only store numbers from 0 to 255,
  // if we add more than that, it will "roll around" back to 0
  // and start over).

  data++;

  // Delay so you can see what's going on:

  delay(delayTime);
}

