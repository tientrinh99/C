#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<math.h>
bool checkisprime(int n)
{
    int check=1;
    int i;
    if (n<2)
    {
        check=0;
    }
    else
    {
        for(i=2;i<n-1;i++)
        {
            if(n%i==0)
            {
                check=0;
                break;
            }
        }
    }
    return check;
}
struct node
{
    int data;
    struct node* pnext;
};
struct linked_list
{
    struct node* phead;
    struct node* ptail;
};
struct node* createnode(int data_newnode)
{
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data= data_newnode;
    newnode->pnext= NULL;
    return newnode;
};
void intit_linked_list(struct linked_list *list)
{
    list->phead= NULL;
    list->ptail= NULL;
}
void insert_tail(struct linked_list* list, int data_newnode)
{
    struct node*newnode=createnode(data_newnode);
    if(list->phead==NULL)
    {
        list->phead=newnode;
        list->ptail=newnode;
    }
    else
    {
        list->ptail->pnext=newnode;
        list->ptail=list->ptail->pnext;
    }
}
void clear_linked_list(struct linked_list* list) {
    struct node* p = list->phead;
    while (p != NULL) {
        struct node* tmp = p->pnext;
        free(p);
        p = tmp;
    }

    list->phead = NULL;
    list->ptail = NULL;
}
int main ()
{
    struct linked_list list;
    intit_linked_list(&list);
    int n;
    int k=0,i;
    int temp[1000];
    {
        scanf("%d",&n);
        insert_tail(&list,n);
    }
    while (n!=-1);
    struct node* p = list.phead;
    while (p->pnext!= NULL)
    {
        if(checkisprime(p->data)==1)
        {
            k++;
        }
        p=p->pnext;
    }
        printf("%d\n",k);
    clear_linked_list(&list);
    return 0;
}
