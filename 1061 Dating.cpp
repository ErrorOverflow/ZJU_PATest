#include<iostream>

using namespace std;

int main(){
	string s[4];
	cin>>s[0]>>s[1]>>s[2]>>s[3];
	int i,time;
	int flag;
	for(i=0;i<s[0].length();i++){
		if((s[0][i]>='A' && s[0][i]<='G') && s[0][i]==s[1][i]){
			flag=s[0][i]-'A'+1;
			switch(flag){
				case 1:{
					cout<<"MON ";
					break;
				}
				case 2:{
					cout<<"TUE ";
					break;
				}
				case 3:{
					cout<<"WED ";
					break;
				}
				case 4:{
					cout<<"THU ";
					break;
				}
				case 5:{
					cout<<"FRI ";
					break;
				}
				case 6:{
					cout<<"SAT ";
					break;
				}
				case 7:{
					cout<<"SUN ";
					break;
				}
			}
			break;
		}
	}
	for(i++;i<s[0].length();i++){
		if(s[0][i]==s[1][i] && ((s[0][i]>='A' && s[0][i]<='N') || (s[0][i]>='0' && s[0][i]<='9'))){
			if(s[0][i]>='A' && s[0][i]<='N'){
				flag=s[0][i]-'A'+10;
			}else{
				flag=s[0][i]-'0';
			}				
			break;
		}
	}
	if(flag<10){
		cout<<"0";
	}
	cout<<flag<<":";
	for(i=0;i<s[2].length();i++){
		if(s[2][i]==s[3][i] && ((s[2][i]>='A' && s[2][i]<='Z') || (s[2][i]>='a' && s[2][i]<='z'))){
			if(i<10){
				cout<<"0";
			}
			cout<<i;
			return 0;
		}
	}
	return 0;
}
