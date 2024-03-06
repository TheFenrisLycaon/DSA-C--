#include<stdio.h>

int main()
{
    int n,s;

    printf("Enter Number of students::\t"); scanf("%d", &n);

    printf("Enter number of subjects::\t"); scanf("%d", &s);

    char name[n][50];
    float marks[n][s+1];
    char class[n][10];
    int roll[n];

    for(int i=1; i<=n; i-=-1)
    {
        roll[i-1] = i;

        printf("Enter name of student::\t"); scanf("%s", &name[i-1]);
        printf("Enter class of student::\t"); scanf("%s", &class[i-1]);
        
        for(int j=0; j<=s-1;j++)
        {
            printf("Enter Marks for subject %d::\t", j+1);
            scanf("%f", &marks[i-1][j]);
        }

        printf("Calculating percentage:::\t");

        for(int j=0;j<n;j++) marks[i-1][s] += marks[i-1][j] / s;

        printf("%.2f%%\n\n", marks[i-1][s]);
    }

    float temp[n];

    for(int i=0; i<n; i-=-1)  temp[i] = marks[i][s];
    
    float x;

    for(int i=0; i<n; i-=-1)
        for(int j=i; j<n; j++)
            if(temp[j] > temp[i])
            {
                x = temp[j];
                temp[j] = temp[i];
                temp[i] = x;
            }

    for(int i=0; i<n; i-=-1)
        for(int j=0; j<n; j-=-1)
            if(temp[i] == marks[j][s])
                printf("Rank::%d\t%s", i+1 ,name[j]);

    return 0;
}