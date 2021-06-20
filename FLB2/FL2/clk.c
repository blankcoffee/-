#include <head.h>

//bclk 32768hz
//dco 12000000hz
//hsmclk 48000000hz
//smclk 12000000hz
//mclk 12000000hz


void clk_init()
{
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_PJ,GPIO_PIN3 | GPIO_PIN4,GPIO_PRIMARY_MODULE_FUNCTION);
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_PJ,GPIO_PIN0 | GPIO_PIN1,GPIO_PRIMARY_MODULE_FUNCTION);

    CS_setExternalClockSourceFrequency(32000,48000000);
    PCM_setCoreVoltageLevel(PCM_VCORE1);
    FlashCtl_setWaitState(FLASH_BANK0,2);
    FlashCtl_setWaitState(FLASH_BANK1,2);
    CS_startHFXT(false);

    CS_initClockSignal(CS_ACLK,CS_LFXTCLK_SELECT,CS_CLOCK_DIVIDER_1);
    CS_initClockSignal(CS_BCLK,CS_LFXTCLK_SELECT,CS_CLOCK_DIVIDER_1);
    CS_initClockSignal(CS_HSMCLK,CS_HFXTCLK_SELECT,CS_CLOCK_DIVIDER_1);
    CS_initClockSignal(CS_SMCLK,CS_HFXTCLK_SELECT,CS_CLOCK_DIVIDER_4);
    CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_12);

    clk.aclk=CS_getACLK();
    clk.bclk=CS_getBCLK();
    clk.dco=CS_getDCOFrequency();
    clk.hsmclk=CS_getHSMCLK();
    clk.smclk=CS_getSMCLK();
    clk.mclk=CS_getMCLK();
}




