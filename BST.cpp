//Implement a program for insertion of node and deletion of node in binary search tree
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
        t->rchild=t->lchild=NULL;
        
        return t;
    }
    else if(s->data>key){
        s->lchild=insert(s->lchild,key);
        return s;
    }else if(s->data<key){
        s->rchild=insert(s->rchild,key);
        return s;
    }
}
int Height(struct node*p){
    if(p==NULL) return 0;
    int x,y;
    x=Height(p->lchild);
    y=Height(p->rchild);
    if(x>y) return x+1;
    else return y+1;
}
struct node*Inpre(struct node*s){
    if(s==NULL) return NULL;
    while(s && s->rchild!=NULL){
        s=s->rchild;
    }
    return s;
}
struct node*Insucc(struct node*s){
    if(s==NULL) return NULL;
    while(s && s->lchild!=NULL){
        s=s->lchild;
    }
    return s;
}
struct node*Delete(struct node*p,int key){
    struct node*q;
    if(p==NULL){
        return NULL;
    }else if(p->lchild==NULL && p->rchild==NULL){
        if(p==root)
        root=NULL;

        return NULL;
        free (p);
    }else{
        if(key>p->data)
        p->rchild=Delete(p->rchild,key);
        else if(key<p->data)
        p->lchild=Delete(p->lchild,key);
        else{
        if(Height(p->lchild)>Height(p->rchild)){
            q=Inpre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }else{
            q=Insucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
        }
    }
}
void Inorder(node*s){
    if(s){
        Inorder(s->lchild);
        cout<<s->data<<" ";
        Inorder(s->rchild);
    }
}
int main(){
    root=insert(root,10);
    insert(root,20);
    insert(root,5);
    insert(root,4);
    insert(root,6);
    insert(root,40);
    insert(root,15);
    Inorder(root);
    Delete(root,15);
    cout<<endl<<"After Deletion of node containing 15, The traversal is :"<<endl;
    Inorder(root);
    return 0;
}