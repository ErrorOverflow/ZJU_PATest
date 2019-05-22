#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<cstring>

using namespace std;

struct INFO{
	map<int,int> id;
};

map<string,set<int>> info[6];

int main(){
	int i,j,k,N,M,ID;
	string s;
	char c;
	char ch[128];
	cin>>N;
	for(i=0;i<N;i++){
		cin>>ID;
		getchar();
		for(j=1;j<=5;j++){
			if(j==3){
				while(cin>>s){
					info[3][s].insert(ID);
					c=getchar();
					if(c=='\n')
						break;
				}
			}else{
				getline(cin,s);
				info[j][s].insert(ID);
			}
		}
	}
	cin>>M;
	getchar();
	map<string,set<int>>::iterator iter;
	set<int>::iterator it;
	for(i=0;i<M;i++){
		cin.getline(ch,128);
		cout<<ch<<endl;
		iter=info[ch[0]-'0'].find(string(&ch[3],strlen(ch)-3));
		if(iter!=info[ch[0]-'0'].end()){
			it=iter->second.begin();
			while(it!=iter->second.end()){
				printf("%07d\n", *it);
				it++;
			}
		}else{
			cout<<"Not Found"<<endl;
		}
	}
}
