// constants won't change. They're used here to set pin numbers:
const int buttonN = 6; // total number of buttons
const int buttonPin[buttonN] = {4, 5, 6, 7, 8, 9}; // the number of the pushbutton pin
//const int buttonPin[buttonN] = {2}; // the number of the pushbutton pin

// variables will change:
int buttonState[buttonN] = {0};         // variable for reading the pushbutton status

void setup() {
  Serial.begin(115200);
  // initialize the LED pin as an output:
  //pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:

  for (int i = 0; i < buttonN; i++) {
    pinMode(buttonPin[i], INPUT_PULLUP);
  }

}

void loop() {
  // read the state of the pushbutton value:

  for (int i = 0; i < buttonN; i++) {
    buttonState[i] = digitalRead(buttonPin[i]);
  }

  for (int i = 0; i < buttonN; i++) {
    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (buttonState[i] == HIGH) {
      Serial.print(i);
      Serial.print(": OFF   ");
    } else {
      Serial.print(i);
      Serial.print(": ON    ");
    }
  }
  Serial.println();
delay(10);
}
