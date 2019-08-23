

#include <EEPROM.h>
struct eepromPID1
{
  byte Kp;
}
;
eepromPID1 eep1;

struct eepromPID2
{
  byte Kd;
}
;
eepromPID2 eep2;

struct eepromPID3
{
  byte Ki;
}
;
eepromPID3 eep3;

int errorterakhir=0, waktu_last=0;
int kondisi;

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
//--LCD--//

#define but1 30
#define Plus digitalRead(30)

#define but2 32
#define Minus digitalRead(32)

#define ok 34
#define woke digitalRead(34)

#define back 36
#define kembali digitalRead(36)

int octasensor;
int p0, p1, p2, p3, p4, p5, p6, p7;

#define RPWM 2
#define LPWM 3

#define RPWM1 4
#define LPWM1 5

void setup()
{

  Serial.begin(9600);
  EEPROM.get (0, eep1);
  EEPROM.get (1, eep2);
  EEPROM.get (2, eep3);

  lcd.begin(16, 2);
  lcd.backlight();

  pinMode(LPWM, OUTPUT);
  pinMode(LPWM1, OUTPUT);
  pinMode(RPWM, OUTPUT);
  pinMode(RPWM1, OUTPUT);

  pinMode(but1, INPUT_PULLUP);
  pinMode(but2, INPUT_PULLUP);
  pinMode(ok, INPUT_PULLUP);
  pinMode(back, INPUT_PULLUP);

  pinMode(42, INPUT_PULLUP);
  pinMode(44, INPUT_PULLUP);
  pinMode(46, INPUT_PULLUP);
  pinMode(48, INPUT_PULLUP);
}

void loop()
{

  //  kananMA(255);
  //  kiriMA(255);
  //  int a = digitalRead(42);
  //  int b = digitalRead(44);
  //  int c = digitalRead(46);
  //  int d = digitalRead(48);
  // int a=analogRead(A5);
 menu();
  //  Serial.print(a);
  //  Serial.print(" ");
  //  Serial.print(b);
  //  Serial.print(" ");
  //  Serial.print(c);
  //  Serial.print(" ");
  //  Serial.print(d);
  //  Serial.print(" ");
  //kananMA(0);
 //kiriMA(0);
//  delay(5000);
//  kananMA(200);
//  kiriMA(200);
//  delay(5000);
}

