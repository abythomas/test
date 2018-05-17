#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

void insert(int data, struct Node **head,struct Node **tail){
  if((*head)==NULL)
  {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->next=NULL;
    (*head)=new_node;
    (*tail)=new_node;
  }
  else{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->next=NULL;
    (*tail)->next=new_node;
    (*tail)=new_node;
  }
}

void printlist(struct Node **head)
{
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node=(*head);
  while(new_node!=NULL)
  {
    printf("%d ",new_node->data);
    new_node=new_node->next;
  }
  printf("\n");
}

void reverse(struct Node **head)
{
  if((*head)==NULL)
  {
    return;
  }
  struct Node* fnode = (struct Node*) malloc(sizeof(struct Node));
  struct Node* rest = (struct Node*) malloc(sizeof(struct Node));
  fnode=(*head);
  rest=fnode->next;

  if(rest==NULL)
  {
    return;
  }
  reverse(&rest);
  fnode->next->next=fnode;
  fnode->next=NULL;
  (*head)=rest;
}

int main()
{
   int inp_val;
   struct Node* head = NULL;
   struct Node* tail = NULL;
   printf("Enter node values (enter -1 to stop)\n");
   scanf("%d",&inp_val);
   while(inp_val!=-1)
   {
     insert(inp_val,&head,&tail);
     scanf("%d",&inp_val);
   }
   printf("Printing linked list...\n" );
   printlist(&head);
   printf("Reversing linked list...\n");
   reverse(&head);
   printf("Printing reversed linked list...\n" );
   printlist(&head);
}
