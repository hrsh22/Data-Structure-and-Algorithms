#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void insert_at_head(struct Node** head,int x){
    printf("Insertion at head :\n");
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=x;
    if(head==NULL){
        *head=new_node;
        return;
    }
    new_node->next=*head;
    *head=new_node;
    return;
}
void insert_at_the_end(struct Node** head,int x){
    printf("Insertion at tail :\n");
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=x;
    if(head==NULL){
        *head=new_node;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->next=NULL;
}
void insert_at_a_position(struct Node** head, int x, int pos){
    printf("Insertion at position %d :\n",pos);
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=x;
    if(pos==0){
        if(head==NULL){
        *head=new_node;
        return;
        }
        new_node->next=*head;
        *head=new_node;
        return;  
    }
    int i=1;
    struct Node* temp=*head;
    while(i<pos){
        temp=temp->next;
	i++;
    }
    new_node->next=temp->next;
    temp->next=new_node;    
}
void delete_acc_to_key(struct Node** head,int key){
    printf("Deleting according to key %d:\n",key);
    int flag=0;
    struct Node* temp=*head;
    while(temp->next->data!=key){
        temp=temp->next;
        if(temp->next->data==key){
            flag=1;
        }
    }
    if(flag==0){
        printf("Key not found ! \n");
        return;
    }
    struct Node* tp=temp->next->next;
    temp->next=tp;
}
void delete_head(struct Node** head){
     printf("Deletion at head : \n");
    if(head==NULL){
        printf("NULL POINTER EXCEPTION !");
        return;
    }
    struct Node* temp=*head;
    temp=temp->next;
    *head=temp;
   
}
void delete_tail(struct Node** head){
       printf("Deletion at tail: \n" );
    if(head==NULL){
        printf("NULL pointer exception!");
        return;
    }
   struct Node* temp=*head;
   if(temp->next==NULL){
        *head=NULL;
         return;
   }
   temp=temp->next;
   struct Node* prev=*head;
   *head=prev;
   while(temp->next!=NULL){
        temp=temp->next;
        prev=prev->next;
   }
   prev->next=NULL;           
}

void reverse_singly_linked_list(struct Node** head){
    struct Node* p=NULL;
    struct Node* n=NULL;
    struct Node* current=*head;
    while(current!=NULL){
        n=current->next;
        current->next=p;
        p=current;
        current=n;
    }
   *head=p;
   printf("Reversing : \n");
   struct Node* node=*head;
   while(node->next!=NULL){
       printf("%d -> ",node->data);
       node=node->next;
   }
   printf("%d\n",node->data);
}
void sort_singly_linked_list(struct Node** head){
    struct Node* sorted=*head;
    struct Node* tp=NULL;
    while(sorted->next!=NULL){
        tp=sorted->next;
        while(tp!=NULL){
            if(tp->data<sorted->data){
                int temp=sorted->data;
                sorted->data=tp->data;
                tp->data=temp;
            }
            tp=tp->next;
        }
        sorted=sorted->next;
    }
    printf("Sorting : \n");
    struct Node* node=*head;
    while(node->next!=NULL){
        printf("%d -> ",node->data);
        node=node->next;
    }
     printf("%d\n",node->data);
}
void update(struct Node** head, int key,int new_data){
    struct Node* node=*head;
    printf("Updation of %d with new data %d: \n",key,new_data);
    while(node!=NULL){
        if(node->data==key){
            node->data=new_data;
            return;
        }
        node=node->next;
    }
    printf("Key not found !\n");
    
    
}
void display(struct Node** head){
    struct Node* node=*head;
    while(node->next!=NULL){
        printf("%d -> ",node->data);
        node=node->next;
    }
    printf("%d\n", node->data);
}

int main()
{
    struct Node* head=NULL;
    
    insert_at_head(&head,4);
    display(&head);
    insert_at_head(&head,22);
      display(&head);
    insert_at_the_end(&head,88);
      display(&head);
    insert_at_a_position(&head,14,0);
    
    display(&head);      
    
    delete_tail(&head); 
    
    display(&head);
    delete_acc_to_key(&head,4);
    
    display(&head);
    
    delete_head(&head);
    
    display(&head);
    
    update(&head,9,30);
    
    display(&head);
    insert_at_the_end(&head,45);
    display(&head);
    insert_at_the_end(&head,60);
    display(&head);
  
    sort_singly_linked_list(&head);
  
    reverse_singly_linked_list(&head);

    return 0;
}