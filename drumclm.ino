/*
 * Ardrumo sketch
 *
 * Use with the Ardrumo software here:
 * <a href="http://code.google.com/p/ardrumo/" rel="nofollow"> <a href="http://code.google.com/p/ardrumo/"> <a href="http://code.google.com/p/ardrumo/">  http://code.google.com/p/ardrumo/
 
</a>
</a>
</a>
 * This is designed to let an Arduino act as a drum machine
 * in GarageBand (sorry, Mac OS X only).
 */
 
#define LEDPIN     13     // status LED pin
#define PIEZOTHRESHOLD 5  // analog threshold for piezo sensing
#define PADNUM 6          // number of pads
 
int val;
 
void setup() {
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(57600);   // set serial output rate
}
 
void loop() {
 
  // Loop through each piezo and send data
  // on the serial output if the force exceeds
  // the piezo threshold
  //for(int i = 0; i < PADNUM; i++) 
  
    val = analogRead(A0);
    if( val >= PIEZOTHRESHOLD ) {
      digitalWrite(LEDPIN,HIGH);  // indicate we're sending MIDI data
      Serial.print(3);
      Serial.print(",");
      Serial.print(val);
      Serial.println();
      digitalWrite(LEDPIN,LOW);
    }
  /*    val = analogRead(A1);
    if( val >= PIEZOTHRESHOLD ) {
      digitalWrite(LEDPIN,HIGH);  // indicate we're sending MIDI data
      Serial.print(1);
      Serial.print(",");
      Serial.print(val);
      Serial.println();
      digitalWrite(LEDPIN,LOW);
    }
      val = analogRead(A2);
    if( val >= PIEZOTHRESHOLD ) {
      digitalWrite(LEDPIN,HIGH);  // indicate we're sending MIDI data
      Serial.print(2);
      Serial.print(",");
      Serial.print(val);
      Serial.println();
      digitalWrite(LEDPIN,LOW);
    }
      val = analogRead(A3);
    if( val >= PIEZOTHRESHOLD ) {
      digitalWrite(LEDPIN,HIGH);  // indicate we're sending MIDI data
      Serial.print(3);
      Serial.print(",");
      Serial.print(val);
      Serial.println();
      digitalWrite(LEDPIN,LOW);
    }
  */
}
