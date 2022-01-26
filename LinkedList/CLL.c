#include<stdio.h>
#include<stdlib.h>

void create();
void insert_begin();
void insert_before();
void insert_after();
void del_begin();
void del();
void display();

struct node{
    int data;
    struct node *next;
}*first=NULL,*last,*n,*temp,*prev;

//main function
int main()
{
    int ch=0;
    printf("enter MENU\n");
    while(ch<=7){
        printf("1.create\n2.display\n3.insert_begin\n4.insert_before\n5.insert_after\n6.Delete Begin\n7.Delete\n");
        printf("enter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();
                break;
            case 2:display();
                break;
            case 3:insert_begin();
                break;
            case 4:insert_before();
                break;
            case 5:insert_after();
                break;
            case 6:del_begin();
                break;
            case 7:del();
                break;
        }
    }
}

//create a node
void create(){
    n = (struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter data:");
    scanf("%d",&n->data);
    n->next=NULL;
    if(first==NULL){
        first=n;
        last=n;
    }
    else{
        last->next=n;
        last=n;
    }
    last->next=first;
}

//insert begin
void insert_begin(){
    n = (struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter data : ");
    scanf("%d",&x);
    n->data=x;
    last->next=n;
    n->next=first;
    first=n;
}

//insert after
void insert_after(){
    n = (struct node*)malloc(sizeof(struct node));
    int x,k;
    printf("Enter element after which u want to insert :");
    scanf("%d",&k);
    printf("Enter data : ");
    scanf("%d",&x);
    n->data=x;
    temp=first;
    while(temp!=NULL){
        temp=temp->next;
        if(temp->data=k){
            break;
        }
        
    }
    n->next=temp->next;
    temp->next=n;
}

//insert before
void insert_before()
{
    int k;
    n=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&n->data);
    n->next=NULL;
    printf("Enter Element before which you want to insert:");
    scanf("%d",&k);
    temp=first;
    while(temp!=NULL)
    {
        if(temp->data==k)
            break;
        else
        {
            prev=temp;
            temp=temp->next;
        }
    }
    n->next=temp;
    prev->next=n;
}

//delete begin
void del_begin(){
    temp = first;
    first = first->next;
    last->next=first;
    free(temp);
}

//delete Element
void del(){
    int k;
    printf("Enter element to delete : ");
    scanf("%d",&k);
    temp=first;
    while(temp!=NULL){
        if(temp->data==k)
            break;
        else{
            prev=temp;
            temp = temp->next;
        }
    }
    prev->next=temp->next;
    free(temp);
}

//display elements
void display(){
    temp=first;
    do{
        printf("%d\n",temp->data);
        temp=temp->next;
    }while(temp!=first);
}


