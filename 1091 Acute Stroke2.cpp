#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n[61][2387][129];
int M,N,L,T,volume;
bool vis[61][2387][129];

struct point{
	int x;
	int y;
};

int main(){
	scanf("%d%d%d%d",&M,&N,&L,&T);
	for(int i=0;i<L;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				scanf("%d",&n[i][j][k]);
			}
		}
	}
	for(int slice=0;slice<L;){
		int x,y;
		bool isFind=false;
		for(x=0;x<M && !isFind;x++){
			for(y=0;y<N && !isFind;y++){
				if(n[slice][x][y] && !vis[slice][x][y]){
					isFind=true;
					vis[slice][x][y]=true;
				}
			}
		}
		if(!isFind){
			slice++;
			continue;
		}
		x--;
		y--;
		vector<point> block[L];
		block[slice].push_back(point{x,y});
		for(int i=slice;i<L && !block[i].empty();i++){
			queue<point> list;
			for(int j=0;j<block[i].size();j++){
				list.push(block[i][j]);
			}
			int pre=list.size();
			while(!list.empty()){
				point j=list.front();
				int a=j.x,b=j.y;
				if(a+1<M && n[i][a+1][b] && !vis[i][a+1][b]){
					list.push(point{a+1,b});
					block[i].push_back(point{a+1,b});
					vis[i][a+1][b]=true;
				}
				if(a-1>=0 && n[i][a-1][b] && !vis[i][a-1][b]){
					list.push(point{a-1,b});
					block[i].push_back(point{a-1,b});
					vis[i][a-1][b]=true;
				}
				if(b+1<N && n[i][a][b+1] && !vis[i][a][b+1]){
					list.push(point{a,b+1});
					block[i].push_back(point{a,b+1});
					vis[i][a][b+1]=true;
				}
				if(b-1>=0 && n[i][a][b-1] && !vis[i][a][b-1]){
					list.push(point{a,b-1});
					block[i].push_back(point{a,b-1});
					vis[i][a][b-1]=true;
				}
				list.pop();
			}
			if(i!=slice-1){
				for(int j=0;j<block[i].size();j++){
					int a=block[i][j].x,b=block[i][j].y;
					if(n[i+1][a][b] && !vis[i+1][a][b]){
						block[i+1].push_back(point{a,b});
						vis[i+1][a][b]=true;
					}
				}
			}
		}
		int tmp=0;
		for(int i=0;i<L;i++){
			tmp+=block[i].size();
		}
		if(tmp>=T) volume+=tmp;
	}
	printf("%d",volume);
	return 0;
}
