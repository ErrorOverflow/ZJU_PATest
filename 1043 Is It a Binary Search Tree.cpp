#include<iostream>
#include<malloc.h>
#include<vector>
using namespace std;

struct NODE{
	int n;
	NODE* lchild=nullptr;
	NODE* rchild=nullptr;
};

int num[1010];
int counter=0;
bool isPre=true;
bool isMir=true;
NODE *root=nullptr;
vector<int> out;

int build(NODE **p,int num){
	if(*p==nullptr){
		*p=(NODE *)malloc(sizeof(NODE));
		(*p)->n=num;
		(*p)->lchild=nullptr;
		(*p)->rchild=nullptr;
		return 0;
	}
	if(num<(*p)->n){
		build(&(*p)->lchild,num);
	}else{
		build(&(*p)->rchild,num);
	}
	return 0;
}

int preorder(NODE *p){
	if(p->n==num[counter]){
		counter++;
	}else{
		isPre=false;
		return 0;
	}
	if(p->lchild!=nullptr)
		preorder(p->lchild);
	if(p->rchild!=nullptr)
		preorder(p->rchild);
	return 0;
}

int postorder(NODE *p){
	if(p->lchild!=nullptr)
		postorder(p->lchild);
	if(p->rchild!=nullptr)
		postorder(p->rchild);
	out.push_back(p->n);
	return 0;
}

int mirorder(NODE *p){
	if(p->rchild!=nullptr)
		mirorder(p->rchild);
	if(p->lchild!=nullptr)
		mirorder(p->lchild);
	out.push_back(p->n);
	return 0;
}

int main(){
	int i,N;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>num[i];
		build(&root,num[i]);
	}
	preorder(root);
	postorder(root);
	if(isPre){
		cout<<"YES"<<endl;
		for(i=0;i<out.size();i++){
			cout<<out[i];
			if(i!=out.size()-1){
				cout<<" ";
			}
		}
	}else{
		vector<int>::iterator iter=out.begin();
		i=N-1;
		while(iter!=out.end()){
			if(*iter!=num[i--]){
				cout<<"NO";
				return 0;
			}
			iter++;
		}	
		cout<<"YES"<<endl;
		out.clear();
		mirorder(root);
		for(i=0;i<out.size();i++){
			cout<<out[i];
			if(i!=out.size()-1){
				cout<<" ";
			}
		}
	}
	return 0;
}
