/*
 * function.h
 *
 *  Created on: 2021年4月30日
 *      Author: 23359
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

#define PERIOD 20000 //单摆周期（ms）
#define pi 3.1415
extern float x_p[6];
extern float y_p[6];
extern int pwm_duty[4];//PWM波测试用
extern float s[5];
extern uint32_t TimeCnt;//计时用
extern float alpha;
extern int function_flag;

void control();
void follow();
void parameter();//PID参数赋值
void test(void);


struct sin //x=a*sin(phase)+h
{
    int a;//振幅
    float phase;//相位差
    int h;
};

struct sin x_;
struct sin y_;


#endif /* FUNCTION_H_ */
