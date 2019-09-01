#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct Node{
	int left;
	int right;
	int fa;
	int level;
};

//unordered_map<int,Node> list;
unordered_map<int,int> loc;
int N,M;

int main(){
	int i,j,k,a,b,flag,m,n;
	vector<int> num;
	cin>>M>>N;
	num.resize(N);
	for(i=0;i<N;i++){
		cin>>k;
		num[i]=k;
		loc[k]=i;
//		list.insert(pair<int,Node>(k,Node{-1,-1,-1,1}));
	}
//	for(i=1,flag=0;i<N;i++){
//		j=num[0];
//		k=1;
//		while(true){
//			if(num[i]<j){
//				if(list.find(j)->second.left==-1){
//					list.find(j)->second.left=num[i];
//					list.find(num[i])->second.fa=j;
//					list.find(num[i])->second.level=k;
//					break;
//				}else{
//					k++;
//					j=list.find(j)->second.left;
//				}
//			}else{
//				if(list.find(j)->second.right==-1){
//					list.find(j)->second.right=num[i];
//					list.find(num[i])->second.fa=j;
//					list.find(num[i])->second.level=k;
//					break;
//				}else{
//					k++;
//					j=list.find(j)->second.right;
//				}				
//			}
//		}
//	}
	for(i=0;i<M;i++){
		cin>>a>>b;
		if(loc.find(a)==loc.end()){
			if(loc.find(b)==loc.end()){
				cout<<"ERROR: "<<a<<" and "<<b<<" are not found."<<endl;
			}else{
				cout<<"ERROR: "<<a<<" is not found."<<endl;
			}
			continue;
		}else if(loc.find(b)==loc.end()){
			cout<<"ERROR: "<<b<<" is not found."<<endl;
			continue;
		}
		for(j=0;j<N;j++){
			if((num[j]>a && b>num[j]) || (num[j]<a && b<num[j])){
				cout<<"LCA of "<<a<<" and "<<b<<" is "<<num[j]<<"."<<endl;
				break;
			}else if((num[j]>=a && b>num[j]) || (num[j]<=a && b<num[j])){
                cout<<a<<" is an ancestor of "<<b<<"."<<endl;
                break;
            }else if((num[j]>a && b>=num[j]) || (num[j]<a && b<=num[j])){
                cout<<b<<" is an ancestor of "<<a<<"."<<endl;
                break;
            }
		}
//		m=a;n=b;
//		while(list.find(m)->second.level>list.find(n)->second.level){
//			m=list.find(m)->second.fa;
//		}
//		if(m==n){
//			cout<<b<<" is an ancestor of "<<a<<"."<<endl;
//			continue;
//		}
//		while(list.find(n)->second.level>list.find(m)->second.level){
//			n=list.find(n)->second.fa;
//		}
//		if(m==n){
//			cout<<a<<" is an ancestor of "<<b<<"."<<endl;
//			continue;
//		}
//		while(m!=n){
//			m=list.find(m)->second.fa;
//			n=list.find(n)->second.fa;
//		}
//		cout<<"LCA of "<<a<<" and "<<b<<" is "<<m<<"."<<endl;
	}
	return 0;
}
