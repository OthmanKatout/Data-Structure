#include <stdio.h>
#include <stdlib.h>

typedef struct {


struct Node* next;
int data;

}Node;

typedef Node * Chan;

void Insert(Chan a [] , int index , int number){


Chan m = (Chan)malloc(sizeof(Node));
if(!m ){
    printf("Sorry :( \n");
    return ;
}
m->data = number;

m->next = a[index]->next;
a[index]->next = m;


}

int main()
{

Chan c [10];


for(int i = 0 ;i < 10 ;i ++){

Chan m = (Chan)malloc(sizeof(Node));
m->data = -1;
m->next = NULL;
c[i] = m;
}

int ch;

do{

scanf("%d",&ch);
if(ch != -1)
Insert(c , ch % 10 , ch);

}while(ch != -1);


for(int i = 0 ;i < 10 ; i ++ ){

Chan p = c[i]->next;
while(p){
    printf("%d ",p->data);
    p = p->next;
}
printf("\n");

}


    return 0;
}
