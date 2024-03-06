#include<stdio.h>

int main()
{
    char inp[50];
    int vow,cons;
    printf("Enter the string::\t");
    scanf("%[^\n]%*c", inp); 
    /*printf("%s", inp); */
    for(int i=0; inp[i] != '\0'; i++)
    {
        if (inp[i] == 'a' || inp[i] == 'e' ||
            inp[i] == 'i' || inp[i] == 'o' ||
            inp[i] == 'u' || inp[i] == 'A' ||
            inp[i] == 'E' || inp[i] == 'I' || 
            inp[i] == 'O' || inp[i] == 'U')
            vow++;
        else if(inp[i] >= '0' && inp[i] <= '9' || inp[i] == ' ')
            continue;
        else
            cons++;
    }

    printf("Vowels::\t%d\nConsonants::\t%d\n", vow,cons);
    return 0; 
}
