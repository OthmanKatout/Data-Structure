#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {

int number;
struct Node * next;


}Node;

Node * creat(int number){

if(number <= 0 ){
    return NULL;
}

Node * first = malloc(sizeof(Node));
Node * help = malloc(sizeof(Node));
int num;

printf("Enter a number : ");
scanf("%d",&num);

first->number = num ;
first->next = NULL;
help = first ;

for(int i = 0 ;i < number - 1 ;i ++ ){
    Node * new_Node = malloc(sizeof(Node));
    printf("Enter a new number ");
    scanf("%d",&num);
    new_Node->number = num;
    new_Node->next=NULL;
    help->next = new_Node;
    help = new_Node;
}

return first ;

}

void Display(Node * it){

Node * it2 = it ;
while(it2){
    printf("%d " , it2->number);
    it2 = it2 ->next;
}
printf("\n");
}
int Number_of_Nodes(Node * it){

if(it ->next == NULL){
    return 1 ;
}

return 1 + Number_of_Nodes(it->next);

}

int SumVal(Node * node){

if(node ->next == NULL){
    return node->number;
}

return node->number + SumVal(node ->next);

}

int max(Node * it){
int mx = -1 ;
while(it ){
    if(it->number > mx){
        mx = it ->number ;
    }
    it = it ->next;
}
return mx ;

}


Node * Replace(Node * head , int number1 , int number2 ){

if(number1 == number2 || head == NULL){
    return head;
}


Node * prev1 = NULL , * ptr1 = head;
Node * prev2 = NULL , * ptr2 = head;

while(ptr1 != NULL){

    if(ptr1 ->number == number1){
      break;
    }
    prev1 = ptr1;
    ptr1 = ptr1->next;
}

while(ptr2 != NULL){

    if(ptr2 ->number == number2){
      break;
    }
    prev2 = ptr2;
    ptr2 = ptr2->next;
}

if(ptr1 == NULL || ptr2 == NULL){
    return head;
}

if(prev1 != NULL){
    prev1->next = ptr2;
}
else{
    head = ptr2;
}
if(prev2 != NULL){
    prev2->next = ptr1 ;
}
else{
    head = ptr1;
}


Node * tmp = ptr1->next;
ptr1->next = ptr2->next;
ptr2->next = tmp;

return head;

}
Node * insert(Node * list , int index , int number){

if(list == NULL || index > Number_of_Nodes(list))return list;

if(index == 0){
    Node *ptr = malloc(sizeof(Node));
    ptr->number = number;
    ptr->next = list;
    list = ptr;
return list;
}
if(index == Number_of_Nodes(list)){
    Node * pointer = list;
    while(pointer->next != NULL){
        pointer = pointer->next;
    }
    Node * node = malloc(sizeof(Node));
    node->number = number;
    pointer->next = node;
    node->next = NULL;
    return list;
}
int point = 1 ;
Node * p = list;
while(p){
    if(point == index){
        Node * element = malloc(sizeof(Node));
        element->number = number;
        element->next = p->next;
        p->next =element;
        break;
    }
    p = p->next;
    point++;
}

return list;

}

Node * creat_ByAdd(Node * List , int number , int index){

if(List == NULL){
    Node * node = malloc(sizeof(Node));
    node->number = number;
    node->next = NULL;
    List = node;
    return List;
}
if(index > Number_of_Nodes(List) || index < 0){
    return List;
}
if(index == 0){
    Node * node = malloc(sizeof(Node));
    node->number = number;
    node->next = List;
    List = node;
    return List;
}
if(index == Number_of_Nodes(List)){

    Node * pointer = List;
    while(pointer ->next != NULL){
        pointer = pointer->next;
    }
    Node * node = malloc(sizeof(Node));
    node->number = number;
    pointer->next= node;
    node->next =NULL;
    return List;
}
Node * ptr = List;
int counter = 1;
while(ptr){
    if(counter == index){
        Node * node = malloc(sizeof(Node));
        node->number = number;
        node->next = ptr->next;
        ptr->next = node;
        return List;
    }
    ptr = ptr->next;
    counter++;
}

}

