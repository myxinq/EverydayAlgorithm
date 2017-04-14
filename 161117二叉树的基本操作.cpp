#include <iostream>
using namespace std;

typedef struct BiTNode{
	char data;
	struct BiTNode *lChild,*rChild;
}BiTNode,*BiTree;

void creatBiTree(BiTree &T){
	char ch;
	ch=getchar();
	if(ch==' '){
		T=NULL;
	}
	else{
		T=(BiTree)malloc(sizeof(BiTNode));
		if(!T){
			return;
		}
		T->data=ch;
		creatBiTree(T->lChild);
		creatBiTree(T->rChild);
	}
}

void preOrderTraverse(BiTree T){
	if(T==NULL){
		return;
	}
	cout<<T->data;
	preOrderTraverse(T->lChild);
	preOrderTraverse(T->rChild);
}

void inOrderTraverse(BiTree T){
	if(T==NULL){
		return;
	}
	inOrderTraverse(T->lChild);
	cout<<T->data;
	inOrderTraverse(T->rChild);
}

void postOrderTraverse(BiTree T){
	if(T==NULL){
		return;
	}
	postOrderTraverse(T->lChild);
	postOrderTraverse(T->rChild);
	cout<<T->data;
}

int main(){
	BiTree T;
	creatBiTree(T);
	preOrderTraverse(T);
	cout<<endl;
	inOrderTraverse(T);
	cout<<endl;
	postOrderTraverse(T);
	cout<<endl;
}