#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

void foo(char *fmt, ...)
{
    va_list ap;
    int d;
    char c, *s;

   va_start(ap, fmt);
    while (*fmt)
        switch (*fmt++) {
        case 's':              /* string */
            s = va_arg(ap, char *);
            printf("string %s\n", s);
            break;
        case 'd':              /* int */
            d = va_arg(ap, int);
            printf("int %d\n", d);
            break;
        case 'c':              /* char */
            /* need a cast here since va_arg only
               takes fully promoted types */
            c = (char) va_arg(ap, int);
            printf("char %c\n", c);
            break;
        }
    va_end(ap);
}

int main(void)
{
    int len;

    len = 0;
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
/*
    printf("*******DIGITS***********\n");

    ft_printf("funo %09d dos\n", 265);
    printf("puno %09d dos\n", 265);
    ft_printf("funo %.9d dos\n", 265);
    printf("puno %.9d dos\n", 265);
    ft_printf("funo %9d dos\n", 265);
    printf("puno %9d dos\n", 265);
    ft_printf("funo %-9d dos\n", 265);
    printf("puno %-9d dos\n", 265);
    ft_printf("funo %-.*d dos\n", 20, -1);
    printf("puno %-.*d dos\n", 20, -1);
    ft_printf("funo %.*d dos\n", 20, -1);
    printf("puno %.*d dos\n", 20, -1);
   // ft_printf("funo %.*d dos\n", 20, -2147483648);
   // printf("puno %.*d dos\n", 20, -2147483648);
    len = ft_printf("funo %.*d dos\n", 20, -32769);
    printf("len: %d\n", len);
    len = printf("puno %.*d dos\n", 20, -32769);
    printf("len: %d\n", len);
    len = ft_printf("funo %*d dos\n", 20, -32769);
    printf("len: %d\n", len);
    len = printf("puno %*d dos\n", 20, -32769);
    printf("len: %d\n", len);

    printf("********* UNSIGNED **********\n");
    ft_printf("funo %*u dos\n", 20, -32769);
    printf("puno %*u dos\n", 20, -32769);
    unsigned int h = 3678;
    ft_printf("funo %*u dos\n", 20, h);
    printf("puno %*u dos\n", 20, h);

    printf("**********STR*************\n");
    ft_printf("funo %*s dos\n", 20, "hola");
    printf("puno %*s dos\n", 20, "hola");
    len = ft_printf("funo %.*s dos\n", 2, "hola");
    printf("len: %d\n", len);
    len = printf("puno %.*s dos\n", 2, "hola");
    printf("len: %d\n", len);
  */ 
 /* 
    printf("**********POINTER**********\n");
    char prueba = 'a';
    int h = 20;
    len = ft_printf("f puntero: %p, char: %c\n", &prueba, prueba);
    printf("len: %d\n", len);
    len = printf("p puntero: %p, char: %c\n", &prueba, prueba);
    printf("len: %d\n", len);
    ft_printf("f puntero: %30p, char: %c\n", &prueba, prueba);
    printf("p puntero: %30p, char: %c\n", &prueba, prueba);
    len = ft_printf("f puntero: %-30p, char: %c\n", &prueba, prueba);
    printf("len: %d\n", len);
    len = printf("p puntero: %-30p, char: %c\n", &prueba, prueba);
    printf("len: %d\n", len);
    len = ft_printf("f puntero: %-14p, char: %c\n", &prueba, prueba);
    printf("len: %d\n", len);
    len = printf("p puntero: %-14p, char: %c\n", &prueba, prueba);
    printf("len: %d\n", len);
    //ft_printf("f puntero: %030p, char: %c\n", &prueba, prueba);
    //printf("p puntero: %030p, char: %c\n", &prueba, prueba);
    //ft_printf("f puntero: %.5p, char: %c\n", &prueba, prueba);
    //printf("p puntero: %.5p, char: %c\n", &prueba, prueba);

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
    printf("decima %e\n", 50000.2);
    printf("decima %f\n", 5000000.2);
    printf("decima %g\n", 50000.2);

    float f = 55.32;
    char *cosa;
    cosa = &f;
    for (int i = 0; i < 6; i++)
    {
        printf("cosa: %c\n", cosa[i]);
    }
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
}