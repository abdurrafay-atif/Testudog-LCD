#include "lcd.h"

int main(void)
{
    // setup, setup struct
    lcd_h lcd;
    // loop
    while(1)
    {
        // read value
        extract_reading(&lcd);
        // update digits displayed
        get_digits_from_reading(&lcd);
        // set 7-seg displays based on new digits
        lcd.display1 = get_display_led_from_digit(lcd.digit1);
        lcd.display2 = get_display_led_from_digit(lcd.digit2);
        // update real world display
        
    }
}