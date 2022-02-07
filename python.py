#pip install pyserial команда в терминал для установки библиотеки
import serial


ser = serial.Serial('COM23', 115200) #вместо COM23 необходимо указать номер порта, куда подключена плата
while True:
    val = input("Введите число от 1 до 2 ")
    if val == "1":
        ser.write(b'1')
    if val == "2":
        ser.write(b'2')
