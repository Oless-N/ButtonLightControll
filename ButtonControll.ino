
#define N1 12
#define N2 11
#define N3 10
#define N4 9
#define b1 2
char inSTR;
void setup() {                
  pinMode(N1, OUTPUT); 
  pinMode(N2, OUTPUT); 
  pinMode(N3, OUTPUT); 
  pinMode(N4, OUTPUT);  
  pinMode(b1, INPUT);   

  digitalWrite(N1,HIGH);
  digitalWrite(N2,HIGH);
  digitalWrite(N3,HIGH);
  digitalWrite(N4,HIGH);
Serial.begin(9600);
}
void loop() {
while (Serial.available())
    {
      if (digitalRead(b1))
      {Serial.write("On");}
          char inChar=(char)Serial.read();
          inSTR=inChar;
          if (inChar =='\n')
          {
            break;
          }
          Serial.write("\n Ok ");
  digitalWrite(N1,HIGH);
  digitalWrite(N2,HIGH);
  digitalWrite(N3,HIGH);
  digitalWrite(N4,HIGH);
    
switch(inSTR)
    {
       case '1':
        digitalWrite(N2,LOW);
        digitalWrite(N3,LOW);
        digitalWrite(N4,LOW);
        delay(500);
        Serial.write("1");
        break;
        case '0':
          digitalWrite(N1,LOW);
          delay(500);
           Serial.write("0");
          break;
        case '2':
          digitalWrite(N2,LOW);
          delay(500);
            Serial.write("2");
          break;
         
        case '6':
        digitalWrite(N1,LOW);
        digitalWrite(N3,LOW);
        delay(500);
        Serial.write("6");
        break;
        case '7':
        digitalWrite(N1,LOW);
        digitalWrite(N4,LOW);
        delay(500);
        Serial.write("7");
        break;
        case '8':
          digitalWrite(N2,LOW);
        digitalWrite(N3,LOW);
        delay(500);
        Serial.write("8");
        break;
       
          case '3':
        digitalWrite(N1,LOW);
        digitalWrite(N3,LOW);
        digitalWrite(N4,LOW);
        delay(500);
        digitalWrite(N1,HIGH);
        digitalWrite(N3,HIGH);
        digitalWrite(N4,HIGH);
        Serial.write("3");
        break;
           case '4':
        digitalWrite(N1,LOW);
        digitalWrite(N2,LOW);
        digitalWrite(N4,LOW);
        delay(500);
        Serial.write("4");
        break;
             case '5':
        digitalWrite(N1,LOW);
        digitalWrite(N3,LOW);
        digitalWrite(N4,LOW);
        delay(500);
        Serial.write("5");
        break;
              
    }   
    }
}
                   
