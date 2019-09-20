// Martin Cerven 2019
// Arduino part that is getting input
// controlling L239 chip
// and sending output on serial line

enum robot_direction_state{
  going_forward,
  going_backward,
  turning_left,
  turning_right,
  stopped,
};



//Motor A
const int motorPin1  = 8;  // Pin 14 of L293
const int motorPin2  = 7;  // Pin 10 of L293
//Motor B
const int motorPin3  = 6; // Pin  7 of L293
const int motorPin4  = 5;  // Pin  2 of L293

//const int enableRight = 10;
//const int enableLeft = 11;

// left switch
const int leftSwitchSensorPin =2 ;

// right switch
const int rightSwitchSensorPin = 3;

// left odometry
const int leftOptoSensorPin = A0; 

// right odometry
const int rightOptoSensorPin = A1;

robot_direction_state robot_direction;

boolean leftSwitchSensorValue;
boolean rightSwitchSensorValue;
int leftOptoSensorValue;
int rightOptoSensorValue; 

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    
    robot_direction=stopped;
       
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
}

void goForward(){
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
}

void goBackward(){
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
}

/**
 * For turning left you need to power right motor.
 */
void turnLeft(){
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
}
void turnRight(){
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
}
void stopMotors(){
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
}

int motorSpeed = 0;

/**
 * //TODO: precitaj zo serialu commandy:
 * F <speed>
 * L <speed>
 * R <speed>
 * B <speed>
 * S - stop
 */
boolean handleSerial() {
    while (Serial.available() > 0) { 
        char incomingCharacter = Serial.read();
        Serial.print(incomingCharacter );
        switch(incomingCharacter){
            case 'F':
                Serial.println('F');
                robot_direction=going_forward;
                break;
            case 'B':
                Serial.println('B');
                robot_direction=going_backward;
                break;
            case 'L':
                Serial.println('L');
                robot_direction=turning_left;
                break;
            case 'R':
                Serial.println('R');
                robot_direction=turning_right;
                break;
            case 'S':
                Serial.println('S');
                robot_direction=stopped;
                break;          
        }             
    }
}

void moveRobot(){
  switch(robot_direction){
      case going_forward:
          goForward();
          break;
      case going_backward:
          goBackward();
          break;
      case turning_left:
          turnLeft();
          break;
      case turning_right:
          turnRight();
          break;
      case stopped:
          stopMotors();
          break;          
    }  
}

void makeDecisions(){
    if(leftSwitchSensorValue  &&  rightSwitchSensorValue){
        robot_direction=going_backward;    
    }
    else if(leftSwitchSensorValue){
      //TODO: potrebujem mat nejaku pamet o tom kde vlastne som, pretoze
        robot_direction=turning_left;
    }
    else if(rightSwitchSensorValue){
        robot_direction=turning_right;  
    }
    else{
      robot_direction=going_forward;
    }
}


void getSensorInputs(){
  delay(100);
  leftSwitchSensorValue  = digitalRead(leftSwitchSensorPin);
  rightSwitchSensorValue = digitalRead(rightSwitchSensorPin);
  leftOptoSensorValue    = analogRead(leftOptoSensorPin);
  rightOptoSensorValue   = analogRead(rightOptoSensorPin);
  
  Serial.print("vals: ");
  Serial.print(leftSwitchSensorValue);
  Serial.print(rightSwitchSensorValue);
  Serial.print(" ");
  Serial.print(leftOptoSensorValue);
  Serial.print(" ");
  Serial.print(rightOptoSensorValue);
  Serial.println();
//  delay(100);
  
}

void loop() {
  getSensorInputs();
  handleSerial();
//  makeDecisions();
  moveRobot();
}
