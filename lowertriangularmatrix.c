#include<stdio.h>
int main(){
    int r,c;

    printf("\t*****INPUT*****\n");
    printf("enter no. of rows and col. resp ");
   
    scanf("%d %d",&r,&c);
    int i,j,a[r][c];
       
    for(i=0;i<r;i++){
        
            for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d",a[i][j]);
        }
        printf("\n");
}
printf("\t*****OUTPUT*****\n");
printf("The elements being summed of the lower triangular matrix are: ");

    int sum = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j <i; j++) {
            if (i >= j) {
                printf("%d ", a[i][j]);
                sum +=a[i][j];
            }
        }}
        printf("\n sum = %d",sum);
    return 0;
    }
