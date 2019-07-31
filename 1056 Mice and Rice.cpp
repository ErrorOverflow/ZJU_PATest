#include<iostream>
#include<map>

using namespace std;

int NP,NG;
int play[100][1010];
int rankin[1010];
int mice[1010]={0};
int number[100]={0};
bool isvisit[1010] = {false};
map<int,int> list;

int main(){
	int i,j,tmp,join,newmem,best,score,round=0,player,rank_num;
	cin>>NP>>NG;
	number[0]=NP;
	for(i=0;i<NP;i++){
		cin>>mice[i];
	}
	for(i=0;i<NP;i++){
		cin>>player;
		play[0][i]=player;
	}
	join=NP;
	while(join!=1){
		for(j=0,tmp=0,best=0,score=0,newmem=0;j<join;j++){
			if(mice[play[round][j]]>score){
				score = mice[play[round][j]];
				best = play[round][j];
			}
			tmp++;
			if(tmp==NG || j==join-1){
				play[round+1][newmem++]=best;
				tmp=0;
				best=0;
				score=0;
			}
		}
		join=newmem;
		number[++round]=join;
	}
	rank_num = 1;
	for(i=round;i>=0;i--){
		for(j=0;j<number[i];j++){
			if(!isvisit[play[i][j]]){
				rankin[play[i][j]]=rank_num;
				isvisit[play[i][j]]=true;
			}
		}
		if(i==round){
			rank_num++;
		}else{
			rank_num+=number[i]-number[i+1];
		}
	}
	for(i=0;i<NP;i++){
		cout<<rankin[i];
		if(i!=NP-1){
			cout<<" ";
		}
	}
	return 0;
}