Node * Insert_Atend(Node * head , int number){

if(head == NULL){
    Node * element = malloc(sizeof(Node));
    element->number = number ;
    element->next = NULL;
    head = element;
    return head;
}

Node * it = head ;
while(it ->next != NULL)it = it->next;
Node * element = malloc(sizeof(Node));
element->number = number;
it->next = element;
element->next =NULL;

return head;

}
Node * Insert_In_Sorting(Node * List , int number){

if(List == NULL){
    Node * element = malloc(sizeof(Node));
    element->number = number;
    element->next = NULL;
    List = element;
    return List;
}
if(List->number >= number){
    Node * newone = malloc(sizeof(Node));
    newone->number = number;
    newone->next = List;
    List = newone;
    return List;
}
Node * it = List ;
while(it->next != NULL){
    Node * it2 = it->next;
    if(it2->number >= number){
        Node * element = malloc(sizeof(Node));
        element->number = number;
        element->next = it2;
        it->next = element;
        return List;
    }
    it =it ->next;
}
Node * element = malloc(sizeof(Node));
element->number = number;
element ->next = NULL;
it->next = element;
return List;

}

Node * Delete_By_Num(Node * Linked , int number ){

if(Linked == NULL){
    return Linked;
}
if(Linked->number == number){
    Node * del = Linked;
    Linked = Linked->next;
    free(del);
    return Linked;
}
Node * p = Linked->next , *q = Linked;
while(p){
    if(p->number == number){
        q->next = p->next;
        free(p);
        return Linked;
    }
    p = p->next;
    q = q ->next;
}

return Linked;


}

bool isSorted(Node * List ){

Node * first = List , * second = List->next;

while(second){

    if(first -> number > second -> number ){
        return false;
    }

    second = second ->next;
    first = first ->next;
}

return true;

}

Node * Remove_Duplicates(Node * List){

if(!List)return List;


Node * ptr = List;


while(ptr){


while(ptr->next ){
        Node * ptr_next = ptr->next;
    if(ptr_next->number == ptr->number){
    Node * next2 = ptr->next;
    ptr->next = next2->next;
    free(next2);
    }else break;
}

    ptr = ptr->next;
}


return List;


}


Node * Reverse(Node * List ){

printf("Enter the Type of reverse you want: \n");
printf("1) using arrays \n2) using sliding windows \n");

int choice;
scanf("%d" , &choice);

if(choice == 1){
    if(!List)return List;
int n = Number_of_Nodes(List) ;
int a[n];
Node * ptr = List;
int in = 0;
while(ptr){
    a[in] = ptr->number;
    in++;
    ptr = ptr->next;
}
in = 0 ; int jn = Number_of_Nodes(List) - 1;
while(in <= jn){
    int tmp = a[in];
    a[in] = a[jn];
    a[jn] = tmp;
    in++;
    jn--;
}

ptr = List;
in = 0;
while(ptr){
    ptr->number = a[in];
    in++;
    ptr = ptr->next;
}

    return List;
}
else if(choice == 2){

if(!List)return List;

Node * first = List;
Node * Second = first->next;
Node * third = malloc(sizeof(Node));
if(Second->next){
    third = Second ->next;
}
else{
    Second->next = first;
    first->next = NULL;
    return Second;
}
first->next = NULL;
while(Second){

    Second->next = first;
    first = Second;
    Second = third;
    if(!Second)break;
    third = third->next;

}

return first;


}


printf("Please Don't joke with me -_- ");
return List;


}


Node * concate(Node * List1 , Node * List2 ){

Node * ptr = List1 ;

while(ptr->next != NULL){
    ptr = ptr->next;
}

ptr ->next = List2;


return List1;

}

Node * merge(Node * List1 , Node * List2 ){

Node * head = NULL , * last = NULL , * f = List1 , *s = List2 ;
if (List1 ->number <= List2 ->number){
    head = List1 ;
    last = head;
    f = f->next;
}
else{
    head = List2 ;
    last = List2 ;
    s = s->next;
}
last ->next = NULL;
while(f && s){
    if(f -> number < s ->number){
        last->next = f;
        last = f;
        f = f->next;
        last ->next = NULL;
    }
    else {
        last->next = s;
        last = s;
        s = s->next;
        last ->next =NULL;
    }
}
if(f == NULL && s == NULL){
    return head;
}
if(f == NULL){
    last ->next = s;
    return head;
}
if(s == NULL){
    last->next = f;
    return head;
}

}

int checkLoop(Node * List ){


Node * ptr = List , *ptr2 = List ->next;
do{

    ptr = ptr->next;
    ptr2 = ptr2->next;
    ptr2 = ptr2->next;

    if(ptr == ptr2){return 1;}


}while(ptr->next != NULL && ptr2->next != NULL);

return 0;

}

Node * Make_Circular_ByAdd(Node * List , int number){

if(List == NULL){
Node * node = malloc(sizeof(Node));
if(!node){
        printf("Sorry !!\n");
return List;
}
node->number = number;
node->next = node;
return node;
}
Node * ptr2 = List;
while(ptr2->next != List ){
    ptr2 = ptr2->next;
}
Node * node  = malloc(sizeof(Node));
if(!node){
    printf("Sorry!!\n");
    return List;
}
node->number = number;
node->next = List;
ptr2->next = node;

return List;

}

