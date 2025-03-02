#include <stdio.h>
#include <stdlib.h>

void Merge(int a [] , int m , int left , int right){

int First [m - left + 1];
int Second[right - m ];


for(int i = 0 ;i < m - left + 1 ; i ++ ){
 First[i] = a [left + i];
}
for(int j = 0 ;j < right - m ; j ++ ){
    Second[j] = a[m + 1 + j];
}


int i = 0 , j = 0 , k = left ;

while(i < m - left + 1 && j < right - m ){

 while(First[i] <= Second[j] && i < m - left + 1){
    a[k] = First[i];
    i++;
    k++;
 }
 while(Second[j] < First[i] && j < right - m ){
    a[k] = Second[j];
    j++;
    k++;
 }

}
while (i < m - left + 1){
    a[k] = First[i];
    i++;
    k++;
}
while(j < right - m){
    a[k] = Second[j];
    j++;
    k++;
}


}

void MergeSort(int arr[] , int left , int right){

if(left < right){

 int mid = (left + right) / 2;

 MergeSort(arr , left ,mid );
 MergeSort (arr , mid + 1 , right);

 Merge(arr , mid , left , right);

}

}

int main()
{

    printf("Enter the number of elements in your array : ");
    int n ;
    scanf("%d" , &n);
    int array[n];
    printf("Now , Enter the elements on it : \n");
    for(int i = 0 ;i < n ;i ++ ){
        scanf("%d" , &array[i]);
    }
    printf("This is your array before sorting : \n\n");
    for(int i = 0 ;i < n;i ++ ){
        printf("%d " , array[i]);
    }
    MergeSort(array , 0, n - 1);

    printf("\n\nMerge Sort Algorithm O( n logn ): \n");
    for(int i = 0 ;i < n ;i ++ ){
        printf("%d " , array[i]);
    }





    return 0;
}
