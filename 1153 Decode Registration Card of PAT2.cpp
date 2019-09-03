#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;

struct node{
	string id;
	int score;
};

struct loca{
	string id;
	int num;
};

bool cmp(const node &a, const node &b){
	return a.score>b.score?true:(a.score==b.score && a.id<b.id?true:false);
}

bool cmp2(const loca &a,const loca &b){
	return a.num>b.num?true:(a.num==b.num && a.id<b.id?true:false);
}

int N,M;
vector<node> list;

int main(){
	scanf("%d%d",&N,&M);
	list.resize(N);
	for(int i=0;i<N;i++){
		string s;
		int score;
		cin>>s;
		scanf("%d",&score);
		list[i].id=s;
		list[i].score=score;
	}
	for(int i=0;i<M;i++){
		int step;
		scanf("%d",&step);
		if(step==1){
			char l;
			cin>>l;
			//scanf("%c",&l);
			printf("Case %d: 1 %c\n",i+1,l);
			vector<node> res;
			for(int j=0;j<N;j++){
				if(list[j].id[0]==l)
					res.push_back(node{list[j].id,list[j].score});
			}
			if(res.empty()){
				printf("NA\n");
				continue;
			}
			sort(res.begin(),res.end(),cmp);
			for(int j=0;j<res.size();j++){
				cout<<res[j].id;
				printf(" %d\n",res[j].score);
			}
		}
		else if(step==2){
			string loc;
			cin>>loc;
			printf("Case %d: 2 ",i+1);
			cout<<loc<<endl;
			int n=0,total=0;
			for(int j=0;j<N;j++){
				if(list[j].id.substr(1,3)==loc){
					n++;
					total+=list[j].score;
				}
			}
			if(n!=0)
				printf("%d %d\n",n,total);
			else
				printf("NA\n");
		}else{
			string d;
			cin>>d;
			printf("Case %d: 3 ",i+1);
			cout<<d<<endl;
			unordered_map<string,int> m;
			vector<loca> res;
			for(int j=0;j<N;j++){
				if(list[j].id.substr(4,6)==d){
					m[list[j].id.substr(1,3)]++;
				}
			}
			for(auto it:m){
				res.push_back(loca{it.first,it.second});
			}
			sort(res.begin(),res.end(),cmp2);
			if(res.empty()){
				printf("NA\n");
				continue;
			}
			for(auto it:res){
				cout<<it.id;
				printf(" %d\n",it.num);
			}
		}
	}
	return 0;
}
