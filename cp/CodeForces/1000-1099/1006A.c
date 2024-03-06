/*https://codeforces.com/problemset/problem/1006/A*/

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    int i,n;
    scanf("%d",&n);
    int a[n+10];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]%2==0)
        {
            a[i]=a[i]-1;
        }
    }
    for(int i=0;i<n-1;i++)
    {
        printf("%d ",a[i]);
    }
    printf("%d\n",a[n-1]);
}
