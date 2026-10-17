#include "lcd.h"
#include <stdio.h>
#include <stdlib.h>

void print_lcd(lcd_h lc)
{
    char metrics[] = {'n', 'u', 'm', ' ', 'k'};
    printf("LCD: READING -> %.1lf, METRIC -> %c\n", lc.reading, metrics[lc.metric]);
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        return 1;
    }
    lcd_h lcd;
    lcd.reading = atof(argv[1]);
    lcd.metric = STANDARD;
    lcd.bcd = 0;
    print_lcd(lcd);
    normalize_reading(&lcd);
    update_bcd_output(&lcd);
    print_lcd(lcd);
    return 0;
}