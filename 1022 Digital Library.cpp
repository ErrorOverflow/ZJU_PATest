#include<iostream>
#include<map>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<functional>

using namespace std;

struct INFO{
	map<int,int> id;
};

map<string,INFO> info1;
map<string,INFO> info2;
map<string,INFO> info3;
map<string,INFO> info4;
map<string,INFO> info5;


int main(){
	int i,j,k,N,M;
	int ID;
	char chars[512];
	vector<string> query;
	vector<int> qn;
	string title,author,words,pub,year;
	string word;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>ID;
		getchar();
		cin.getline(chars,512);
		title=string(chars,strlen(chars));
		if(info1.find(title)==info1.end()){
			INFO info;
			info.id.insert(pair<int,int>(ID,ID));
			info1.insert(pair<string,INFO>(title,info));
		}else{
			info1.find(title)->second.id.insert(pair<int,int>(ID,ID));
		}
		cin.getline(chars,512);
		author=string(chars,strlen(chars));
		if(info2.find(author)==info2.end()){
			INFO info;
			info.id.insert(pair<int,int>(ID,ID));
			info2.insert(pair<string,INFO>(author,info));
		}else{
			info2.find(author)->second.id.insert(pair<int,int>(ID,ID));
		}
		cin.getline(chars,512);
		for(j=0,k=0;j<strlen(chars);j++){
			if(chars[j]==' '){
				word=string(&chars[k],j-k);
				k=j+1;
				if(info3.find(word)==info3.end()){
					INFO info;
					info.id.insert(pair<int,int>(ID,ID));
					info3.insert(pair<string,INFO>(word,info));
				}else{
					info3.find(word)->second.id.insert(pair<int,int>(ID,ID));
				}
			}
		}
		word=string(&chars[k],strlen(chars)-k);
		if(info3.find(word)==info3.end()){
			INFO info;
			info.id.insert(pair<int,int>(ID,ID));
			info3.insert(pair<string,INFO>(word,info));
		}else{
			info3.find(word)->second.id.insert(pair<int,int>(ID,ID));
		}		
		cin.getline(chars,512);
		pub=string(chars,strlen(chars));
		if(info4.find(pub)==info4.end()){
			INFO info;
			info.id.insert(pair<int,int>(ID,ID));
			info4.insert(pair<string,INFO>(pub,info));
		}else{
			info4.find(pub)->second.id.insert(pair<int,int>(ID,ID));
		}
		cin.getline(chars,512);
		year=string(chars,strlen(chars));
		if(info5.find(year)==info5.end()){
			INFO info;
			info.id.insert(pair<int,int>(ID,ID));
			info5.insert(pair<string,INFO>(year,info));
		}else{
			info5.find(year)->second.id.insert(pair<int,int>(ID,ID));
		}
	}
	cin>>M;
	getchar();
	for(i=0;i<M;i++){
		cin.getline(chars,512);
		query.push_back(string(&chars[3],strlen(chars)-3));
		qn.push_back(chars[0]-'0');
	}
	map<int,int>::iterator iter;
	for(i=0;i<M;i++){
		cout<<qn[i]<<": "<<query[i]<<endl;
		switch(qn[i]){
			case 1:{
				if(info1.find(query[i])==info1.end()){
					cout<<"Not Found"<<endl;
				}else{
					iter=info1.find(query[i])->second.id.begin();
					while(iter!=info1.find(query[i])->second.id.end()){
						cout<<iter->first<<endl;
						iter++;
					}			
				}
				break;
			}
			case 2:{
				if(info2.find(query[i])!=info2.end()){
					iter=info2.find(query[i])->second.id.begin();
					while(iter!=info2.find(query[i])->second.id.end()){
						cout<<iter->first<<endl;
						iter++;
					}	
				}else{
					cout<<"Not Found"<<endl;
				}
				break;
			}
			case 3:{
				if(info3.find(query[i])!=info3.end()){
					iter=info3.find(query[i])->second.id.begin();
					while(iter!=info3.find(query[i])->second.id.end()){
						cout<<iter->first<<endl;
						iter++;
					}	
				}else{
					cout<<"Not Found"<<endl;
				}
				break;
			}
			case 4:{
				if(info4.find(query[i])!=info4.end()){
					iter=info4.find(query[i])->second.id.begin();
					while(iter!=info4.find(query[i])->second.id.end()){
						cout<<iter->first<<endl;
						iter++;
					}	
				}else{
					cout<<"Not Found"<<endl;
				}
				break;
			}
			case 5:{
				if(info5.find(query[i])!=info5.end()){
					iter=info5.find(query[i])->second.id.begin();
					while(iter!=info5.find(query[i])->second.id.end()){
						cout<<iter->first<<endl;
						iter++;
					}	
				}else{
					cout<<"Not Found"<<endl;
				}
				break;
			}
		}
	}
	return 0;
}
