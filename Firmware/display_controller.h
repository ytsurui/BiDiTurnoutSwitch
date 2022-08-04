/*
 * display_controller.h
 *
 * Created: 2021/12/31 0:50:38
 *  Author: Y.Tsurui
 */ 

void initDisplay(void);
void displayClock(void);

void set_7seg_timer(void);
void set_7seg_data(uint16_t data);
void set_led_power_stat(uint8_t stat);
void set_prog_mode(void);
void set_clr_msg(void);
void set_null_msg(uint8_t pos);

uint8_t appTimer(void);
