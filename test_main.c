#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");

    printf("\n----------------------------------------------------------------\n");

    _printf("Len of previous sentence [%d]\n", len);
    printf("Len of previous sentence [%d]\n", len2);
    


    printf("\n----------------------------------------------------------------\n");


    _printf("Len of previous sentence with %%i [%i]\n", len);
    printf("Len of previous sentence %%i [%i]\n", len2);
    

    printf("\n----------------------------------------------------------------\n");
    return (0);


}
