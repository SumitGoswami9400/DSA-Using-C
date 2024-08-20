#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
    int data;
    struct queue *next;
}q;

void enq(q**,q**);
void deq(q**,q**);
void disp(q*);

int main(){
    q *f = NULL, *r = NULL;
    int ch;
    while(1){
        printf("\n1-enq\n2-deq\n3-disp\n4-exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            enq(&f,&r);
            break;

            case 2:
            deq(&f,&r);
            break;

            case 3:
            disp(f);
            break;

            case 4:
            exit(0);
        }
    }
    return 0;
}

void enq(q **f, q **r){
    q *p = NULL;
    int x;

    p = (q*) malloc(sizeof(q));

    if(p != NULL){
        printf("Enter data: ");
        scanf("%d",&x);
        p->data = x;

        if(*f == NULL && *r == NULL){
            *f = *r = p;
        }

        else{
            (*r)->next = p;
            *r = p;
        }
        (*r)->next = *f;
    }
}

void deq(q **f, q **r){
    q *p = NULL;
    if(*f == NULL && *r == NULL){
        printf("Queue is empty");
    }
    else{
        p = *f;
        printf("Deleted element is:  %d",(*f)->data);
        *f = (*f)->next;
        (*r)->next = *f;
        if(p == *r){
            *f = *r = NULL;
        }
        free(p);
    }
}

void disp(q *f){
    q *p = f;
    if(f == NULL){
        printf("Queue is empty");
    }
    else{
        do{
            printf("%d  ",p->data);
            p = p->next;
        }while(p != f);
        }
    }
