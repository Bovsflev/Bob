//Flemming G. Herner
//Herner Design

/* Dette er et program til automatisering af terrarie.
   P = Pumpe.
   BU = Blæser ud.
   BI = Blæser ind.
   DHT = Sensor
*/

#include <DHT.h> //Bibliotek - Sensor
#include <LiquidCrystal.h> //Bibliotek - Skærm
#define DHTPIN A0 //Sensor plasering
#define DHTTYPE DHT11 //Sensor type
const int P = 6; //P plasering
const int BU = 7; //BU plasering
const int BI = 8; //BI plasering
DHT dht(DHTPIN, DHTTYPE); //Defination
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Plasering

void setup() {
  lcd.begin(40, 2); //Tænder skærm
  pinMode(P, OUTPUT); //Defination af type (OUTPUT/INPUT)
  pinMode(BU, OUTPUT); //Defination af type (OUTPUT/INPUT)
  pinMode(BI, OUTPUT); //Defination af type (OUTPUT/INPUT)
  digitalWrite(BI, 0); //Slukker relæ
  digitalWrite(P, 0); //Slukker relæ
  digitalWrite(BU, 0); //Slukker relæ
  lcd.setCursor(0, 0); //Sætter kurser plasering
  lcd.print("HERNER"); //Skriver på LCD
  lcd.setCursor(10, 1);//Sætter kurser plasering
  lcd.print("DESIGN"); //Skriver på LCD
  delay(5000); //Pause
  lcd.clear(); //Fjerner tekst fra LCD
  lcd.setCursor(0, 0); //Sætter kurser plasering
  lcd.print("Det her er Bob."); //Skriver på LCD
  lcd.setCursor(0, 1); //Sætter kurser plasering
  lcd.print("Han er en gekko."); //Skriver på LCD
  delay(5000); //Pause
  lcd.clear(); //Fjerner tekst fra LCD
  lcd.print("Tjekker klimaet."); //Skriver på LCD
  dht.begin(); //Tænder sensor
  delay(2500); //Pause
}

void loop() {

  int humF = dht.readHumidity(); //Fortæller hvor i programmet den skal læse fugtighed fra sensor
  int tempF = dht.readTemperature(); //Fortæller hvor i programmet den skal læse temperatur fra sensor
  delay(5); //Pause
  for (int i = 0; i < 61; i++) {
    for (int i = 0; i < 61; i++) {
      lcd.setCursor(0, 0); //Sætter kurser plasering
      lcd.print("Temperatur: "); //Skriver på LCD
      lcd.print(tempF); //Skriver temperatur værdi
      lcd.print((char)223); //Skriver på LCD
      lcd.print("C "); //Skriver på LCD
      lcd.setCursor(0, 1); //Sætter kurser plasering
      lcd.print("Fugtighed: "); //Skriver på LCD
      lcd.print(humF); //Skriver fugtigheds værdig
      lcd.print("%"); //Skriver på LCD
      delay(1000); //Pause

    }
  }
  lcd.clear(); //Fjerner tekst fra LCD

  if (humF > 70) { //Hvis fugtigheden er over 70 skal den gøre følgende
    lcd.setCursor(0, 0); //Sætter kurser plasering
    lcd.print("Her er for"); //Skriver på LCD
    lcd.setCursor(0, 1); //Sætter kurser plasering
    lcd.print("fugtigt."); //Skriver på LCD
    delay(5000); //Pause
    lcd.clear(); //Fjerner tekst fra LCD
    lcd.print("Lufter."); //Skriver på LCD
    digitalWrite(BI, 1); //Tænder BI
    delay(5000); //Pause
    digitalWrite(BI, 0); //Slukker BI
    delay(5); //Pause
    lcd.clear(); //Fjerner tekst fra LCD
  } else if (humF < 59) {
    lcd.setCursor(0, 0); //Sætter kurser plasering
    lcd.print("Her er ikke"); //Skriver på LCD
    lcd.setCursor (0, 1); //Sætter kurser plasering
    lcd.print("fugtigt nok."); //Skriver på LCD
    delay(5000); //Pause
    lcd.clear(); //Fjerner tekst fra LCD
    lcd.print("Vander."); //Skriver på LCD
    digitalWrite(BU, 1); //Tænder BU
    delay(5000); //Pause
    digitalWrite(BU, 0); //Slukker BU
    delay(5); //Pause
    digitalWrite(P, 1); //Tænder P
    delay(10000); //Pause
    digitalWrite(P, 0); //Slukker P
    delay(5); //Pause
    lcd.clear(); //Fjerner tekst fra LCD
  }
}
