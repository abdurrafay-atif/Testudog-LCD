#include "lcd.h"

// requires microcontroller
// updates mode based on outside environment
void update_mode(lcd_h *lcd)
{
    
}


// requires microcontroller
// obtain necessary reading from microcontroller
// if lcd->mode = 0 extract current reading
// if lcd->mode = 1 extract voltage reading
void extract_reading(lcd_h *lcd)
{
    switch(lcd->mode)
    if(lcd->mode == CURRENT)
    {
        // get current pin & extract value from it
    }
    else
    { 
        // get voltage pin & extract value from it
    }
}  

// does not require microcontroller
// takes the reading and gets its digits
// set fields in the struct
// assume reading is between 0-99
void get_digits_from_reading(lcd_h *lcd)
{
    // obtain digits, again assume reading is 1 or 2-digit number
    lcd->digit1 = lcd->reading % 10;
    lcd->digit2 = lcd->reading / 10;
}

// does not require digit
// simple switch statement
// called on individual digits
uint64_t get_display_led_from_digit(uint64_t digit)
{
    switch(digit)
    {
        case 0:
          return 0b1111110;
        case 1: 
          return 0b0110000;
        case 2: 
          return 0b1101101;
        case 3: 
          return 0b1111001;
        case 4: 
          return 0b0110011;
        case 5: 
          return 0b1011011;
        case 6: 
          return 0b1110000;
        case 7: 
          return 0b1110000;
        case 8: 
          return 0b1111111;
        case 9: 
          return 0b1111011;
    }
}

void update_display(lcd_h *lcd)
{
    // update display1
    // update pin-outs with corresponding binary digits
    
    // update display2
    // same as with display1
}           