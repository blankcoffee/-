
#ifndef PID_H_
#define PID_H_

//位置型PID结构体

int pid_x(void);
int pid_y(void);

struct pid//串级PID
{
    int set;//外环角度设定值
    int actl;//外环角度当前值
    int iactl;//内环角加速度
    int e;//外环误差当前值
    int e_add,e_last,e_d;//外环误差
    int ie;//内环角速度误差
    int ie_add,ie_last,ie_d;
    float p,i;//外环角度参数
    float ip,ii,id;//外环参数

    int uk;//外环输出结果
    int iuk;//内环输出结果
};
struct pid x;
struct pid y;


#endif /* PID_H_ */
