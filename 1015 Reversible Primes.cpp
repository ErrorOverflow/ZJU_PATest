#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

bool isPrime(int res){
	int i;
	for(i=2;i<=sqrt(res);i++){
		if(res%i==0)
			return false;
	}
	return true;
}

int calculate(int num,int radix){
	vector<int> rever;
	int i,max=0,remain=0,mid,res=0;
	while(pow(radix,max)<=num){
		max++;
	}
	remain=num;
	for(i=max-1;remain>0;i--){
		mid=remain/pow(radix,i);
		remain-=mid*pow(radix,i);
		rever.push_back(mid);
	}
	for(i=0;i<rever.size();i++){
		res+=rever[i]*pow(radix,i);
	}
	//cout<<res<<" ";
	if(res==1)
		return 0;
	if(res==2)
		return 1;
	return isPrime(res);
	//reverse(rever.begin(), rever.end());
}

int main(){
	int total=0,A[1010],B[1010];
	int tmp=1,i;
	while(true){
		cin>>tmp;
		if(tmp<0)
			break;
		A[total]=tmp;
		cin>>B[total];
		total++;
	} 
	for(i=0;i<total;i++){
		if(isPrime(A[i]) && calculate(A[i],B[i]))
			cout<<"Yes";
		else
			cout<<"No";
		if(i!=total-1)
			cout<<endl;
	}
	return 0;
}
