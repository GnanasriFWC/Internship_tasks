const int bcdPins[] = {2, 3, 4, 5};  // BCD input pins (A, B, C, D)

void setup() {
  // Set BCD pins as outputs
  for (int i = 0; i < 4; i++) {
    pinMode(bcdPins[i], OUTPUT);
  }

}

void loop() {
  for (int num = 0; num < 10; num++) {
    // Convert decimal number to BCD
    int bcd = num % 10;

    // Set BCD input pins
    for (int i = 0; i < 4; i++) {
      digitalWrite(bcdPins[i], bitRead(bcd, i));
    }

    // Display the number
    delay(1000); // Display for 1 second
  }
}
