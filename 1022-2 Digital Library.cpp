#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<vector>

using namespace std;

int N,M;

struct Tree{
	vector<int> n;
	Tree *Node[128];
	Tree(){
		int i;
		for(i=0;i<128;i++){
			Node[i]=nullptr;
		}
	}
};

Tree *title=new Tree;
Tree *author=new Tree;
Tree *key=new Tree;
Tree *pub=new Tree;
Tree *year=new Tree;

vector<int> *res;

int check(char*c,int size,Tree* tree){
	int i;
	Tree* tmp=tree;
	for(i=0;i<size;i++){
		if(tmp==nullptr || (int)c[i]>=128){
			return 0;
		}
		tmp=tmp->Node[(int)c[i]];
	}
	res=&tmp->n;
	return tmp->n.size();
}

int main(){
	int i,j,t,k,l,ID;
	char input[512];
	Tree *tmp=nullptr;
	Tree *pre=nullptr;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>ID;
		getchar();
		cin.getline(input,512);
		tmp=title;
		for(t=0;t<strlen(input);t++){
			if(tmp==NULL){
				//tmp=(Tree *)malloc(sizeof(Tree));
				tmp=new Tree;
			}
			if(tmp->Node[(int)input[t]]==nullptr)
				tmp->Node[(int)input[t]]=new Tree;
			tmp=tmp->Node[(int)input[t]];
		}
		tmp->n.push_back(ID);
		cin.getline(input,512);
		tmp=author;
		for(t=0;t<strlen(input);t++){
			if(tmp==NULL){
				//tmp=(Tree *)malloc(sizeof(Tree));
				tmp=new Tree;
			}
			if(tmp->Node[(int)input[t]]==nullptr)
				tmp->Node[(int)input[t]]=new Tree;
			tmp=tmp->Node[(int)input[t]];
		}
		tmp->n.push_back(ID);
		cin.getline(input,512);
		for(j=0,l=0;j<strlen(input);j++){
			if(input[j]==' '){
				tmp=key;
				for(t=l;t<j;t++){
					if(tmp==NULL){
						//tmp=(Tree *)malloc(sizeof(Tree));
						tmp=new Tree;
					}
					if(tmp->Node[(int)input[t]]==nullptr)
						tmp->Node[(int)input[t]]=new Tree;
					tmp=tmp->Node[(int)input[t]];
				}
				tmp->n.push_back(ID);
				l=j+1;
			}
		}
		cin.getline(input,512);
		tmp=pub;
		for(t=0;t<strlen(input);t++){
			if(tmp==NULL){
				//tmp=(Tree *)malloc(sizeof(Tree));
				tmp=new Tree;
			}
			if(tmp->Node[(int)input[t]]==nullptr)
				tmp->Node[(int)input[t]]=new Tree;
			tmp=tmp->Node[(int)input[t]];
		}
		tmp->n.push_back(ID);
		cin.getline(input,512);
		tmp=year;
		for(t=0;t<strlen(input);t++){
			if(tmp==NULL){
				//tmp=(Tree *)malloc(sizeof(Tree));
				tmp=new Tree;
			}
			if(tmp->Node[(int)input[t]]==nullptr)
				tmp->Node[(int)input[t]]=new Tree;
			tmp=tmp->Node[(int)input[t]];
		}
		tmp->n.push_back(ID);
	}
	//cout<<year->Node['2']->Node['0']->Node['1']->Node['1']<<endl;
	cin>>M;
	getchar();
	for(i=0;i<M;i++){
		cin.getline(input,512);
		switch(input[0]){
			case '1':tmp=title;break;
			case '2':tmp=author;break;
			case '3':tmp=key;break;
			case '4':tmp=pub;break;
			case '5':tmp=year;break;
			default:break; 
		}
		
		cout<<input<<endl;
		j=check(&input[3],strlen(input)-3,tmp);
		vector<int> tmp_vec;
		if(j>0){
			tmp_vec=*res;
			for(k=0;k<j;k++){
				cout<<tmp_vec[k]<<endl;
			}
		}
		else{
			cout<<"Not Found"<<endl;
		}
	}
	return 0;
} 
