#include<iostream>
#include<vector>

using namespace std;

struct Node{
	int left=-1;
	int right=-1;
};

Node node[100];
vector<int> res;

int post(int p){
	if(node[p].left>0){
		post(node[p].left);
	}
	if(node[p].right>0){
		post(node[p].right);
	}
	res.push_back(p);
	return 0;
}

int main(){
	int N;
	string step;
	int i,p,stack[100],high=0,f=0,s,flag=0;
	cin>>N;
	for(i=0;i<2*N;i++){
		cin>>step;
		if(step=="Push"){
			cin>>p;
			if(i==0){
				s=p;
			}
			stack[high++]=p;
			if(flag){
				node[f].right=p;
			}else{
				node[f].left=p;
			}
			f=stack[high-1];
			flag=0;
		}else{
            if(high<=0){
                continue;
            }
			if(node[stack[high-1]].left==-1){
				if(high>1){
					f=stack[high-2];
					flag=0;	
				}
			}else{
				if(high>0){
					f=stack[high-1];
					flag=1;			
				}
			}
			high--;
		}
	}
	post(s);
	for(i=0;i<res.size();i++){
		cout<<res[i];
		if(i!=res.size()-1){
			cout<<" ";
		}
	}
	return 0;
}
