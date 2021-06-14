#include <16f877a.h>
#fuses xt,nowdt,noprotect,nobrownout,nolvp,noput,nowrt,nodebug,nocpd
#use delay(clock=4000000)
#define use_portb_lcd TRUE
#include<lcd.c>
#use rs232(baud=9600,xmit=pin_c6,rcv=pin_c7,parity=N,stop=1)
char alinan[10],ver[10];
int verilecek;
void main()
{
setup_psp(PSP_DISABLED);
setup_timer_1(T1_DISABLED);
SETUP_timer_2(T2_DISABLED,0,1);
setup_adc_ports(no_analogs);
setup_adc(adc_off);
setup_ccp1(ccp_off);
setup_ccp2(ccp_off);
lcd_init();
   while(TRUE)
   {
   verilecek=input_a();
  sprintf(ver,"%d",verilecek);
   puts(ver);
   gets(alinan);
   printf(lcd_putc,"\f\ralinan deger %s",alinan);
      delay_ms(1000);
   }}
