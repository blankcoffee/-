#include "head.h"

//����ֵ
int abs(int num)
{
    if(num>0)
    {
        return num;
    }
    else
    {
        return (-num);
    }
}
//�������������Сֵ
int max_ary(int *array,int length)
{
    int max=array[0];
    int i;
    for(i=1;i<length;i++)
    {
        if(max<array[i])
        {
            max=array[i];
        }
    }
    return max;
}

int min_ary(int *array,int length)
{
    int min=array[0];
    int i;
    for(i=1;i<length;i++)
    {
        if(min>array[i])
        {
            min=array[i];
        }
    }
    return min;
}

//ƽ��ֵ�˲���
int avg_filter(int *ary,int length)
{
    int sum=0;
    int avg=0;
    int i=0;
    for(i=0;i<length;i++)
    {
        sum+=ary[i++];
    }
    avg=sum/length;
    return avg;
}

































