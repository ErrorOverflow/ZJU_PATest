#include<iostream>
#include<set>
#include<cmath>
using namespace std;

int main(){
	int i,j,N,a;
	double res=0;
	multiset<double> ropes;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>a;
		ropes.insert((double)a);
	}
	i=N;
	for(auto iter=ropes.begin();iter!=ropes.end();iter++,i--){
		if(iter==ropes.begin()){
			res+=*iter*pow(0.5,i-1);
		}else{
			res+=*iter*pow(0.5,i);
		}
	}
	cout<<(int)res;
}
