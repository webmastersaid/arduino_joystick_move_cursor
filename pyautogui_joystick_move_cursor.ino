int btnPin = 8; // button joystick
int xPin = A0; // X axis joystick
int yPin = A5; // Y axix joystick

void setup() {

  Serial.begin(9600);

  pinMode(btnPin, INPUT);

  digitalWrite(btnPin, HIGH);

}

void loop() {

  int btn_click = 0;
  int x = analogRead(xPin);
  int y = analogRead(yPin);
  int x_pos, y_pos;

  if(x > 450 and x < 550) // joystick center position
    x_pos = 0;

  if(x >= 550) // joystick move up 
    x_pos = map(x, 550, 1023, 0, 80);

  if(x <= 450) // joystick move down
    x_pos = map(x, 450, 0, 0, -80);

  if(y > 450 and y < 550) // joystick center position
    y_pos = 0;

  if(y >= 550) // joystick move right
    y_pos = map(y, 550, 1023, 0, 80);

  if(y <= 450) // joystick move left
    y_pos = map(y, 450, 0, 0, -80);

  if(digitalRead(btnPin) == LOW)
    btn_click = 1;
  else
    btn_click = 0;

  // print the data and separating by ","
  Serial.print(x_pos);
  Serial.print(",");
  Serial.print(y_pos);
  Serial.print(",");
  Serial.print(btn_click);
  Serial.print(",");
  Serial.println();
  delay(120); // normalize

}