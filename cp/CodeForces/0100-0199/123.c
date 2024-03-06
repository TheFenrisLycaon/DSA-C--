/* Question: https://codeforces.com/problemset/problem/123/C */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    if (n <= 0){
        return 0;
    }
    int A[n];
    A[0] = 0, A[1] = 1;
    int sum;
    sum = A[0] + A[1];
    for (int i=2; i<=n; i++){
        A[i] = A[i-1] + A[i-2];
        sum = sum + A[i];
    }
    printf("%d",sum);
     return 0;
}
