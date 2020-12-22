#include<stdio.h>
#include <stdlib.h>
struct node
{
    int ngay;
    int thang;
    int nam;
    struct node* pnext;
};
struct linked_list
{
    struct node* phead;
    struct node* ptail;
};
struct node* createnode(int ngay_new_node, int thang_new_node, int nam_new_node)
{
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    newnode->ngay= ngay_new_node;
    newnode->thang= thang_new_node;
    newnode->nam= nam_new_node;
    newnode->pnext= NULL;
    return newnode;
};
void intit_linked_list(struct linked_list *list)
{
    list->phead= NULL;
    list->ptail= NULL;
}
void insert_tail(struct linked_list* list, int ngay_new_node,int thang_new_node, int nam_new_node)
{
    struct node*newnode=createnode(ngay_new_node,thang_new_node,nam_new_node);
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
    int nam,thang,ngay;
    int k=0,i;
    int j=1;
    int maxnam=-1;
    int temp[100000];
    scanf("%d",&n);
        for(i=0;i<n;i++)
    {
        scanf("%d %d %d ",&ngay,&thang,&nam);
        insert_tail(&list,ngay,thang,nam);
    }
    insert_tail(&list,1000,1000,1000);
    struct node* p = list.phead;
    while (p->pnext!= NULL)
    {
        if(p->nam>maxnam)
        {
            maxnam=p->nam;
        }
    }
    for(i=0;i<k;i++)
    {
        printf("%d ",j);
    }
    clear_linked_list(&list);
    return 0;
}
