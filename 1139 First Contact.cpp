#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
const int maxv=10000;

struct bridge{
	int c;
	int d;
};

int N,M,K;
bool link[maxv][maxv];
bool genda[maxv];
set<int> v;

int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		string a,b;
		cin>>a>>b;
		int ida,idb;
		ida=a[0]=='-'?-stoi(a):stoi(a);
		idb=b[0]=='-'?-stoi(b):stoi(b);
		link[ida][idb]=link[idb][ida]=true;
		genda[ida]=a[0]=='-'?true:false;
		genda[idb]=b[0]=='-'?true:false;
		v.insert(ida);
		v.insert(idb);
	}
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		int ida,idb;
		ida=a<0?-a:a;
		idb=b<0?-b:b;
		bool fg1=genda[ida],fg2=genda[idb];
		vector<int> f1,f2;
		for(auto j=v.begin();j!=v.end();j++){
			if(*j!=ida && *j!=idb && genda[*j]==fg1 && link[*j][ida]){
				f1.push_back(*j);
			}
		}
		for(auto j=v.begin();j!=v.end();j++){
			if(*j!=ida && *j!=idb && genda[*j]==fg2 && link[*j][idb]){
				f2.push_back(*j);
			}
		}
		vector<bridge> res;
		for(int j=0;j<f1.size();j++){
			for(int k=0;k<f2.size();k++){
				//if(f1[j]!=f2[k] && link[f1[j]][f2[k]]){
				if(link[f1[j]][f2[k]]){
					res.push_back(bridge{f1[j],f2[k]});
				}
			}
		}
		printf("%d\n",res.size());
		for(int j=0;j<res.size();j++){
			printf("%04d %04d\n",res[j].c,res[j].d);
		}
	}
	return 0;
} 
