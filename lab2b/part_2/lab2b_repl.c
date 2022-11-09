#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"
#include "registers.h"

#include "/home/siddhant/pico/pico-sdk/src/boards/include/boards/adafruit_qtpy_rp2040.h"

#define IS_RGBW true
#define NUM_PIXELS 150
#define PICO_DEFAULT_WS2812_POWER_PIN 11

#define QTPY_BOOT_PIN_NUM 21

#ifdef PICO_DEFAULT_WS2812_PIN
#define WS2812_PIN PICO_DEFAULT_WS2812_PIN
#else
// default to pin 2 if the board doesn't have a default WS2812 pin defined
#define WS2812_PIN 2
#endif

void set_neopixel_color(uint32_t color_num){
    //
    uint32_t r_num = color_num >> 16;
    uint32_t g_num = color_num << 16;
    g_num = g_num >> 24;
    uint32_t b_num = color_num << 24;
    b_num = b_num >> 24;
    uint32_t color_final = ((r_num << 8) |
                            (g_num << 16)|
                            (b_num));
    pio_sm_put_blocking(pio0, 0, color_final << 8u);
}


int main() {
    //set_sys_clock_48();
    // Initialize the GPIO Pins
    const uint POWER_PIN_NAME = PICO_DEFAULT_WS2812_POWER_PIN;
    gpio_init(POWER_PIN_NAME);
    gpio_init(QTPY_BOOT_PIN_NUM);
    gpio_set_dir(POWER_PIN_NAME, GPIO_OUT);
    gpio_set_dir(QTPY_BOOT_PIN_NUM, GPIO_IN);
    gpio_put(POWER_PIN_NAME, 1);
    stdio_init_all();

    // todo get free sm
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    volatile uint32_t* QTPY_GPIO_CTRL_REG = IO_BANK0_BASE + 0x004;
    /* volatile uint32_t QTPY_BOOT_PIN_REG_PIN_NAME = */


    while(!stdio_usb_connected());

    while(1){
        /* int user_inp = getchar_timeout_us(5000); */

        uint32_t reg_status = register_read(QTPY_GPIO_CTRL_REG);
        printf("Already existing value is: 0x%08x\n" , reg_status);

        uint32_t reg_updated_value;
        printf("Enter your value:\n");
        scanf("%x" , &reg_updated_value);
        register_write(QTPY_GPIO_CTRL_REG , reg_updated_value);

        uint32_t reg_overwrite_value= register_read(QTPY_GPIO_CTRL_REG);
        printf(" The updated value of the register after overwriting is : 0x%08x\n", reg_overwrite_value);

        uint32_t bit_set;
        printf("Enter the value for bit setting:\n");
        scanf("%x", &bit_set);
        bit_set = bit_set |reg_overwrite_value;
        register_write(QTPY_GPIO_CTRL_REG, bit_set);


        uint32_t reg_value_after_bit_set = register_read(QTPY_GPIO_CTRL_REG);
        printf("Register Value after bit setting is:  0x%08x\n", reg_value_after_bit_set);

        sleep_ms(1000);



        }
   }
