/*
 * pushButton.h
 *
 * Created: 2021/12/31 15:08:00
 *  Author: Y.Tsurui
 */ 


void buttonClock();
void initButton(void);
uint8_t getButtonStat(uint8_t buttonId);
uint8_t pushButtonEvent(uint8_t buttonId);

#define BUTTON_ID_SET_C 0
#define BUTTON_ID_SET_T 1
#define BUTTON_ID_CLR	2
#define BUTTON_ID_PROG	3