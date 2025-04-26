//Implement a program to show push pop operation
#include<iostream>
using namespace std;
struct node{
    int data;
    node*next;
}*top=NULL;
class stack{
    public:
    void push(int value){
        node*s;
        s=new node;
        s->data=value;
        if(top==NULL){
            s->next=NULL;
            top=s;
        }else{
            s->next=top;
            top=s;
        }
    }
    int pop(){
        if(top==NULL) {
            cout<<"Stack is empty";
            return -1;
        }
        else{
            node*s=top;
            top=top->next;
            int x=s->data;
            delete(s);
            return x;
        }
    }
    void display(){
        node*s=top;
    
        while(s!=NULL){
            cout<<s->data<<" ";
            s=s->next;
        }
    }
};
int main(){
    stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.display();
    cout<<endl<<"The element popped :"<<s1.pop()<<endl;
    s1.display();
    return 0;
}