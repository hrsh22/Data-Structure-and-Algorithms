#include <stdio.h>
#include <stdlib.h>

struct stack{
    int *stack;
    int top;
    int max;
};

int main()
{
    struct stack*sstack;
    int ch,ele;

    sstack=(struct stack*)malloc(sizeof(struct stack));
    printf("Enter the number of elements to be stored in the stack: ");
    scanf("%d",&sstack->max);
    sstack->stack=(int*)malloc(sstack->max*sizeof(int));

    sstack->top=-1;
    while(1)
    {
        printf("\n Enter the operations to be performed on stack: ");
        printf("\n 1. Push an element(Insert)");
        printf("\n 2. Pop an element(Delete)");
        printf("\n 3. Peep");
        printf("\n 4. Display");
        printf("\n 5. Infix to postfix");
        printf("\n 6. Exit \n");
        scanf("%d",&ch);


        switch(ch)
        {   

        case 1: printf("\nEnter the element to be inserted: ");
                scanf("%d",&ele);
                push(sstack,ele);
                display();
                break;
        case 2: printf("\nThe deleted element is: ");
                printf("%d",pop(sstack));
                break;
        case 3: printf("%d",peep(sstack));
                break;
        case 4: display(sstack);
                break;
        case 5:
        case 6: exit(0);
        }
    }
}

int push(struct stack*sstack, int ele){
    if (sstack->top==sstack->max-1){
        printf("Stack Full");
    }
    else{
        sstack->top+=1;
        sstack->stack[sstack->top]=ele;
        return 1;
    } 
}

int pop(struct stack*sstack){
    int temp = sstack->stack[sstack->top];
    sstack->top-=1;
    return temp;
}

int peep(struct stack*sstack){
    return sstack->stack[sstack->top];
}

void display(struct stack*sstack){
    printf( "The elements of the stack are: \n");
    int i;
    if (sstack->top==-1){
        printf("The stack is empty");
    }
    else{
        for (i=sstack->top;i>-1;i--){
        printf("%d \n",sstack->stack[i]);
        }
    }
}