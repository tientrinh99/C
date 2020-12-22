#include<stdio.h>
#include <stdlib.h>
struct node
{
    float data;
    struct node* pnext;
};
struct linked_list
{
    struct node* phead;
    struct node* ptail;
};
struct node* createnode(float data_newnode)
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
void insert_tail(struct linked_list* list, float data_newnode)
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
    float n;
    int k=0,i;
    float temp[1000];
    do
    {
        scanf("%f",&n);
        insert_tail(&list,n);
    }
    while (n!=-1);
    struct node* p = list.phead;
    while (p->pnext!= NULL)
    {
        if(p->data<5.0)
        {
            temp[k]=p->data;
            k++;
        }
        p=p->pnext;
    }
    for(i=0;i<k;i++)
    {
        printf("%0.1f\n",temp[i]);
    }
    clear_linked_list(&list);
    return 0;
}
