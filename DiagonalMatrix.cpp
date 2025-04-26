//To implement a program to print only diagonal elements
#include<iostream>
using namespace std;
class Matrix{
    int **A;
    int rows;
    int cols;
public:
    Matrix(int r,int c){
        rows=r;
        cols=c;
    }
    void input(){
        A=new int*[rows];
        for(int i=0;i<cols;i++){
            A[i]=new int[cols];
        }
        cout<<"Enter the elements here :"<<endl;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cin>>A[i][j];
            }
        }
    }
    void diagdisplay(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i==j) cout<<A[i][j]<<" ";
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Matrix m1(2,2);
    m1.input();
    cout<<"Displaying Only Diagonal Elments :"<<endl;
    m1.diagdisplay();
    return 0;
}