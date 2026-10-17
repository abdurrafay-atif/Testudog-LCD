#include "lcd.h"

// assumes reading has already been obtained
// assumes lcd reading won't go beyond kilo or below nano
void normalize_reading(lcd_h *lcd)
{ 
    // edge case
    if(lcd->reading == 0.0)
    {
        return;
    }
    // normalize backwards
    while(lcd->reading < 1.0)
    {
        lcd->reading *= 1000.0;
        lcd->metric--;
    }
    // normalize forwards
    while(lcd->reading >= 1000.0)
    {
        lcd->reading /= 1000.0;
        lcd->metric++;
    }
}

// extracts BCD codes from reading
// 4 BCD codes from short
// it is a double value... multiply by 10, then convert to short
void update_bcd_output(lcd_h *lcd)
{
    // convert to short for proper conversion
    // need to multiply by 10 so we don't lose data
    short digits = (int) (lcd->reading * 10);
    // extract each digit & place accordingly
    for(int shift = 0; shift < 16; shift += 4)
    {
        lcd->bcd |= ((digits & 0b1111) << shift);
        digits /= 10;
    }
}