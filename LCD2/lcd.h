#ifndef LCD_H
#define LCD_H

#include <stdint.h>

typedef enum
{
    CURRENT,  // 0
    VOLTAGE   // 1
}
mode_t;

typedef struct 
{
    mode_t mode : 1;        // either reading volts or current
    uint64_t reading : 7;   // from analog to digital converter. reading around 3-6 A, or 3-6 V
    uint64_t digit1 : 4;    // extracted from reading
    uint64_t digit2 : 4;    // extracted from reading
    uint64_t display1 : 8;  // display LED for dig1
    uint64_t display2 : 8;  // display LED for dig2
}
lcd_h;

void update_mode(lcd_h *lcd);                     // requires microcontroller
void extract_reading(lcd_h *lcd);                 // requires microcontroller
void get_digits_from_reading(lcd_h *lcd);         // can be done without microcontroller
uint64_t get_display_led_from_digit(lcd_h *lcd);  // can be done without microcontroller
void update_display(lcd_h *lcd);                  // requires microcontroller

#endif