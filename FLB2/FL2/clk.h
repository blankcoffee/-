#ifndef CLK_H_
#define CLK_H_

void clk_init();
//ʱ��Ƶ�ʽṹ��
struct clk
{
    uint32_t aclk;
    uint32_t bclk;
    uint32_t dco;
    uint32_t hsmclk;
    uint32_t smclk;
    uint32_t mclk;
}clk;

#endif /* CLK_H_ */
