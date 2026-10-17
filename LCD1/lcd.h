/*
  given:
  some digital value
  need to send:
  4 codes representing digits
  first three are whole digits
  last is decimal digit 

  struct (used for both volt & current)
  --> reading (double)
  --> size (char), either nano, micro, milli, standard, or kilo
    --> will prolly use global char array with these 5 items, set to 3 at default
  --> short consisting of all BCD digits (after calling funcs, will be sent)
      --> A3A2A1A0B3B2B1B0C3C2C1C0.D3D2D1D0
  --> size also has its specified codes... there are 5, so need 3 bits. 
    --> need some way of displaying letters 
  note edge case is when reading is 0 which if that's the case don't update reading

  functions:
  --> get reading from DAC (hardware required)
  --> update reading & size (takes in struct, updates reading until within 1 <= x < 1000)
  --> update BCD digits based on new reading
  --> send reading & size to circuit (hardware required)
*/

#ifndef LCD_H
#define LCD_H

typedef enum 
{
    NANO, 
    MICRO,
    MILLI,
    STANDARD, 
    KILO
}
metric_t;

typedef struct 
{
    double reading;
    metric_t metric;
    short bcd;
} 
lcd_h;

void normalize_reading(lcd_h *lcd);
void update_bcd_output(lcd_h *lcd);

#endif

/*
  more 7's, 8's, 9's than 1's, 2's, 3's
  might have other characters!
  77881122
*/