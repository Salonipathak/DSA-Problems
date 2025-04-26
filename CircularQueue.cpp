//To implement a program of Circular Queue
#include<iostream>
using namespace std;
class queue{
    int sz;
    int*A;
    int front,rear;
    public:
    queue(int s){
        sz=s;
        A=new int[sz];
        front=rear=-1;
    }
    void enqueue(int value){
        if(front==(rear+1)%sz) cout<<"Queue is full";
        else{
            rear=(rear+1)%sz;
            A[rear]=value;
        }
    }
    int dequeue(){
        if(front==rear){
            cout<<"Queue is Empty";
            return -1;
        }else{
            front=(front+1)%sz;
            int x=A[front];
            return x;
        }
    }
    void display(){
        for(int i=front+1;i<=rear;i++){
            cout<<A[i]<<" ";
        }
    }
};
int main(){
    queue q(6);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.display();
    cout<<endl<<"The element that is popped out is "<<q.dequeue();
    return 0;
}