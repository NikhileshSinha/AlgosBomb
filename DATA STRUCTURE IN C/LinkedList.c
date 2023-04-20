#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct node *h = NULL;

void firstInsert()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int ele;
    printf("Enter the value:\n");
    scanf("%d", &ele);
    temp->val = ele;
    temp->next = NULL;

    if (h == NULL)
    {
        h = temp;
    }
    else
    {
        printf("List is not empty\n");
        temp->next = h;
        h = temp;
        printf("Node inserted at begning\n");
    }
}

void display()
{
    struct node *t = h;
    if (t == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (t != NULL)
        {
            printf("%d ", t->val);
            t = t->next;
        }
    }
}


void lastInsert(){
    struct node *t = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value:\n");
    int ele;
    scanf("%d", &ele);
    t->val = ele;
    t->next = NULL;

    if(h == NULL){
        h=t;
    }
    else{
        struct node *p = h;
        while(p->next != NULL){
            p=p->next;
        }
        p->next = t;
    }
}

void delFirst(){
    if(h == NULL){
        printf("LinkedList is empty\n");
    }
    else{
        h = h->next;
    }
}

void delLast(){
    if (h == NULL){
        printf("LinkedList is empty\n");
    }
    else{
        struct node *p = h, *q;
        while(p->next != NULL){
            q=p;
            p = p->next;
        }
        q->next = NULL;
    }
}

void delRandom(int v){
    if (h == NULL)
    {
        printf("LinkedList is empty\n");
    }
    else
    {
        struct node *p = h, *q;
        int c = 1;
        while (p->next != NULL && c<v)
        {
            c++;
            p = p->next;
        }
        q = p->next;
        q = q->next;
        p->next = q;
    }
}

    int
    main()
{
    int a;
    while (1)
    {
        printf("\n1.Fisrt Insert\n2.Last Insert\n3.First Delete\n4.Last delete5.Random Delete\n6.display\n7.exit\n\n");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
            firstInsert();
            break;
        case 2:
            lastInsert();
            break;
        case 3:
            delFirst();
            break;
        case 4:
            delLast();
            break;
        case 5:
            printf("Enter the node value:\n");
            int valueOfNode;
            scanf("%d", &valueOfNode);
            delRandom(valueOfNode);
            break;
        case 6:
            display();
            break;
        case 7:
            exit(1);
            break;

        default:
            break;
        }
    }
}
