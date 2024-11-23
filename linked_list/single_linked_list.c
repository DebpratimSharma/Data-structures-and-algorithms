#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}snode;

snode *first=NULL;

snode * createNode(){
    int val;
    snode *newnode;
    printf("Enter the value : ");
    if (scanf("%d", &val) != 1) {
        printf("Failed to read integer input.\n");
        return NULL;
    }
    printf("Input value: %d\n", val); // Debugging statement
    newnode = (snode *)malloc(sizeof(snode));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newnode->data = val;
    newnode->next = NULL;
    printf("Node created with value: %d\n", newnode->data); // Debugging statement
    return newnode;
}

void createList(int n){
    int i;
    snode *newnode,*temp;
    for(i=0;i<n;i++){
        newnode=createNode();
        if(first==NULL){
            first=newnode;
            first->next=NULL;
        }
        else{
            temp=first;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
        }
        // printf("\n\n%d\n\n", newnode->data);
    }
}

//insertions
void insertBeg(){
    snode *newnode;
    newnode=createNode();
    if(first==NULL){
        first=newnode;
    }
    else{
        newnode->next=first;
        first=newnode;
    }
}

void insertLast(){
    snode *temp,*newnode;
    newnode=createNode();
    temp=first;
    if(first==NULL)
        first=newnode;
    else{
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    } 
}

void insertAny(){
    int pos,len=1;
    snode *temp,*newnode,*prev;
    newnode=createNode();
    if(first==NULL)
        first=newnode;
    else{
        temp=first;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        printf("Enter the position: ");
        scanf("%d",&pos);
        if(pos<=len && pos>0){
            temp=first;
            prev=first;
            for(int i=1;i<pos;i++){
                prev=temp;
                temp=temp->next;
            }
            prev->next=newnode;
            newnode->next=temp;
            printf("\n%d entered at %d position.\n",newnode->data,pos);
        }
        else
            printf("\nPosition Invalid.\n");
    }  
}

//deletion

void deleteFirst(){
    if(first!=NULL){
        int val=first->data;
        snode *temp=first;
        first=first->next;
        free(temp);
        printf("%d element deleted.\n", val);
    }
    else
        printf("No data to delete,\n");
}

void deleteLast() {
    if (first == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    if (first->next == NULL) {
        // Only one node in the list
        free(first);
        first = NULL;
        printf("Last node deleted, list is now empty.\n");
        return;
    }

    snode *temp = first;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Now temp is the second last node
    free(temp->next);
    temp->next = NULL;
    printf("Last node deleted.\n");
}

void deleteAny(){
     if (first == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    if (first->next == NULL) {
        // Only one node in the list
        printf("Only one element in the list\n");
        return;
    }
    int pos;
    snode *temp,*prev;
    temp=first;
    prev=first;
    printf("Enter the position: ");
    scanf("%d",&pos);
    int len=0;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    printf("\nLength is %d.\n", len);
    temp=first;
    if(pos>1 && pos<=len){
        for(int i=1;i<pos;i++){ 
            prev=temp;
            temp=temp->next;
        }
        printf("\n%d deleted.\n", temp->data);
        prev->next=temp->next;
        free(temp);
    }
    else{
        printf("\nInvalid position\n");
        return;
    }
}

void display(){
    snode *temp;
    temp=first;
    if(first==NULL)
        printf("No items.\n");
    else{
        printf("The nodes' values are: ");
        while (temp!=NULL)
        {
        printf("%d\t",temp->data);
        temp=temp->next;
        }
        printf("\n");
    }
     
}

//main function
int main(){
    int ch,n;
    do{
        printf("1.Create list with n nodes.\n2.Insert at first.\t3.Insert at last.\n4.Insert at any position\n5.delete first\t6.delete last.\t7.delete any position\n8.Display\t99.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1 :
            printf("\nEnter no. of nodes: ");
            scanf("%d", &n);
            createList(n);
            break;
        case 2 : insertBeg();
            break;
        case 3 : insertLast();
            break;
        case 4 : insertAny();
            break;
        case 5 : deleteFirst();
            break;
        case 6 : deleteLast();
            break;
        case 7: deleteAny();
            break;
        case 8 : display();
            break;
        case 99: printf("\n**Exiting the code.**\n");
            return 0;
        default: printf("Invalid Choice.\n **enter correct choice**\n");
            break;
        }
    }while(ch!=99);
    return 0;
}