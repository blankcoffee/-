#include <head.h>

/********************************
 * 串级PID，角度做外环，角速度做内环
 *
 * 输入->error 输出->uk
 *
 * 参数：p，i,ip,ii,id;
 ********************************/
int pid_x()
{
    static int i;
    x.e=x.set-x.actl;//当前角度误差
    x.e_add+=x.e;//角度误差积分
    x.uk=x.p*x.e + x.i*x.e_add;//外环角度PID输出
    x.ie=x.uk-x.iactl;//内环角速度误差
    x.ie_add+=x.ie;//内环角速度误差积分
    x.ie_d=x.ie-x.ie_last;//内环角速度微分
    x.iuk=x.ip*x.ie+x.ii*x.ie_add+x.id*x.ie_d;//内环PID输出
    i++;
    if(i==10)
    {
        x.ie_last=x.ie;//记录上一次角速度误差值
        i=0;
    }
    return(x.iuk);
}
int pid_y()
{
    static int i;
    y.e=y.set-y.actl;//当前角度误差
    y.e_add+=y.e;//角度误差积分
    y.uk=y.p*y.e + y.i*y.e_add;//外环角度PID输出
    y.ie=y.uk-y.iactl;//内环角速度误差
    y.ie_add+=y.ie;//内环角速度误差积分
    y.ie_d=y.ie-y.ie_last;//内环角速度微分
    y.iuk=y.ip*y.ie+y.ii*y.ie_add+y.id*y.ie_d;//内环PID输出
    i++;
    if(i==10)
    {
        y.ie_last=y.ie;//记录上一次角速度误差值
        i=0;
    }
    return(y.iuk);
}























