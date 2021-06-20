
#ifndef MPU6050_H_
#define MPU6050_H_

void mpu6050_init();
struct SAcc
{
    short a[3];
    short T;
} stcAcc;
struct SGyro
{
    short w[3];
    short T;
} stcGyro;
struct SAngle
{
    short Angle[3];
    short T;
} stcAngle;
struct SMag
{
    short h[3];
    short T;
} stcMag;

#endif /* MPU6050_H_ */
