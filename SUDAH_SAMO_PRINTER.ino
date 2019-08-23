#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal_I2C_ByVac.h>
#include <LiquidCrystal_SI2C.h>
#include <LiquidCrystal_SR.h>
#include <LiquidCrystal_SR1W.h>
#include <LiquidCrystal_SR2W.h>
#include <LiquidCrystal_SR3W.h>

#include <Adafruit_Thermal.h>
#include "SoftwareSerial.h"
#include <Key.h>
#include <Keypad.h> 
/*
 * Arduino Keypad calculator Program
 */
//Header file for LCD from https://www.arduino.cc/en/Reference/LiquidCrystal
//Header file for Keypad from https://github.com/Chris--A/Keypad

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Three columns

// Define the Keymap
char keys[ROWS][COLS] = {

  {'1','2','3','A'},

  {'4','5','6','B'},

  {'7','8','9','C'},

  {'*','0','#','D'},

};

byte rowPins[ROWS] = { 0, 30, 2, 3 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 4, 5, 6, 7 }; // Connect keypad COL0, COL1 and COL2 to these Arduino pins.

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //  Create the Keypad

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8; //Pins to which LCD is connected
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

 String Num1,Num2,Number;
 char key,action;
 boolean result,sudahpilih = false;

SoftwareSerial mySerial(18, 19); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial); 
 
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  printer.begin();
  printer.println(F("HALO!!!"));
  
  lcd.begin(16, 2); //We are using a 16*2 LCD display
  lcd.print("Menu Selector"); //Display a intro message
  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
  lcd.print("hehe pkm"); //Display a intro message 

   delay(500); //Wait for display to show info
    lcd.clear(); //Then clean it
  pinMode(24, INPUT_PULLUP);
  pinMode(46, OUTPUT); //LED yang di bread board
  pinMode(47, OUTPUT); //LED yang di kotak makan
}

void loop() {

key = kpd.getKey(); //storing pressed key value in a char

if (key!=NO_KEY)
DetectButtons();

if (sudahpilih==false)  
  {
  lcd.setCursor(0,0);
  lcd.print("INPUT MENU:");
  }

CalculateResult();

if (sudahpilih==true)
  Bayar();
}

void DetectButtons()
{ 
        sudahpilih=false;
     lcd.setCursor(0,1);
    if (key=='*') //If cancel Button is pressed
    {Serial.println ("Button Cancel"); result=false;}
    
     if (key == '1') //If Button 1 is pressed
    {Serial.println ("Button 1"); 
    if (Number.length()==0)
    Number="1";
    else
    Number = Number + "1"; //Pressed twice
       lcd.print(Number);
    }
    
     if (key == '4') //If Button 4 is pressed
    {Serial.println ("Button 4"); 
    if (Number.length()==0)
    Number="4";
    else
    Number = Number + "4"; //Pressed twice
       lcd.print(Number);
    }
    
     if (key == '7') //If Button 7 is pressed
    {Serial.println ("Button 7");
    if (Number.length()==0)
    Number="7";
    else
    Number = Number + "7"; //Pressed twice
       lcd.print(Number);
    } 
  

    if (key == '0')
    {Serial.println ("Button 0"); //Button 0 is Pressed
    if (Number.length()==0)
    Number="0";
    else
    Number = Number + "0" ; //Pressed twice
       lcd.print(Number);
    }
    
     if (key == '2') //Button 2 is Pressed
    {Serial.println ("Button 2"); 
     if (Number.length()==0)
    Number="2";
    else
    Number = Number + "2"; //Pressed twice
       lcd.print(Number);
    }
    
     if (key == '5')
    {Serial.println ("Button 5"); 
     if (Number.length()==0)
    Number="5";
    else
    Number = Number + "5"; //Pressed twice
       lcd.print(Number);
    }
    
     if (key == '8')
    {Serial.println ("Button 8"); 
     if (Number.length()==0)
    Number="8";
    else
    Number = Number + "8"; //Pressed twice
       lcd.print(Number);
    }   
  

    if (key == '#')
    {Serial.println ("Button Equal"); 
    Num2=Number;
    result=false;


    }
    
     if (key == '3')
    {Serial.println ("Button 3"); 
     if (Number.length()==0)
    Number="3";
    else
    Number = Number + "3"; //Pressed twice
       lcd.print(Number);
    }
    
     if (key == '6')
    {Serial.println ("Button 6"); 
    if (Number.length()==0)
    Number="6";
    else
    Number =  Number + "6"; //Pressed twice
       lcd.print(Number);
    }
    
     if (key == '9')
    {Serial.println ("Button 9");
    if (Number.length()==0)
    Number="9";
    else
    Number = Number + "9"; //Pressed twice
       lcd.print(Number);
    }  

      if (key == 'A') //Detecting Buttons on Column 4
  {
    Num1 = Number;
    Number = "";   
    Serial.println ("Addition"); action = '+';

  }
  
}

