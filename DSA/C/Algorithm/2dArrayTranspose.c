  #include<stdio.h>
  void main()
  
{
    int a[20][20],i,j,r,c;
    printf("\nEnter the number of rows : ");
    scanf("%d",&r);
    printf("Enter the number of columns : ");
    scanf("%d",&c);

    printf("Enter the elements : \n");

    for(i=0;i<r;i++)
    for(j=0;j<c;j++)
    scanf("%d",&a[i][j]);

    printf("/nOriginal array : \n");
    for(i=0;i<r;i++)
   { for(j=0;j<c;j++)
   printf("%d ",a[i][j]);
    printf("\n");}

    printf("\nTranspose of array : \n");
    for(i=0;i<c;i++)
    {for(j=0;j<r;j++)
    printf("%d ",a[j][i]);
    printf("\n");}

}

  