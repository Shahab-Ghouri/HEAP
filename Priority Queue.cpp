  
// 		© Copyright 2021 , OBAID ULLAH SHAHAB GHOURI 

#include <iostream>
using namespace std;

class Node{
	public:
		int priority,data;
		Node *next;
};
class Priority_Queue{
	private:
		Node *head,*tail;
		
	public:
		Priority_Queue(){
			head = NULL;
			tail = NULL;
		}
		
		void push(int value,int p){
			// create a new Node
			Node *temp = new Node;
			temp->next = NULL;
			temp->data = value;
			temp->priority = p;
			
			// check if head is NULL
			if(head == NULL){
				head = temp;
				tail = temp;
			}
			else{
				// check the priority of head, if greater than insert the new node before head
				if(head->priority > p){
					temp->next = head;
					head = temp;
				}
				else{
					Node *ptr = head;
					while(ptr->next !=NULL && ptr->next->priority < p){
						ptr = ptr->next;
					}
					temp->next = ptr->next;		// either next of new node will be NULL or newnode will be at required place
					ptr->next = temp;
				}
			}
			
		}
		// pop from head
		void pop(){
			Node *temp;
			temp = head->next;
			head->next = NULL;
			head = temp;	
		}
		int front(){
			return head->data;	
		}
		void display(){
			Node *temp = head;
			while(temp != NULL){
				cout<<" Value : "<<temp->data<<endl<<" Priority : "<<temp->priority<<endl<<endl;
				temp = temp->next;
			}
		}
};

main(){
	Priority_Queue pq;
	pq.push(5,1);
	pq.push(2,2);
	pq.push(20,3);
	pq.push(5,0);
	pq.display();

}
