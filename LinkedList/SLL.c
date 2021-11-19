#include <stdio.h>
#include <stdlib.h>

//create struct node and install variables
struct node
{
int data;
struct node *next;
}*m,*first=NULL,*last,*n,*prev,*temp;

//---------------INSERT FUNCTIONS---------------------//
//create a node
void create()
{
    int x;
    printf("enter a value : ");
    scanf("%d",&x);
    n=(struct node*)malloc(sizeof(struct node));
    n->data=x;
    n->next=NULL;
    if(first==NULL)
    {
        first=n;
        last=n;
    }
    else
    {
        last->next=n;
        last=n;
    }
}

//insert value at begin
void insert_begin()
{
     int x;
    printf("enter a value : ");
    scanf("%d",&x);
    n=(struct node*)malloc(sizeof(struct node));
    n->data=x;
    n->next=NULL;
    n->next=first;
    first=n;
}

//insert a value at end
void insert_end()
{
      int x;
    printf("enter a value : ");
    scanf("%d",&x);
    n=(struct node*)malloc(sizeof(struct node));
    n->data=x;
    n->next=NULL;
    last->next=n;
    last=n;
}

//insert a value before a element
void insert_before()
{
      int x,key;
    printf("enter a value : ");
    scanf("%d",&x);
    n=(struct node*)malloc(sizeof(struct node));
    n->data=x;
    n->next=NULL;
    temp=first;
    printf("enter key : ");
    scanf("%d",&key);
    while(temp->next!=NULL)
    {
        if(temp->data==key)
        break;
        else
        {
            prev=temp;
            temp=temp->next;
        }
        n->next=temp;
        prev->next=n;
    }
}

//insert a value after an element
void insert_after()
{
    int x,key;
    printf("enter a value : ");
    scanf("%d",&x);
    n=(struct node*)malloc(sizeof(struct node));
    n->data=x;
    n->next=NULL;
    temp=first;
    printf("enter key : ");
    scanf("%d",&key);
    while(temp->next!=NULL)
    {
        if(temp->data==key)
        break;
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
}

//display node elements
void display()
{
    m=first;
    while(m!=NULL)
    {
        printf("%d->",m->data);
        m=m->next;
    }printf("\n");
}
//-------------------------------------------------------//

//----------------------DELETE FUNCTIONS-----------------//
//delete first element
void delete_begin(){
    if(first==NULL){
        printf("List is empty\n");
    }
    else{
        m=first;
        first=first->next;
        free(m);
        printf("Removed first element\n");
    }
}
//delete last element
void delete_end(){
    if(first==NULL)
        printf("List is empty\n");
    else
    {
        temp=first;
        while(temp!=last)
        {
            prev=temp;
            temp=temp->next;
        }
        m=last;
        last=prev;
        last->next=NULL;
        printf("%d is deleted\n",m->data);
        free(m);
    }
}
//delete a element
void delete_element(){
    int r;
    printf("Enter value : ")
    scanf("%d",&r);
    if(first==NULL){
        printf("List is empty\n");
    }
    else{
        temp=first;
        while(temp->data!=r)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        m=temp;
        printf("%d is deleted\n",m->data);
        free(m);
    }
}


//-------------------------------------------------------//
//main function
int main()
{
    int ch;
    printf("enter MENU\n");
    do{
        printf("1.create\n2.display\n3.insert_begin\n4.insert_end\n5.insert_before\n6.insert_after\n7.Delete Begin\n8.Delete End\n9.Delete Element\n");
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
            case 4:insert_end();
            break;
            case 5:insert_before();
            break;
            case 6:insert_after();
            break;
            case 7:delete_begin();
            break;
            case 8:delete_end();
            break;
            case 9:delete_element();
            break;
        }
    }while(ch<=9);
}
