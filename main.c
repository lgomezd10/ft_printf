/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-d <lgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:12:20 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/03/02 16:23:06 by lgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include <float.h>
#include <limits.h>
#define DBL_INF    0x7FF0000000000000
void check_nbr(char *str, int dato)
{
    static int item = 0;
    int len;

    item++;
    printf("\n%d: %s\n", item, str);
    len = ft_printf(str, dato);
    printf("*len: %d\n", len);
    len = printf(str, dato);
    printf("*len: %d\n", len);
}

void check_str(char *str, char *dato)
{
    static int item = 0;
    int len;

    item++;
    printf("\n%d: %s\n", item, str);
    len = ft_printf(str, dato);
    printf("*len: %d\n", len);
    len = printf(str, dato);
    printf("*len: %d\n", len);
}

void check_pointer(char *str, void *dato)
{
    static int item = 0;
    int len;

    item++;
    printf("\n%d: %s\n", item, str);
    len = ft_printf(str, dato);
    printf("*len: %d\n", len);
    len = printf(str, dato);
    printf("*len: %d\n", len);
}

void check_char(char *str, char dato)
{
    static int item = 0;
    int len;

    item++;
    printf("\n%d: %s\n", item, str);
    len = ft_printf(str, dato);
    printf("*len: %d\n", len);
    len = printf(str, dato);
    printf("*len: %d\n", len);
}

void check_percent(char *str)
{
    static int item = 0;
    int len;

    item++;
    printf("\n%d: %s\n", item, str);
    len = ft_printf(str);
    printf("*len: %d\n", len);
    len = printf(str);
    printf("*len: %d\n", len);
}

void check_double(char *str, double dato)
{
    static int item = 0;
    int len;

    item++;
    printf("\n%d: %s\n", item, str);
    len = ft_printf(str, dato);
    printf("*len: %d\n", len);
    len = printf(str, dato);
    printf("*len: %d\n", len);
}

void check_long(char *str, long int dato)
{
    static int item = 0;
    int len;

    item++;
    printf("\n%d: %s\n", item, str);
    len = ft_printf(str, dato);
    printf("*len: %d\n", len);
    len = printf(str, dato);
    printf("*len: %d\n", len);
}

