
void startPID()
{
  adcnowhile();
  int erroradc;
  biner();
  switch (octasensor)
  {
    case 0B00000001: erroradc = 13; break;
    case 0B00000011: erroradc = 11 ; break;
    case 0B00000010: erroradc = 9 ; break;
    case 0B00000110: erroradc = 7 ; break;
    case 0B00000100: erroradc = 5 ; break;
    case 0B00001100: erroradc = 2 ; break;
    case 0B00001000: erroradc = 1 ; break;
    case 0B00011000: erroradc = 0; break;
    case 0B00010000: erroradc = -1; break;
    case 0B00110000: erroradc = -2; break;
    case 0B00100000: erroradc = -5; break;
    case 0B01100000: erroradc = -7; break;
    case 0B01000000: erroradc = -9; break;
    case 0B11000000: erroradc = -11; break;
    case 0B10000000: erroradc = -13; break;
  }

  //double error = erroradc;
  unsigned long sekarang = millis();
  double TimeSampling = (double)(sekarang - waktu_last);
  double error = 0-erroradc;
  double errorjumlah = errorjumlah + (error * TimeSampling);
  double errorD = (error - errorterakhir) / TimeSampling;
  double outpid = 5 * error + 0 * errorjumlah +   11* errorD;


  double kananPID = 130 + outpid;
  double kiriPID = 130 - outpid;

 abs(kananPID);
  abs(kiriPID);
//  if(kananPID<0){
//  kananPID=0;
//}
//
//if(kiriPID<0){
//  kiriPID=0;
//}

  kananMA(kananPID);
  kiriMA(kiriPID);

  errorterakhir=error;
  waktu_last=sekarang;
//  waktu_last. = sekarang;

//if(kananPID<0){
//  kananPID=0;
//}
//
//if(kiriPID<0){
//  kiriPID=0;
//}

//if(kananPID>255){
//  kananPID=255;
//}
//
//if(kiriPID>255){
//  kiriPID=255;
//}

if (!kembali)
    { while (1)
      {
        delay(200);
        menu();
      }
    }

    if (digitalRead(44) == 0)
    {
      while (1)
      {
        delay(200);
        menu();
      }
    }

    if (digitalRead(46) == 0)
    {
      while (1)
      {
        delay(200);
        menu();
      }
    }
}

void start()
{
  while (1)
  {
    adcnowhile();
    int erroradc;
    biner();
    switch (octasensor)
    {
      case 0B00000001: erroradc = 15; break;
      case 0B00000011: erroradc = 13 ; break;
      case 0B00000010: erroradc = 9 ; break;
      case 0B00000110: erroradc = 7 ; break;
      case 0B00000100: erroradc = 5 ; break;
      case 0B00001100: erroradc = 3 ; break;
      case 0B00001000: erroradc = 1 ; break;
      case 0B00111100: erroradc = 0; break;
      case 0B00010000: erroradc = -1; break;
      case 0B00110000: erroradc = -3; break;
      case 0B00100000: erroradc = -5; break;
      case 0B01100000: erroradc = -7; break;
      case 0B01000000: erroradc = -9; break;
      case 0B11000000: erroradc = -13; break;
      case 0B10000000: erroradc = -15; break;
    }

    if (erroradc < 8 && erroradc > 0)
    {
      //sensor kiri 00000001
      kananMA(135);
      kiriMA(100);
    }

    else if (erroradc < 0 && erroradc > -8)
    {
      // sensor kanan 10000000
      kananMA(110);
      kiriMA(120);
    }
    else
    {
      kananMA(135);
      kiriMA(120);
    }

    if (!kembali)
    { while (1)
      {
        delay(200);
        menu();
      }
    }

    if (digitalRead(44) == 0)
    {
      while (1)
      {
        delay(200);
        menu();
      }
    }

    if (digitalRead(46) == 0)
    {
      while (1)
      {
        delay(200);
        menu();
      }
    }
  }
}