void CalculateResult()
{
  if (action=='+')
    {   if(Num1=="02") {Num1 = "999MdlIkn 10 BYR"; Serial.println("ModelIkan 10000");   printer.println(F("ModelIkan 10000"));}
    else if(Num1=="03") {Num1 = "999MdlGdm 7 BYR"; Serial.println("ModelGndm 7000"); printer.println(F("ModelGndm 7000"));}
    else if(Num1=="01") {Num1 = "999Tekwan 10 BYR"; Serial.println("Tekwan 10000"); printer.println(F("Tekwan 10000"));}
    else if(Num1=="04") {Num1 = "888MiAyam 14 BYR"; Serial.println("Mie Ayam 14000"); printer.println(F("Mie Ayam 14000"));}
    else if(Num1=="05") {Num1 = "888Siomay 10 BYR"; Serial.println("Siomay 10000"); printer.println(F("Siomay 10000"));}
    else if(Num1=="06") {Num1 = "888Batgor 10 BYR"; Serial.println("Batagor 10000"); printer.println(F("Batagor 10000"));}
    else if(Num1=="07") {Num1 = "888Mrtbak 10 BYR"; Serial.println("Martabak 10000"); printer.println(F("Martabak 10000"));}
    else if(Num1=="08") {Num1 = "BSONsSoto 10 BYR"; Serial.println("Nasi Soto 10000"); printer.println(F("Nasi Soto 10000"));}
    else if(Num1=="09") {Num1 = "BAKSOBiasa11 BYR"; Serial.println("Bakso biasa 11000"); printer.println(F("Bakso biasa 11000"));}
    else if(Num1=="10") {Num1 = "BAKSOBesar15 BYR"; Serial.println("Bakso besar 15000"); printer.println(F("Bakso besar 15000"));}
    else if(Num1=="11") {Num1 = "BAKSOTelor15 BYR"; Serial.println("Bakso telor 15000"); printer.println(F("Bakso telor 15000"));}
    else if(Num1=="12") {Num1 = "LemonTMera 7 BYR"; Serial.println("LemonTMerah 7000"); printer.println(F("LemonTMerah 7000"));}
    else if(Num1=="13") {Num1 = "LemonTHijo 7 BYR"; Serial.println("LemonTHijau 7000"); printer.println(F("LemonTHijau 7000"));}
    else if(Num1=="14") {Num1 = "Lemonade 7 BYR"; Serial.println("Lemonade 7000"); printer.println(F("Lemonade 7000"));}
    else if(Num1=="15") {Num1 = "LemonCapuc 7 BYR"; Serial.println("Capuccino 7000"); printer.println(F("Capuccino 7000"));}
    else if(Num1=="16") {Num1 = "TMeraManis 6 BYR"; Serial.println("TMerahManis 6000"); printer.println(F("TMerahManis 6000"));}
    else if(Num1=="17") {Num1 = "GrenTManis 6 BYR"; Serial.println("GreenTManis 6000"); printer.println(F("GreenTManis 6000"));}
    else if(Num1=="18") {Num1 = "TtarikSusu 8 BYR"; Serial.println("TtarikSusu 8000"); printer.println(F("TtarikSusu 8000"));}
    else if(Num1=="19") {Num1 = "LemonSusu 8 BYR"; Serial.println("LemonSusu 8000"); printer.println(F("LemonSusu 8000"));}
    else if(Num1=="20") {Num1 = "LemonSucok 8 BYR"; Serial.println("LemonSucok 8000"); printer.println(F("LemonSucok 8000"));}
    else if(Num1=="21") {Num1 = "LmnFntSqsh 8 BYR"; Serial.println("LmFantaSquash 8000"); printer.println(F("LmFantaSquash 8000"));}
    else if(Num1=="22") {Num1 = "LmnSquash 8 BYR"; Serial.println("LemonSquash 8000"); printer.println(F("LemonSquash 8000"));}
    else if(Num1=="23") {Num1 = "LmSusuSqsh 9 BYR"; Serial.println("LemonSusuSqsh 9000"); printer.println(F("LemonSusuSqsh 9000"));}
    else if(Num1=="24") {Num1 = "LmSucokSqsh9 BYR"; Serial.println("LemonSuCokSqsh 9000"); printer.println(F("LemonSuCokSqsh 9000"));}
    else if(Num1=="25") {Num1 = "SusuPutih 7 BYR"; Serial.println("SusuPutih 7000"); printer.println(F("Susu Putih 9000"));}
    else if(Num1=="26") {Num1 = "SusuCoklat 7 BYR"; Serial.println("Susu Coklat 7000"); printer.println(F("Susu Coklat 7000"));}
    else if(Num1=="27") {Num1 = "TopingJely 1 BYR"; Serial.println("TopingJely 1000"); printer.println(F("Topping Jelly 1000"));}
    else if(Num1=="28") {Num1 = "WallPopulai5 BYR"; Serial.println("Walls Populaire 5000"); printer.println(F("Walls Populaire 5000"));}
    else if(Num1=="29") {Num1 = "WallHapyFru2 BYR"; Serial.println("Walls HappyFru 2000"); printer.println(F("Walls HappyFru 2000"));}
    else if(Num1=="30") {Num1 = "WallPaddle 3 BYR"; Serial.println("Walls Paddlepop 3000"); printer.println(F("Walls Paddlepop 3000"));}
    else if(Num1=="31") {Num1 = "WallSolero 5 BYR"; Serial.println("Walls Solero 5000"); printer.println(F("Walls Solero 5000"));}
    else if(Num1=="32") {Num1 = "WallCorneto5 BYR"; Serial.println("Walls Cornetto 5000"); printer.println(F("Walls Cornetto 5000"));}
    else if(Num1=="33") {Num1 = "WallFeast 5 BYR"; Serial.println("Walls Feast 5000"); printer.println(F("Walls Feast 5000"));}
    else if(Num1=="34") {Num1 = "WallMagnum14 BYR"; Serial.println("Walls Magnum 14000"); printer.println(F("Walls Magnum 14000"));}
    result = true;
    sudahpilih=true;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SILAHKAN BAYAR:"); 
    lcd.setCursor(0,1);
    lcd.print(Num1);
   result=false;

   action='x';
  

    }

}

void Bayar()
{
  int sensorValue = digitalRead(24);
  if(sensorValue == LOW){
    digitalWrite(46, HIGH); //turn on LED di bread board
    digitalWrite(47, HIGH); //turn on LED di kotak makan
    Serial.println("SUCCESS");
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("BERHASIL BAYAR");
    printer.println(F("BERHASIL BAYAR"));
    printer.println(F(".")); //spacer
    printer.println(F(".")); //spacer

    lcd.setCursor(6,1);
    lcd.print("3");
    delay(1000);
    digitalWrite(46, LOW); //turn off LED di bread board
    digitalWrite(47, LOW); //turn off LED di kotak makan
    lcd.print("2");
 
    delay(1000);
    lcd.print("1");
    delay(1000);
    lcd.clear();
    sudahpilih=false;
  }
}


