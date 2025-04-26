//Program to insert element at  start,specific position and last in Doubly Linked List
#include<iostream>
using namespace std;
struct node{
    int data;
    node*next;
    node*prev;
};
class LinkedList{
    public:
    node*root=NULL;
    void Insert(int value){
        node*s=new node;
        s->data=value;
        if(root==NULL){
            s->next=s->prev=NULL;
            root=s;
        }else{
            node*temp=root;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=s;
            s->prev=temp;
            s->next=NULL;
        }
    }
    void InsertAtStart(int value){
        node*s=new node;
        s->data=value;
        s->prev=NULL;
        s->next=root;
        root->prev=s;
        root=s;
    }
    void InsertAtSpecific(int pos,int value){
        node*s=new node;
        s->data=value;
        node* temp=root;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        temp->next->prev=s;
        s->next=temp->next;
        temp->next=s;
        s->prev=temp;
    }
    void display(){
        node*temp=root;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};
int main(){
    LinkedList l;
    l.Insert(1);
    l.Insert(10);
    l.InsertAtSpecific(1,2);
    l.InsertAtStart(0);
    l.display();
    return 0;
}