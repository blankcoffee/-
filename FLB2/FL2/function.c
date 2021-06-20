#include"head.h"
///////////////////////////////////////////////
/*PID参数赋值
 * [0]->set,[1]->p,[2]->i,
 * [3]->ip,[4]->ii,[5]->id
 */
/*正弦参数赋值
 * s[0]->n
 * s[1]->x_.a,s[2]->x_.h
 * s[3]->y_.a,s[4]->y_.h
 *
 * x=amplitude_x*sin(alpha)+h;y=amplitude_y*sin(alpha+phase)+h
 */
//////////////////////////////////////////////
void parameter()
{
    //换题目时积分清零
    static int flag,flag_last;
    flag=function_flag;
    if(flag!=flag_last)
    {
        x.e_add=0;
        y.e_add=0;
        x.ie_add=0;
        y.ie_add=0;
    }
    flag_last=flag;

    alpha=(float)TimeCnt/PERIOD*2*pi;
    x_.a=s[1];
    x_.phase=alpha;
    x_.h=s[2];
    y_.a=s[3];
    y_.phase=alpha+pi*s[0];
    y_.h=s[4];
    x_p[0]=x_.a*sin(x_.phase)+x_.h;
    y_p[0]=y_.a*sin(y_.phase)+y_.h;

    x.actl=stcAngle.Angle[1];
    x.iactl=stcGyro.w[1];
    x.set=x_p[0];
    x.p=x_p[1];
    x.i=x_p[2];
    x.ip=x_p[3];
    x.ii=x_p[4];
    x.id=x_p[5];

    y.actl=stcAngle.Angle[0];
    y.iactl=stcGyro.w[0];
    y.set=y_p[0];
    y.p=y_p[1];
    y.i=y_p[2];
    y.ip=y_p[3];
    y.ii=y_p[4];
    y.id=y_p[5];

    m_x(pid_x());
    m_y(pid_y());
}
/*********************************************
 * 李萨如方法
 * x=amplitude_x*sin(alpha)+h;y=amplitude_y*sin(alpha+phase)+h
 * phase相位差
 * n=1/2,phase=pi/2,为圆
 * n=3/2,phase=3pi/2,为圆
 * 其他是椭圆
 * n=0 是线段，调整tan（angle）=sin（amplitude_x）/sin（amplitude_y）得到不同角度
**********************************************/
void control(void)
{
    switch(function_flag)
    {
    case 0:s[0]=0;s[1]=0;s[2]=0;s[3]=0;s[4]=0;break;//固定原点
    case 1:s[0]=0;s[1]=0;s[2]=1000;s[3]=0;s[4]=1000;break;//定点x=1000,y=1000
    case 2:s[0]=0;s[1]=0;s[2]=2000;s[3]=0;s[4]=2000;break;//定点x=2000,y=2000
    case 3:s[0]=0;s[1]=1000;s[2]=0;s[3]=1000;s[4]=0;break;//画45°直线（其他角度需要进行另外计算）
    case 4:s[0]=0.5;s[1]=1000;s[2]=0;s[3]=1000;s[4]=0;break;//画r=1000的圆
    case 5:s[0]=0.5;s[1]=2000;s[2]=0;s[3]=2000;s[4]=0;break;//画r=2000的圆
    case 6:s[0]=0.5;s[1]=1000;s[2]=0;s[3]=2000;s[4]=0;break;//画椭圆
    case 7:s[0]=0.5;s[1]=1000;s[2]=1000;s[3]=1000;s[4]=1000;break;//画圆心在（1000，1000）的r=1000的圆
    case 8:break;//自定义
    default:break;
    }
    parameter();
}

void test(void)
{
    pwm_2_4_duty(pwm_duty[0]);
    pwm_2_5_duty(pwm_duty[1]);
    pwm_2_6_duty(pwm_duty[2]);
    pwm_2_7_duty(pwm_duty[3]);
}





