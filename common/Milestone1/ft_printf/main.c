#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include "ft_printf.h"
#include <stdlib.h>

char *merge(int count,...)
{
    va_list args;
    va_start(args, count);
    char *a;
    a = malloc(count + 1);
    int i = 0;
    while(i < count)
    {
        a[i] = va_arg(args, int);
        i++;
    }
    va_end(args);
    return(a);
}

int addx(int x, int y,...)
{
    va_list (args);
    va_start(args,y);

    int i = 0;
    int re = 0;
    while(i < y)
    {
        re = va_arg(args,int) + x;
        printf("%d",re);
        i++;
    } 
    va_end(args);
    return (0);
}


int main(void) {

    char *a = merge(3,'4','3','2');
    printf("%s",a);
    free(a);
    addx(5,3,4,3,2); // 9, 8, 7

    int ret1, ret2;

    // Test: Tam Sayılar (d, i)
    printf("=== Tam Sayılar Test ===\n");
    
    ret1 = ft_printf("0: %d\n", 0);
    ret2 = printf("0: %d\n", 0);
    printf("Return: %d, Expected: %d\n", ret1, ret2);
    
    ret1 = ft_printf("Negative: %d\n", -123);
    ret2 = printf("Negative: %d\n", -123);
    printf("Return: %d, Expected: %d\n", ret1, ret2);
    
    ret1 = ft_printf("Positive: %d\n", 123);
    ret2 = printf("Positive: %d\n", 123);
    printf("Return: %d, Expected: %d\n", ret1, ret2);
    
    ret1 = ft_printf("Max Int: %d\n", INT_MAX);
    ret2 = printf("Max Int: %d\n", INT_MAX);
    printf("Return: %d, Expected: %d\n", ret1, ret2);
    
    ret1 = ft_printf("Min Int: %d\n", INT_MIN);
    ret2 = printf("Min Int: %d\n", INT_MIN);
    printf("Return: %d, Expected: %d\n", ret1, ret2);
    
    // Test: Karakter (c)
    printf("=== Karakter Test ===\n");

    ret1 = ft_printf("Char: %c\n", 'A');
    ret2 = printf("Char: %c\n", 'A');
    printf("Return: %d, Expected: %d\n", ret1, ret2);
    
    ret1 = ft_printf("Space: %c\n", ' ');
    ret2 = printf("Space: %c\n", ' ');
    printf("Return: %d, Expected: %d\n", ret1, ret2);
    
    ret1 = ft_printf("Newline: %c\n", '\n');
    ret2 = printf("Newline: %c\n", '\n');
    printf("Return: %d, Expected: %d\n", ret1, ret2);

    // Test: Dizeler (s)
    printf("=== Dize Test ===\n");

    ret1 = ft_printf("Empty string: %s\n", "");
    ret2 = printf("Empty string: %s\n", "");
    printf("Return: %d, Expected: %d\n", ret1, ret2);
      ret1 = ft_printf("Valid string: %s\n", "Hello, World!");
    ret2 = printf("Valid string: %s\n", "Hello, World!");
    printf("Return: %d, Expected: %d\n", ret1, ret2);
    
    ret1 = ft_printf("NULL string: %s\n", NULL);
    ret2 = printf("NULL string: %s\n", NULL);
    printf("Return: %d, Expected: %d\n", ret1, ret2);

    // Test: Hexadecimal (x, X)
    printf("=== Hexadecimal Test ===\n");

    ret1 = ft_printf("Hex 0: %x\n", 0);
    ret2 = printf("Hex 0: %x\n", 0);
    printf("Return: %d, Expected: %d\n", ret1, ret2);

    ret1 = ft_printf("Hex 255: %x\n", 255);
    ret2 = printf("Hex 255: %x\n", 255);
    printf("Return: %d, Expected: %d\n", ret1, ret2);
    
    ret1 = ft_printf("Hex Max: %x\n", UINT_MAX);
    ret2 = printf("Hex Max: %x\n", UINT_MAX);
    printf("Return: %d, Expected: %d\n", ret1, ret2);
    
    ret1 = ft_printf("Hex 255 Upper: %X\n", 255);
    ret2 = printf("Hex 255 Upper: %X\n", 255);
    printf("Return: %d, Expected: %d\n", ret1, ret2);
    
    // Test: Pointer (p)
    printf("=== Pointer Test ===\n");

    int value = 42;
    ret1 = ft_printf("Null pointer: %p\n", NULL);
    ret2 = printf("Null pointer: %p\n", NULL);
    printf("Return: %d, Expected: %d\n", ret1, ret2);
    
    ret1 = ft_printf("Pointer value: %p\n", (void*)&value);
    ret2 = printf("Pointer value: %p\n", (void*)&value);
    printf("Return: %d, Expected: %d\n", ret1, ret2);

    // Test: Unsigned Tam Sayılar (u)
    printf("=== Unsigned Tam Sayılar Test ===\n");

    ret1 = ft_printf("Unsigned 0: %u\n", 0);
    ret2 = printf("Unsigned 0: %u\n", 0);
    printf("Return: %d, Expected: %d\n", ret1, ret2);
    
    ret1 = ft_printf("Unsigned 123: %u\n", 123);
    ret2 = printf("Unsigned 123: %u\n", 123);
    printf("Return: %d, Expected: %d\n", ret1, ret2);
    
    ret1 = ft_printf("Unsigned Max: %u\n", UINT_MAX);
    ret2 = printf("Unsigned Max: %u\n", UINT_MAX);
    printf("Return: %d, Expected: %d\n", ret1, ret2);
    
    // Test: Yüzde İşareti (%)
    printf("=== Yüzde İşareti Test ===\n");

    ret1 = ft_printf("Percent sign: %%\n");
    ret2 = printf("Percent sign: %%\n");
    printf("Return: %d, Expected: %d\n", ret1, ret2);

    return (0);
}
