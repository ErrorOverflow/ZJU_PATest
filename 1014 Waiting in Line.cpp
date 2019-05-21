#include<iostream>
#include<vector>
#include<string>

using namespace std;

string changeTime(int t){
	string s="";
	int h,m;
	h=8+t/60;
	m=t%60;
	s+=(h<10)?"0":"";
	s+=to_string(h);
	s+=":";
	s+=(m<10)?"0":"";
	s+=to_string(m);
	return s;
}

int main(){
	int i,j,N,M,K,Q,process[1010],query[1010],tmp,now,min,min_window;
	int line[21][11][2]={0},line_s[21]={0},res[1010]={0};//line: M个人的结束时间 是谁 
	cin>>N>>M>>K>>Q;
	for(i=1;i<=K;i++){
		cin>>process[i];
	}
	for(i=0;i<Q;i++){
		cin>>tmp;
		query[i]=tmp;
	}
	for(i=0;i<M;i++){
		for(j=1;j<=N;j++){
			line[j][i][0]=i*N+j;
			line[j][i][1]=(i==0)?process[i*N+j]:line[j][i-1][1]+process[i*N+j];
		}
	}
	now=N*M+1;
	while(true){
		min=540;
		for(i=1;i<=N;i++){
			if(line[i][line_s[i]][1]<min){
				min=line[i][line_s[i]][1];
				min_window=i;
			}
		}
		if(min==540 || now>K){
			for(i=1;i<=N;i++){
				for(j=line_s[i];j<M;j++){
					res[line[i][j][0]]=line[i][j][1];
					if(line[i][j][1]>=540){
						j++;
						break;
					}
				}
				if(j!=M){
					for(;j<M;j++){
						res[line[i][j][0]]=-1;
					}
					for(j=0;j<line_s[i];j++){
						res[line[i][j][0]]=-1;
					}
					continue;							
				}
				for(j=0;j<line_s[i];j++){
					res[line[i][j][0]]=line[i][j][1];
					if(line[i][j][1]>=540){
						j++;
						break;
					}
				}		
				for(;j<line_s[i];j++){
					res[line[i][j][0]]=-1;
				}						
			}
			break;
		}
		//cout<<"#"<<now<<":"<<min<<" "<<min_window;
		res[line[min_window][line_s[min_window]][0]]=(line[min_window][line_s[min_window]][1]>540)?(-1):line[min_window][line_s[min_window]][1];
		line[min_window][line_s[min_window]][0]=now;
		line[min_window][line_s[min_window]][1]=line[min_window][(line_s[min_window]==0?M-1:(line_s[min_window]-1))][1]+process[now];
		//cout<<" "<<line[min_window][(line_s[min_window]==0?M-1:(line_s[min_window]-1))][1]<<" "<<process[now]<<endl;
		now++;
		line_s[min_window]=(line_s[min_window]==M-1)?0:line_s[min_window]+1;
	}
	for(i=now;i<=K;i++){
		res[i]=-1;
	}
	for(i=0;i<Q;i++){
		cout<<(res[query[i]]>0?changeTime(res[query[i]]):"Sorry")<<endl;
	}
	return 0;
}
