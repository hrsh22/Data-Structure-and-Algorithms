#include <stdio.h>
#include <stdlib.h>
int main()
{
int arr[20];
int size=0,position,i,value,element;
int ch;
printf("enter the number of elements in an array:");
scanf("%d",&size);
printf("Enter the elements:\n",size);
for(i=0;i<size;i++)
scanf("%d",&arr[i]);
while(1){
printf("\n Enter the choice");
printf("\n 1. Insert");
printf("\n 2. Delete");
printf("\n 3. Display");
printf("\n 4. Search");
printf("\n 5. Sort");
printf("\n 6. Exit");
printf("\n");
scanf("%d",&ch);
switch(ch){
case 1: printf("Enter the position where you want to insert the element:");
scanf("%d",&position);
printf("Enter the value into that position:");
scanf("%d",&value);
if(position<=size){
for(i=size-1;i>=position-1;i--)
arr[i+1]=arr[i];
arr[position-1]= value;
printf("Final array after inserting the value is\n");
for(i=0;i<=size;i++)
printf("%d\n",arr[i]);
size++;
}
else{
printf("Insertion at position %d is invalid",position);
}
break;
case 2: printf("Enter the position of element which you have to delete:");
scanf("%d",&position);
if(position>size){
printf("Not possible");
}
else{
for(i=position-1;i<size-1;i++)
arr[i]=arr[i+1];
printf(" Array after deletion:\n");
for(i=0;i<size-1;i++)
printf("%d\n",arr[i]);
size--;
}
break;
case 3: printf("\n The array is:");
for(int i=0;i<size;i++)
printf("\n %d",arr[i]);
break;
case 4: printf("Enter the element you want to search:\n");
scanf("%d",&element);
printf("Linear search:\n");
int x;
for(i=0;i<size;i++){
if(arr[i]==element){
position=i+1;
x=1;
break;
}
}
if(x==1)
printf("%d element found successfully at %d position\n",element,position);
else
printf("Element not found.");
break;
case 5: for(i=0;i<size;i++){
int j,temp;
for(j=i+1;j<size;j++){
if(arr[i] > arr[j]){
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}
}
printf("Sorted array elements are:\n");
for(i=0;i<size;i++){
printf("%d\n",arr[i]);
}
break;
case 6: exit(0);
}
}
}