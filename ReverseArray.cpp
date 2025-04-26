//A program to reverse the array using recursion
#include<iostream>
using namespace std;
void reverse(int *A,int i,int j){
    int temp=0;
    if(i>=j){
        return ;
    }
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        reverse(A,i+1,j-1);
}
int main(){
    int sz;
    cout<<"Enter the size of array :"<<endl;
    cin>>sz;
    int *S;
    S=new int[sz];
    cout<<"Enter the elements of array :";
    for(int i=0;i<sz;i++){
        cin>>S[i];
    }
    reverse(S,0,sz-1);
    cout<<"The Reversed Array is :"<<endl;
    for(int i=0;i<sz;i++){
        cout<<S[i]<<" ";
    }
    return 0;
}