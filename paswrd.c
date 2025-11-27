#include<lpc21xx.h>
#include<string.h>
#include"header.h"
#define led 255
u8 flag,a[10];
int main()
{
u8 p[10]="123456";
u8 i,j;
uart0_init(9600);
lcd_init();
uart0_interrupt();
IODIR0|=led;
IOSET0=led;
uart0_tx_string("ENTER PASSSWORD: ");
lcd_string("ENTER PASSWORD");
while(1)
{
if(flag==1)
{
flag=0;
if(strcmp(a,p)==0)
{
lcd_cmd(0x01);
lcd_string("ACCESS GRANTED");
uart0_tx_string("\r\nACCESS GRANTED");
IOCLR0=led;
delay_ms(600);
}
else
{
lcd_cmd(0x01);
lcd_string("ACCESS DENIED");
uart0_tx_string("\r\nACCESS DENIED");
for(j=0;j<3;j++)
{
IOCLR0=led;
delay_ms(400);
IOSET0=led;
delay_ms(400);
}
}
lcd_cmd(0x01);
lcd_string("ENTER PASSWORD");
uart0_tx_string("\r\nENTER PASSWORD: ");
}
}
}

