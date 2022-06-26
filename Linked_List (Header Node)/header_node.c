#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char name[20];
    int enroll_no;
    float cgpa;
    struct node *next;
}*head;

typedef struct node node;
node *first, *ptr, *temp;

void main(){
    int choice, n, pos;
    void create_linkedlist(int num);
    void display();
    void insert();
    void update(int n);
    void delete();

    head = (node*)malloc(sizeof(node));
    head->enroll_no = 0;
    head->next = NULL;

    while(1){
        printf("\n\n1.Create Linked list \n2.Display list \n3.Display no. of studens having cgpa > 7.0 \n4.Insert \n5.Update a node \n6.Delete node \n7.Exit\n\nChoice: ");
        scanf("%d",&choice);

        switch (choice){
        case 1:
            printf("\nEnter the number of nodes you want to create: ");
            scanf("%d",&n);
            create_linkedlist(n);
            break;

        case 2:
            display();
            break;

        case 3:
            printf("\n%d students have CGPA greater than 7.0",head->enroll_no);
            break;

        case 4:
            insert();
            break;

        case 5:
            printf("\nEnter the position of node to be updated: ");
            scanf("%d",&pos);
            update(pos);
            break;

        case 6:
            delete();
            break;

        case 7:
            exit(0);
            break;
        }
    }
}

void create_linkedlist(int num){
    int e_no;
    float c;
    char n[20];
    first = NULL;

    for (int i = 1; i <= num; i++){
        printf("\nEnter Name of student: ");
        scanf("%s",n);

        printf("Enter enrollment no: ");
        scanf("%d",&e_no);

        printf("Enter CGPA: ");
        scanf("%f",&c);

        if(c > 7.0){
            head->enroll_no += 1;
        }

        temp = (node*)malloc(sizeof(node));
        
        strcpy(temp->name,n);
        temp->enroll_no = e_no;
        temp->cgpa = c;

        temp->next=NULL;

        if (first == NULL){
            first = temp;
            head->next = first;
        }

        else{
            ptr = first;
            while (ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next=temp;
        }
    }

    printf("\nLinked list is created");
}

void display()
{
    ptr = first;
    
    printf("\nData is as followed: ");
    while (ptr != NULL) 
    {
        printf("\n\nName: %s",ptr->name);
        printf("\nEnrollment no: %d",ptr->enroll_no);
        printf("\nCGPA: %f",ptr->cgpa);
        ptr = ptr->next;
    }
}

void insert()
{
    ptr = first;
    int e_no;
    float c;
    char n[20];

    while (ptr->next != NULL){
        ptr = ptr->next;    
    }
    temp = (node*)malloc(sizeof(node));

    printf("\nEnter Name of student: ");
    scanf("%s",n);

    printf("Enter enrollment no: ");
    scanf("%d",&e_no);

    printf("Enter CGPA: ");
    scanf("%f",&c);

    if(c > 7.0){
        head->enroll_no += 1;
    }
    
    strcpy(temp->name,n);
    temp->enroll_no = e_no;
    temp->cgpa = c;

    ptr->next = temp;
    
    temp->next = NULL;
}

void update(int n){
    ptr = first;
    float new_cgpa, old_cgpa;

    if(n != 1){
        while (n != 1){
            ptr = ptr->next;
            n--;
        }
    }

    printf("\nEnter the new CGPA of %s: ",ptr->name);
    scanf("%f",&new_cgpa);

    old_cgpa = ptr->cgpa;

    if (old_cgpa < 7.0 && new_cgpa > 7.0){
        head->enroll_no += 1;
    }

    else if (old_cgpa > 7.0 && new_cgpa < 7.0){
        head->enroll_no -= 1;
    }
    
    ptr->cgpa = new_cgpa;
    printf("\nCGPA updated successfully");
}

void delete(){
    ptr = first;
    if (ptr == NULL){
        printf("\nNo node present in the list to delete");
    }

    else if(ptr->next == NULL){
        if(ptr->cgpa > 7.0){
            head->enroll_no -= 1;
        }  
        free(ptr);
        first = NULL;
        head->next = NULL;
        printf("\nNode deleted successfully");
    }

    else{
        while (ptr->next != NULL){
            temp = ptr;
            ptr = ptr->next;
        }

        if(ptr->cgpa > 7.0){
            head->enroll_no -= 1;
        }    

        temp->next = NULL;

        free(ptr);
        printf("\nNode deleted successfully");
    }
}