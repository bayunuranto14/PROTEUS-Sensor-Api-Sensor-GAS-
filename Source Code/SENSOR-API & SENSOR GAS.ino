#include <LiquidCrystal.h>
const int rs = 12, e = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

//Deklarasi MQPin Gas Sensor
#define MQPin A0

#define buzzer 1

const int sensorPin = 2;
  const int outputPin = 13;

//sensor api
  int bacasensor = 0;
  
void setup() {
  pinMode(outputPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);

  lcd.setCursor(0,0);
  lcd.print("Bayu Afif Nuranto");
  lcd.setCursor(0,1);
  lcd.print("NIM : 2020230903");
  delay (500);

  lcd.setCursor(0,0);
  lcd.print("   SELAMAT DATANG   ");
  lcd.setCursor(0,1);
  lcd.print("  SENSOR MENDETEKSI ADANYA  ");
  lcd.print(""); 
  lcd.print("KEBAKARAN");
  delay(500);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("MELIPUTI :");
  lcd.print("\n");
  lcd.setCursor(0,1);
  lcd.print("SENSOR API, GAS, DAN SUHU"); 
  delay(500);
  lcd.clear();

  lcd.begin(16,2);
  pinMode(MQPin, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
    lcd.setCursor(5, 0);
    lcd.print("GAS");
    lcd.setCursor(3,1);
    lcd.print("TERDETEKSI");
    delay(500);
    lcd.clear();
  
}

void loop() {


  
  bacasensor = digitalRead(sensorPin);
 
  if (bacasensor == HIGH) {
    //LED ON
    digitalWrite(outputPin, HIGH);
    Serial.println("Sensor API : TERDETEKSI ");
    Serial.println("=========================================");
    Serial.println("\n");
    delay(100);
  }else {
    //LED OFF
    digitalWrite(outputPin ,LOW);
    Serial.println("Sensor API : TIDAK TERDETEKSI");
    Serial.println("=========================================");
    Serial.println("\n");
    delay(100);
  }
  
 

int gas_value = digitalRead(MQPin);

if(gas_value==HIGH)
{
  digitalWrite(buzzer, HIGH);
  lcd.setCursor(6, 0);
  lcd.print("GAS");
   lcd.setCursor(3, 1);
  lcd.print("TERDETEKSI");
  delay(100);
  lcd.clear();
  delay(100);
  
}
else
{
 lcd.clear();
 digitalWrite(buzzer, LOW); 
}


    
}
