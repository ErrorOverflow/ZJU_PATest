#include<iostream>

using namespace std;

int main(){
	double a,b,c,res[3][2],p;
	int i;
	for(i=0;i<3;i++){
		cin>>a>>b>>c;
		if(a>b){
			if(b>c){
				res[i][0]=0;
				res[i][1]=a;
			}else{
				if(a>c){
					res[i][0]=0;
					res[i][1]=a;
				}else{
					res[i][0]=2;
					res[i][1]=c;					
				}
			}
		}else{
			if(b>c){
				res[i][0]=1;
				res[i][1]=b;
			}else{
				res[i][0]=2;
				res[i][1]=c;				
			}
		}
	}
	for(i=0;i<3;i++){
		if(res[i][0]==0){
			cout<<"W ";
		}else if(res[i][0]==1){
			cout<<"T ";
		}else{
			cout<<"L ";
		}
	}
	p = (res[0][1]*res[1][1]*res[2][1]*0.65-1)*2;
	printf("%.2f",p);
	return 0;
} 