void display_Circular(Node * List ){


Node *ptr = List;
do{

    printf("%d ", ptr->number);
    ptr = ptr->next;

}while(ptr != List);

}

Node * Delete_Circle(Node * List , int number ){


// Search the number :
if(List == NULL)return List;
Node * ptr = List;

do{

    ptr = ptr->next;

}while(ptr != List && ptr ->number != number);


if(ptr == List){


    Node * last = List;
    while(last ->next != List)last = last->next;
    last->next = List->next;
    List = List->next;
    free(ptr);

}
else if(ptr ->next == List) {

    Node * prev = List;
    while(prev ->next != ptr){prev = prev->next;}
    prev->next = List;
    free(ptr);

}
else{

    Node * prev = List;
    while(prev->next != ptr){prev = prev->next;}
    prev ->next = ptr->next;
    free(ptr);

}

return List;

}

bool isdisjoint(Node * List , Node * List2){


if(List == NULL || List2 == NULL)return true;

Node * ptr = List , *ptr2 = List2 ;

while(ptr != NULL){

    while(ptr2 && ptr2 ->number <= ptr->number){
        if(ptr->number == ptr2->number)return false;
    ptr2 = ptr2->next;
    }
    ptr = ptr->next;

}


return true;


}

bool recisdisjoint(Node * List1 , Node * List2){

if(!List1 || !List2 )return true;
if(List1->number == List2->number)return false;
if(List1 ->number >= List2 ->number){
    return recisdisjoint(List1 , List2->next);
}
else{
    return recisdisjoint(List1 ->next , List2);
}


}



Node * swappairs(Node * List ){


if(!List)return List;


Node * dummy = malloc(sizeof(Node));

dummy->number = 0;
dummy->next = List;


Node * prev = dummy , * current = List , * Second = List->next;


while(Second){

    Node * Third = Second->next;

    Second->next = current;
    current->next = Third;
    prev->next = Second;

    //---------
    Second = Third;
    current = Third;
    if(!Second)break;
    Second = Second ->next;
    prev = prev->next;
    if(!prev)break;
    prev = prev->next;
}


return dummy->next;


}

Node * DeleteList(Node * List){

if(!List)return List;

while(List){
    Node * ptr = List;
    List = List->next;
    free(ptr);
}

return NULL;


}

bool isempty(Node * List){

return List == NULL;

}


