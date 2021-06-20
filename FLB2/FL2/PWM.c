#include "head.h"

//SMCLK=12000000hz

#define PWM_PERIOD 1200//T=1200/12000000s


//测试完成，正常工作
//调用PWM占空比函数pwm_2_x_duty(unsigned int)

Timer_A_PWMConfig pwm_2_4 =//TA0.1
{
    TIMER_A_CLOCKSOURCE_SMCLK,
    TIMER_A_CLOCKSOURCE_DIVIDER_1,
    PWM_PERIOD,
    TIMER_A_CAPTURECOMPARE_REGISTER_1,
    TIMER_A_OUTPUTMODE_RESET_SET,
    0
};

Timer_A_PWMConfig pwm_2_5 =//TA0.2
{
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        PWM_PERIOD,
        TIMER_A_CAPTURECOMPARE_REGISTER_2,
        TIMER_A_OUTPUTMODE_RESET_SET,
        0
};

Timer_A_PWMConfig pwm_2_6 =//TA0.3
{
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        PWM_PERIOD,
        TIMER_A_CAPTURECOMPARE_REGISTER_3,
        TIMER_A_OUTPUTMODE_RESET_SET,
        0
};
Timer_A_PWMConfig pwm_2_7 =//TA0.4
{
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        PWM_PERIOD,
        TIMER_A_CAPTURECOMPARE_REGISTER_4,
        TIMER_A_OUTPUTMODE_RESET_SET,
        0
};

void pwm_init()
{
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN4 | GPIO_PIN5,
                                                GPIO_PRIMARY_MODULE_FUNCTION);
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN6 | GPIO_PIN7,
                                                GPIO_PRIMARY_MODULE_FUNCTION);

    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &pwm_2_4);
    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &pwm_2_5);
    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &pwm_2_6);
    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &pwm_2_7);
}

void pwm_2_4_duty(unsigned int duty)
{
    pwm_2_4.dutyCycle=duty;

    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &pwm_2_4);
}
void pwm_2_5_duty(unsigned int duty)
{
    pwm_2_5.dutyCycle=duty;

    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &pwm_2_5);
}
void pwm_2_6_duty(unsigned int duty)
{
    pwm_2_6.dutyCycle=duty;

    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &pwm_2_6);
}
void pwm_2_7_duty(unsigned int duty)
{
    pwm_2_7.dutyCycle=duty;

    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &pwm_2_7);
}
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
void m_x(int32_t duty)
{
    //限制幅度
    if(duty>=PWM_PERIOD)
    {
        duty=PWM_PERIOD;
    }
    if(duty<=-PWM_PERIOD)
    {
        duty=-PWM_PERIOD;
    }
    //控制两个电机输出
    if(duty>0)
    {
        pwm_2_4_duty(0);
        pwm_2_5_duty(duty);
    }
    else
    {
        duty=-duty;
        pwm_2_5_duty(0);
        pwm_2_4_duty(duty);
    }
}
void m_y(int32_t duty)
{
    if(duty>=PWM_PERIOD)
    {
        duty=PWM_PERIOD;
    }
    if(duty<=-PWM_PERIOD)
    {
        duty=-PWM_PERIOD;
    }
    //控制两个电机输出
    if(duty>0)
    {
        pwm_2_7_duty(0);
        pwm_2_6_duty(duty);
    }
    else
    {
        duty=-duty;
        pwm_2_6_duty(0);
        pwm_2_7_duty(duty);
    }


}









