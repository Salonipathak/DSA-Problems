//Implement a program to delete element from specific position in Doubly Linked List
#include<iostream>
using namespace std;
struct node{
    int data;
    node*prev;
    node*next;
};
class LinkedList{
    node*head=NULL;
    public:
    void insert(int data){
        node*s=new node;
        s->data=data;
        if(head==NULL){
            s->next=s->prev=NULL;
            head=s;
        }else{
            node*temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=s;
            s->prev=temp;
            s->next=NULL;
        }
    }
    int SpecDelete(int pos){
        if(head==NULL){
            cout<<"List is Empty !!"<<endl;
            return -1;
        }
        node*temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        int x=temp->data;
        delete temp;
        return x;
    }
    void display(){
        node*temp=head;
    while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};
int main(){
    LinkedList l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.display();
    cout<<endl;
    cout<<l.SpecDelete(2);
    return 0;
}