 /*
    === Arduino Motion Detecting Night Light===
               with Serial Monitor
      by Shri30yans
*/
 
#define pirPin 2  //the digital pin connected to the PIR sensor's output //Note:This can be any Digital I/O Pin 
#define ledPin 11 //the PWM connected to the Led strip output       //Note:This can be any PWM pin (3,5,6,9,10,11 on Arduino Uno and pins 2-13 on the Mega) 
#define LDR  A0   //the Analog In Pin connected to the LDR's input   //Note:This can be any Analog In Pin
int Brightness = 0;       //Declaring the variable "Brightness"
int Darkness = 0;       //Declaring the variable "Darkness"
int calibrationTime = 30; //the time we give the sensor to calibrate 

void setup(){
  Serial.begin(9600);      //Starting Serial Monitor with a Baud Rate of 9600 
  pinMode(pirPin, INPUT);  //Setting the pinmodes of the PIR sensor
  pinMode(ledPin, OUTPUT); //Setting the pinmodes of the Led 
  pinMode(LDR, INPUT);     //Setting the pinmodes of the LDR
  digitalWrite(ledPin, LOW);//Switching off the led strip by default
  
 
  //Give the sensor some time to calibrate (This piece of code prints dots on the Serial Monitor to show that conection with Arduino is stable.)
  Serial.print("Calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println("PIR Activated");
    delay(50);
  }
 
void loop(){
  delay(1000);
 Brightness = analogRead(LDR);
 Darkness = Brightness-700;
 Serial.println(Brightness);
 if (Brightness < 700 ){ //If it is dark to a certain point only then the PIR would detect motion and the Led  would light up
  Serial.println("It is Dark.");
   if (digitalRead(pirPin) == HIGH){  //If motion is detected...
       Serial.println("Motion Detected...Light is on");
       analogWrite(ledPin,Darkness/4);//the degree of darkness of the room would increase the degree of brightness of the Led
       //Darkness is divided by four as the LDR gives values of (0-1023),but Arduino can only Analog write the PWM values of (0-255)
       delay(100);}   //A pause for 100 Milliseconds
   
    else{
      Serial.println("No Motion Detected.");
      digitalWrite(ledPin, LOW);}//If Motion is not Detected the Led is not lit up
  }
  else{
    Serial.println("It is not Dark.");
    digitalWrite(ledPin, LOW);}//If it is not dark enough the Led is not lit up
 
} 

  
