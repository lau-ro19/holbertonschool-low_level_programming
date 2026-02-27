#include <stdio.h>

/**
 * addition - Calcule la somme de deux entiers
 * @A: Le premier nombre entier
 * @B: Le deuxième nombre entier
 * Return: Le résultat de l'addition (A + B)
 */
int addition(int A, int B)
{
    int Result;

    Result = A + B;
    return(Result);
}
/**
 * soustraction - Calcule la différence entre deux entiers
 * @A: Le premier nombre
 * @B: Le nombre à soustraire
 * * Return: Le résultat de A - B
 */
int soustraction(int A, int B)
{
    int Result;
    
    Result = A - B;
    return(Result);
}
/**
 * multiplivation - Calcule le produit entre deux entiers
 * @A: Le premier nombre
 * @B: Le nombre à soustraire
 * * Return: Le résultat de A * B
 */
int multiplication(int A, int B)
{
    int Result;

    Result = A * B;
    return(Result);
}
int main(void)
{

    int input = -1; 
    int A = 0; 
    int B = 0; 

    printf("Simple Calculator\n");

    while(input != 0)
    {
        printf("1) Add\n2) Subtract\n3) Multiply\n4) Divide\n0) Quit\n");
        printf("choice:");
        scanf("%d", &input);

        if(input == 0)
        {
            printf("Bye!\n");
            break;
        }

        if (input >= 1 && input <= 4)
        {
        printf("A: ");
        scanf("%d", &A);
        printf("B: ");
        scanf("%d", &B);

        if (input == 1)
        {
            printf("Result: %d\n", addition(A, B));
        }
        else if (input == 2)
        {
            printf("Result: %d\n", soustraction(A, B));
        }
        else if (input == 3)
        {
            printf("Result: %d\n", multiplication(A, B));
        }
    }     
    }
    return(0);
}
