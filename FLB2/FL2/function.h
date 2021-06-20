/*
 * function.h
 *
 *  Created on: 2021��4��30��
 *      Author: 23359
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

#define PERIOD 20000 //�������ڣ�ms��
#define pi 3.1415
extern float x_p[6];
extern float y_p[6];
extern int pwm_duty[4];//PWM��������
extern float s[5];
extern uint32_t TimeCnt;//��ʱ��
extern float alpha;
extern int function_flag;

void control();
void follow();
void parameter();//PID������ֵ
void test(void);


struct sin //x=a*sin(phase)+h
{
    int a;//���
    float phase;//��λ��
    int h;
};

struct sin x_;
struct sin y_;


#endif /* FUNCTION_H_ */
