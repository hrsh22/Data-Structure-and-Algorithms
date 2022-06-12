#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int q[30];
int f1=-1,r1=-1;
int f2=-1,r2=-1;
void insert_left(int x);
void insert_right(int x);
void display();
void delete_left();
void delete_right();
int main(){
    int ch,x;
    while(1){
        printf("Enter 1 to go to left\n");
        printf("Enter 2 to go to right\n");
        printf("Enter 3 to delete left side\n");
        printf("Enter 4 to delete right side\n");
        printf("Enter 5 to display\n");
        printf("Enter 6 to exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter element to be added\n");
                    scanf("%d",&x);
                    insert_left(x);
                    break;
            case 2: printf("Enter element to be added\n");
                    scanf("%d",&x);
                    insert_right(x);
                    break;
            case 3: delete_left();
                    break;
            case 4 :delete_right();
                    break;
            case 5: display();
                    break;
            case 6: exit(0);
        }    
    }
    return 0;
}

void insert_left(int x){
    if(r1+1==r2){
        printf("BUS FULL\n");
    }
    else{
        if(f1==-1 && r1==-1){
            f1=0;
            r1=0;
        }
        else{
            r1++;
        }
        q[r1]=x;
    }
}

void insert_right(int x){
    if(r1+1==r2){
        printf("BUS FULL\n");
    }
    else{
        if(f2==-1 && r2==-1){
            f2=29;
            r2=29;
        }
        else{
            r2--;
        }
        q[r2]=x;
    }
}

void display(){
    int i;
    printf("The passengers on left are\n");
    for(i=f1;i<=r1;i++){
        printf("%d\n",q[i]);
    }
    printf("The passengers on right are\n");
    for(i=r2;i<=f2;i++){
        printf("%d\n",q[i]);
    }
}
void delete_left(){
    int i;
    for(i=f1;i<=r1;i++){
        if(f1==r1){
            f1=-1;
            r1=-1;
        }
        else{
            f1++;
        }
    }
}

void delete_right(){
    int i;
    for(i=r2;i<=f2;i++){
        if(f2==r2){
            f2=-1;
            r2=-1;
        }
        else{
            r2++;
        }
    }
}