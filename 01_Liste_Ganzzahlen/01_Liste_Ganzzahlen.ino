void setup() {

  Serial.begin(9600);

  Serial.println("Bitmuster\tuint8_t\tint8_t"); //Bitmuster\tint8_t\n0\t\t0\n
  for(int16_t i = 0; i <= 255; ++i)
  {
    Serial.print(i, BIN);
    
    /* das ist ein Hack, um eine schöne Tabelle zu erzeugen */
    if (i <= 127) Serial.print("\t\t");
    else Serial.print("\t");

    /* obiger if-Block ist identisch mit:
    if (i <= 127)
    {
      Serial.print("\t\t");
    }
    else
    {
      Serial.print("\t");
    }
    */

    Serial.print((uint8_t) i); //explicit type cast: i bekommt kurzzeitig den Datentyp uint8_t
    Serial.print("\t");
    Serial.println((int8_t) i); //explicit type cast: i bekommt kurzzeitig den Datentyp int8_t
  }
}

void loop() {
}
