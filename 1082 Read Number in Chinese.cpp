#include<iostream>
#include<vector> 

using namespace std;

vector<string> res;

void display(char c){
	switch(c){
		case '1':{
			res.push_back("yi");
			break;
		}
		case '2':{
			res.push_back("er");
			break;
		}
		case '3':{
			res.push_back("san");
			break;
		}
		case '4':{
			res.push_back("si");
			break;
		}
		case '5':{
			res.push_back("wu");
			break;
		}
		case '6':{
			res.push_back("liu");
			break;
		}
		case '7':{
			res.push_back("qi");
			break;
		}
		case '8':{
			res.push_back("ba");
			break;
		}
		case '9':{
			res.push_back("jiu");
			break;
		} 
	}
}

int main(){
	string s;
	int i,j,t,flag,f[3]={0};
	cin>>s;
	if(stoi(s)==0){
		cout<<"ling";
		return 0;
	}
	if(s[0]=='-'){
		res.push_back("Fu");
		i=1;
	}else{
		i=0;
	}
	for(t=i;t<s.length();t++){
		i=t;
		if(s[t]!='0'){
			break;
		}
	}
	if(s.length()-i>=9){
		display(s[i]);
		res.push_back("Yi");
		f[0]=1;
	}
	if((int)s.length()-8>=i){
		t=s.length()-8;
	}else{
		t=i;
	}
	for(flag=1;t>=i && t<(int)s.length()-4;t++){
		if(s[t]=='0'){
			flag=0;
		}else{
			if(!flag){
				res.push_back("ling");
			}
			display(s[t]);
			if(s.length()-4-t==2){
				res.push_back("Shi");
			}else if(s.length()-4-t==3){
				res.push_back("Bai");
			}else if(s.length()-4-t==4){
				res.push_back("Qian");
			}
			f[1]=1;
			flag=1;
		}
	}
	if(f[1]){
		res.push_back("Wan");
	}
	if((int)s.length()-4>=i){
		t=s.length()-4;
	}else{
		t=i;
	}
	for(flag=1;t>=i && t<(int)s.length();t++){
		if(s[t]=='0'){
			flag=0;	
		}else{
			if(!flag){
				res.push_back("ling");
			}
			display(s[t]);
			if(s.length()-t==2){
				res.push_back("Shi");
			}else if(s.length()-t==3){
				res.push_back("Bai");
			}else if(s.length()-t==4){
				res.push_back("Qian");
			}
			flag=1;
		}
	}
	for(i=0;i<res.size();i++){
		cout<<res[i];
		if(i!=res.size()-1){
			cout<<" ";
		}
	}
} 
