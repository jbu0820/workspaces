#include "led.h" // "led.h" == <led.h> ""이 범위가 작음
#include <avr/io.h>

int main(){

    LED led;                //LED라는 구조를 가진 led변수 선언 
    led.port = &PORTD;
    led.pin = 0;
    for (uint8_t i = 0; i < 8; i++){
        led.pin = i;
        ledInit(&led);
    }
    
    while(1){
        ledOn(&led);
        _delay_ms(200);    
        ledOff(&led);
        _delay_ms(200);
        led.pin++;
        led.pin = (led.pin) % 8;
    }
}



// uint8_t ledArr[] = {
//     0x00,       // 0000 0000
//     0x80,       // 1000 0000
//     0xC0,       // 1100 0000
//     0xE0,       // 1110 0000
//     0xF0,       // 1111 0000
//     0xF8,       // 1111 1000
//     0xFC,       // 1111 1100
//     0xFE,       // 1111 1110
//     0xFF,       // 1111 1111
//     0x7F,       // 0111 1111
//     0x3F,       // 0011 1111
//     0x1F,       // 0001 1111
//     0x0F,       // 0000 1111
//     0x07,       // 0000 0111
//     0x03,       // 0000 0011
//     0x01        // 0000 0001
// };

// int main(){
//     DDRD = 0xFF;

//     uint8_t arrSize = sizeof(ledArr)/sizeof (ledArr[0]);
//     while(1){
//         for (uint8_t i = 0; i < arrSize; i++)
//         {
//         PORTD = ledArr[i];
//         _delay_ms(200);
//         }
    
//     }
    
// }
//#define LED_PORT PORTD
//#define LED_DDR DDRD

// void GPIO_Output(uint8_t data)
// {
//     LED_PORT = data;    // LED 포트에 주어진 data를 대입
// }

// void ledInit(){
//     LED_DDR = 0xFF;
// }


// //LED shift func
// void ledshift(uint8_t i, uint8_t *data){
//     *data = (1 << i) | (1 << (7-i)); // 좌우 방향을 해당하는 비트설정
// }


// int main(){

//     ledInit();                  //Led init
//     uint8_t ledData = 0x01;     //Led intial data 

//     while(1){
//         for(int i = 0; i < 8; i++){
//             ledshift(i, &ledData);  // Call shift func 
//             GPIO_Output(ledData);   // Call Led output
//             _delay_ms(1000);        // delay 1s
//         }
//     }

// }
//LED code 
// int main(){
    
//     DDRD |= 0b11111111; 

//     while(1){

//         for (uint8_t i = 0; i < 8; i++){
//             PORTD = (0b00000001 << i);
//             _delay_ms(200);
//         }
//         for (uint8_t j = 0; j < 8; j++){
//             PORTD = (0b10000000 >> j);
//             _delay_ms(200);
//         }
//     }

// }
