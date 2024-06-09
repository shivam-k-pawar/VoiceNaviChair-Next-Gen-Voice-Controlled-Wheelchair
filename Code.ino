// motor control pins
const int enA = 5;
const int in1 = 6;
const int in2 = 7;
const int in3 = 8;
const int in4 = 9;
const int enB = 10;

// voice control input
const int forwardPin = 3;
const int backwardPin = 4;
const int leftPin = 11;
const int rightPin = 12;
// pin to switch the mode between joystick and voice control
const int switchMode = 2; 

// joystick control input
const int yAxis_pin = A0; // Joysticks Y-axis
const int xAxis_pin = A1; // Joysticks X-axis

bool isJoystick = false;
int motorSpeedA = 0;
int motorSpeedB = 0;

void setup() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);

  // put your setup code here, to run once:
  pinMode(forwardPin, INPUT);
  pinMode(backwardPin, INPUT);
  pinMode(leftPin, INPUT);
  pinMode(rightPin, INPUT);
  pinMode(switchMode, INPUT);

  pinMode(xAxis_pin, INPUT);
  pinMode(yAxis_pin, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  Serial.begin(9600);
  delay(100);
}

void loop() {
  // if switchMode pin is HIGH then joystick should work
  if(digitalRead(switchMode) == HIGH){
    isJoystick = true;
  }
  else{
    isJoystick = false;
  }

  if(isJoystick){
    int xAxis = analogRead(xAxis_pin); // Read Joysticks X-axis
    int yAxis = analogRead(yAxis_pin); // Read Joysticks Y-axis

    // If joystick stays in middle the motors are not moving
    if(xAxis > 470 && xAxis <550 && yAxis > 470 && yAxis <550){stop();}

    if (xAxis > 470 && xAxis <550){    
      // Y-axis used for left and right control
      if (yAxis < 470){right();
        // Convert the declining Y-axis readings for going backward from 470 to 0 into 0 to 255 value for the PWM signal for increasing the motor speed  
        motorSpeedA = map(yAxis, 470, 0, 0, 255);
        motorSpeedB = map(yAxis, 470, 0, 0, 255);    
      }

    if (yAxis > 550) {
      left();
      // Convert the increasing Y-axis readings for going forward from 550 to 1023 into 0 to 255 value for the PWM signal for increasing the motor speed      
      motorSpeedA = map(yAxis, 550, 1023, 0, 255);
      motorSpeedB = map(yAxis, 550, 1023, 0, 255); 
    }

    }
    else{
      if (yAxis > 470 && yAxis <550){   
        // X-axis used for forward and backward control  
        if (xAxis < 470){forward();}
        if (xAxis > 550){backward();}

        if (xAxis < 470){
        // Convert the declining X-axis readings for going backward from 470 to 0 into 0 to 255 value for the PWM signal for increasing the motor speed  
          motorSpeedA = map(xAxis, 470, 0, 0, 255);
          motorSpeedB = map(xAxis, 470, 0, 0, 255); 
        }

        if (xAxis > 550){
          // Convert the increasing X-axis readings for going forward from 550 to 1023 into 0 to 255 value for the PWM signal for increasing the motor speed      
          motorSpeedA = map(xAxis, 550, 1023, 0, 255);
          motorSpeedB = map(xAxis, 550, 1023, 0, 255);
        }                
    }
    else{

      if(xAxis < 470){forward();}
      if(xAxis > 550){backward();}

      if(yAxis < 470){
        // Convert the declining Y-axis readings from 470 to 0 into increasing 0 to 255 value
        int yMapped = map(yAxis, 470, 0, 0, 255);
    
        // Move to left - decrease left motor speed, increase right motor speed
        motorSpeedA = motorSpeedA + yMapped;
        motorSpeedB = motorSpeedB - yMapped;
    
    // Confine the range from 0 to 255
        if(motorSpeedA > 255) {motorSpeedA = 255;}
        if(motorSpeedB > 70){motorSpeedB = 70;}
      }
 
      if (yAxis > 550){
        // Convert the increasing Y-axis readings from 550 to 1023 into 0 to 255 value
        int yMapped = map(yAxis, 550, 1023, 0, 255);
    
        // Move right - decrease right motor speed, increase left motor speed
        motorSpeedA = motorSpeedA - yMapped;
        motorSpeedB = motorSpeedB + yMapped;
    
        // Confine the range from 0 to 255
      if(motorSpeedA < 70){motorSpeedA = 70;}
      if(motorSpeedB > 255){motorSpeedB = 255;}
    }
  } 
}

// Prevent buzzing at low speeds (Adjust according to your motors. My motors couldn't start moving if PWM value was below value of 70)
    if(motorSpeedA < 70){motorSpeedA = 0;}
    if(motorSpeedB < 70){motorSpeedB = 0;}
  
    analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
    analogWrite(enB, motorSpeedB); // Send PWM signal to motor B

    delay(10);
  }

  // when isJoystick is false - voice control will be activated
  else{
    int speed = 80;
    if(digitalRead(forwardPin)==HIGH){
      forward();
      analogWrite(enA, speed);
      analogWrite(enB, speed);
    }
    else if(digitalRead(backwardPin)==HIGH){
      backward();
      analogWrite(enA, speed);
      analogWrite(enB, speed);  
    }
    else if(digitalRead(leftPin)==HIGH){
      left();
      analogWrite(enA, speed);
      analogWrite(enB, 0);
    }
    else if(digitalRead(rightPin)==HIGH){
      right();
      analogWrite(enA, 0);
      analogWrite(enB, speed);
    }
    else{
      stop();
      analogWrite(enA, 0);
      analogWrite(enB, 0);
    }
  }
}

void forward(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.println("forward");
  delay(100);
}

void backward(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println("backward");
  delay(100);
}

void left(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("left");
  delay(100);
}

void right(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.println("right");
  delay(100);
}

void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("stop");
  delay(100);
}