int main(){

printf("Create Linked List with initially 5 elements of your choice \n");

Node * Linked_List = creat(5);
printf("--------------------------------------\n");
printf("Display All the elements of the Linked List : \n");
printf("--------------------------------------\n");
Display(Linked_List);
printf("--------------------------------------\n");
printf("Calculate the number of Nodes in the linked list : \n");
printf("--------------------------------------\n");
printf("%d \n" , Number_of_Nodes(Linked_List));
printf("--------------------------------------\n");
printf("Calculate the Sum of the elements : \n");
printf("--------------------------------------\n");
printf("Sum : %d\n",SumVal(Linked_List));
printf("--------------------------------------\n");
printf("Max element in the Linked List \n");
printf("--------------------------------------\n");
printf("Max Element : %d \n",max(Linked_List));
printf("--------------------------------------\n");
printf("Replace Two Numbers on it : \n");
printf("--------------------------------------\n");
int number1 , number2 ;
printf("Enter Two numbers to Swap\n");
scanf("%d%d",&number1 , &number2 );
Linked_List = Replace(Linked_List , number1 , number2 );
Display(Linked_List);
printf("--------------------------------------\n");
printf("Insert on it : \n");
printf("--------------------------------------\n");
printf("Enter the index to insert and the number to insert : ");
int index , number;
scanf("%d%d",&index , &number);
Linked_List = insert(Linked_List , index , number);
Display(Linked_List);
printf("--------------------------------------\n");
printf("Create new Linked list by adding elements to it : \n");
printf("--------------------------------------\n");
Node * Linked_List2 = NULL;
Linked_List2 = creat_ByAdd(Linked_List2 , 10 , 0);
Linked_List2 = creat_ByAdd(Linked_List2 , 15 , 0);
Display(Linked_List2);
printf("--------------------------------------\n");
printf("insert by the end of the Linked List number 90 : \n");
printf("--------------------------------------\n");
Linked_List = Insert_Atend(Linked_List , 90);
Display(Linked_List);
printf("--------------------------------------\n");
printf("Inserting in the sorted Linked List: \n");
printf("--------------------------------------\n");
printf("Enter a number to insert : ");
int NUM;
scanf("%d",&NUM);
Linked_List = Insert_In_Sorting(Linked_List , NUM);
Display(Linked_List);
printf("--------------------------------------\n");
printf("Delete an element by his value : \n");
printf("--------------------------------------\n");
printf("Enter the Element : ");
int element ;
scanf("%d",&element);
Linked_List = Delete_By_Num(Linked_List , element);
Display(Linked_List);
printf("--------------------------------------\n");
printf("Is this List sorted or not ? \n");
printf("--------------------------------------\n");

if(isSorted(Linked_List)){
    printf("It is Sorted : ) \n");
}
else{
    printf("It is not Sorted : ( \n");
}
printf("--------------------------------------\n");
printf("if its a Sorted Linked list , i will delete all the duplicates on it : \n");
printf("--------------------------------------\n");
if(isSorted(Linked_List)){
    Linked_List = Remove_Duplicates(Linked_List);
    Display(Linked_List);
}
else{
    printf("Sorry it is not sorted \n");
}
printf("--------------------------------------\n");
printf("Reverse The Linked List : \n");
printf("--------------------------------------\n");
Linked_List = Reverse(Linked_List);
Display(Linked_List);
printf("--------------------------------------\n");
printf("The List 1 and List 2 concatenate \n");
printf("--------------------------------------\n");
Node * List_Concate = concate(Linked_List , Linked_List2);
Display(List_Concate);
printf("--------------------------------------\n");
printf("The result of merging two sorted Linked Lists \n");
printf("--------------------------------------\n");
printf("Now its up to you to make a sorted Linked Lists of 5 elements : \n");
printf("Create Linked List with initially 5 elements of your choice \n");
Node * List1 = creat(5);
printf("Create Linked List with initially 5 elements of your choice \n");
Node * List2 = creat(5);
if(isSorted(List1) && isSorted(List2)){
   List1 = merge(List1 , List2);
   Display(List1);
}
else{
    printf("OH , No ... It's Not sorted yet :( ");
}

//printf("--------------------------------------\n");
//printf("The First Linked List is a Loop Linked List : %s \n" , checkLoop(Linked_List) ? "TRUE" : "FALSE");
//printf("--------------------------------------\n");
//undefined reference to checkLoop :(


printf("--------------------------------------\n");
printf("The Circular Linked List : \n");
printf("--------------------------------------\n");
Node * Linked_List_Circular = NULL;
Linked_List_Circular = Make_Circular_ByAdd(Linked_List_Circular , 10);
Linked_List_Circular = Make_Circular_ByAdd(Linked_List_Circular , 20);
Linked_List_Circular = Make_Circular_ByAdd(Linked_List_Circular , 30);
Linked_List_Circular = Make_Circular_ByAdd(Linked_List_Circular , 40);
display_Circular(Linked_List_Circular);
Linked_List_Circular = Delete_Circle(Linked_List_Circular , 20);
Linked_List_Circular = Delete_Circle(Linked_List_Circular , 40);
printf("\nAfter Deleting 20 and 40 from the Circular Linked List : \n");
display_Circular(Linked_List_Circular);
Node * List_1 = Insert_In_Sorting(List_1 , 10);
List_1 = Insert_In_Sorting(List_1 , 20);
List_1 = Insert_In_Sorting(List_1 , 20);
List_1 = Insert_In_Sorting(List_1 , 40);
Node * List_2 = Insert_In_Sorting(List_2 , 5);
List_2 = Insert_In_Sorting(List_2 , 5);List_2 = Insert_In_Sorting(List_2 , 6);List_2 = Insert_In_Sorting(List_2 , 11);
printf("--------------------------------------\n");
printf("are the Two sorted lists disjoint ?\n");
printf("The answer : %s " ,(isdisjoint(List_1 , List_2) ? "YES\n" :"NO\n"));
printf("--------------------------------------\n");
printf("Same as recursion : %s " , (recisdisjoint(List_1 , List_2) ? "YES\n" : "NO\n"));
printf("--------------------------------------\n");
printf("Swap pairs : \n");
Display(swappairs(Linked_List));
printf("--------------------------------------\n");
printf("I will create a linked list of length 3 and then delete it : '10 20 30'");


Node * first = malloc(sizeof(Node));
Node * second = malloc(sizeof(Node));
Node * third = malloc(sizeof(Node));


first->number = 10;
second ->number = 20;
third->number = 30;

first->next = second;

second->next = third;
third->next = NULL;

first = DeleteList(first);

printf("\nIs this list empty ? : %s " , ( isempty(first) ? "YES\n" : "NO\n" ) );





    return 0;
}
