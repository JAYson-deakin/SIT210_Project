#include <Wire.h>



const int LED=13;



const int DMIC = 3;

const int AMIC = A0;

const int DMIC2 = 4;

const int AMIC2 = A1;



int dval;

int aval;

int dval2;

int aval2;

int avalsent;

//char buffer[64];



//String avals;

//String aval2s;



void setup() {

  Wire.begin(0x8);               // Join i2c Bus with address #8

  Wire.onRequest(sendData);      // Register the event to call

    

  Serial.begin(9600);            // Set up to also print to serial  

  pinMode(LED, OUTPUT);          // Set builtin Arduino LED as output

  pinMode(DMIC, INPUT);          // Digital sensor pin to input

  pinMode(AMIC, INPUT);          // Analog sensor pin to input

}



void loop() {

  dval = digitalRead(DMIC);      // Read the digital pin state

  dval2 = digitalRead(DMIC2);

  if (dval == HIGH && dval2 == HIGH)              // If the state is high

  {

    digitalWrite(LED, HIGH);     // Light the LED

    aval = analogRead(AMIC);    // Get the analog value

    aval2 = analogRead(AMIC2);
    
    aval = aval * 5;

    //avals = String(aval);

    //aval2s = String(aval2);

    //wordus = aval + "," + aval2;

    //sprintf(buffer, "%d, %d", avals, aval2s);

    //Serial.println(aval);

    //delay(1000);// Write the analog val to serial

    //Serial.println(aval2);

    //delay(1000);
    
    avalsent = aval;
    
    Serial.println(avalsent);
    
    delay(1000);
    
    avalsent = aval2;
    
    Serial.println(avalsent);
    
    delay(1000);

  }

  else

  {

    digitalWrite(LED, LOW);      // Otherwise turn the LED off

  }

}





void sendData() {

  Wire.write(avalsent);            // Write the current analog value to the i2c bus

}
