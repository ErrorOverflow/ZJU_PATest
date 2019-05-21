#include<iostream>
#include<vector>

using namespace std;

struct MAN{
	int code;
	vector<int> child;
};

MAN man[100];

int main(){
	int N,M,i,j,ID,K,id,isLast,nochild;
	cin>>N>>M;
	vector<int> list;
	vector<int> childlist;
	for(i=0;i<M;i++){
		cin>>ID>>K;
		for(j=0;j<K;j++){
			cin>>id;
			man[ID].child.push_back(id);
		}
	}
	nochild=0;
	list.push_back(1);
	while(true){
		isLast=1;
		nochild=0;
		for(i=0;i<list.size();i++){
			if(man[list[i]].child.size()==0){
				nochild++;
				continue;
			}
			for(j=0;j<man[list[i]].child.size();j++){
				isLast=0;
				childlist.push_back(man[list[i]].child[j]);
			}
		}
		list.clear();
		list.assign(childlist.begin(),childlist.end());
		childlist.clear();
		cout<<nochild;
		if(isLast)
			break;
		else
			cout<<" ";
	}
	return 0;
}
