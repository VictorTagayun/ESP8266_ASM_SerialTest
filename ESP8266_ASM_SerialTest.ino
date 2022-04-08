/*
  ASCII table

  Prints out byte values in all possible formats:
  - as raw binary values
  - as ASCII-encoded decimal, hex, octal, and binary values

  For more on ASCII, see http://www.asciitable.com and http://en.wikipedia.org/wiki/ASCII

  The circuit: No external hardware needed.

  created 2006
  by Nicholas Zambetti <http://www.zambetti.com>
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/ASCIITable
*/

#include <SimpleTimer.h>
SimpleTimer timer1;

#include <Ticker.h>
Ticker blinker;

int cntr;

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

void blinkLed() {

  cntr++;

  //  Serial.print(cntr % 2, DEC); Serial.print(" " );
  //  Serial.println(cntr % 6, DEC);

  if ((cntr % 6) == 1) {
    digitalWrite(12, HIGH);
  }
  if ((cntr % 6) == 3) {
    digitalWrite(13, HIGH);
  }
  if ((cntr % 6) == 5) {
    digitalWrite(15, HIGH);
  }
  if ((cntr % 2) == 0) {
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(15, LOW);
  }
}

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(19200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(15, OUTPUT);

  // prints title with ending line break
  Serial.println(""); delay(200); Serial.println(""); delay(200); Serial.println(""); delay(200); Serial.println(""); delay(200); Serial.println(""); delay(200);
  Serial.println("Connecting to victortagayun.github.io ");
  Serial.println(""); delay(200); Serial.println(""); delay(200); Serial.println(""); delay(200); Serial.println(""); delay(200); Serial.println(""); delay(5000);
  Serial.println("Parsing data....  ");
  Serial.println(""); delay(200); Serial.println(""); delay(200); Serial.println(""); delay(200); Serial.println(""); delay(200); Serial.println(""); delay(5000);
  Serial.println("This device is owned by Victor Tagayun, please return it if you are not given permission to use.");
  Serial.println(""); delay(200); Serial.println(""); delay(200); Serial.println(""); delay(200); Serial.println(""); delay(200); Serial.println(""); delay(5000);
  Serial.println("For troubleshooting guidelines please visit victortagayun.github.io ");
  Serial.println(""); delay(200); Serial.println(""); delay(200); Serial.println(""); delay(200); Serial.println(""); delay(200); Serial.println(""); delay(5000);
  Serial.println("Good bye! Disconnecting.... ");
  Serial.println(""); delay(200); Serial.println(""); delay(200); Serial.println(""); delay(200); Serial.println(""); delay(200); Serial.println(""); delay(200);

  inputString.reserve(200);
  
  //  timer1.setInterval(300L, blinkLed);
  blinker.attach(0.3, blinkLed);
}


void loop() {
//  if (Serial.available()) {      // If anything comes in Serial (USB),
//    Serial.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
//  }

  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.print("You typed >>> \"");
    Serial.print(inputString);
    Serial.println("\"");
    Serial.println("--- by victortagayun.github.io ");
    Serial.println("");
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}


/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
//    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } else
    {
      inputString += inChar;
    }
  }
}
