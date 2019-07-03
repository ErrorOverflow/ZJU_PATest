#include<iostream>
#include<math.h>
#include<string>
#include <algorithm>  
using namespace std;

string input; 

int counter(int bit){
	int i;
	long long total;
	total=1;
	for(i=2;i<=bit;i++){
		total+=(9*total+pow(10,i-1));
	}
	return total;
}

int main(){
	int i,j,bit;
	long long total=0,tmp;
	cin>>input;
	reverse(input.begin(),input.end());  
	bit=input.length()-1;
	for(i=bit;i>0;i--){
		tmp=counter(i);
		total+=(input[i]-'0')*tmp;
		if(input[i]>'1'){
			total+=pow(10,i);
		}else if(input[i]=='1'){
			for(j=0;j<i;j++){
				total+=(input[j]-'0')*pow(10,j);
			}
			total++;
		}
	}
	if(input[0]>='1'){
		total++;
	}
	cout<<total;
	return 0;
}
