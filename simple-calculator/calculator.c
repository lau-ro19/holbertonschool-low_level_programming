#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{

    int input= -1; 
    int A, B, Result; 

    printf("Simple Calculator\n");

    while(input != 0)
    {
        printf("1) Add\n2) Subtract\n3) Multiply\n4) Divide\n0) Quit\n");
        printf("choice:");
        scanf("%d", &input);

        if(input == 1)
        {
            printf("A:");
            scanf("%d", &A);
            printf("B:");
            scanf("%d", &B);

            Result= A + B;

            printf("Result: %d\n", Result);

        }

        else if(input > 4 || input < 0)
        {
            printf("Invalide Choice\n");
        }

        else if(input == 0)
        {
            printf("Bye!\n");
        }
    }
    return(0);
}
