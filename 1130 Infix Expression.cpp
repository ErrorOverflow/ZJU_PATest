#include<iostream>
#include<map>
using namespace std;

int node[100][2],root;
string n[100];

int DFS(int p){
	if(p!=root && (node[p][0]!=-1 || node[p][1]!=-1)){
		cout<<"(";
	}
	if(node[p][0]!=-1){
		DFS(node[p][0]);
	}
	cout<<n[p];
	if(node[p][1]!=-1){
		DFS(node[p][1]);
	}	
	if(p!=root && (node[p][0]!=-1 || node[p][1]!=-1)){
		cout<<")";
	}
	return 0;
}

int main(){
	int N,i,j,a,b;
	string s;
	bool isRoot[100]={false};
	cin>>N;
	for(i=1;i<=N;i++){
		cin>>s>>a>>b;
		node[i][0]=a;
		node[i][1]=b;
		n[i]=s;
		isRoot[a]=true;
		isRoot[b]=true;
	}
	for(i=1;i<=N;i++){
		if(!isRoot[i]){
			root=i;
			break;
		}
	}
	DFS(root);
	return 0;
} 
