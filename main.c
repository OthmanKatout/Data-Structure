#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int max(char c[][50] , int n){

int mx = 0 ;

for(int i = 0 ;i < n ;i ++ ){

    if(strlen(c[i]) > mx ){
        mx = strlen(c[i]);
    }
}
return mx;
}

void count_sort(char c[][50] , int n , int pos){

char answer[n][50];
char count[26]={0};

for(int i = 0 ;i < n ;i ++ ){
    if(pos < strlen(c[i])){
        count[c[i][pos] - 'a']++;
    }
    else{
        count[0]++;
    }
}

for(int i = 1 ;i < 26 ;i ++ ){
    count[i]+=count[i - 1];
}

for(int i = n - 1 ; i > -1 ;i --){
int index = (pos < strlen(c[i]) ? ( c[i][pos] - 'a' ) : 0 );
strcpy(answer[count[index] - 1] , c[i]);
count[index]--;
}

for(int i = 0 ;i < n; i ++ ){
    strcpy(c[i] , answer[i]);
}


}
void radix_sort(char c[][50] , int n){

int max_len = max(c , n);

for(int i = max_len - 1 ; i > -1 ; i--){

    count_sort(c , n , i);

}

}


int main()
{

char letter [5][50] = {"othman" , "need" , "money" , "now" , "please"};

radix_sort(letter , 5);

for(int i = 0 ;i < 5 ;i ++ ){
    printf("%s \n" , letter[i]);
}



    return 0;
}
