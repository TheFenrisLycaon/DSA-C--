#include<stdio.h>
#include<stdlib.h>

int check(int **arr,int row,int col){
    float e,t;
    int i,j,cz = 0,cn = 0;
    for(i = 0;i<row;i++){
        for(j = 0;j<col;j++){
            if(arr[i][j] == 0) cz += 1;
            else cn += 1;
        }
    }
    e = (float)cz/(cz+cn);
    t = (float)2/3;
    if(e >= t) return 1;
    else return 0;
}

int create(int **arr,int row,int col){
    int i,j,nz = 0;
    printf("Enter the elements of the matrix:\n");
    for(i = 0;i<row;i++){
        arr[i] = (int *)malloc(col*sizeof(int));
        printf("Enter elements of row %d:\n",i+1);
        for(j = 0;j<col;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j] != 0) nz += 1;
        }
    }
    return(nz);
}

void createSparse(int **sm,int srow,int **arr,int row,int col){
    int i,j,k = 1;
    for(i = 0;i<srow;i++) sm[i] = (int *)malloc(3*sizeof(int));
    sm[0][0] = row;
    sm[0][1] = col;
    sm[0][2] = srow-1;
    for(i = 0;i<row;i++){
        for(j = 0;j<col;j++){
            if(arr[i][j] != 0){
                sm[k][0] = i+1;
                sm[k][1] = j+1;
                sm[k][2] = arr[i][j];
                k += 1;
            }
        }
    }
    return;
}

void print(int **sm,int srow){
    int i,j;
    printf("The sparse matrix is:\n");
    for(i = 0;i<srow;i++){
        for(j = 0;j<3;j++){
            printf("%d ",sm[i][j]);
        }
        printf("\n");
    }
    return;
}

int main(){
    int row,col,sparse_row,non_zero_ele,count, **arr, **sparse;
    // creating the initial matrix
    printf("Enter row:");
    scanf("%d",&row);
    printf("Enter column:");
    scanf("%d",&col);
    arr = (int **)malloc(row*sizeof(int *));
    non_zero_ele = create(arr,row,col);
    sparse_row = non_zero_ele + 1;
    // checking if the initial matrix is for suitable sparse representation or not
    count = check(arr,row,col);
    if(count){
        // creating sparse representation
        sparse = (int **)malloc(sparse_row*sizeof(int *));
        createSparse(sparse,sparse_row,arr,row,col);
        // printing sparse matrix
        print(sparse,sparse_row);
    }
    else printf("Sorry! This matrix is not suitable for sparse representation.");
    free(arr);
    free(sparse);
    return 0;
}