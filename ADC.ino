void sensor()
{
  int  lampu1 = analogRead(A0);
  if (lampu1 > 800)
  {
    p0 = 1;
  }
  else
  {
    p0 = 0;
  }

  int  lampu2 = analogRead(A1);
  if (lampu2 > 800)
  {
    p1 = 1;
  }
  else
  {
    p1 = 0;
  }

  int  lampu3 = analogRead(A2);
  if (lampu3 > 800)
  {
    p2 = 1;
  }
  else
  {
    p2 = 0;
  }


  int  lampu4 = analogRead(A3);
  if (lampu4 > 800)
  {
    p3 = 1;
  }
  else
  {
    p3 = 0;
  }


  int  lampu5 = analogRead(A4);
  if (lampu5 > 800)
  {
    p4 = 1;
  }
  else
  {
    p4 = 0;
  }



  int  lampu6 = analogRead(A5);
  if (lampu6 > 800)
  {
    p5 = 1;
  }
  else
  {
    p5 = 0;
  }


  int  lampu7 = analogRead(A6);
  if (lampu7 > 800)
  {
    p6 = 1;
  }
  else
  {
    p6 = 0;
  }


  int  lampu8 = analogRead(A7);
  if (lampu8 > 800)
  {
    p7 = 1;
  }
  else
  {
    p7 = 0;
  }
}

void biner()
{
  sensor();
  octasensor = (p7 * 128) + (p6 * 64) + (p5 * 32) + (p4 * 16) + (p3 * 8) + (p2 * 4) + (p1 * 2) + (p0 * 1);

}

void adc()
{
  while (1)
  {
    sensor();
    lcd.setCursor(0, 0);
    lcd.print("     ");
//    Serial.print("     ");

    lcd.setCursor(12, 0);
    lcd.print("    ");
//    Serial.print("    ");

    lcd.setCursor(0, 1);
    lcd.print("    ");
//    Serial.print("    ");

    lcd.setCursor(5, 1);
    lcd.print("      ");
//    Serial.print("      ");

    lcd.setCursor(12, 1);
    lcd.print("    ");
//    Serial.print("    ");

    lcd.setCursor(4, 1 );
    lcd.print(p7);
//    Serial.print(p7);

    lcd.setCursor(5, 0 );
    lcd.print(p6);
//    Serial.print(p6);

    lcd.setCursor(6, 0 );
    lcd.print(p5);
//    Serial.print(p5);

    lcd.setCursor(7, 0 );
    lcd.print(p4);
//    Serial.print(p4);

    lcd.setCursor(8, 0);
    lcd.print(p3);
//    Serial.print(p3);

    lcd.setCursor(9, 0 );
    lcd.print(p2);
//    Serial.print(p2);

    lcd.setCursor(10, 0 );
    lcd.print(p1);
//    Serial.print(p1);

    lcd.setCursor(11, 1 );
    lcd.print(p0);
//    Serial.print(p0);

    lcd.setCursor(11, 0);
    lcd.print("     ");
//    Serial.println("     ");

    if (!kembali)
    { while (1)
      {
        delay(200);
        menu();
      }
    }
  }
}

void adcnowhile()
{
  sensor();
  lcd.setCursor(0, 0);
  lcd.print("     ");

  lcd.setCursor(12, 0);
  lcd.print("    ");

  lcd.setCursor(0, 1);
  lcd.print("    ");

  lcd.setCursor(5, 1);
  lcd.print("      ");

  lcd.setCursor(12, 1);
  lcd.print("    ");

  lcd.setCursor(4, 1 );
  lcd.print(p0);

  lcd.setCursor(5, 0 );
  lcd.print(p1);

  lcd.setCursor(6, 0 );
  lcd.print(p2);

  lcd.setCursor(7, 0 );
  lcd.print(p3);

  lcd.setCursor(8, 0);
  lcd.print(p4);

  lcd.setCursor(9, 0 );
  lcd.print(p5);

  lcd.setCursor(10, 0 );
  lcd.print(p6);

  lcd.setCursor(11, 1 );
  lcd.print(p7);

  lcd.setCursor(11, 0);
  lcd.print("     ");
}
