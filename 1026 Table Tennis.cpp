#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<list>
using namespace std;

struct Info{
	int vip;
	int time;
};

int N,K,M;
map<int,Info> data;

int change(string c){
	int h,m,s;
	h=stoi(c.substr(0,2));
	m=stoi(c.substr(3,2));
	s=stoi(c.substr(6,2));
	return h*3600+m*60+s;
}

void display(int t){
	if(t/3600<=9){
		printf("0%d:",t/3600);
	}else{
		printf("%d:",t/3600);
	}
	t%=3600;
	if(t/60<=9){
		printf("0%d:",t/60);
	}else{
		printf("%d:",t/60);
	}
	t%=60;
	if(t<=9){
		printf("0%d",t);
	}else{
		printf("%d",t);
	}
}

int main(){
	int i,j,k,t,v;
	string s;
	map<int,int> res;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>s>>t>>v;
		data.insert(pair<int,Info>(change(s),Info{v,t*60}));
	}
	cin>>K>>M;
	set<int> vip;
	set<int> nip;
	for(i=0;i<M;i++){
		cin>>v;
		vip.insert(v-1);
	}
	for(i=0;i<K;i++){
		if(vip.find(i)==vip.end()){
			nip.insert(i);
		}
	}
	int table[K]={0};
	int serve[K]={0};
	list<int> wait;
	for(auto iter=data.begin();iter!=data.end();iter++){
		wait.push_back(iter->first);
		auto info=data.find(wait.front());
		bool isFind=false;
		int mint=1e9,mini,mintvip=1e9,minivip;
		for(i=0;i<K;i++){
			if(table[i]<mint){
				mint=table[i];
				mini=i;
			}
		}
		if(mint>=21*3600){
			break;
		}
		//cout<<iter->first<<" "<<mini<<" "<<mint<<endl;
		if(info->second.vip){
			for(auto i=vip.begin();i!=vip.end();i++){
				if(table[*i]<mintvip){
					mintvip=table[*i];
					minivip=*i;
				}
			}			
			if(mintvip<=info->first){
				res.insert(pair<int,int>(info->first,info->first));
				table[minivip]=info->first+info->second.time;
				serve[minivip]++;
			}else if(mint<=info->first){
				res.insert(pair<int,int>(info->first,info->first));
				table[mini]=info->first+info->second.time;
				serve[mini]++;			
			}else{
				res.insert(pair<int,int>(table[mini],info->first));
				table[mini]=table[mini]+info->second.time;
				serve[mini]++;	
			}
			wait.pop_front();	
		}else{
			if(mint<info->first){
				res.insert(pair<int,int>(info->first,info->first));
				table[mini]=info->first+info->second.time;
				serve[mini]++;
				wait.pop_front();
			}else if(vip.find(mini)==vip.end()){
				res.insert(pair<int,int>(mint,info->first));
				table[mini]+=info->second.time;
				serve[mini]++;
				wait.pop_front();	
			}else{
				for(auto next=wait.begin();next!=wait.end();next++){
					if(data.find(*next)->second.vip && *next<=mint){
						res.insert(pair<int,int>(table[mini],*next));
						table[mini]+=data.find(*next)->second.time;
						serve[mini]++;
						wait.erase(next);
						break;
					}
				}
			}
		}
	}
	for(auto iter=res.begin();iter!=res.end();iter++){
		display(iter->second);
		printf(" ");
		display(iter->first);
		printf(" ");
		printf("%d\n",((iter->first-iter->second)%60!=0)?((iter->first-iter->second)/60+1):(iter->first-iter->second)/60);
	}
	printf("%d",serve[0]);
	for(i=1;i<K;i++){
		printf(" %d",serve[i]);
	}
	return 0;
} 
