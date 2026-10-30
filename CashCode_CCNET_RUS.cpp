#include "Arduino.h"
#include "CashCode_CCNET_RUS.h"

uint8_t CashCode_reset[] = {0x02, 0x03, 0x06, 0x30, 0x41, 0xB3}; // 02 03 06 30 41 B3
uint8_t CashCode_ack[] = {0x02, 0x03, 0x06, 0x00, 0xC2, 0x82}; // 02 03:06:00 C2 82
uint8_t CashCode_poll[] = {0x02, 0x03, 0x06, 0x33, 0xDA, 0x81};
uint8_t CashCode_enable[] = {0x02, 0x03, 0x0C, 0x34, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xB5, 0xC1};
uint8_t CashCode_disable[]= {0x02, 0x03,  0x0C, 0x34, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x0C};
uint8_t CashCode_bills[] = {0x02, 0x03, 0x06, 0x35, 0xEC, 0xE4};

CashCode_CCNET_RUS::CashCode_CCNET_RUS(int speed) {
Serial.begin(speed);
}

void CashCode_CCNET_RUS::reset(){
Serial.write( CashCode_reset, sizeof( CashCode_reset ) );
delay(300);
}

void CashCode_CCNET_RUS::update(){
  Serial.write( CashCode_poll, sizeof( CashCode_poll ) );
  delay(5);
  Serial.write( CashCode_bills, sizeof( CashCode_bills ) );
  delay(5);
  Serial.write( CashCode_ack, sizeof( CashCode_ack ) );
}

int CashCode_CCNET_RUS::getBanknote() {
    uint8_t info[6];

    if (Serial.available()) {
        info[0] = Serial.read();
        info[1] = Serial.read();
        info[2] = Serial.read();

        if ((info[0] == 0x02) && (info[1] == 0x03)) {
            info[3] = Serial.read();
            info[4] = Serial.read();
            info[5] = Serial.read();

            int banknote = info[4];

            // Вывод для отладки
            Serial.print("Received bytes: ");
            for (int i=0; i<6; i++) Serial.print(info[i], HEX), Serial.print(" ");
            Serial.println();

            switch (banknote) {
                case 2: delay(5); return 10;
                case 3: delay(5); return 50;
                case 4: delay(5); return 100;
                case 5: delay(5); return 500;
                case 6: delay(5); return 1000;
                case 7: delay(5); return 5000;
                case 12: delay(5); return 200;
                case 13: delay(5); return 2000;
                default:
                    
                    break;
            }
        }

        // Очистка буфера
        while (Serial.available()) {
            Serial.read();
        }
    }
    return 0; // Нет данных или некорректных
}

void CashCode_CCNET_RUS::enable() {
delay(5);
Serial.write( CashCode_poll, sizeof( CashCode_poll ) );
  delay(5);
Serial.write( CashCode_enable, sizeof( CashCode_enable ) );
}

void CashCode_CCNET_RUS::disable() {
delay(5);
Serial.write( CashCode_poll, sizeof( CashCode_poll ) );
  delay(5);
  Serial.write( CashCode_disable, sizeof( CashCode_disable ) );
}