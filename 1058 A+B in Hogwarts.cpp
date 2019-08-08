#include<iostream>

using namespace std;

int main(){
	int a1,a2,a3,b1,b2,b3,c[3];
	scanf("%d.%d.%d %d.%d.%d",&a1,&a2,&a3,&b1,&b2,&b3);
	if(a3+b3>=29){
		c[2]=(a3+b3)%29;
		c[1]=1;
	}else{
		c[1]=0;
		c[2]=(a3+b3);	
	}
	if(c[1]+a2+b2>=17){
		c[1]=(c[1]+a2+b2)%17;
		c[0]=1;
	}else{
		c[0]=0;
		c[1]=(c[1]+a2+b2);	
	}
	c[0]+=(a1+b1);
	cout<<c[0]<<"."<<c[1]<<"."<<c[2]<<endl;
	return 0;
} 
