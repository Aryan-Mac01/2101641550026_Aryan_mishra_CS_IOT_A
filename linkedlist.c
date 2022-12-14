#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *add;
};

// Inserting element at beginning of the linked list .

void insertatfront(data,head){
    node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->add=NULL;
    node->add=head;
    head=node;
}


//inserting element at end of the linked list.

void insertatafter(data,head,dataafter){
    node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->add=NULL;
    int s=head;
    while(s->data!=dataafter){
        s=s->add;
    }
    node->add=s->add;
    s->add=node;
}

//delete element at beginning of linked list.

void deleteatfront(head){
    int temp=head;
    head=head->add;
    free(temp);
}

//delete element at end of linked list.

void deleteatend(head){
    int s=head;
    while(s->add->add!=NULL){
        s=s->add;
        free(s->add);
        s->add=NULL;
    }
}

//print linked list.

void printLL(head){
    int s=head;
    while(s!=NULL){
        printf("%d",s->data);
        s=s->add;
    }
}

//find nth node in linked list.(1st approach)

void find_nth_node(head){
    int s=head;
    int len=0;
    while(s!=NULL){
        len++;
        s=s->add;
    }
    int loop=len-n;
    s=head;
    while(loop>0){
        s=s>add;
        loop--;
    }
    return s->data;
}

//find nth node in linked list.(2nd approach)

void find_nth_node(head,n){
    n=n-1;
    int s=head;
    int t=head;
    while(n>0){
        t=t->add;
        n--;
    }
    while(t->add==NULL){
        s=s->add;
        t=t->add;
    }
    return s->data;
}

//find middle element in linked list.

void midelement(head){
    int s=head;
    int mid=len/2;
    if(len&1==0){
        len--;
    }
    while(mid>0){
        s=s->add;
        mid--;
    }
    return s->data;
}
