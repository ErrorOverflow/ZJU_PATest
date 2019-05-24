#include<iostream>
using namespace std;

int a[200001],b;
int alen,blen;

int main(){
	int i,t,ac,bc,N,total=0;
	long num;
	cin>>alen;
	for(i=0;i<alen;i++){
		cin>>a[i];
	}
	cin>>blen;
	t=0;
	ac=0;
	for(i=0;i<blen;i++){
		cin>>b;
		while(a[ac]<b){
			t++;
			if(t>=(alen+blen)/2+(alen+blen)%2){
				cout<<a[ac];
				return 0;
			}
			ac++;
		}
		t++;
		if(t>=(alen+blen)/2+(alen+blen)%2){
			cout<<b;
			return 0;
		}
	}
}
