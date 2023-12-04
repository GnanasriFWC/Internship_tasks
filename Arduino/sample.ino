// Pin configuration
const int dataPinD1 = 2;      // Connect to Pin 2 (D1) of SN74ALS74AN
const int dataPinD2 = 3;      // Connect to Pin 10 (D2) of SN74ALS74AN
const int dataPinD3 = 8;
const int dataPinD4 = 9;
const int clockPin1 = 4;       // Connect to Pin 9 (CLK) of SN74ALS74AN
const int setPin = 5;
const int resetPin = 6;
const int qOutputPinQ1 = 7;   // Connect to Pin 7 (Q1) of SN74ALS74AN
const int qOutputPinQ2 = 13;  // Connect to Pin 13 (Q2) of SN74ALS74AN
const int qOutputPinQ3 = 10;
const int qOutputPinQ4 = 11;
const int pinA = A0;
const int pinB = A1;
const int pinC = A2;
const int pinD = A3;
const int clockPin2 = A4;
int D1,D2,D3,D4;

void setup() {
  // Set the data, clock, and output pins as OUTPUT
  pinMode(dataPinD1, OUTPUT);
  pinMode(dataPinD2, OUTPUT);
  pinMode(dataPinD3, OUTPUT);
  pinMode(dataPinD4, OUTPUT);
  pinMode(clockPin1, OUTPUT);
  pinMode(clockPin2, OUTPUT);
  pinMode(setPin, OUTPUT);
  pinMode(resetPin, OUTPUT);
  pinMode(qOutputPinQ1, INPUT);  // Q1 is an output from the flip-flop
  pinMode(qOutputPinQ2, INPUT);  // Q2 is an output from the flip-flop
  pinMode(qOutputPinQ3, INPUT); 
  pinMode(qOutputPinQ4, INPUT);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  // Initialize Serial communication for debugging
  Serial.begin(9600);
}

void inp_7447(int D1,int D2, int D3,int D4){

  digitalWrite(setPin, HIGH);
  digitalWrite(resetPin, HIGH);
  
  digitalWrite(dataPinD1, D1);
  digitalWrite(dataPinD2, D2);  // Set D2 to LOW for the first clock pulse
  digitalWrite(dataPinD3, D3); 
  digitalWrite(dataPinD4, D4);  // Set D4 to LOW for the first clock pulse

  // Provide a clock pulse (transition from LOW to HIGH)
  digitalWrite(clockPin1, LOW);
  delay(10);
  digitalWrite(clockPin1, HIGH);

  // Provide a clock pulse (transition from LOW to HIGH)
  digitalWrite(clockPin2, LOW);
  delay(10);
  digitalWrite(clockPin2, HIGH);

  // Read the values from the flip-flop outputs
  int q1Value = digitalRead(qOutputPinQ1);
  int q2Value = digitalRead(qOutputPinQ2);
  int q3Value = digitalRead(qOutputPinQ3);
  int q4Value = digitalRead(qOutputPinQ4);

  digitalWrite(A0, q1Value);
  digitalWrite(A1, q2Value);
  digitalWrite(A2, q3Value);
  digitalWrite(A3, q4Value);

}

void loop() {
  for (int i = 0; i < 10; ++i) {
    // Set data inputs
    
    // Set the binary v                                                                  alue on D1, D2, D3, D4
    D1 = i % 2;
    D2 = (i / 2) % 2;
    D3 = (i / 4) % 2;
    D4 = (i / 8) % 2;
    inp_7447(D1,D2,D3,D4);
    delay(1000);  // Display each digit for 1 second
  }
    
}
