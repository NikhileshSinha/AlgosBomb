#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coefficient;
    int power;
    struct node *next;
};

struct node *poly01 = NULL;
struct node *poly02 = NULL;
struct node *poly03 = NULL;

void InsertPoly(int i, int poww, int coeff)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->power = poww;
    t->coefficient = coeff;

    t->next = NULL;
    if(i==1){
        if (poly01 == NULL)
        {
            poly01 = t;
        }
        else
        {
            t->next = poly01;
            poly01 = t;
        }
    }
    if(i==2){
        if (poly02 == NULL)
        {
            poly02 = t;
        }
        else
        {
            t->next = poly02;
            poly02 = t;
        }
    }
    if(i==3){
        if (poly03 == NULL)
        {
            poly03 = t;
        }
        else
        {
            t->next = poly03;
            poly03 = t;
        }
    }
}

void display(struct node *head)
{
    struct node *t = head;
    if (t == NULL)
    {
        printf("Polynomial is empty\n");
    }
    else
    {
        while (t != NULL)
        {
            printf("Power: %d, coefficient: %d\n", t->power, t->coefficient);
            t = t->next;
        }
    }
}

void Polynomialaddition(struct node *p1 , struct node *p2, struct node *p3){
    struct node *t1 = p1, *t2 = p2;
    if (t1 == NULL && t2 == NULL)
    {
        printf("Both polynomials are empty\n");
    }
    else
    {
        while (t1 != NULL)
        {
            int pwr =t1->power, flag=0;
            t2 = p2;
            while (t2 != NULL)
            {
                if (pwr == t2->power)
                {
                    InsertPoly(3, pwr, (t1->coefficient + t2->coefficient));
                    flag=1;
                }
                t2 = t2->next;
            }
            if(flag==0){
                InsertPoly(3, pwr,t1->coefficient);
            }
            t1 = t1->next;
        }
    }
}

int main()
{
    
    int n, i, j, deg, coff;
    printf("Enter the degree of the 1st polynomial :");
    scanf("%d", &deg);
    for (j = 0; j <= deg; j++)
    {
        printf("Enter the coefficient whose degree is %d :",j);
        scanf("%d", &coff);
        InsertPoly(1, j, coff);
    }

    printf("Enter the degree of the 2nd polynomial :");
    scanf("%d", &deg);
    for (j = 0; j <= deg; j++)
    {
        printf("Enter the coefficient whose degree is %d :", j);
        scanf("%d", &coff);
        InsertPoly(2, j, coff);
    }

    printf("p1:\n");
    display(poly01);
    printf("p2:\n");
    display(poly02);

    printf("Start Adding\n\n");
    Polynomialaddition(poly01, poly02, poly03);

    printf("\n\np3:\n");
    display(poly03);
}
