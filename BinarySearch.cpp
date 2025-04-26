//Implement a program to show Binary Search
#include<iostream>
using namespace std;
class Array{
    int sz;
    int*A;
    public:
    Array(int size){
        sz=size;
        A=new int[sz];
    }
    void input(){
        cout<<"Enter the elements od array in sorted order :"<<endl;
        for(int i=0;i<sz;i++){
            cin>>A[i];
        }
    }
    int BinarySearch(int key){
        int l=0;
        int h=sz-1;
        while(l<h){
        int mid=(l+h)/2;
        if(A[mid]==key){
            return mid;
        }else if(A[mid]>key){
            h=mid-1;
        }else{
            l=mid+1;
        }
        }
        
    }
    void display(){
        for(int i=0;i<sz;i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Array A(7);
    A.input();
    A.display();
    int k;
    cout<<"Enter the value you wanna find :";
    cin>>k;
    cout<<"The "<<k<<" element is at"<<A.BinarySearch(k);
    return 0;
}