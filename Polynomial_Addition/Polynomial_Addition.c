#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{   int coeff;
    int power;
    struct node *next;
};
void display(struct node * first,int n);
struct node * create();
struct node *poly_add(struct node *first1,struct node *first2);
void main(){
    struct node *first1,*first2,*first3;
    printf("Enter the first polynomial coeffecient first in descending order:\n");
    first1=create();
    printf("Enter the second polynomial coeffecient first in descending order:\n");
    first2=create();
    display(first1,1);
    display(first2,2);
    first3=poly_add(first1,first2);
    display(first3,3);

}

struct node *create(){   struct node *temp,*ptr;
    struct node *first=NULL;
    int n;
    printf("\nEnter the number of nodes in the polynomial:\n ");
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        temp=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the Coefficents: ");
        scanf("%d",&temp->coeff);
        printf("Enter the powers: ");
        scanf("%d",&temp->power);
        temp->next=NULL;
        if(first==NULL)
            first=temp;
        else
        {
            ptr=first;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
        }

    }
    return first;
}

void display(struct node * first,int n){
    struct node*ptr;
    ptr=first;
    if(ptr==NULL){
        printf("The linked list empty");
    }
    else{
         printf("\nThe polynomial %d is as follows:\n",n);
        while(ptr!=NULL){
            printf("%dx^%d +",ptr->coeff,ptr->power);
            ptr=ptr->next;
        }
    }
}

struct node* poly_add(struct node *first1, struct node *first2){
    struct node *p1=first1; struct node *p2=first2;
    struct node* first3=NULL;
    struct  node*temp,*ptr;

    while(p1!=NULL && p2!=NULL){
        temp=(struct node *)malloc(sizeof(struct node));
        temp->next=NULL;

        if(p1->power==p2->power){
            temp->coeff=p1->coeff+p2->coeff;
            temp->power=p1->power;
            p1=p1->next;
            p2=p2->next;
        }
        else if (p1->power>p2->power){
            temp->coeff=p1->coeff;
            temp->power=p1->power;
            p1=p1->next;
        }
        else{
            temp->coeff=p2->coeff;
            temp->power=p2->power;
            p2=p2->next;
        }
        if(first3==NULL){
            first3=temp;
        }
        else{
            ptr=first3;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
    }

    while(p1!=NULL){
        temp=(struct node *)malloc(sizeof(struct node));
        temp->next=NULL;
        temp->coeff=p1->coeff;
        temp->power=p1->power;

        if(first3==NULL){
            first3=temp;
        }
        else{
            ptr=first3;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
    }
    while(p2!=NULL){
        temp=(struct node *)malloc(sizeof(struct node));
        temp->next=NULL;
        temp->coeff=p2->coeff;
        temp->power=p2->power;

        if(first3==NULL){
            first3=temp;
        }
        else{
            ptr=first3;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
    }
  return first3;
}