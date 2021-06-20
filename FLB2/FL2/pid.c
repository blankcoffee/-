#include <head.h>

/********************************
 * ����PID���Ƕ����⻷�����ٶ����ڻ�
 *
 * ����->error ���->uk
 *
 * ������p��i,ip,ii,id;
 ********************************/
int pid_x()
{
    static int i;
    x.e=x.set-x.actl;//��ǰ�Ƕ����
    x.e_add+=x.e;//�Ƕ�������
    x.uk=x.p*x.e + x.i*x.e_add;//�⻷�Ƕ�PID���
    x.ie=x.uk-x.iactl;//�ڻ����ٶ����
    x.ie_add+=x.ie;//�ڻ����ٶ�������
    x.ie_d=x.ie-x.ie_last;//�ڻ����ٶ�΢��
    x.iuk=x.ip*x.ie+x.ii*x.ie_add+x.id*x.ie_d;//�ڻ�PID���
    i++;
    if(i==10)
    {
        x.ie_last=x.ie;//��¼��һ�ν��ٶ����ֵ
        i=0;
    }
    return(x.iuk);
}
int pid_y()
{
    static int i;
    y.e=y.set-y.actl;//��ǰ�Ƕ����
    y.e_add+=y.e;//�Ƕ�������
    y.uk=y.p*y.e + y.i*y.e_add;//�⻷�Ƕ�PID���
    y.ie=y.uk-y.iactl;//�ڻ����ٶ����
    y.ie_add+=y.ie;//�ڻ����ٶ�������
    y.ie_d=y.ie-y.ie_last;//�ڻ����ٶ�΢��
    y.iuk=y.ip*y.ie+y.ii*y.ie_add+y.id*y.ie_d;//�ڻ�PID���
    i++;
    if(i==10)
    {
        y.ie_last=y.ie;//��¼��һ�ν��ٶ����ֵ
        i=0;
    }
    return(y.iuk);
}























