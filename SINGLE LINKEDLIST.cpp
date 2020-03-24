#include<iostream>
using namespace std;

void nodeOperations();
void createNewNode(int value);
void insertFirst(int value);
void insertLast(int value);
void insertIndex(int value,int index);
void deleteFirst();
void deleteLast();
void deleteIndex(int index);
void display();
struct node
{
	int data;
	node *next;
};
class LinkedList
{
	node *head,*tail;
     public:
		LinkedList()
		{
			head=NULL;
			tail=NULL;
		}
		
		void createNewNode(int value)
		{
			node *temp=new node;
	         temp->data=value;
	         temp->next=NULL;
	        if(head==NULL)
			{
				head=temp;
				tail=temp;
			}
			else
			{
				tail->next=temp;
				tail=temp;
			}
	
		}
		void insertFirst(int value)
		{
			node *temp=new node;
			temp->data=value;
			temp->next=head;
			head=temp;
		}
		void display()
		{
			node *temp=new node;
			temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
			     temp=temp->next;	
			}
		}
		void insertIndex(int value,int index)
		{
			int i;
			node *temp=new node;
			node *pre=new node;
			node *cur=new node;
            cur=head;
              for(i=1;i<index;i++)
              {
              	pre=cur;
              	cur=cur->next;
         	  }
  
			temp->data=value;
			temp->next=NULL;
             pre->next=temp;
             temp->next=cur;
		}
		void deleteFirst()
		{
			node *temp;
			temp=head;
			head=temp->next;
			delete temp;
		}
		void deleteLast()
		{
		   node *pre=new node;
		   node *cur=new node;
		    cur=head;
		   while(cur!=tail && tail!=NULL)
		   {
		   	pre=cur;
		   	cur=cur->next;
		   	 }
		   tail=pre;
		   tail->next=NULL;
		   delete cur;
		}
		void deleteIndex(int index)
		{
			int i;
			node *x=new node;
			node *y=new node;
			node *z=new node;
			y=head;
			for(i=1;i<index;i++)
			{
				x=y;
				y=y->next;
			}
			z=y->next;
			x->next=z;
			delete y;
		}
		void search(int search)
		{
			int flag=0;
			node *temp=new node;
			temp=head;
		  while(temp!=NULL)
		  {
		  	if(temp->data==search)
			{
				flag++;
			}
			temp=temp->next;
		}
		if(flag>0)
		{
			cout<<"Yes";
		}
		else
		{
			cout<<"No";
		}
		}
		void deleteFoccur(int search)
		{
			if(search==head->data)
			{
						deleteFirst();
			}
			else
			{
				node *pre;
				node *cur;
				node *temp;
				cur=head;
				while(cur->next!=NULL)
				{		
					if(search==cur->next->data)
					{
						pre=cur;
						temp=cur->next;
						pre->next=temp->next;
					    delete temp;
					    break;
					}
					cur=cur->next;
				}
			}
		if(search==tail->data)
		{
		    deleteLast();
			}
		}
		void deleteLoccur(int search)
		{
				int count=0;
				node *cur;
				cur=head;
				 while(cur!=NULL)
				{
					if(search==cur->data)
					{
						count++;
					}
					cur=cur->next;
				}
				cout<<"count:"<<count;
		}
		void nodeOperations()
		{
			int opt,value,index;
			cout<<"==================Node Operations================"<<endl;
			cout<<"1. Create New Node"<<endl;
			cout<<"2. Insert Last"<<endl;
			cout<<"3. Insert First"<<endl;
			cout<<"4. Insert Index"<<endl;
			cout<<"5. Delete first"<<endl;
			cout<<"6. Delete Last"<<endl;
			cout<<"7. Delete Index"<<endl;
			cout<<"8. search"<<endl;
			cout<<"9. Delete first occurance"<<endl;
			cout<<"10. Delete last occurance"<<endl;
			cout<<"0. EXIT"<<endl;
			do{
			
			cout<<"\nEnter any number between 1-7 :   ";
	        cin>>opt;
	        if(opt==1)
	        {
	        	cout<<"Enter new vlaue to create new node ";
	        	cin>>value;
	        	createNewNode(value);
	        	display();
			}
			else if(opt==2)
			{
					cout<<"Enter new vlaue to create new node ";
	        	cin>>value;
	        	createNewNode(value);
	        	display();
			}
			else if(opt==3)
			{
				cout<<"Enter new vlaue to create new node ";
	        	cin>>value;
				insertFirst(value);
				display();
			}
			else if(opt==4)
			{
				cout<<"Enter new vlaue to create new node ";
	        	cin>>value;
	        	cout<<"enter index";
	        	cin>>index;
	        	insertIndex(value,index);
	        	display();
			}
			else if(opt==5)
			{
				deleteFirst();
				display();
			}
			else if(opt==6)
			{
				deleteLast();
				display();
			}
			else if(opt==7)
			{
				
				cout<<"Enter index to delete node";
				cin>>index;
				deleteIndex(index);
				display();
			}
			else if(opt==8)
			{
				int value;
				cout<<"Enter search element";
				cin>>value;
				search(value);
			}
			else if(opt==9)
			{
				int search;
				cout<<"enter search element";
				cin>>search;
				deleteFoccur(search);
				display();
			}
			else if(opt==10)
			{
				int search;
				cout<<"enter search element";
				cin>>search;
				deleteLoccur(search);
			//	display();
			}
		}
		while(opt!=0);
		}
};
int main()
{
LinkedList l;
l.nodeOperations();

}
