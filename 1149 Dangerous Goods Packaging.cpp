#include<iostream>
#include<map>
#include<set>
using namespace std;

int main(){
	int i,j,t,N,M,K;
	string a,b,c,d;
	set<string> list;
	//bool isS[1000000][1000000]={false};
	cin>>N>>M;
	for(i=0;i<N;i++){
		cin>>a>>b;
		c.assign(a.begin(),a.end());
		list.insert(a.append(b));
		list.insert(b.append(c));
	}
	for(i=0;i<M;i++){
		cin>>K;
		string s[K];
		bool isSafe=true;
		for(j=0;j<K;j++){
			cin>>s[j];
		}
		for(j=0;j<K-1;j++){
			for(t=j+1;t<K;t++){
				c.assign(s[j].begin(),s[j].end());
				d.assign(s[t].begin(),s[t].end());
				if(list.find(c.append(s[t]))!=list.end() || list.find(d.append(s[t]))!=list.end()){
					isSafe=false;
					cout<<"No"<<endl;
					break;
				}
			}
			if(!isSafe){
				break;
			}
		}
		if(isSafe){
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}
