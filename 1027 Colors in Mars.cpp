#include<iostream>

using namespace std;

void change(int n){
	int a,b;
	a=n/13;
	b=n%13;
	if(a<10){
		cout<<a;
	}else{
		cout<<(char)(a-10+'A');
	}
	if(b<10){
		cout<<b;
	}else{
		cout<<(char)(b-10+'A');
	}	
}

int main(){
	int R,G,B;
	char res[3];
	cin>>R>>G>>B;
	cout<<"#";
	change(R);
	change(G);
	change(B);
	return 0;
}
