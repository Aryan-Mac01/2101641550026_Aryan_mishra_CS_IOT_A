#include<stdio.h>
#include<stdlib.h>
typedef struct nodetype{
	int info;
	struct nodetype *next;
}node;
void insertatbeg(node **start,int item){
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->next=*start;
	*start=ptr;
}
void insertatend(node **start,int item){
	node *ptr,*last;
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->next=NULL;
	if(*start != NULL){
		*start=ptr;
	}
	else{
		last=*start;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=ptr;
	}
	
}
void display(node *start){
	if(start==NULL){
		printf("LL is empty");
		return;
	}
	while(start!=NULL){
		printf("%d->",start->info);
		start=start->next;
	}
}
void deleteatbeg(node **start){
	node *ptr;
	if(*start==NULL){
		printf("LL is empty");
		return;
	}
	ptr= *start;
	*start=ptr->next;
	printf("\n Deleted value =%d",ptr->info);
	free(ptr);
}
void deleteatend(node **start){
	node *ptr,*last;
	if(*start==NULL){
		printf("\n LL is empty");
		return;
	}
	if((*start)->next==NULL){
		ptr=*start;
		*start=ptr->next;
	}
	else{
		last=*start;
		while(last->next->next!=NULL)
			last=last->next;
		ptr=last->next;
		last->next=NULL;
	}
	printf("\n Deleted value=%d",ptr->info);
	free(ptr);
}
void displayinrev(node *start){
	if(start->next!=NULL){
		displayinrev(start->next);
	}
	printf("%d->",start->info);
}
void reverselist(node **start){
	node *prevnode,*curnode,*nextnode;
	prevnode=NULL;
	curnode=*start;
	nextnode=curnode->next;
	curnode->next=NULL;
	while(nextnode!=NULL){
		prevnode=curnode;
		curnode=nextnode;
		nextnode=curnode->next;
		curnode->next=prevnode;
	}
	*start=curnode;
}
node *search(node *start,int key){
	while(start!=NULL && start->info != key){
		start = start->next;
	}
	return start;
}
void insertafterloc(node *start,int item,int after){
	node *ptr,*loc;
	loc = search(start,after);
	if(loc == NULL){
		printf("\n Location not found");
		return;
	}
	ptr = (node*)malloc(sizeof(node));
	ptr->info = item;
	ptr->next = loc->next;
	loc->next = ptr;
}
void deleteafterloc(node *start,int after){
	node *ptr,*loc;
	loc = search(start,after);
	if(loc == NULL){
		printf("\n Location not found");
		return;
	}
	ptr->next = loc->next;
	free(ptr);
	printf("\n Deleted Item = %d",loc);
}
int main(){
	int item,choice,pos;
	node *head;
	head=NULL;
	while(1){
		printf("\n........Linked List Menu........\n");
		printf("\n1.Insert at begining");
		printf("\n2.Insert at end");
		printf("\n3.Delete at begining");
		printf("\n4.Delete at end");
		printf("\n5.Display in order");
		printf("\n6.Display in reverse");
		printf("\n7.Reverse List in Memory");
		printf("\n8.Insert at given positon");
		printf("\n9.Delete at given positon");
		printf("\n10.Exit");
		printf("\n\n Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter Item = ");
				scanf("%d",&item);
				insertatbeg(&head,item);
				break;
			case 2:
				printf("Enter Item = ");
				scanf("%d",&item);
				insertatend(&head,item);
				break;
			case 3:
				deleteatbeg(&head);
				break;
			case 4:
				deleteatend(&head);
				break;
			case 5:
				display(head);
				break;
			case 6:
				displayinrev(head);
				break;
			case 7:
				reverselist(&head);
				break;
			case 8:
				printf("Enter Item = ");
				scanf("%d",&item);
				printf("Enter Positon = ");
				scanf("%d",&pos);
				insertafterloc(&start,item,pos);
			case 9:
				printf("Enter Positon = ");
				scanf("%d",&pos);
				deleteafterloc(&start,pos);
			default:
				exit(1);
				
		}	
	}
}
