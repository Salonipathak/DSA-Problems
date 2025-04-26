//Implement a program to insert element at last in a circular link list
#include<iostream>
using namespace std;
struct node{
    int data;
    node*next;
};
class LinkList{
    node*head=NULL;
    public:
    void Insert(int data){
        node*s;
        s=new node;
        s->data=data;
        if(head==NULL){
            s->next=s;
            head=s;
            return ;
        }
        node*temp=head;
        do{
            temp=temp->next;
        }while(temp->next!=head);
            temp->next=s;
            s->next=head;
            return ;
    }
    void display(){
        node*temp=head;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
    }
};
int main(){
    LinkList l;
    l.Insert(1);
    l.Insert(2);
    l.Insert(3);
    l.Insert(5);
    l.Insert(4);
    l.display();

    return 0;
}