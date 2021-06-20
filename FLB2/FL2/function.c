#include"head.h"
///////////////////////////////////////////////
/*PID������ֵ
 * [0]->set,[1]->p,[2]->i,
 * [3]->ip,[4]->ii,[5]->id
 */
/*���Ҳ�����ֵ
 * s[0]->n
 * s[1]->x_.a,s[2]->x_.h
 * s[3]->y_.a,s[4]->y_.h
 *
 * x=amplitude_x*sin(alpha)+h;y=amplitude_y*sin(alpha+phase)+h
 */
//////////////////////////////////////////////
void parameter()
{
    //����Ŀʱ��������
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
 * �����緽��
 * x=amplitude_x*sin(alpha)+h;y=amplitude_y*sin(alpha+phase)+h
 * phase��λ��
 * n=1/2,phase=pi/2,ΪԲ
 * n=3/2,phase=3pi/2,ΪԲ
 * ��������Բ
 * n=0 ���߶Σ�����tan��angle��=sin��amplitude_x��/sin��amplitude_y���õ���ͬ�Ƕ�
**********************************************/
void control(void)
{
    switch(function_flag)
    {
    case 0:s[0]=0;s[1]=0;s[2]=0;s[3]=0;s[4]=0;break;//�̶�ԭ��
    case 1:s[0]=0;s[1]=0;s[2]=1000;s[3]=0;s[4]=1000;break;//����x=1000,y=1000
    case 2:s[0]=0;s[1]=0;s[2]=2000;s[3]=0;s[4]=2000;break;//����x=2000,y=2000
    case 3:s[0]=0;s[1]=1000;s[2]=0;s[3]=1000;s[4]=0;break;//��45��ֱ�ߣ������Ƕ���Ҫ����������㣩
    case 4:s[0]=0.5;s[1]=1000;s[2]=0;s[3]=1000;s[4]=0;break;//��r=1000��Բ
    case 5:s[0]=0.5;s[1]=2000;s[2]=0;s[3]=2000;s[4]=0;break;//��r=2000��Բ
    case 6:s[0]=0.5;s[1]=1000;s[2]=0;s[3]=2000;s[4]=0;break;//����Բ
    case 7:s[0]=0.5;s[1]=1000;s[2]=1000;s[3]=1000;s[4]=1000;break;//��Բ���ڣ�1000��1000����r=1000��Բ
    case 8:break;//�Զ���
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