int main(void)
{
    int len;

    len = 0;

    static char *s_hidden = "hi low\0don't print me lol\0";
    check_str("%09s", s_hidden);
    check_char("%09c", 'a');
/********BONUS***********/
printf("********BONUS**********\n");
/*
    check_nbr("%#x", 0);
    check_percent("%#");
    check_nbr("%#d", 0);

    check_nbr("%#x", 300);
    check_nbr("%#X", 300);

    check_nbr("%-#x", 300);
    check_nbr("%0#x", 300);
    check_nbr("%#0x", 300);
    check_nbr("%#010x", 300);
    check_nbr("%+d", 300);
    check_nbr("%+d", -300);
    check_nbr("%+010d", 300);
    check_nbr("%+010d", -300);
    check_nbr("%010d", 300);
    check_nbr("%010d", -300);
    check_nbr("%+u", 300);
    check_nbr("%+u", -300);
    check_str("%+s", "hola");
    check_nbr("%+010x", 300);


    check_nbr("% 05d", 43);
    check_nbr("%07d", -54);
    check_nbr("% d", 55);
    check_nbr("% d", -55);
    check_nbr("% +d", 55);
    check_nbr("% +d", -55);
*/
/*
    check_nbr("% u", 55);
    check_nbr("% u", -55);
    check_nbr("% x", 55);
    check_nbr("% x", -55);
    check_nbr("% p", 55);
    check_nbr("%+p", 55);
    check_nbr("%+5.7p", 55);
    check_nbr("%020p", 55);
    check_nbr("%020.10p", 55);
    check_percent("prueba \" hola \" tu");
    check_percent("prueba \% tu");
    check_percent("prueba \\ tu");
*/

printf("************ REAL ***********\n");

/*
    float f1;
    float f2;
    f1 = 5.2;
    f1 *= 10;
    printf("%f\n", f1);
    f2 = (int)f1;
    printf("%f\n", f2);
    f1 = f1 - f2;
    len = (int)(f1 * 10);
    printf("%d\n", len);
*/

//ft_printf("%02f\n", -0.0);

/*
double cosa = -0.0;
double cosa2 = -0.0;
int pos;

if (1/cosa == 1/0.0)
    pos = 1;
else
    pos = 0;

printf("valor pos: %d\n", 1/cosa == 1/0.0);
*/
/*
int isPositiveZero(double a) {
    return 1/a == 1/0.0;
}
*/

/*
printf("para ya %lld\n", ((long long int)cosa & (long long int)cosa2));
if (((long long int)cosa & (long)cosa2) == 1)
    printf("no hay nada que hacer\n");
cosa *= 1;
printf("%f\n", cosa);


int cosaint = -5;
int signo;
int sign_bit;
// = ((unsigned int)cosa) >> 31;
printf("size %lu\n", sizeof(int));
ft_memcpy(&signo, &cosa, sizeof(int));
sign_bit = ((unsigned int)signo) >> 31;

printf("signo loco %d num: %d\n", sign_bit, signo);
*/

/*
    double cosa;
    unsigned int cosaint;
    unsigned int desp;

    cosa = -1.0;

    cosaint = -0;
    desp = (cosaint >> 3);
    printf("cosa %u\n", desp);
    */
/*
   check_percent("%#");
check_percent("%hh");
check_percent("%h");
check_percent("%ll");
check_percent("%l");

len = ft_printf("%*.*d", 10, -20, 453);
printf("*len: %d\n", len);
len = printf("%*.*d", 10, -20, 453);
printf("*len: %d\n", len);
len = ft_printf("%*.*f", 3, -5, 45.62);
printf("*len: %d\n", len);
len = printf("%*.*f", 3, -5, 45.62);
printf("*len: %d\n", len);
len = ft_printf("%*.*f", 3, 5, 45.62);
printf("*len: %d\n", len);
len = printf("%*.*f", 3, 5, 45.62);
printf("*len: %d\n", len);
check_nbr("%10d\n", 43);
check_str("%10.100s", "");
*/
/*
printf("%.2000g\n", DBL_MIN);
ft_printf("%.2000g\n", DBL_MIN);
ft_printf("%.2000g\n", -DBL_MIN);
printf("%.0g\n", 0.000000000000000000000000000049);
ft_printf("%.0g\n", 0.000000000000000000000000000049);
printf("%.0g\n", DBL_MAX);
ft_printf("%.0g\n", DBL_MAX);
*/
/*
printf("%g", 0.000039);
check_double("%g", 0.000039);
check_double("%g", 23.00041);
check_double("%g", 9873.000001);
printf("printf %.2000g\n", -DBL_MIN);
check_double("%.2000g", -DBL_MIN);
ft_printf("%.0g\n", DBL_MAX);

check_nbr("%llu\n", -1);
printf("a ver %llu\n", (long long unsigned int)-1);
*/
/*
double special; *((unsigned long *)(&special)) = DBL_INF;
printf("PRUEBA: %g", 9218868437227405318.0);
printf("G:%g\n", special);
ft_printf("G: %g\n", special);
*/
/*
printf("pF: %f\n", special);
ft_printf("fF: %f\n", special);
*/

/*
check_nbr("%#X", 345);
check_nbr("%#x", 345);
static double			mx_f = 0.625;
static long				mx_li =  4223372036854775800;
static long long		mx_lli = 3223372036654775200;
static short			mx_hi = -3244;
static char				mx_hhi = 'F';
static unsigned int		mx_u = 235;
static char				mx_c = 'G';
static char			   *mx_s = "Hello, World!";
static int				mx_i = 42;
short int   si = 5;
long int li = 4223372036854775800;

ft_printf("%hd %ld %hhd %ld\n", si, li, si, li);
printf("%hd %ld %hhd %ld\n", si, li, si, li);
system("leaks a.out");
*/
/*
printf("%ld\n", 9218868437227405318);
*/
//ft_printf("%.0g\n", DBL_MAX);
/*
check_double("%g", -0.99999949);


   check_double("%#-5.3g", 0.0);

check_double("%#-5.3g", 7.3);
check_double("%#-5.6g", 7.3);
check_double("%#-5.3g", -7.3);
check_double("%#-5.6g", -7.3);
check_double("%#.0g", 0.0);
check_double("%#.0g", -0.0);
check_double("%.0g", -0.0);
check_double("%+.0g", -0.0);
check_double("%#-.0g", -0.0);
check_double("%#.0g", -0.0);
check_double("%#.0g", -0.0);
check_double("%#-5.3g", -0.0);
check_double("%#5.3g", -0.0);

check_double("%g", 0.999999);

check_nbr("% 042.41hhd", 45);

  check_double("%.0g", -0.00032);
    check_double("%.0g", 0.0032);
    check_double("%.0g", 0.003);
    check_double("%.0g", 0.0003);
    check_double("%.0g", 0.00003);
    check_double("%.0g", 0.000003);
    check_double("%g", 0.003);
    check_double("%g", 0.0003);
    check_double("%g", 0.00003);
    check_double("%g", 0.000003);
    check_double("%g", -0.99999949);
    check_double("%.0f", 2.5);
    check_double("%.0f", -5.5);
    check_double("%.0f", 5.5);
    check_double("%.0f", 1.5);
*/
/*
check_nbr("^.^/% 042.41hd^.^/", 1181573488);
check_nbr("^.^/% 042.41hhd^.^/", 1181573488);
check_nbr("^.^/%22.2hu^.^/", 1181573488);
check_nbr("^.^/%22.2hx^.^/", 1181573488);
check_nbr("%8.2hu", 1083232574);
check_nbr("%22.2hu", 1181573488);
check_nbr("%22.2hu", 1083232574);
check_char("^.^/%16lc^.^/", (char)56);
check_char("%lc", (char)173);
check_char("^.^/%16c^.^/", (char)172);
check_char("^.^/%16c^.^/", (char)56);
check_char("^.^/%16lc^.^/", (char)56);
*/
/*
check_double("%.8g", 23.375094499);
 check_double("%.8g", -985.765426499);
 check_double("%.8g", 0.0894255);
 check_double("%.8g", -56.2012685);
 check_double("%.8g", 43.4399999);
 check_double("%.8g", -5.0299999);
 check_double("%.8g", 43.43999949);
 check_double("%.8g", -5.02999949);
 check_double("%.8g", 1.99999949);
 check_double("%.8g", -0.99999949);
 check_double("%.8g", 3.9999999);
 check_double("%.7g", 23.375094499);
 check_double("%.7g", -985.765426499);
 check_double("%.7g", 0.0894255);
 check_double("%.7g", -56.2012685);
 check_double("%.7g", 43.4399999);
 check_double("%.7g", -5.0299999);

    check_double("%e", 444444.444444444444);
    check_double("%e", 4.44444444444444444);    
    check_double("%10.2e", 444444.444444444444);
    check_double("%10.2e", 0.000444444444);
    

    check_double("%e", 444444.444444444444);    
    check_double("%10.2e", 444444.444444444444);
    check_double("%e", 9234.123456789);
    check_double("%10.5e", 9234.123456789);
    check_double("%30.20e", 9234.123456789);
    check_double("%.20e", 9234.123456789);
    check_double("%30e", 9234.123456789);
    check_double("%10.20f", 9234.123456789);
    check_double("%e", 9223372036854775807);
    check_double("%g", 444444.444444444444);
    check_double("%10.2g", 444444.444444444444);
   
    check_double("%.3f", 0.4255);
    check_double("%10.3f", 1.6685);
    check_double("%10.3f", 9.9996);
    check_double("this %.0f float", 1.6);
    check_double("%.0f", -3.85);
    check_double("%.0f", 573.924);    
    check_double("%.10f", 0.87650894255);
    check_double("%.16f",  0.999999999999999900);
    check_double("%-05.0f", 7.3);
    check_double("%-5.0f", 7.3);
    check_double("%-05.0f", 0.0);
    check_double("%-05.0f", -0.0);    
    check_double("%#.0f", 0.0);
    check_double("%#.0f", -0.0);
    check_double("%#.0f", 7.4);
    check_double("%#.0f", -7.4);
    check_double("%0-5.0f", 0.0);
    check_double("%0-5.1f", -7.3);
    check_double("%#-5.0f", 0.0);    
    check_double("%+05.3f", 0.0);

    check_double("%g", 44.666);
    check_double("%g", 444444.666);
    check_double("%g", 44.66666);
    check_double("%g", 44.66600);
    check_double("%g", 44.66606);
    check_double("%20.5g", 44.666);
    check_double("%020.5g", 44.666);
    check_double("%g", 4444444.666);
    check_double("%g", -44.66606);
    check_double("%20.5g", -44.666);
    check_double("%020.5g", -44.666);
    check_double("%g", 0.00567);
    check_double("%g", 0.050);
    check_double("%g", 0.000000050);
    check_double("%g", 0.000050);
    check_double("%g", 0.00050);
    check_double("%g", 0.0);
    check_double("%g", 4.5684);
    check_double("%g", 0.999999);
    check_double("%g", 0.9999990);
    check_double("%g", 0.66666666);
    check_double("%g", 1.66666666);    

   check_double("%g", 0.0);
   check_double("%g", 23.00042);
   check_double("%g", 0.001);
   check_double("%g", 0.0001);
   check_double("%g", 0.00001);
   check_double("%g", 0.000001);
   check_double("%g", -56.2012685);
   check_double("%g", 56.2012685);
   check_double("%g", 9873.000001);
   check_double("%g", -0.99999949);
   check_double("%g", 0.99999949);
   check_double("%g", 0.05553332249);

   check_double("%g", 0.0894255);
   check_double("%g", 0.00894255);
   check_double("%10.0g", 0.00894255);
   check_double("%10.3g", 456.0894255);
   check_double("%10.2g", 423.5684);
    check_double("%g", -4444444.666);
    check_double("%g", 4444444.666);

    check_double("%.0g", 573.924);
    check_double("%.0g", -958.125);
    check_double("%.0g", 23.00041);
    check_double("%.0g", -0.00032);
    check_double("%.0e", -958.125);
    check_double("%5.4e", -999.995);
    check_double("%.1g", 573.924);
    check_double("%.1g", -958.125);
    check_double("%.1g", 23.00041);

    check_double("%.8g", -56.2012685);
    check_double("%.8g", -56.20126856);
    check_double("%.8g", -56.20126854);
    check_double("%.8g", -56.20126855);
    check_double("%10.20g", 5436433546464364);

    check_double("%.8g", -56.2012685000006);
    check_double("%.8g", -56.20126849900);
    check_double("%.8g", -56.2012684999999999999999999);

    check_double("%g", 0.0005654557);
    check_double("%g", 0.0005654002);
    check_double("%g", 10.0005654002);
    check_double("%g", 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000005654002);


    system("leaks a.out");
  */  
/*

    check_double("%.0f", 0.0);
    check_double("%5.0f", 0.0);
    check_double("%5.f", 0.0);
    check_double("%e", 0.0);
    check_double("%e", 10.00556);
    check_double("%e", 5.5);
    check_double("%e", 5.5);
    check_double("%10.0e", 0.0);
    check_double("%10.0e", -0.0);
    check_double("%+10.0e", 0.0);
    check_double("%#10.0e", 0.0);
   */
  /*
   check_double("%f", 23.375094499);
   check_double("%f", -985.765426499);
   check_double("%f", -56.2012685);
   check_double("%.10f", -985.2459765426499);
   
  
    check_double("%f", 9.9999999);
    check_double("%f", 9.8999999);
    */
/*
    check_double("%f", 573.924);
    check_double("%f", 573.923999);   
    check_double("%.2f", 573.34552);  
    check_double("%.2f", 573.34502);  
    check_double("%.4f", 573.916256);
    check_double("%.4f", 573.917250);
    check_double("%.4f", 573.908250); 
    check_double("%.4f", 573.906250);
    check_double("%.4f", 573.905250);
    
    check_double("%.4f", 573.904250); 
    check_double("%10.30f", 444444.5555555545543453);
    check_double("%10.32f", 444444.5555555545543453);
    check_double("%10.28f", 444444.5555555545543453);

    check_double("%f", -0.0);    
    check_double("%f", 57345.924);
    check_double("%f10.0", 57345.99999);

    
    check_double("%f", 444444.444444444444);
    check_double("%10.2f", 444444.444444444444);
    check_double("%10.2f", 444444.5555555);
    
    check_double("%10.2f", -444444.5555555);
    check_double("%015.2f", -444444.5555555);
    check_double("%f", 55345.123456789);
    check_double("%f", 55345.123456123);
    check_double("%f", 55345.823457523);
    check_double("%f", 55345.823457223);

    check_double("%f", (double)9223372036854775807);
    check_double("%f", -9223372036854775809);
    check_double("%f", 9223372036.854775);
    check_double("%f", 18446744073709551.615);
    check_double("%30.30f", 18446744073709551.615);
    check_double("%+10.2f", 5.20);

    check_double("%g\n", 1.00000000000000000006);

  */
/*
    check_double("%10.0e", 5.5);
    check_double("%10.0g", 5.5);
    check_double("%10.0f", 65.5);
    check_double("%10.1f", 6.555);
*/
printf("********** l ll h hh **********\n");
/*
    int a = 'a';
    len = printf("%hhcFIN\n", (char)45);
    printf("*len: %d\n", len);
    len = ft_printf("%hhcFIN\n", (char)45);
    printf("*len: %d\n", len);
    len = printf("%cFIN\n", (char)45);
    printf("*len: %d\n", len);
    len = ft_printf("%cFIN\n", (char)45);
    printf("*len: %d\n", len);
    len = printf("%hhsFIN\n", "hola");
    printf("*len: %d\n", len);
    len = ft_printf("%hhsFIN\n", "hola");
    printf("*len: %d\n", len);
    len = printf("%hhdFIN\n", (char)45);
    printf("*len: %d\n", len);
    len = ft_printf("%hhdFIN\n", (char)45);
    printf("*len: %d\n", len);
    len = printf("%hhdFIN\n", (char)-45);
    printf("*len: %d\n", len);
    len = ft_printf("%hhdFIN\n", (char)-45);
    printf("*len: %d\n", len);
    len = printf("%dFIN\n", (char)45);
    printf("*len: %d\n", len);
    len = ft_printf("%dFIN\n", (char)45);
    printf("*len: %d\n", len);
   len =  printf("%hdFIN\n", (short)385);
   printf("*len: %d\n", len);
    len = ft_printf("%hdFIN\n", (short)385);
    printf("*len: %d\n", len);
    len = printf("%hdFIN\n", (short)-385);
    printf("*len: %d\n", len);
    len = ft_printf("%hdFIN\n", (short)-385);
    printf("*len: %d\n", len);
*/
/*
    ft_printf("PRUEBA i y d\n");
    ft_printf("uno %d dos %d tres\n", 8, 20);
    ft_printf("uno %d dos %c tres\n", 8, 'z');
    ft_printf("uno %s dos %c tres\n", "pepito", 'z');
    ft_printf("uno %9d dos %09d tres\n", 30, 30);
    ft_printf("funo %*i dos %0*d tres\n", 9, 30, 3, 30);
    printf("puno %*i dos %0*d tres\n", 9, 30, 3, 30);
    printf("pprueba de punto %.9d uno\n", 30);
    ft_printf("fprueba de punto %.9d uno\n", 30);
    ft_printf("PRUEBA S\n");
    ft_printf("uno %s dos %s tres\n", "string1", "string2");
    len = printf("puno %15s dos %-15s tres %2s cuatro %.2s cinco\n", "string1", "string2", "string3", "string4");
    printf("len: %d\n", len);
    len = ft_printf("funo %15s dos %-15s tres %2s cuatro %.2s cinco\n", "string1", "string2", "string3", "string4");
    printf("len: %d\n", len);
*/
/*
    int x = -1;
    unsigned int z = (unsigned int)x;
    printf("para el x: %d, tenemos %u\n", x, z);
    printf("PRUEBA X\n");
    printf("Hexa negativo: %x\n", -1);
    printf("Hexa negativo: %u\n", -1);
*/

    printf("***********HEX**********\n");
/*
    check_nbr("%x", 265);
    check_nbr("%x", 15);
    check_nbr("%x", 1000);
    check_nbr("%x", -265);
    check_nbr("%x", -15);
    check_nbr("%x", -1000);
    check_nbr("%20x", -1000);
    check_nbr("%20.18x", -1000);
    check_nbr("%-20x", -1000);
    check_nbr("%-20.18x", -1000);
    check_nbr("%20x", 1000);
    check_nbr("%20.18x", 1000);
    check_nbr("%-20x", 1000);
    check_nbr("%-20.18x", 1000);
    check_nbr("%20.2x", 1000);
    check_nbr("%-20x", 1000);
    check_nbr("%-20.2x", 1000);
    check_nbr("%020.18x", 1000);
    check_nbr("%-020x", 1000);
    check_nbr("%-020.2x", 1000);
    check_nbr("%-020.2x", 0);
    check_nbr("%-020.X", 0);
    check_nbr("%-020.X", 1000);
    check_nbr("%-020.X", -1000);
    check_nbr("%-#020.X", 1000);
    check_nbr("%-#020.X", -1000);
    check_nbr("%#020X", -1000);
*/
/*
    check_nbr("%X", 265);
    check_nbr("%X", 15);
    check_nbr("%X", 1000);
    check_nbr("%X", -265);
    check_nbr("%X", -15);
    check_nbr("%X", -1000);
    check_nbr("%20X", -1000);
    check_nbr("%20.18X", -1000);
    check_nbr("%-20X", -1000);
    check_nbr("%-20.18X", -1000);
    check_nbr("%20X", 1000);
    check_nbr("%20.18X", 1000);
    check_nbr("%-20X", 1000);
    check_nbr("%-20.18X", 1000);
    check_nbr("%20.2X", 1000);
    check_nbr("%-20X", 1000);
    check_nbr("%-20.2X", 1000);
    check_nbr("%020.18X", 1000);
    check_nbr("%-020X", 1000);
    check_nbr("%-020.2X", 1000);
    check_nbr("%-020.2X", 0);
    check_nbr("%-020.X", 0);
    check_nbr("%-020.X", 1000);
    check_nbr("%-020.X", -1000);
*/

    printf("******** LONG *************\n");
/*
    static char 		ch_pos_1 = 100, ch_neg_1 = -87;
    static short		sh_pos_1 = 3047, sh_neg_1 = -8875;
    static int			i_pos_1 = 878023;
    static long			l_pos_1 = 22337203685477, l_neg_1 = -22337203685477;
    static long long	ll_pos_1 = 22337203685477, ll_neg_1 = -22337203685477;
    static long			lmax	= 9223372036854775807;
    static long			lmin	= -9223372036854775807;
    static long long	llmax = 9223372036854775807;
    static long long	llmin = -9223372036854775807ll;
    static unsigned char 		uch_pos_1 = 100;
    static unsigned short		ush_pos_1 = 3047;
    static unsigned int		ui_pos_1 = 878023;
    static unsigned long		ul_pos_1 = 22337203685477;
    static unsigned long long	ull_pos_1 = 22337203685477;
    static unsigned long long  ullmax = 9223372036854775807;
    static unsigned long  		ulmax = 9223372036854775807;

    check_long("%d", ullmax);
    printf("*%d\n", llmax);
    check_long("%ld", ullmax);
    check_long("%lld", llmax);
    check_long("%lu", ul_pos_1);
    check_long("%u", ul_pos_1);
    check_long("%llu", ul_pos_1);
*/
    printf("*******DIGITS***********\n");
/*
    check_nbr("this %d number", -267);
    check_nbr("%d", -1);
    check_nbr("%7d", -14);
    check_nbr("%5d", -2562);
    check_nbr("%4d", -2464);

    check_nbr("%-7d", -14);
    check_nbr("%-5d", -2562);
    check_nbr("%-4d", -2464);
    check_nbr("%.3d", 13862);
    check_nbr("%.3d",-23646);
    check_nbr("%8.3d", 8375);
    check_nbr("%10.8d", 8375);
    check_nbr("%-10.8d", 8375);
    check_nbr("%-010.8d", 8375);
    check_nbr("%10.8d", -8375);
    check_nbr("%-10.8d", -8375);
    check_nbr("%-010.8d", -8375);
    check_nbr("%8.3d", -8473);
    check_nbr("%03.3d", 6983);
    check_nbr("%.0d", 1);
    check_nbr("%9.6d", -355);
    check_nbr("%9.2d", -355);
    check_nbr("%09.6d", -355);
    check_nbr("%.6d", -3);
    check_nbr("%07d", -54);
    check_nbr("%09d", -265);
    check_nbr("%.9d", -265);
    check_nbr("%9d", -265);
    check_nbr("%-9d", -265);
    check_nbr("%30.20d", -2147483648);
    check_nbr("%020d", -2147483648);
    check_nbr("%5d", 0);
    check_nbr("%.0d", 0);
    check_nbr("%5.2d", 0);
    check_nbr("%5.0d", 0);
    check_nbr("%5d", 0);
*/
    printf("********* UNSIGNED **********\n");
/*
    check_nbr("%u", 265);
    check_nbr("%u", 15);
    check_nbr("%u", 1000);
    check_nbr("%u", -265);
    check_nbr("%u", -15);
    check_nbr("%u", -1000);
    check_nbr("%20u", -1000);
    check_nbr("%20.18u", -1000);
    check_nbr("%-20u", -1000);
    check_nbr("%-20.18u", -1000);
    check_nbr("%20u", 1000);
    check_nbr("%20.18u", 1000);
    check_nbr("%-20u", 1000);
    check_nbr("%-20.18u", 1000);
    check_nbr("%20.2u", 1000);
    check_nbr("%-20u", 1000);
    check_nbr("%-20.2u", 1000);
    check_nbr("%020.18u", 1000);
    check_nbr("%-020u", 1000);
    check_nbr("%-020.2u", 1000);

    ft_printf("funo %*u dos\n", 20, -32769);
    printf("puno %*u dos\n", 20, -32769);
    unsigned int h = 3678;
    ft_printf("funo %*u dos\n", 20, h);
    printf("puno %*u dos\n", 20, h);

    check_nbr("%lu", -343566);
    check_nbr("%llu", -343566);
    check_nbr("%hu", -343566);
    check_nbr("%hhu", -343566);
    check_nbr("% u", 343566);
    check_nbr("%+u", 343566);
    check_nbr("%#20.15u", 343566);
    check_nbr("%#020.0u", 0);
*/
    printf("**********STR*************\n");

/*
    check_str("*%.03s", NULL);
    check_str("*%3.s", NULL);
    check_str("*%10.s", NULL);
    check_str("*%-3.s", NULL);
    check_str("*%-8.s", NULL);
    check_str("*%3.1s", NULL);
    check_str("*%9.1s", NULL);
    check_str("*%-3.1s", NULL);
    check_str("*%-9.1s", NULL);
    check_str("%7.5s", "yolo");    
    check_str("%7.5s", "bombastic");
    check_str("%-7.5sFIN", "yolo");
    check_str("%7.3s", "yolo");
    check_str("%3.5s", "yolo");
    check_str("%3.0s", "yolo");
    check_str("%3.s", "yolo");
    check_str("%020.06s", "hello world");
    check_str("%030.020s", "hello world");
    check_str("%-030.020s", "hello world");
    check_str("%030s", "hello world");
    check_str("%30.020s", "hello world");
    check_str("%020s", "hello world");
    check_str("%-020s", "hello world");
    */
   /*
    check_char("%09lc", 'a');
    check_char("%-09lc", 'a');

    check_char("%09c", 172);
    check_char("%-09c", 172);
    check_char("42%-2lc42", 'I');

    check_percent("%09%");
    check_percent("%-09%");
    */

/*
    check_str("%+- 06.06s", "hello world");
    check_str("%+- \t 06.06s", "hello world");
    check_str("%+-  -06.06s", "hello world");
    check_str("%- \t -06.06s", "hello world");
    check_str("%- \t 06.06s", "hello world");
    check_str("% \t -06.06s", "hello world");
    check_str("%-  -06.06s", "hello world");
    check_str("%- jk-06.06s", "hello world");
    check_str("%- jkss", "hello world");
*/
/*
    printf("t %d n %d v %d f %d r %d\n", '\t', '\n', '\v', '\f', '\r');
    
*/

/*
    len = ft_printf("%*s", -32, "abc");
    printf("*len: %d\n", len);
    len = printf("%*s", -32, "abc");
    printf("*len: %d\n", len);

    len = ft_printf("%*.*s", 32, -5, "abc");
    printf("*len: %d\n", len);
    len = printf("%*.*s", 32, -5, "abc");
    printf("*len: %d\n", len);

    len = ft_printf("%*.*s", 32, -2, "abc");
    printf("*len: %d\n", len);
    len = printf("%*.*s", 32, -2, "abc");
    printf("*len: %d\n", len);

    len = ft_printf("%*.*s", 32, 2, "abc");
    printf("*len: %d\n", len);
    len = printf("%*.*s", 32, 2, "abc");
    printf("*len: %d\n", len);

    len = ft_printf("%*d", -32, 55);
    printf("*len: %d\n", len);
    len = printf("%*d", -32, 55);
    printf("*len: %d\n", len);

     len = ft_printf("%*.*d", 10, -5, 55);
    printf("*len: %d\n", len);
    len = printf("%*.*d", 10, -5, 55);
    printf("*len: %d\n", len);

    len = ft_printf("%*.*d", 10, 5, 55);
    printf("*len: %d\n", len);
    len = printf("%*.*d", 10, 5, 55);
    printf("*len: %d\n", len);

    check_str("%32s", "abc");
*/
/*
 
    len = ft_printf("%3.7s%3.7s", "hello", "world");
    printf("*len: %d\n", len);
    len = printf("%3.7s%3.7s", "hello", "world");
    printf("*len: %d\n", len);

    len = ft_printf("%7.3s%7.7s", "hello", "world");
    printf("*len: %d\n", len);
    len = printf("%7.3s%7.7s", "hello", "world");
    printf("*len: %d\n", len);

    len = ft_printf("%3.3s%3.7s", "hello", "world");
    printf("*len: %d\n", len);
    len = printf("%3.3s%3.7s", "hello", "world");
    printf("*len: %d\n", len);
*/
 /*  
    
    ft_printf("funo %*s dos\n", 20, "hola");
    printf("puno %*s dos\n", 20, "hola");
    len = ft_printf("funo %.*s dos\n", 2, "hola");
    printf("len: %d\n", len);
    len = printf("puno %.*s dos\n", 2, "hola");
    printf("len: %d\n", len);
    len = ft_printf("funo %.7s dos\n", "hola");
    printf("len: %d\n", len);
    len = printf("puno %.7s dos\n", "hola");
    printf("len: %d\n", len);
    
    len = ft_printf("funo %0*s dos\n", 10, "hola");
    printf("len: %d\n", len);
    len = printf("puno %0*s dos\n", 10, "hola");
    printf("len: %d\n", len);

    len = ft_printf("funo %-0*s dos\n", 10, "hola");
    printf("len: %d\n", len);
    len = printf("puno %-0*s dos\n", 10, "hola");
    printf("len: %d\n", len);
    */
 
    printf("**********POINTER**********\n");
/*
static char	a01;
static unsigned char a02;
static short a03;
static unsigned short a04;
static int a05;
static unsigned int a06;
static long a07;
static unsigned long a08;
static long long a09;
static unsigned long long a10;
static char *a11;
static void *a12;

len = ft_printf("%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
printf("*len: %d\n", len);
len = printf("%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
printf("*len: %d\n", len);
*/


    char a01 = 'a';
    char a02= 'a';
    char a03 = 'a';
    int h = 20;

    check_pointer("%p", NULL);
    check_pointer("%.0p", 0);
    check_pointer("%5p", 0);
    check_pointer("%5p", &a01);

    len = ft_printf("%p%p%p", &a01, &a02, &a03);
    printf("*len: %d\n", len);
    len = printf("%p%p%p", &a01, &a02, &a03);
    printf("*len: %d\n\n", len);



    len = ft_printf("%.5lp", 0);
    printf("*len: %d\n", len);
    len = printf("%.5lp", 0);
    printf("*len: %d\n\n", len);

    len = ft_printf("%.0p", 0);
    printf("*len: %d\n", len);
    len = printf("%.0p", 0);
    printf("*len: %d\n\n", len);

    len = ft_printf("%.10p", 0);
    printf("*len: %d\n", len);
    len = printf("%.10p", 0);
    printf("*len: %d\n\n", len);

    printf("%%-10.3p\n");
    len = ft_printf("%-10.3p", 1234);
    printf("*len: %d\n", len);
    len = printf("%-10.3p", 1234);
    printf("*len: %d\n\n", len);

    printf("%%-010.20p\n");
    len = ft_printf("%-010.20p", 1234);
    printf("*len: %d\n", len);
    len = printf("%-010.20p", 1234);
    printf("*len: %d\n\n", len);

    printf("%%-10p\n");
    len = ft_printf("%-10p", 1234);
    printf("*len: %d\n", len);
    len = printf("%-10p", 1234);
    printf("*len: %d\n\n", len);

    printf("%%-10.20p\n");
    len = ft_printf("%-10.20p", 1234);
    printf("*len: %d\n", len);
    len = printf("%-10.20p", 1234);
    printf("*len: %d\n\n", len);

    printf("%%.10p\n");
    len = ft_printf("%.10p", 1234);
    printf("*len: %d\n", len);
    len = printf("%.10p", 1234);
    printf("*len: %d\n\n", len);

    printf("%%9.20p\n");
    len = ft_printf("%9.20p", 1234);
    printf("*len: %d\n", len);
    len = printf("%9.20p", 1234);
    printf("*len: %d\n\n", len);


    len = ft_printf("%9.3p", 1234);
    printf("*len: %d\n", len);
    len = printf("%9.3p", 1234);
    printf("*len: %d\n\n", len);

/*******/

/*
    len = ft_printf("%010p", 1234);
    printf("*len: %d\n", len);
    len = printf("%010p", 1234);
    printf("*len: %d\n\n", len);


    len = ft_printf("%9.p", 1234);
    printf("*len: %d\n", len);
    len = printf("%9.p", 1234);
    printf("*len: %d\n\n", len);  

    printf("%%10p\n");
    len = ft_printf("%10p", 1234);
    printf("*len: %d\n", len);
    len = printf("%10p", 1234);
    printf("*len: %d\n\n", len);

    printf("%%-010p\n");
    len = ft_printf("%-010p", 1234);
    printf("*len: %d\n", len);
    len = printf("%-010p", 1234);
    printf("*len: %d\n\n", len);

  */
    
/* UNDEFINE
    len = ft_printf("f puntero: %9.2p, char: %c\n", &prueba, prueba);
    printf("len: %d\n", len);
    len = printf("p puntero: %9.2p, char: %c\n", &prueba, prueba);    
    printf("len: %d\n", len);
*/

/*
    len = ft_printf("f puntero: %p, char: %c\n", &prueba, prueba);
    printf("len: %d\n", len);
    len = printf("p puntero: %p, char: %c\n", &prueba, prueba);
    printf("len: %d\n", len);
    len = ft_printf("f puntero: %30p, char: %c\n", &prueba, prueba);
    printf("len: %d\n", len);
    len = printf("p puntero: %30p, char: %c\n", &prueba, prueba);
    printf("len: %d\n", len);
    len = ft_printf("f puntero: %-30p, char: %c\n", &prueba, prueba);
    printf("len: %d\n", len);
    len = printf("p puntero: %-30p, char: %c\n", &prueba, prueba);
    printf("len: %d\n", len);
    len = ft_printf("f puntero: %-14p, char: %c\n", &prueba, prueba);
    printf("len: %d\n", len);
    len = printf("p puntero: %-14p, char: %c\n", &prueba, prueba);
    printf("len: %d\n", len);
    len = ft_printf("f puntero: %030p, char: %c\n", &prueba, prueba);
    printf("len: %d\n", len);
    len = printf("p puntero: %030p, char: %c\n", &prueba, prueba);
    printf("len: %d\n", len);
    len = ft_printf("f puntero: %.30p, char: %c\n", &prueba, prueba);
    printf("len: %d\n", len);
    len = printf("p puntero: %.30p, char: %c\n", &prueba, prueba);
    printf("len: %d\n", len);
    len = ft_printf("f puntero: %.*p, char: %c\n", 30, &prueba, prueba);
    printf("len: %d\n", len);
    len = printf("p puntero: %.*p, char: %c\n", 30, &prueba, prueba);
    printf("len: %d\n", len);

    ft_printf("hola%dtu%%%druru\n", 5, 6);
 */
/*
    printf("********N*********\n");

    int dato1;
    int dato2;
    len = ft_printf("123456789%s%nFIN\n", "1234", &dato1);
    printf("cambio: %d len: %d\n", dato1, len);
    len = ft_printf("123456789%s%nFIN\n", "1234", &dato2);
    printf("cambio: %d len: %d\n", dato2, len);
*/
/*
    printf("decima %e\n", 50000.2);
    printf("decima %f\n", 5000000.2);
    printf("decima %g\n", 50000.2);

    float f = 55.32;
    printf("fload %lu", (unsigned long)f);
*/
/*
printf("*********NULL*************\n");

ft_printf("fcaracter null:%cFIN\n", '\0');
printf("pcaracter null:%cFIN\n", '\0');


len = ft_printf("%s", (char *)0);
printf("lenf: %d\n", len);
len = printf("%s", (char *)0);
printf("lenp: %d\n", len);


ft_printf("1ft %05%FIN\n");
printf("1pr %05%FIN\n");

ft_printf("2ft %.5%FIN\n");
printf("2pr %.5%FIN\n");

ft_printf("3ft %*%FIN\n", 5);
printf("3pr %*%FIN\n", 5);

ft_printf("4ft %-5%FIN\n");
printf("4pr %-5%FIN\n");

len = ft_printf("5ft %-05%FIN\n");
printf("lenp: %d\n", len);
len = printf("5pr %-05%FIN\n");
printf("lenp: %d\n", len);

len = ft_printf("5ft %-.05%FIN\n", 'x');
printf("lenp: %d\n", len);
len = printf("5pr %-.05%FIN\n", 'x');
printf("lenp: %d\n", len);
*/


printf("*********CHAR**********\n");

/*
check_char("%c", '\0');
check_char("%5c", '\0');
check_char("%-5c", '\0');
check_char("%c", 'j');
check_char("%10c", 'j');
check_char("%10.5c", 'j');
check_char("%010.5c", 'j');
check_char("%-10c", 'j');
check_char("%-010c", 'j');
check_char("%-010.c", 'j');
check_char("%.10c", 'j');
check_char("%.1c", 'j');
check_char("%.0c", 'j');
check_char("%10.0c", 'j');
check_char("%-10.0c", 'j');
check_char("%10-.0c", 'j');
*/

printf("***************PERCENT*****************\n");
/*
check_percent("%5%");
check_percent("%.5%");
check_percent("%%");
check_percent("%10%");
check_percent("%10.5%");
check_percent("%010.5%");
check_percent("%05.10%");
check_percent("%-10%");
check_percent("%-010%");
check_percent("%-010.%");
check_percent("%.10%");
check_percent("%.1%");
check_percent("%.0%");
check_percent("%10.0%");
check_percent("%-10.0%");
check_percent("%10-.0%");
*/
    /*
    //cspdiuxX % x y X conversion hexadeci sin signo
    printf("un hexadecima %x otro %x\n", -2147483647 , -2);
    printf("un deci sin signo %u otro %u\n", 5, -1);

    printf("una cosa %9s otra cosa\n", "prueba");
    printf("una cosa %-9s otra cosa\n", "prueba");
    printf("una cosa %3s otra cosa\n", "prueba");

    printf("prueba del punto %.9s\n", "unomuylargoparaque recorte");
    printf("DIGITOS\n");
    printf("prueba del digito %.9dfin\n", 30);
    printf("prueba del digito %09dfin\n", 30);
    printf("prueba del digito %.-9dfin\n", 30);
    printf("prueba del digito %-.9dfin\n", 30);
    printf("prueba del digito %-9dfin\n", 30);
    printf("digito con 0 y menos %*9d\n", 10, 30);
    printf("prueba del digito %.*d\n", 2, 305456);
    printf("prueba del digito con menos %-9d hola\n", 30);
    //printf("prueba del digito %-09d\n", 30); // el menos no funciona con cero
    printf("El punto con digito rellena de ceros %0.9d\n", 30); //o lo usar para rellenar de ceros o lo ignora
    printf("prueba del punto y * %.*s\n", 5, "unomuylargoparaque recorte");
    printf("prueba del 0 %09d\n", 30); //solo para numeros
    printf("prueba de * %*s\n", 9, "uno");
    printf("prueba de * %-*s dos\n", 9, "uno");
    //    foo("ss", "hola", "hola tu");
    */
   //system("leaks a.out");
}