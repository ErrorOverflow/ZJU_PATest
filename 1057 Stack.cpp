#include<iostream>
#include<string>
#include<map>

using namespace std;

int N;
map<int,int> rankin;

int main(){
	int i,j,num,deep,list[100010],size=0;
	string step;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>step;
		if(step=="PeekMedian"){
			if(size==0){
				cout<<"Invalid"<<endl;
			}else{
				if(size%2==0){
					deep =size/2-1;
				}else{
					deep=size/2;
				}
				auto iter=rankin.begin();
				for(j=0;j<deep;){
					j+=iter->second;
					iter++;
				}
				cout<<iter->first<<endl;
			}
		}else if(step=="Push"){
			cin>>num;
			list[size]=num;
			if(rankin.find(num)==rankin.end()){
				rankin.insert(pair<int,int>(num,1));
			}else{
				rankin.find(num)->second++;
			}
			size++;
		}
		else if(step=="Pop"){
			if(size==0){
				cout<<"Invalid"<<endl;
			}else{
				rankin.find(list[size-1])->second--;
				cout<<list[size-1]<<endl;
				size--;				
			}
		}
	}
	return 0;
}
