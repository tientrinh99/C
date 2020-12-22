#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
typedef struct node NODE;
struct linked_list
{
    NODE *head;
    NODE *tail;
};
typedef struct linked_list LINKED_LIST;
NODE *createnode(int new_data)
{
    NODE* p= (NODE*)malloc(sizeof(NODE));

    p->data= new_data;
    p->next= NULL;
    return p;
}
void intit_linked_list(LINKED_LIST *list)
{
    list->head= NULL;
    list->tail= NULL;
}
void insert_tail(LINKED_LIST* list,int data)
{
    NODE* p=createnode(data);
    if(list->head==NULL && list->tail==NULL )
    {
        list->head=p;
        list->tail=p;
    }
    else
    {
        list->tail->next=p;
        list->tail=list->tail->next;
    }

}
void clear_linked_list(LINKED_LIST* list) {
    NODE* p = list->head;
    while (p != NULL) {
        NODE* tmp = p->next;
        free(p);
        p = tmp;
    }

    list->head = NULL;
    list->tail = NULL;
}
int main()
{
    LINKED_LIST list;
    intit_linked_list(&list);
    int n;
    int i;
    int k=0;
    int temp[100000];
    int data;
    scanf("%d",&n);
        for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        insert_tail(&list,data);
    }
    insert_tail(&list,1000);
    struct node* p = list.head;
        while (p->next!= NULL)
    {
        if(p->data%5!=0 || p->data%10==0 )
        {
            temp[k]=p->data;
            k++;
        }
        p=p->next;
    }
    for(i=0;i<k;i++)
    {
        printf("%d ",temp[i]);
    }
    clear_linked_list(&list);
    return 0;
}
