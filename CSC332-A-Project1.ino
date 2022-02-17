//CSC 332-A Project 1 - Bidirectional People Counter
//Yunah Kim and Haoyang Chen
//February 21, 2022

//ultrasonic sensor 1
int trigPin1 = 8;
int echoPin1 = 9;
int LED = 13;

//ultrasonic sensor 2
int trigPin2 = 6;
int echoPin2 = 7;

//sequence of sensors
String sequence = "";
 
int timeoutCounter = 0;
int currentPeople = 0;
 
int distance1, distance2, initialDistance1, initialDistance2;
 
int measureDistance(int trigPin, int echoPin){
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   int duration = pulseIn (echoPin, HIGH);
   return (duration/2) / 29.1; //return distance
}

void setup() {  
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(LED, OUTPUT);
  
  Serial.begin(9600);
 
  //initial readings
  initialDistance1 = measureDistance(trigPin1, echoPin1);
  initialDistance2 = measureDistance(trigPin2, echoPin2);
}
 
void loop(){
  delay(200); //reading taken after 200 milliseconds
 
  distance1 = measureDistance(trigPin1, echoPin1);
  distance2 = measureDistance(trigPin2, echoPin2);
 
  //process data
  if(distance1 < initialDistance1 - 30 && sequence.charAt(0) != '1'){
    sequence += '1';
  }
  else if(distance2 < initialDistance2 - 30 && sequence.charAt(0) != '2'){
    sequence += '2';
  }

  //person is entering
  if(sequence.equals("12")){
    Serial.print("Seq: ");
    Serial.println(sequence);
    currentPeople++;  
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
    sequence="";
    delay(350);
  }
  //person is exiting
  else if(sequence.equals("21") && currentPeople > 0){
    Serial.print("Seq: ");
    Serial.println(sequence);
    currentPeople--;
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
    sequence="";
    delay(350);
  }
 
  //reset sequence if invalid or timeout
  if(sequence.length() > 2 || sequence.equals("11") || sequence.equals("22") || timeoutCounter > 200){
    sequence="";
  }
 
  if(sequence.length() == 1){ 
    timeoutCounter++;
  }
  else{
    timeoutCounter=0;
  }
  
 //print values to serial
  Serial.print("S1: ");
  Serial.print(distance1);
  Serial.print("  S2: ");
  Serial.println(distance2);
  Serial.print("Current people: ");
  Serial.println(currentPeople);
 
}
