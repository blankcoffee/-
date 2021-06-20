#include "head.h"
//UART配置
//P3.2-->RX
//P3.3-->TX
//波特率 115200
//波特率查询工具：http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html


const eUSCI_UART_ConfigV1 mpu6050_Config =
    {
            EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK=12000000
            6,                                     // BRDIV = 78
            8,                                       // UCxBRF = 2
            0x20,                                       // UCxBRS = 0
            EUSCI_A_UART_NO_PARITY,                  // No Parity
            EUSCI_A_UART_LSB_FIRST,                  // LSB First
            EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
            EUSCI_A_UART_MODE,                       // UART mode
            EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
    };

void mpu6050_init()
{

    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P3,GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);

       /* Configuring UART Module */
       MAP_UART_initModule(EUSCI_A2_BASE, &mpu6050_Config);

       /* Enable UART module */
       MAP_UART_enableModule(EUSCI_A2_BASE);

       /* Enabling interrupts */
       MAP_UART_enableInterrupt(EUSCI_A2_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);
       MAP_Interrupt_enableInterrupt(INT_EUSCIA2);
}

void EUSCIA2_IRQHandler(void)
{
    uint32_t status = UART_getEnabledInterruptStatus(EUSCI_A2_BASE);
    UART_clearInterruptFlag(EUSCI_A2_BASE, status);

    static unsigned char ucRxCnt = 0;
    static unsigned char ucRxBuffer[12];

    if(status & EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG)
    {
        UART_transmitData(EUSCI_A2_BASE, UART_receiveData(EUSCI_A2_BASE));

//MPU6050信号接收
        ucRxBuffer[ucRxCnt++]=UART_receiveData(EUSCI_A2_BASE);//接收字符
        if (ucRxBuffer[0]!=0x55) //数据头不对，则重新开始寻找0x55数据头
            {
                ucRxCnt=0;
                return;
            }
        if (ucRxCnt<11) {return;}//数据不满11个，则返回
        else
            {
                switch(ucRxBuffer[1])
                {
                    case 0x51:  stcAcc.a[0] = ((unsigned short)ucRxBuffer[3]<<8)|ucRxBuffer[2];
                                stcAcc.a[1] = ((unsigned short)ucRxBuffer[5]<<8)|ucRxBuffer[4];
                                stcAcc.a[2] = ((unsigned short)ucRxBuffer[7]<<8)|ucRxBuffer[6];
                                break;
                    case 0x52:  stcGyro.w[0] = ((unsigned short)ucRxBuffer[3]<<8)|ucRxBuffer[2];
                                stcGyro.w[1] = ((unsigned short)ucRxBuffer[5]<<8)|ucRxBuffer[4];
                                stcGyro.w[2] = ((unsigned short)ucRxBuffer[7]<<8)|ucRxBuffer[6];
                                break;
                    case 0x53:  stcAngle.Angle[0] = ((unsigned short)ucRxBuffer[3]<<8)|ucRxBuffer[2];
                                stcAngle.Angle[1] = ((unsigned short)ucRxBuffer[5]<<8)|ucRxBuffer[4];
                                stcAngle.Angle[2] = ((unsigned short)ucRxBuffer[7]<<8)|ucRxBuffer[6];
                                stcAngle.T = ((unsigned short)ucRxBuffer[9]<<8)|ucRxBuffer[8];
                                break;
                    case 0x54:  stcMag.h[0] = ((unsigned short)ucRxBuffer[3]<<8)|ucRxBuffer[2];
                                stcMag.h[1] = ((unsigned short)ucRxBuffer[5]<<8)|ucRxBuffer[4];
                                stcMag.h[2] = ((unsigned short)ucRxBuffer[7]<<8)|ucRxBuffer[6];
                                stcAngle.T = ((unsigned short)ucRxBuffer[9]<<8)|ucRxBuffer[8];
                                break;
                }
                ucRxCnt=0;
            }
    }
}










