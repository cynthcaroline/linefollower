void menu()
{
  kananMA(0);
  kiriMA(0);

  while (1)
  {
    if (digitalRead(42) == 0)
    {
      while (1)
      {
        delay(200);
        //start();
      startPID();
      }
    }

    if (digitalRead(48) == 0)
    {
      while (1)
      {
        delay(200);
        //start();
      startPID();        
      }
    }

    if (!Plus)
    {
      delay(200);
      kondisi++;
      if (kondisi > 4)
      {
        kondisi = 0;
      }
    }

    if (!Minus)
    {
      delay(200);
      kondisi--;
      if (kondisi < 0)
      {
        kondisi = 4;
      }
    }

    switch (kondisi)
    {
      case 0:
        lcd.setCursor(0, 0);
        lcd.print(">1.Cek ADC          ");

        lcd.setCursor(0, 1);
        lcd.print(" 2.Kp           ");
        if (!woke)
        {
          delay(200);
          adc();
        }
        break;

      case 1:
        lcd.setCursor(0, 0);
        lcd.print(" 1.Cek ADC          ");

        lcd.setCursor(0, 1);
        lcd.print(">2.Kp               ");

        if (!woke)
        {
          delay(200);
          setkp();
        }
        break;

      case 2:
        lcd.setCursor(0, 0);
        lcd.print(">3.Kd               ");

        lcd.setCursor(0, 1);
        lcd.print(" 4.Ki               ");

        if (!woke)
        {
          delay(200);
          setkd();
        }
        break;

      case 3:
        lcd.setCursor(0, 0);
        lcd.print(" 3.Kd               ");

        lcd.setCursor(0, 1);
        lcd.print(">4.Ki               ");

        if (!woke)
        {
          delay(200);
          setki();
        }
        break;

      case 4:
        lcd.setCursor(0, 0);
        lcd.print(">5.Start               ");

        lcd.setCursor(0, 1);
        lcd.print("                       ");

        if (!woke)
        {
          delay(200);
          start();
        }
        break;
    }
  }
}

void setki()
{
  while (1)
  {
    lcd.setCursor(0, 0);
    lcd.print("                ");

    lcd.setCursor(6, 1);
    lcd.print("Ki:");

    lcd.setCursor(9, 1);
    lcd.print(eep3.Ki);

    lcd.setCursor(0, 1);
    lcd.print("      ");

    lcd.setCursor(11, 1);
    lcd.print("     ");

    if (digitalRead(30) == 0)
    {
      delay(200);
      eep3.Ki += 0.5;
      EEPROM.put(0, eep3.Ki);
    }

    if (digitalRead(32) == 0)
    {
      delay(200);
      eep3.Ki -= 0.5;
      EEPROM.put(0, eep3.Ki);
    }

    if (!kembali)
    { while (1)
      {
        delay(200);
        menu();
      }
    }
  }
}

void setkp()
{
  while (1)
  {
    lcd.setCursor(0, 0);
    lcd.print("Kp:");

    lcd.setCursor(3, 0);
    lcd.print(eep1.Kp);

    lcd.setCursor(5, 0);
    lcd.print("           ");

    lcd.setCursor(0, 1);
    lcd.print("               ");

    if (digitalRead(30) == 0)
    {
      delay(200);
      eep1.Kp++;
      EEPROM.put(0, eep1.Kp);
    }

    if (digitalRead(32) == 0)
    {
      delay(200);
      eep1.Kp--;
      EEPROM.put(0, eep1.Kp);
    }

    if (!kembali)
    { while (1)
      {
        delay(200);
        menu();
      }
    }
  }
}

void setkd()
{
  while (1)
  {
    lcd.setCursor(11, 0);
    lcd.print("Kd:");

    lcd.setCursor(14, 0);
    lcd.print(eep2.Kd);

    lcd.setCursor(0, 0);
    lcd.print("           ");

    lcd.setCursor(0, 1);
    lcd.print("               ");

    if (digitalRead(30) == 0)
    {
      delay(200);
      eep2.Kd++;
      EEPROM.put(0, eep2.Kd);
      lcd.setCursor(14, 0);
      lcd.print(eep2.Kd);
    }

    if (digitalRead(32) == 0)
    {
      delay(200);
      eep2.Kd--;
      EEPROM.put(0, eep2.Kd);
      lcd.setCursor(14, 0);
      lcd.print(eep2.Kd);

    }

    if (!kembali)
    { while (1)
      {
        delay(200);
        menu();
      }
    }
  }
}
