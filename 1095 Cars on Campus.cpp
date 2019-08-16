#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<string>
using namespace std;

int N,K;

struct Car{
	vector<int> in;
	vector<int> out;
};

int timechange(string t){
	return stoi(string(t.substr(0,2)))*3600+stoi(string(t.substr(3,2)))*60+stoi(string(t.substr(6,2)));
}

int display(int t){
	int h,m,s;
	h=t/3600;
	t%=3600;
	m=t/60;
	t%=60;
	s=t;
	if(h<10){
		cout<<"0";
	}
	cout<<h<<":";
	if(m<10){
		cout<<"0";
	}
	cout<<m<<":";
	if(s<10){
		cout<<"0";
	}
	cout<<s;
}

int main(){
	int i,j,now;
	string t,id,state;
	vector<int> time;
	map<string,Car> record;
	map<string,int> stoptime;
	map<string,bool> isLegal;
	cin>>N>>K;
	for(i=0;i<N;i++){
		cin>>id>>t>>state;
		if(record.find(id)==record.end()){
			record.insert(pair<string,Car>(id,Car{}));
		}
		if(state=="in"){
			record.find(id)->second.in.push_back(timechange(t));
		}else{
			if(record.find(id)->second.in.size()==0){
				
			}
			record.find(id)->second.out.push_back(timechange(t));
		}
	}
	return 0;
} 
