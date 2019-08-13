#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(){
	int N,i,j,tmp;
	string input;
	long long num[101][2];
	long long integer=0,numerator=0,denominator=0;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>input;
		for(j=0;j<input.length();j++){
			if(input[j]=='/'){
				num[i][0]=stoi(string(input.substr(0,j)));
				num[i][1]=stoi(string(input.substr(j+1,input.length()-j)));
			}
		}
	}
	for(i=0;i<N;i++){
		if(denominator==0){
			numerator=num[i][0];
			denominator=num[i][1];
		}
		else if(denominator%num[i][1]!=0){
			if(num[i][1]%denominator==0){
				numerator*=num[i][1]/denominator;
				denominator=num[i][1];
				numerator+=num[i][0];
				continue; 
			}
			tmp=1;
			while(denominator%tmp==0 && num[i][1]%tmp==0){
				tmp*=2;
			}
			tmp/=2;
			for(j=3;j<=sqrt(denominator) && j<=sqrt(num[i][1]);j+=2){
				tmp*=j;
				if(denominator%tmp==0 && num[i][1]%tmp==0){
					j-=2;
				}else{
					tmp/=j;
				}
			}
			numerator*=num[i][1]/tmp;
			denominator*=num[i][1]/tmp;
			numerator+=denominator/num[i][1]*num[i][0];
		}else{
			numerator+=denominator/num[i][1]*num[i][0];
		}
	}
	for(j=2,tmp=1;j<=denominator && j<=numerator;j++){
		if(denominator%j==0 && numerator%j==0){
			tmp=j;
		}
	}
	denominator/=tmp;
	numerator/=tmp;
	integer=numerator/denominator;
	numerator%=denominator;
	if(integer!=0 || numerator==0){
		cout<<integer;
		if(numerator!=0)
			cout<<" ";
	}
	if(numerator!=0){
		cout<<numerator<<"/"<<denominator;
	}
	return 0;
}
