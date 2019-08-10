#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int N;
	int i,count;
	char sen[110][257];
	char res[257];
	cin>>N;
	getchar();
	for(i=0;i<N;i++){
		cin.getline(sen[i],257);
	}
	count=0;
	while(true){
		for(i=0;i<N-1;i++){
			if(strlen(sen[i])<=count || strlen(sen[i+1])<=count || sen[i][strlen(sen[i])-count-1]==' ' || sen[i][strlen(sen[i])-count-1] != sen[i+1][strlen(sen[i+1])-count-1]){
				if(count==0){
					cout<<"nai";
					return 0;
				}else{
					for(i=count-1;i>=0;i--){
						cout<<res[i];
					}
					return 0;
				}
			}
		}
		res[count]=sen[0][strlen(sen[0])-count-1];
		count++;
	}
	return 0;
}
