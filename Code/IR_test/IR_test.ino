//#include <MIDI.h>
//MIDI_CREATE_DEFAULT_INSTANCE();
// These constants won't change. They're used to give names to the pins used:
const int potN = 2; // total number of pots
const int analogInPin[potN] = {A0, A1}; // Analog input pin that the potentiometers are attached to

int sensorValue[potN] = {0};        // value read from the pot
int sensorPValue[potN] = {0};        // previous val
int potVar[potN] = {0};        // previous val
int outputValue[potN] = {0};        // value output to the midi
int outputValue_old[potN] = {0};    

const byte channel = 0;



void setup() {
Serial.begin(9600); 
}
void loop()
{

  // read the analog in value:
  //sensorValue = analogRead(analogInPin);

  for (int i = 0; i < potN; i++) {
    //sensorValue[i] = analogRead(analogInPin[i]);

    // one pole filter
    // y[n] = A0 * x[n] + B1 * y[n-1];
    // A = 0.15 and B = 0.85
    int reading = analogRead(analogInPin[i]);
    float filteredVal = 0.5 * reading + 0.5 * sensorPValue[i];
    sensorValue[i] = filteredVal;

    potVar[i] = abs(sensorValue[i] - sensorPValue[i]);
    sensorPValue[i] = sensorValue[i];
  }
  
  // map it to the range of the analog out:
  for (int i = 0; i < potN; i++) {
  outputValue[i] = map(sensorValue[i], 0, 1023, 0, 128);
  }
  
  
  

  // print the results to the Serial Monitor:
  for (int i = 0; i < potN; i++) {
    //Serial.print(i);
    //Serial.print(": ");
    //Serial.print(sensorValue[i]);
    Serial.print(outputValue[i]);
    Serial.print(" ");

  }
  Serial.println();

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
delay(80); // for staiblity
}
