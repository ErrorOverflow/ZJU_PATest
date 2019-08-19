#include<iostream>

using namespace std;

int N;
long double sum=0;

int main(){
	int i,j;
	double x;
	cin>>N;
	for(i=0;i<N;i++){
		scanf("%lf",&x);
		sum+=x*((i+1)*(N-i));
	}
	printf("%.2Lf",sum);
	return 0;
}
