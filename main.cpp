#include "mbed.h"

#define BLINK_LED_ON  25ms
#define BLINK_LED_OFF  975ms
#define LED PC_13

int main()
{
    DigitalOut led(LED);
    BufferedSerial Serial(PA_2, PA_3);
    Serial.set_baud(115200);
    Serial.set_format(8, BufferedSerial::None, 1);

    const char *texto = "Hola mundo\n";

    while(true)
    {
        led = 1;
        ThisThread::sleep_for(BLINK_LED_OFF);
        led = 0;
        Serial.write(texto, strlen(texto));
        ThisThread::sleep_for(BLINK_LED_ON);
    }
}