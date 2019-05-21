#include<iostream>
#include<unordered_map> 
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<functional>

using namespace std;

struct INFO{
	vector<int> id;
};

bool MyCompare(const string &p1, const string &p2) {
    return (p1.compare(p2)==-1)?true:false;
}

unordered_map<string,INFO,function<bool(const string &, const string &)>> info1(MyCompare);
unordered_map<string,INFO,function<bool(const string &, const string &)>> info2(MyCompare);
unordered_map<string,INFO,function<bool(const string &, const string &)>> info3(MyCompare);
unordered_map<string,INFO,function<bool(const string &, const string &)>> info4(MyCompare);
unordered_map<string,INFO,function<bool(const string &, const string &)>> info5(MyCompare);


int main(){
	int i,j,k,l,N,M;
	int ID;
	char chars[256];
	vector<string> query;
	vector<int> qn;
	string title,author,words,pub,year;
	string word[5];
	cin>>N;
	for(i=0;i<N;i++){
		cin>>ID;
		getchar();
		gets(chars);
		title=string(chars,strlen(chars));
		if(info1.find(title)!=info1.end()){
			INFO info;
			info.id.push_back(ID);
			info1.insert(pair<string,INFO>(title,info));
		}else{
			info1.find(title)->second.id.push_back(ID);
		}
		gets(chars);
		author=string(chars,strlen(chars));
		if(info2.find(author)!=info2.end()){
			INFO info;
			info.id.push_back(ID);
			info2.insert(pair<string,INFO>(author,info));
		}else{
			info2.find(author)->second.id.push_back(ID);
		}
		gets(chars);
		for(j=0,k=0,l=0;j<strlen(chars);j++){
			if(chars[j]==' '){
				word[l++]=string(&chars[k+1],j-k);
				k=j;
				if(info3.find(word[l-1])!=info3.end()){
					INFO info;
					info.id.push_back(ID);
					info3.insert(pair<string,INFO>(word[l-1],info));
				}else{
					info3.find(word[l-1])->second.id.push_back(ID);
				}
			}
		}
		gets(chars);
		pub=string(chars,strlen(chars));
		if(info4.find(pub)!=info4.end()){
			INFO info;
			info.id.push_back(ID);
			info4.insert(pair<string,INFO>(pub,info));
		}else{
			info4.find(pub)->second.id.push_back(ID);
		}
		gets(chars);
		year=string(chars,strlen(chars));
		if(info5.find(year)!=info5.end()){
			INFO info;
			info.id.push_back(ID);
			info5.insert(pair<string,INFO>(year,info));
		}else{
			info5.find(year)->second.id.push_back(ID);
		}
	}
	cin>>M;
	for(i=0;i<M;i++){
		gets(chars);
		query.push_back(string(chars[3],strlen(chars)-3));
		qn.push_back(chars[0]-'0');
	}
	for(i=0;i<query.size();i++){
		cout<<qn[i]<<": "<<query[i]<<endl;
		switch(qn[i]){
			case 1:{
				if(info1.find(query[i])!=info1.begin()){
					for(j=0;j<info1.find(query[i])->second.id.size();j++){
						cout<<info1.find(query[i])->second.id[j]<<endl;
					}
				}else{
					cout<<"Not Found"<<endl;
				}
				break;
			}
			case 2:{
				if(info2.find(query[i])!=info2.begin()){
					for(j=0;j<info2.find(query[i])->second.id.size();j++){
						cout<<info2.find(query[i])->second.id[j]<<endl;
					}
				}else{
					cout<<"Not Found"<<endl;
				}
				break;
			}
			case 3:{
				if(info3.find(query[i])!=info3.begin()){
					for(j=0;j<info3.find(query[i])->second.id.size();j++){
						cout<<info3.find(query[i])->second.id[j]<<endl;
					}
				}else{
					cout<<"Not Found"<<endl;
				}
				break;
			}
			case 4:{
				if(info4.find(query[i])!=info4.begin()){
					for(j=0;j<info4.find(query[i])->second.id.size();j++){
						cout<<info4.find(query[i])->second.id[j]<<endl;
					}
				}else{
					cout<<"Not Found"<<endl;
				}
				break;
			}
			case 5:{
				if(info5.find(query[i])!=info5.begin()){
					for(j=0;j<info5.find(query[i])->second.id.size();j++){
						cout<<info5.find(query[i])->second.id[j]<<endl;
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
