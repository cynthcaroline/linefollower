void kiriMU (byte kirimundur)
{
  analogWrite(LPWM, kirimundur);
  analogWrite(RPWM, 0);
}

void kiriMA (byte kirimaju)
{
  analogWrite(LPWM, 0);
  analogWrite(RPWM, kirimaju);
}

void kananMA (byte  kananmaju)
{
  analogWrite(LPWM1, 0);
  analogWrite(RPWM1, kananmaju);
}

void kananMU (byte  kananmundur)
{
  analogWrite(LPWM1, kananmundur);
  analogWrite(RPWM1, 0);
}
