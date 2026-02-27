#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{

    int input= -1;

    printf("Simple Calculator\n");

    while(input != 0)
    {
        printf("1) Add\n2) Subtract\n3) Multiply\n4) Divide\n0) Quit\n");
        printf("choice:");
        scanf("%d", &input);

    if(input == 0)
    {
        printf("Bye\n");
    }
    }
    return(0);
}
