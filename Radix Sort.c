#include <stdio.h>
#include <stdlib.h>

int max(int a[] , int n ){

int mx = a[0];

for(int i = 0 ;i < n ; i ++){
    if(a[i] > mx){mx = a[i];}
}

return mx;

}

void count_sort(int a[] , int n , int e){

int count[10]={0};

int answer[n];

for(int i = 0 ;i < n ;i ++ ){

    count[ ( (a[i] / e ) % 10 ) ]++;
}

for(int i = 1; i < 10 ;i ++ ){
    count[i]+=count[i - 1];
}

for(int i = n - 1  ; i >= 0 ; i --){
    answer[ count[(a[i] / e ) % 10] - 1] = a[i];
    count[(a[i] / e ) % 10] -- ;
}

for(int i = 0 ;i < n ;i ++ ){
    a[i] = answer[i];
}


}

void radix_sort(int a[] , int n ){

int mx = max(a , n );

// for loop on the maximum number of digits :
for(int i = 1 ; mx / i > 0 ; i*=10 ){
    count_sort(a , n , i);
}


}

int main()
{

int n ;
printf("Enter the size of the Array ! :  ");

scanf( "%d" , &n);

int a[n];
printf("Fill the input numbers : \n");
for(int i = 0 ;i < n ;i ++ ){
    scanf("%d", &a[i]);
}

radix_sort(a , n);

printf("The sorted array : \n");
for(int i = 0 ;i < n ;i ++ ){
    printf("%d " , a[i]);
}


    return 0;
}
