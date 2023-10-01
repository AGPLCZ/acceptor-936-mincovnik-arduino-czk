#include <WiFiNINA.h>

const int coin = 2;
volatile long totalInterrupts = 0;
unsigned long balance = 0;
unsigned long lastInterruptTime = 0;

char ssid[] = "your_network_name"; // your network SSID (name)
char pass[] = "your_network_password"; // your network password

int status = WL_IDLE_STATUS; // the WiFi radio's status

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(coin), coinInterrupt, RISING);
  
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(10000);
  }
  
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void loop() {
  if (millis() - lastInterruptTime > 1 && totalInterrupts > 0) {
    balance += totalInterrupts;
    if (balance >= 75) {
      sendGetRequest();
      balance = 0; // Reset balance after reaching the target
    }
    Serial.println("Zustatek: " + String(balance) + " Kc");
    totalInterrupts = 0;
  }
}

void sendGetRequest() {
  WiFiClient client;
  
  if (client.connect("your_server_ip_or_domain", 80)) {
    client.println("GET /your_script.php?balanceReached=true HTTP/1.1");
    client.println("Host: your_server_ip_or_domain");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("Connection to server failed");
  }
  
  delay(5000);
}

void coinInterrupt() {
  totalInterrupts++;
  lastInterruptTime = millis();
}
