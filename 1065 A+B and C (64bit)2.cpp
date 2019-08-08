#include<iostream>

using namespace std;

int main(){
	int N,i,j;
	long long a,b,c,res;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>a>>b>>c;
		cout<<"Case #"<<i+1<<": "<<((a+b>c)?("true"):("false"))<<endl;
	}
	return 0;
} 
