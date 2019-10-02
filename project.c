#include<stdio.h>
#include<stdlib.h>
/*poly divided into 3 parts :-1)containing coeff. of element 2)containing power of x 3)containg address of next element
another thing to keep in mind is that program work well in local variable but if made global variable changes need to be made*/
struct poly{
	int coef;
	int pow;
	struct poly *next;
};
struct poly *head1=NULL;//Store base address of first element of poly1
struct poly *head2=NULL;//Store base address of first element of poly2
struct poly *head3=NULL;//Store base address of first element of sum of poly
struct poly *head4=NULL;//Store base address of first element of diff of poly
struct poly* create_node(struct poly*);
struct poly* display_node(struct poly*);
struct poly* add_poly(struct poly*,struct poly*,struct poly*);
struct poly* sub_poly(struct poly*,struct poly*,struct poly*);
struct poly* add_node(struct poly*,int ,int);
int main()
{
	int choice;
	do{
		printf("enter your choice :-\n1. to create first polynomial\n2. to display first polynomial\n3. to create second polynomial\n4. to display second polynomial\n");
		printf("5. to add polynomial\n6. to display added poly\n7. to sub poly\n8. to display sub poly\n9. to exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:head1=create_node(head1);break;
			case 2:head1=display_node(head1);break;
			case 3:head2=create_node(head2);break;
			case 4:head2=display_node(head2);break;
			case 5:head3=add_poly(head1,head2,head3);break;
			case 6:head3=display_node(head3);break;
			case 7:head4=sub_poly(head1,head2,head4);break;
			case 8:head4=display_node(head4);break;
		}
		printf("\n");
		}while(choice!=9);
	}
struct poly* create_node(struct poly *start)
	{	int ch=1; struct poly *p=NULL;
	while(ch==1){	
		struct poly *temp=(struct poly*)malloc(sizeof(struct poly));
		if(start==NULL)
		{
		printf("\nenter the coef  ");
		scanf("%d",&temp->coef);
		printf("enter the pow  ");
		scanf("%d",&temp->pow);
			p=start=temp;
			temp->next=NULL;
		}
		else
		{	
			p->next=temp;
			p=temp;
			printf("\nenter the coef  ");
			scanf("%d",&temp->coef);
			printf("enter the pow  ");
			scanf("%d",&temp->pow);
			temp->next=NULL;
		}
		printf("\nDo you want to enter more segments of polynomial\nA) Press 1 for yes\nB) Press 0 for no\n");
			scanf("%d",&ch);
	}
	return start;
}
struct poly* display_node(struct poly *start)
{
	if(start ==NULL)
	{ 
		printf("\npolynomial do not exist\n");
	}
	else
	{
	
	struct poly *t1,*t2;int temp;
	t1=start;
	while(t1->next!=NULL)                                        //here it is rearranging the power of x accroding to decreasing manner
	{                                                              
		t2=t1->next;
		while(t2!=NULL)
		{
			if(t2->pow>t1->pow)
			{
			temp=t2->pow;
			t2->pow=t1->pow;
			t1->pow=temp;
			temp=t2->coef;
			t2->coef=t1->coef;
			t1->coef=temp;
			}
			t2=t2->next;
		}
		t1=t1->next;
	}
	t1=start;
	printf("\npolynomial is:-  ");
	while(t1!=NULL)
	{
		printf("%dx^%d->",t1->coef,t1->pow);
		t1=t1->next;
	}
	printf("\n");
}
	return start;
}
struct poly* add_poly(struct poly *head1,struct poly *head2,struct poly *head3)
{    int sum;
	while(head1!=NULL&&head2!=NULL)
	{
		if(head1->pow==head2->pow)
		{
			sum=head1->coef+head2->coef;
		head3=add_node(head3,head1->pow,sum);           //add_node function  is collecting the result of addition and subtraction 
		head1=head1->next;                              //base address of added and subtracted poly store to head3 and head4
		head2=head2->next;
		}
		else if(head1->pow>head2->pow)
		{
			head3=add_node(head3,head1->pow,head1->coef);
			head1=head1->next;
		}
		else
		{
			head3=add_node(head3,head2->pow,head2->coef);
			head2=head2->next;
		}
	}
	if(head1==NULL)
	{
		while(head2!=NULL)
		{
			head3=add_node(head3,head2->pow,head2->coef);
			head2=head2->next;
		}
	}
		if(head2==NULL)
	{
		while(head1!=NULL)
		{
			head3=add_node(head3,head1->pow,head1->coef);
			head1=head1->next;
		}
	}
	printf("\n polynomial added");
	return head3;
}
struct poly* sub_poly(struct poly *head1,struct poly *head2,struct poly *head4)
{    int diff;
	while(head1!=NULL&&head2!=NULL)
	{
		if(head1->pow==head2->pow)
		{
		diff=head1->coef-head2->coef;
		head4=add_node(head4,head1->pow,diff);
		head1=head1->next;
		head2=head2->next;
		}
		else if(head1->pow>head2->pow)
		{
			head4=add_node(head4,head1->pow,head1->coef);
			head1=head1->next;
		}
		else
		{
			head4=add_node(head4,head2->pow,head2->coef);
			head2=head2->next;
		}
	}
	if(head1==NULL)
	{
		while(head2!=NULL)
		{
			head4=add_node(head4,head2->pow,head2->coef);
			head2=head2->next;
		}
	}
		if(head2==NULL)
	{
		while(head1!=NULL)
		{
			head4=add_node(head4,head1->pow,head1->coef);
			head1=head1->next;
		}
	}
	printf("\npolynomial subtracted");
	return head4;
}
struct poly* add_node(struct poly *start,int p,int c )
{
		struct poly *temp=(struct poly*)malloc(sizeof(struct poly));
		struct poly *rear;
	if(start==NULL)
		{
		temp->coef=c;
		temp->pow=p;
		start=temp;
		temp->next=NULL;
		}
		else
		{
			rear=start;
			while(rear->next!=NULL)
			{
				rear=rear->next;
			}
			rear->next=temp;
			temp->coef=c;
			temp->pow=p;
			temp->next=NULL;
		}
		
	return start;
}


