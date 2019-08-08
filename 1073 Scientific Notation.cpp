#include<iostream>
#include<string>
using namespace std;

int main(){
	int i,j,round;
	int point_loc;
	bool isNeg=false;
	bool isMin=false;
	string s;
	string res;
	string split[2];
	cin>>s;
	if(s[0]=='-'){
		isNeg=true;
	}
	for(i=1;i<s.size();i++){
		if(s[i]=='E'){
			split[0]=string(s.substr(1,i-1));
			split[1]=string(s.substr(i+2,s.length()-i));
		}else if(s[i]=='-'){
			isMin=true;
		}
	}
	i=0;
	while(split[0][i]<'1' || split[0][i]>'9') i++;
	for(point_loc=0;i<split[0].length() && split[0][i]!='.';i++,point_loc++);
	//cout<<point_loc<<endl;
	round=stoi(split[1]);
	if(isNeg){
		cout<<"-";
	}
	if(isMin){
		if(point_loc<=round){
			cout<<"0.";
			for(i=0;i<round-point_loc;i++){
				cout<<"0";
			}
			i=0;
			while(split[0][i]=='0') i++;
			for(;i<split[0].length();i++){
				if(split[0][i]!='.'){
					cout<<split[0][i];
				}
			}			
		}
		else{
			i=0;
			while(split[0][i]=='0') i++;
			for(j=0;j<point_loc-round && i<split[0].length();i++,j++){
				cout<<split[0][i];
			}
			cout<<".";
			for(;i<split[0].length();i++){
				if(split[0][i]!='.'){
					cout<<split[0][i];
				}
			}
		}
	}else{
		i=0;
		while(split[0][i]=='0') i++;
		for(j=0;j<round+point_loc && i<split[0].length();i++,j++){
			if(j==round+point_loc && i!=split[0].length()-1){
				cout<<".";
			}
			if(split[0][i]=='.'){
				j--;
				if(stoi(split[0].substr(i+1,split[0].length()-i))==0 && stoi(split[0].substr(0,i))==0){
					cout<<"0";
					return 0;
				}
				continue;
			}
			else{
				cout<<split[0][i];
			}
		}
		for(;j<round+point_loc;j++){
			cout<<"0";
		}
	}
	return 0;
}
