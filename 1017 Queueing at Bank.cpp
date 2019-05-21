#include<iostream>
#include<string>

using namespace std;

int change(string s, int *res){
	string t;
	*res=0;
	t=s.substr(0,2);
	*res+=stoi(t)*3600;
	t=s.substr(3,5);
	*res+=stoi(t)*60;
	t=s.substr(6,8);
	*res+=stoi(t);
	return 0;
}

int main(){
	int i,j,N,K,min,min_window,tmp_int,tmp,wait=0,window[101],real=0;
	string tmp_s;
	int input[1010][2]={0};
	cin>>N>>K;
	for(i=0;i<N;i++){
		cin>>tmp_s>>tmp_int;
		change(tmp_s,&tmp);
		if(tmp>17*3600){
			continue;
		}
		input[real][0]=tmp;
		input[real][1]=tmp_int*60;
		real++;
	}
	for(i=0;i<real-1;i++){
		for(j=i+1;j<real;j++){
			if(input[i][0]>input[j][0]){
				tmp=input[i][0];
				input[i][0]=input[j][0];
				input[j][0]=tmp;
				tmp=input[i][1];
				input[i][1]=input[j][1];
				input[j][1]=tmp;
			}
		}
	}
	for(i=0;i<K;i++){
		window[i]=8*3600;
	}
	int iter;
	for(iter=0;iter<real;iter++){
		min=18*3600;
		for(i=0;i<K;i++){
			if(window[i]<min){
				min=window[i];
				min_window=i;
			}
		}
		if(input[iter][0]<min){
			wait+=min-input[iter][0];
		}
		window[min_window]=min+input[iter][1];
		cout<<input[iter][0]<<" "<<input[iter][1]<<" "<<wait<<endl;
	}
	printf("%.1f",double(wait)/real/60);
	return 0;
} 
