#include<stdio.h>
#include<iostream>

using namespace std;

bool isDel[512]={false};

int main(){
	int i;
	char s[10010],tmp='\0';
	cin.getline(s,10001);
	while(tmp!='\n'){
		scanf("%c",&tmp);
		isDel[tmp]=true;
	}
	tmp='\0';
	for(i=0;s[i]!='\0';i++){
		if(!isDel[s[i]]){
			printf("%c",s[i]);
			tmp=s[i];
		}
	}
	return 0;
}
