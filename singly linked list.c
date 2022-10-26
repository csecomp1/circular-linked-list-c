//singly circular linked list
#include<stdio.h>
#include<stdlib.h>
int count();
struct node *head;
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL,*tail=NULL;
void creation()
{
    struct node *newnode;
    int c=1;
    tail=NULL;
    while(c==1)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter number:");
        scanf("%d",&newnode->data);

        if(tail==NULL)
        {
               tail=newnode;
           tail->next=newnode;
        }
        else
        {
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }

        printf("\nDo you want to continue: (1,0)");
        scanf("%d",&c);
    }

}
void beginsert()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter element to insert: ");
    scanf("%d",&newnode->data);
    if(tail==NULL){
          tail=newnode;
        tail->next=newnode;
    }
 else{
    newnode->next=tail->next;
    tail->next=newnode;
 }
}
void   lastinsert()
{struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter element to insert: ");
    scanf("%d",&newnode->data);
  newnode->next=tail->next;
  tail->next=newnode;
  tail=newnode;
}

void randominsert()
{
    int pos, l;
    struct node *temp,*newnode;
    printf("\nEnter  position to insert");
    scanf("%d",&pos);
    temp=tail->next;
    l=count();
    if(pos>l)
    {
        printf("\n Invalid position");
    }
    else
    {
        int i=1;
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter element: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        temp=tail->next;

        while(i<pos-1)
        {

            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }


}
void begin_delete()
{
    struct node *temp;
    temp=tail->next;
    if(temp==NULL)
    {
        printf("\nList is Empty");
    }
    else if(temp->next==tail)
    {
        tail=NULL;
       free(temp);
    }
else{
   tail->next=temp->next;
   free(temp);

}

}
void last_delete()
{
    struct node *curr,*pre;
   curr=tail->next;
   if(tail==NULL)
    printf("\nNo elements");
   else if(curr->next==tail->next)
   {
       tail=NULL;
       free(curr);
   }
   else{
    while(curr->next!=tail->next)
    {
        pre=curr;
        curr=curr->next;
    }
    pre->next=tail->next;
    tail=pre;

    free(curr);

   }
}
void random_delete()
{
    int pos,i=1,l;
    struct node *nextnode ,*currnode  ;
    printf("\nEnter position: ");
    scanf("%d",&pos);
    l=count();
    if(pos>l)
    {
        printf("\nInvalid Position");
    }

    else
    {
       currnode =tail->next;
        while(i<pos-1)
        {

            currnode=currnode->next;
            i++;
        }
        nextnode=currnode->next;
        currnode->next=nextnode->next;
        free(nextnode);
    }
}
void search()
{ struct node *temp;
    int num,i=1;
    printf("\nEnter element to search: ");
    scanf("%d",&num);
    temp=tail->next;

    while(temp->next!=tail->next)
    {
        if(temp->data==num)
        {
            printf("\nThe position of element is %d",i);
            break;
        }
        else
        {
            temp=temp->next;
            i++;
        }
    }
}

int count()
{   int cnt=1;
    struct node *temp;
    temp=tail->next;
    while(temp->next!=tail->next)
    {
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
void display()
{

 struct node *temp;
    temp=tail->next;
    while(temp->next!=tail->next)
    {
        printf("%d       ",temp->data);
        temp=temp->next;


    }
    printf("%d",temp->data);
}

int main()
{
    int g=1;
    int choice =0;
    do
    {
        printf("\n\n****Main Menu****\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n 5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n10.create linked list \n");
        printf("\nEnter your choice?\n");
        scanf("\n%d",&choice);
        switch(choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            randominsert();
            break;
        case 4:
            begin_delete();
            break;
        case 5:
            last_delete();
            break;
        case 6:
            random_delete();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        case 10:
            creation();
            break;
        default:
            printf("Please enter valid choice..");
        }

    }while(g);
}
