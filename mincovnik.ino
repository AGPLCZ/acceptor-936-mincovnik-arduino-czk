const int pinMince = 2; // Pin, na kterém detekujeme signál z mincovníku
const int cena = 75; // Cena v centech/korunách, která musí být dosažena
volatile long pocetPreruseni = 0; // Počet přerušení, která byla vyvolána (kolikrát byla vhazována mince)
unsigned long zustatek = 0; // Aktuální zůstatek
unsigned long posledniCasPreruseni = 0; // Čas posledního přerušení

void setup() {
  Serial.begin(9600); // Inicializace sériové komunikace s rychlostí 9600 baudů
  attachInterrupt(digitalPinToInterrupt(pinMince), preruseniMince, RISING); // Nastavení přerušení na pinu mince
}

void loop() {
  // Kontrola, zda uplynul dostatečný čas od posledního přerušení a zda bylo vyvoláno nějaké přerušení
  if (millis() - posledniCasPreruseni > 1 && pocetPreruseni > 0) {
    zustatek += pocetPreruseni; // Přičtení počtu přerušení k zůstatku
    if (zustatek >= cena) { // Kontrola, zda je zůstatek větší nebo roven ceně
      Serial.println("balanceReached"); // Vypsání zprávy, že zůstatek dosáhl ceny
      zustatek = 0; // Resetování zůstatku po dosažení ceny
    }
    Serial.println("Zustatek: " + String(zustatek) + " Kc"); // Vypsání aktuálního zůstatku
    pocetPreruseni = 0; // Resetování počtu přerušení
  }
}

void preruseniMince() {
  pocetPreruseni++; // Inkrementace počtu přerušení (přičtení mince)
  posledniCasPreruseni = millis(); // Aktualizace času posledního přerušení
}
