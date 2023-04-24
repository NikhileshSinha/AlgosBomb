#include<stdio.h>
#define size 5
int queue[size], front = -1, rear = -1;

void enqueue(){
    if(rear == size-1)
        printf("Stack is full\n");
    else{
        if (front == -1)
            front++;
        printf("Enter element: \n");
        scanf("%d", &queue[++rear]);
    }
}

void dequeue(){
    if(rear == -1)
        printf("Stack is Empty\n");
    else
        printf("%d element is removed\n",queue[front++]);
}

void display(){
    if (rear == -1)
        printf("Stack is Empty\n");
    else
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
    
}

int main(){
    while(1){
        printf("\n\nEnter your choice 1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        int ch;
        scanf("%d", &ch);
        switch(ch){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong Input\n");
        }
    }
    return 0;
}
