#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
}*n,*m,*first=NULL,*last=NULL,*temp;

//create
void create(){
    int x;
    n=(struct node*)malloc(sizeof(struct node));
    
    printf("Enter data:");
    scanf("%d",&x);
    n->data=x;
    n->next=NULL;
    n->prev = NULL;
    if(first==NULL){
        first=n;
        last=n;
    }
    else{
        n->prev=last;
        n->next=NULL;
        last->next=n;
        last=n;
        
    }
}

//insert begin
void insertbeg(){
    int x;
    n = (struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&x);
    n->data =x;
    
    if(first==NULL){
        printf("List is empty\n");
    }
    else{
        n->prev = NULL;
        n->next = first;
        first->prev = n;
        first = n;
    }
}

//del begin
void delbeginn(){
 m = (struct node*)malloc(sizeof(struct node));
  
    if(first==NULL){
        printf("List is empty\n");
        
    }
    else{
        m=first;
        first = m->next;
        first->prev = NULL;
        }
    free(m);
}

//del end
void delend(){
    m = (struct node*)malloc(sizeof(struct node));
    if(first==NULL){
        printf("List is empty");
        
    }
    else{
        m=last;
        last = m->prev;
        last->next = NULL;
    }
    free(m);
}
//del element
void delelement(){
    int k;
    scanf("%d",&k);
    m = (struct node*)malloc(sizeof(struct node));
    if(first==NULL){
        printf("List is empty");
        
    }
    else{
        m=first;
        while(m!=NULL){
            if(m->data=k){
                break;
            }
            m=m->next;
            
        }
    }
}
//display
void display(){
    m=first;
    while(m!=NULL){
        printf("%d-->",m->data);
        m = m->next; 
    }
}

//main
int main(){
    int ch;
    do{
    printf("\n1.create\n2.display\n3.insert begin\n4.Del begin\n5.Del end\n");
    printf("Enter option:");
    scanf("%d",&ch);
    switch(ch){
        case 1:create();
        break;
        case 2:display();
        break;
        case 3:insertbeg();
        break;
        case 4:delbeginn();
        break;
        case 5:delend();
        break;
        default:
        return;
    }
    }while(ch<=5);
}