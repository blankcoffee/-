
#ifndef PID_H_
#define PID_H_

//λ����PID�ṹ��

int pid_x(void);
int pid_y(void);

struct pid//����PID
{
    int set;//�⻷�Ƕ��趨ֵ
    int actl;//�⻷�Ƕȵ�ǰֵ
    int iactl;//�ڻ��Ǽ��ٶ�
    int e;//�⻷��ǰֵ
    int e_add,e_last,e_d;//�⻷���
    int ie;//�ڻ����ٶ����
    int ie_add,ie_last,ie_d;
    float p,i;//�⻷�ǶȲ���
    float ip,ii,id;//�⻷����

    int uk;//�⻷������
    int iuk;//�ڻ�������
};
struct pid x;
struct pid y;


#endif /* PID_H_ */
