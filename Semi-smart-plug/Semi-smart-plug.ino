unsigned long last_time, last_press;
bool start, midbt, ltbt, rtbt, midbutt, leftbutt, rightbutt;
unsigned int t, timer;
void setup() {
  pinMode(4, digitalWrite);
  pinMode(3, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  midbt = !digitalRead(3);
  ltbt = !digitalRead(5);
  rtbt = !digitalRead(6);
  timer = 1000 * 60 * t;
  // Обработка нажатия левой кнопки
  if (ltbt && !leftbutt && millis() - last_press > 100) {
    leftbutt = 1;
    start = 0;
    digitalWrite(4, LOW);
    if ((t - 1) != 65535) {t --;}
    Serial.println(t);
    last_time = millis();
    last_press = millis();
  }
  if (!ltbt && leftbutt && millis() - last_press > 100) {
    leftbutt = 0;
    last_press = millis();
  }
  // Обработка нажатия правой кнопки
  if (rtbt && !rightbutt && millis() - last_press > 100) {
    rightbutt = 1;
    start = 0;
    digitalWrite(4, LOW);
    if ((t + 1) <= 60) {t ++;}
    Serial.println(t);
    last_time = millis();
    last_press = millis();
  }
  if (!rtbt && rightbutt && millis() - last_press > 100) {
    rightbutt = 0;
    last_press = millis();
  }
  // Обработка нажатия средней кнопки
  if (midbt && !midbutt && millis() - last_press > 100) {
    midbutt = 1;
    start = 1;
    digitalWrite(4, HIGH);
    last_time = millis();
    last_press = millis();
  }
  if (!midbt && midbutt && millis() - last_press > 100) {
    midbutt = 0;
    last_press = millis();
  }
  if (millis() - last_time >= timer && start == 1) {
    digitalWrite(4, LOW);
    last_time = millis();
    start = 0;
  }
}
