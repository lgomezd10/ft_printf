/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:12:20 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/19 11:06:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

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
    printf("*len: %p\n", len);
    len = printf(str, dato);
    printf("*len: %p\n", len);
}

int main(void)
{
    int len;

    len = 0;
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
/*
    printf("***********HEX**********\n");
    len = ft_printf("funo %x dos\n", 265);
    printf("len: %d\n", len);
    len = printf("puno %x dos\n", 265);
    printf("len: %d\n", len);
    len = ft_printf("funo %x dos\n", 15);
    printf("len: %d\n", len);
    len = printf("puno %x dos\n", 15);
    printf("len: %d\n", len);
    len = ft_printf("funo %x dos\n", 10000);
    printf("len: %d\n", len);
    len = printf("puno %x dos\n", 10000);
    printf("len: %d\n", len);
    len = ft_printf("funo %x dos\n", 4095);
    printf("len: %d\n", len);
    len = printf("puno %x dos\n", 4095);
    printf("len: %d\n", len);
    len = ft_printf("funo %x dos\n", -1);
    printf("len: %d\n", len);
    len = printf("puno %x dos\n", -1);
    printf("len: %d\n", len);
    len = ft_printf("funo %X dos\n", -354);
    printf("len: %d\n", len);
    len = printf("puno %X dos\n", -354);
    printf("len: %d\n", len);
    len = ft_printf("***PRUEBA HEX CON FLAGS***\n");
    printf("len: %d\n", len);
    len = ft_printf("funo %09x dos\n", 265);
    printf("len: %d\n", len);
    len = printf("puno %09x dos\n", 265);
    printf("len: %d\n", len);
    len = ft_printf("funo %.9x dos\n", 265);
    printf("len: %d\n", len);
    len = printf("puno %.9x dos\n", 265);
    printf("len: %d\n", len);
    len = ft_printf("funo %9x dos\n", 265);
    printf("len: %d\n", len);
    len = printf("puno %9x dos\n", 265);
    printf("len: %d\n", len);
    ft_printf("funo %-9x dos\n", 265);
    printf("puno %-9x dos\n", 265);
    ft_printf("funo %-*x dos\n", 9, 265);
    printf("puno %-*x dos\n", 9, 265);
    ft_printf("funo %.*x dos\n", 9, 265);
    printf("puno %.*x dos\n", 9, 265);
    ft_printf("funo %.*x dos\n", 1, 265);
    printf("puno %.*x dos\n", 1, 265);
    ft_printf("funo %-.*x dos\n", 20, -1);
    printf("puno %-.*x dos\n", 20, -1);
    //ft_printf("funo %-09x dos\n", 265);
    //printf("puno %-09x dos\n", 265);
  */  

    printf("*******DIGITS***********\n");


/*
void	ft_fill_and_print(char *str, t_var *opt)
{
	int len;
	int rest;
	int i;
   
	len = ft_strlen(str);
	rest = (len < opt->len) ? (opt->len - len) : 0;
	opt->out += len + rest;
	if (!opt->right)
		ft_putstr_fd(str, 1);
	i = 0;
	while (i++ < rest)
		ft_putchar_fd(opt->fill, 1);
	if (opt->right)
		ft_putstr_fd(str, 1);
}*/
/*
    printf("%%9.6d\n");
    len = ft_printf("%9.6d", -321);
    printf("len: %d\n", len);
    len = printf("%9.6d", -321);
    printf("len: %d\n", len);

    printf("%%9.2d\n");
    len = ft_printf("%9.2d", -355);
    printf("len: %d\n", len);
    len = printf("%9.2d", -355);
    printf("len: %d\n", len);

    printf("%%09.6d\n");
    len = ft_printf("%09.6d", -355);
    printf("len: %d\n", len);
    len = printf("%09.6d", -355);
    printf("len: %d\n", len);

    printf("%%.6d\n");
    len = ft_printf("%.6d", -3);
    printf("len: %d\n", len);
    len = printf("%.6d", -3);
    printf("len: %d\n", len);

    printf("%%07d\n");
    len = ft_printf("%07d", -54);
    printf("len: %d\n", len);
    len = printf("%07d", -54);
    printf("len: %d\n", len);

    check_nbr("%09d", -265);
    check_nbr("%.9d", -265);
    check_nbr("%9d", -265);
    check_nbr("%-9d", -265);
    check_nbr("%.*d", -2147483648);
*/    

/*
    printf("********* UNSIGNED **********\n");
    ft_printf("funo %*u dos\n", 20, -32769);
    printf("puno %*u dos\n", 20, -32769);
    unsigned int h = 3678;
    ft_printf("funo %*u dos\n", 20, h);
    printf("puno %*u dos\n", 20, h);
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
*/ 
/*
    printf("t %d n %d v %d f %d r %d\n", '\t', '\n', '\v', '\f', '\r');
    len = ft_printf("%+- 06.06s", "hello world");
    printf("*len: %d\n", len);
    len = printf("%+- 06.06s", "hello world");
    //len = printf("printf %\t\n\v\f\r 06.06s", "hello world");
    printf("*len: %d\n", len);

    len = ft_printf("%.7s", "hello");
    printf("*len: %d\n", len);
    len = printf("%.7s", "hello");
    printf("*len: %d\n", len);
    
    len = ft_printf("%32s", NULL);
    printf("*len: %d\n", len);
    len = printf("%32s", NULL);
    printf("*len: %d\n", len);

     len = ft_printf("%-32s", NULL);
    printf("*len: %d\n", len);
    len = printf("%-32s", NULL);
    printf("*len: %d\n", len);

    len = ft_printf("%032s", NULL);
    printf("*len: %d\n", len);
    len = printf("%032s", NULL);
    printf("*len: %d\n", len);

     len = ft_printf("%-032s", NULL);
    printf("*len: %d\n", len);
    len = printf("%-032s", NULL);
    printf("*len: %d\n", len);

    len = ft_printf("%7.3s", NULL);
    printf("*len: %d\n", len);
    len = printf("%7.3s", NULL);
    printf("*len: %d\n", len);
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

   
    len = ft_printf("%7.5s", "yolo");
    printf("\nlen: %d\n", len);
    len = printf("%7.5s", "yolo");
    printf("\nlen: %d\n", len);
    len = ft_printf("%7.5s", "bombastic");
    printf("\nlen: %d\n", len);
    len = printf("%7.5s", "bombastic");
    printf("\nlen: %d\n", len);
    len = ft_printf("%-7.5sFIN", "yolo");
    printf("\nlen: %d\n", len);
    len = printf("%-7.5sFIN", "yolo");
    printf("\nlen: %d\n", len);

    len = ft_printf("%7.3s", "yolo");
    printf("\nlen: %d\n", len);
    len = printf("%7.3s", "yolo");
    printf("\nlen: %d\n", len);
    len = ft_printf("%3.5s", "yolo");
    printf("\nlen: %d\n", len);
    len = printf("%3.5s", "yolo");
    printf("\nlen: %d\n", len);
    len = ft_printf("%3.0s", "yolo");
    printf("\nlen: %d\n", len);
    len = printf("%3.0s", "yolo");
    printf("\nlen: %d\n", len);
    len = ft_printf("%3.s", "yolo");
    printf("\nlen: %d\n", len);
    len = printf("%3.s", "yolo");
    printf("\nlen: %d\n", len);
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


    check_pointer("%p", NULL);
    check_pointer("%.0p", 0);
    check_pointer("%5p", 0);
/*

    len = ft_printf("%.5p", 0);
    printf("*len: %d\n", len);
    len = printf("%.5p", 0);
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
*/
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
    char prueba = 'a';
    int h = 20;
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
int c_nullterm_basic(void){return test("%c", '\0');}
int c_nullterm_5w(void){return test("%5c", '\0');}
int c_nullterm_5wlj(void){return test("%-5c", '\0');}
*/
/*
len = ft_printf("%c", 'x');
printf("*1lenp: %d\n", len);
len = printf("%c", 'x');
printf("*1lenp: %d\n", len);

len = ft_printf("%5c", 'x');
printf("*1lenp: %d\n", len);
len = printf("%5c", 'x');
printf("*1lenp: %d\n", len);

len = ft_printf("%-5c", 'x');
printf("*1lenp: %d\n", len);
len = printf("%-5c", 'x');
printf("*1lenp: %d\n", len);

len = ft_printf("%c", '\0');
printf("*2lenp: %d\n", len);
len = printf("%c", '\0');
printf("*2lenp: %d\n", len);

len = ft_printf("%5c", '\0');
printf("*3lenp: %d\n", len);
len = printf("%5c", '\0');
printf("*3lenp: %d\n", len);

len = ft_printf("%-5c", 'x');
printf("*4lenp: %d\n", len);
len = printf("%-5c", 'x');
printf("*4lenp: %d\n", len);

len = ft_printf("%05c", 'x');
printf("*5lenp: %d\n", len);
len = printf("%05c", 'x');
printf("*5lenp: %d\n", len);

len = ft_printf("%-05c", 'x');
printf("*6lenp: %d\n", len);
len = printf("%-05c", 'x');
printf("*6lenp: %d\n", len);


len = ft_printf("%-5.2c", '\0');
printf("*7lenp: %d\n", len);
len = printf("%-5.2c", '\0');
printf("*7lenp: %d\n", len);
*/
/*
ft_printf("1ft %05cFIN\n", 'x');
printf("1pr %05cFIN\n", 'x');

len = ft_printf("2ft %.5cFIN\n", 'x');
printf("lenp: %d\n", len);
len = printf("2pr %.5cFIN\n", 'x');
printf("lenp: %d\n", len);

ft_printf("3ft %*cFIN\n", 5, 'x');
printf("3pr %*cFIN\n", 5, 'x');

ft_printf("4ft %-5cFIN\n", 'x');
printf("4pr %-5cFIN\n", 'x');

len = ft_printf("5ft %-05cFIN\n", 'x');
printf("lenp: %d\n", len);
len = printf("5pr %-05cFIN\n", 'x');
printf("lenp: %d\n", len);

len = ft_printf("5ft %-.05cFIN\n", 'x');
printf("lenp: %d\n", len);
len = printf("5pr %-.05cFIN\n", 'x');
printf("lenp: %d\n", len);

len = ft_printf("%cFIN\n", '\0');
printf("lenf: %d\n", len);
len = printf("%cFIN\n", '\0');
printf("lenp: %d\n", len);
*/

    /*
    //cspdiuxX % x y X conversion hexadecimal sin signo
    printf("un hexadecima %x otro %x\n", -2147483647 , -2);
    printf("un decimal sin signo %u otro %u\n", 5, -1);

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