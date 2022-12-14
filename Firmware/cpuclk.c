/*
 * cpuclk.c
 *
 * Created: 2021/01/25 10:04:40
 *  Author: Y.Tsurui
 */ 

#include <avr/io.h>
#include <avr/cpufunc.h>

void setCLK(void)
{
	// Clock Configuration (10MHz)
	//CCP = CCP_IOREG_gc;
	//CLKCTRL.MCLKCTRLB = 0x01;	// Prescaler Disable (20MHz)
	ccp_write_io((void *) & (CLKCTRL.MCLKCTRLB), 0);
	
	// BOD Enable
	//BOD.CTRLA = BOD_ACTIVE_ENABLED_gc;
	//BOD.CTRLB = BOD_LVL_BODLEVEL0_gc; 
	ccp_write_io((void *) & (BOD.CTRLA), BOD_ACTIVE_ENABLED_gc);
	ccp_write_io((void *) & (BOD.CTRLB), BOD_LVL_BODLEVEL0_gc);
}
