#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> list;

int main(){
	int i;
	cin>>N;
	list.resize(N);
	for(i=0;i<N;i++){
		cin>>list[i];
	}
	sort(list.begin(),list.end());
	if(N%2==0){
		cout<<list[N/2];
	}else{
		cout<<list[N/2];
	}
	return 0;
}
