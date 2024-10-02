#define MEASURE_START   cli();              \
                        TCCR1A = 0;         \
                        TCCR1B = 1 << CS10; \
                        TCCR1C = 0;         \
                        TCNT1 = 0;

/** offset empty loop is 4 cycles with optimization off */
/** offset empty loop is 1 cycles with standard optimization */
#define MEASURE_STOP(c, offset)  c = TCNT1; \
                         c = c - offset;    \
                         TCCR1B = 0;        \
                         sei();


int sprintf_binary(char* buffer, uint8_t i) {
  const static char string_0[] PROGMEM = "0000";
  const static char string_1[] PROGMEM = "0001";
  const static char string_2[] PROGMEM = "0010";
  const static char string_3[] PROGMEM = "0011";
  const static char string_4[] PROGMEM = "0100";
  const static char string_5[] PROGMEM = "0101";
  const static char string_6[] PROGMEM = "0110";
  const static char string_7[] PROGMEM = "0111";
  const static char string_8[] PROGMEM = "1000";
  const static char string_9[] PROGMEM = "1001";
  const static char string_a[] PROGMEM = "1010";
  const static char string_b[] PROGMEM = "1011";
  const static char string_c[] PROGMEM = "1100";
  const static char string_d[] PROGMEM = "1101";
  const static char string_e[] PROGMEM = "1110";
  const static char string_f[] PROGMEM = "1111";

  static PGM_P const bit_rep[] PROGMEM = {
    string_0, string_1, string_2, string_3,
    string_4, string_5, string_6, string_7,
    string_8, string_9, string_a, string_b,
    string_c, string_d, string_e, string_f,
  };

  return sprintf_P(buffer, PSTR("%S%S"), (PGM_P)pgm_read_word(&(bit_rep[i >> 4])), (PGM_P)pgm_read_word(&(bit_rep[i & 0x0F])));
}

void setup() {

  Serial.begin(9600);

  Serial.println("Bitmuster\tuint8_t\tint8_t");  //Bitmuster\tint8_t\n0\t\t0\n

  uint8_t i = 0;
  uint16_t cycles;
  char buffer[sizeof(i)*8];
  do {
    
//    MEASURE_START


    {
      auto k{i};
      for (uint8_t j = sizeof(i)*8; j > 0; k >>= 1)   buffer[--j] = '0' + (k & 0x1);
    }

//    sprintf_binary(buffer, i);

//    MEASURE_STOP(cycles, 1)
//    Serial.print("Anzahl Takte: ");
//    Serial.println(cycles);


    Serial.print(buffer);
    Serial.print("\t");
    Serial.print((uint8_t)i);  //explicit type cast: i bekommt kurzzeitig den Datentyp uint8_t
    Serial.print("\t");
    Serial.println((int8_t)i);  //explicit type cast: i bekommt kurzzeitig den Datentyp int8_t
    ++i;
  } while (i != 0);
}

void loop() {
}
