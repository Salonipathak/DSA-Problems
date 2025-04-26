//Implement a program for tree traversal
#include<iostream>
using namespace std;
struct node{
    int data;
    node*lchild;
    node*rchild;
}*root=NULL;
node* insert(node*s,int key){
    node*t=NULL;
    if(s==NULL){
        t=new node;
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(s->data>key){
        s->lchild=insert(s->lchild,key);
    }else if(s->data<key){
        s->rchild=insert(s->rchild,key);
    }
    return s;
}
void PreOrder(node*s){
    if(s){
        cout<<s->data<<" ";
        PreOrder(s->lchild);
        PreOrder(s->rchild);
    }
}
void Inorder(node*s){
    if(s){
        Inorder(s->lchild);
        cout<<s->data<<" ";
        Inorder(s->rchild);
    }
}
void PostOrder(node*s){
    if(s){
        PostOrder(s->rchild);
        PostOrder(s->lchild);
        cout<<s->data<<" ";
    }
}
int main(){
    root=insert(root,50);
    insert(root,25);
    insert(root,75);
    insert(root,15);
    insert(root,45);
    insert(root,60);
    insert(root,90);
    cout<<"The PreOrder Tree Traversal is :"<<endl;
    PreOrder(root);
    cout<<endl<<"The InOrder Tree Trtaversal is :"<<endl;
    Inorder(root);
    cout<<endl<<"The PostOrder Tree Traversal is :"<<endl;
    PostOrder(root);
    return 0;
}