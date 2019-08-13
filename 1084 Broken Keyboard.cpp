#include<iostream>
#include<vector>
using namespace std;

bool isBad[512]={false};
vector<char> list;

int main(){
	string a,b;
	int i,j;
	char tmp;
	cin>>a>>b;
	for(i=0,j=0;i<b.length();i++,j++){
		while(b[i]!=a[j] && j<a.length()){
			if((int)a[j]>='a' && (int)a[j]<='z'){
				tmp=(int)a[j]-'a'+'A';
			}else{
				tmp=(int)a[j];
			}
			if(!isBad[(int)tmp]){
				list.push_back(tmp);
				isBad[(int)tmp]=true;
			}
			j++;
		}
	}
	for(i=0;i<list.size();i++){
		cout<<list[i];
	}
	return 0;
}
