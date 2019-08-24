#include<iostream>
#include<string>
using namespace std;

int main(){
	int N,i,j;
	double sum=0;
	int total=0;
	bool isLegal,isf;
	string s;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>s;
		isLegal=true;
		isf=true;
		float k;
		if(s.length()>9){
			isLegal=false;
		}
		for(j=0;j<s.length();j++){
			//cout<<s[j]<<endl;
			if(s[j]=='.'){
				if(j==0){
					isLegal=false;
					break;
				}else{
					if(isf){
						isf=false;
					}else{
						isLegal=false;
						break;
					}
					if(s.size()-j>3){
						isLegal=false;
						break;
					}
				}
			}else if(s[j]=='-' && j==0){
			}else if(s[j]<'0' || s[j]>'9'){
				isLegal=false;
				break;
			}
		}
		if(isLegal){
			if(stof(s)>1000 || stof(s)<-1000){
				cout<<"ERROR: "<<s<<" is not a legal number"<<endl;
			}else{
				total++;
				sum+=stof(s);
			}
		}else{
			cout<<"ERROR: "<<s<<" is not a legal number"<<endl;
		}
	}
	if(total==0){
		cout<<"The average of 0 numbers is Undefined";
	}else{
		cout<<"The average of "<<total<<" numbers is ";
		printf("%.2lf",sum/total);
	}
	return 0;
}
