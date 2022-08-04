/*
 * turnoutDriver.h
 *
 * Created: 2021/12/31 15:45:27
 *  Author: Y.Tsurui
 */

#define TURNOUT_CLOSE	1
#define TURNOUT_THROWN	2

void turnoutClock(void);
void initTurnoutDriver(void);
void setTurnout(uint8_t dir);
void resetTurnoutTimer(void);