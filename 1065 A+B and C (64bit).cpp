#include<iostream>

using namespace std;

bool judge(string a,string b){
	
}

void add(string a,string b,string &res){
	int a_i,b_i;
	bool isAdd=true;
	bool isBoth=false;
	if(a[0]=='-' && b[0]!='-'){
		  
	}
	string mid;
	res.clear();
	a_i=a.length()-1;
	b_i=b.length()-1;
	do{
		
		a_i--;
		b_i--;
	}while(a_i>=0 || b_i>=0);
}

int main(){
	int N,i,j;
	string a,b,c,res;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>a>>b>>c;
		add(a,b,res);
		cout<<res<<endl;
		cout<<"Case #:"<<i<<(judge(res,c))?("true"):("false")<<endl;
	}
	return 0;
} 
