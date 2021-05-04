int redLed = 11;
int greenLed = 12;
int les=5;
char data;

int smokeA0 = A0;
// Your threshold value
int sensorThres = 560;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(les, OUTPUT);
 
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
     Serial.write('1'); 
  
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
     Serial.write('0');
  }
  delay(100);
 if (Serial.available()){     
    //Si un message a été reçu  faire ceci
     data=Serial.read();  
     // controler la lampe 1 reliée à la broche 13
     //récuperer le caractère reçu
     if(data=='1') //si le caractère lu est égale à 1
    {
       digitalWrite(les, HIGH);
       delay(100);
       // digitalWrite(les, LOW);
      // delay(100);
      // alumer la lampe 
     }  
     else if(data=='0') //si le caractère lu est égale à 0

     {
        digitalWrite(les, LOW);
     
     }   

     
     }




  
}
