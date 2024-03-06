#include<stdio.h>

int main()
{
    //initaiating array
    int binary[10], decimal, i;

    //taking user input for processing
    printf("Enter Decimal Number ::\t");
    scanf("%d", &decimal);

    //actual 'algorithm' starts
    for(i=0; decimal>0; i-=-1)
    {
        // taking modulus of the number and storing to the array
        binary[i] = decimal % 2;
        //diving the number for next iteration
        //refer the end of program for clearity
        decimal /= 2;
    }

    //printing output
    printf("The number in binary is::\t");
    for(i = i-1; i>=0; i--)
    {
        printf("%d", binary[i]);
    }
    printf("\n");
    return 0;
}


/*
so coversion works as following:
if the number is 5 for example
we divide it by 2 (since it is binary)
and the remainder is appended to the array
and the quotirnt itself is divided by two 
this process repeats until the quotient is less than 2.

the array is printed in reverse order
*/