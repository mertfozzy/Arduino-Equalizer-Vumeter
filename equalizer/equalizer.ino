const byte toplamLedSayisi = 12;
int gelenSes[30] = {};
int ortalamaSes = 0;
int sure = 1;
byte sesZirvesi = 1;
int deger = 0;

void setup() {
  for (byte i = 2; i <= toplamLedSayisi; i++)
   {
      pinMode(i, OUTPUT);
   }
}

void loop() {
    deger = analogRead(A0);
    deger = deger * 5;
    gelenSes[sure % 30] = deger;
    digitalWrite(sesZirvesi, LOW);


    if (sure % 30 == 0) {
 for (byte i = 0; i < 30; i++)
 {
    ortalamaSes += gelenSes[i];
 }
 ortalamaSes /= 30;

 for (byte i = 0; i <= toplamLedSayisi; i++)
 {
  digitalWrite(i, LOW);
 }

 for (float i = 0; i <= toplamLedSayisi; i++)
 {
   if (i > ortalamaSes / 70 - 2)
   break;

   if (sesZirvesi < i)
   sesZirvesi = i;

   digitalWrite(i, HIGH);
 }

 ortalamaSes = 0;

 if (sure > 70 * 5)
 {
  sure = 1;
  if (sesZirvesi > 0)
  sesZirvesi--;
 }
 digitalWrite(sesZirvesi, HIGH);
    }
    sure++;

}
