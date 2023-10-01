const int pinDig = 2;
const int price = 75;
volatile long totalInterrupts = 0;
unsigned long balance = 0;
unsigned long lastInterruptTime = 0;

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(pinDig), coinInterrupt, RISING);
}

void loop() {
  if (millis() - lastInterruptTime > 1 && totalInterrupts > 0) {
    balance += totalInterrupts;
    if (balance >= price) {
    Serial.println("balanceReached"); 
      balance = 0;
    }
    Serial.println("Zustatek: " + String(balance) + " Kc");
    totalInterrupts = 0;
  }
}

void coinInterrupt() {
  totalInterrupts++;
  lastInterruptTime = millis();
}
