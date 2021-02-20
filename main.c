/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:12:20 by lgomez-d          #+#    #+#             */
/*   Updated: 2021/02/20 11:17:07 by user42           ###   ########.fr       */
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
    check_nbr("%.0d", 0);
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
    check_nbr("%.*d", -2147483648);
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
*/
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

/*
check_percent("%%");
check_percent("%10%");
check_percent("%10.5%");
check_percent("%010.5%");
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