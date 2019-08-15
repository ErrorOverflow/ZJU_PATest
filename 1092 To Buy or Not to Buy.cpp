#include<iostream>

using namespace std;

int main(){
	string a,b;
	int i,j,less,more;
	int need[512]={0};
	bool isSatisfy=true;
	cin>>a>>b;
	for(i=0;i<b.length();i++){
		need[(int)b[i]]+=1;
	}
	for(i=0;i<a.length();i++){
		need[(int)a[i]]-=1;
	}
	for(i=0,less=0,more=0;i<512;i++){
		if(need[i]>0){
			isSatisfy=false;
			less+=need[i];
		}else{
			more+=(-need[i]);
		}
	}
	if(isSatisfy){
		cout<<"Yes "<<more;
	}
	else{
		cout<<"No "<<less;
	}
	return 0;
}
