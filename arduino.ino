int datafromUser;

void setup() {
  Serial.begin(115200); //устанавливаем скорость монитора порта
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available() > 0){ //если пришли данные в мониторе порта
    datafromUser = Serial.read(); //присваиваем переменной данные с монитора порта
    if (datafromUser == '1') {
      digitalWrite(13, 1); //включаем светодиод
    }
    else if (datafromUser == '2') {
      digitalWrite(13, 0);//выключаем светодиод
    }
  }
}
