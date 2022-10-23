int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;

int ENA_pin_1 = 8;
int ENA_pin_2 = 9;
int speed_ENA = 50;

int time_delay = 3000;

void setup() {
  Serial.begin(9600);   
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT); 
}

void go_forward(int pos_1 = HIGH, int pos_2 = LOW) {
  //clockwise + clockwise, 
  digitalWrite(motor1pin1, pos_1);
  digitalWrite(motor1pin2, pos_2);
  
  digitalWrite(motor2pin1, pos_1);
  digitalWrite(motor2pin2, pos_2);
  delay(time_delay);
}

void go_back(int pos_1 = HIGH, int pos_2 = LOW) {
  //anti-clockwise + anti-clockwise
  go_forward(pos_2, pos_1);
}

void go_right(int pos_1 = LOW, int pos_2 = HIGH) {
  //clockwise + anti-clockwise
  digitalWrite(motor1pin1, pos_1);
  digitalWrite(motor1pin2, pos_2);
  
  digitalWrite(motor2pin1, pos_2);
  digitalWrite(motor2pin2, pos_1);
  delay(time_delay);
}

void go_left(int pos_1 = LOW, int pos_2 = HIGH) {
  //anti-clockwise + clockwise
  go_right(pos_2, pos_1);
}

void loop() {
  //time to connect power
  delay(7000);
  go_forward();
  delay(time_delay);
  go_right();
  delay(time_delay);
  go_back();
  delay(time_delay);
  go_left();
  delay(time_delay); 
}
