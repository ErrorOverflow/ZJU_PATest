#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int supply;
vector<int> next_r[100010];
int N;
double P,r;

int main(){
	int i,j;
	cin>>N>>P>>r;
	for(i=0;i<N;i++){
		cin>>supply;
		next_r[supply+1].push_back(i+1);
	}
	vector<int> list;
	vector<int> tmp;
	bool isF;
	int level=0;
	list.push_back(0);
	while(true){
		isF=true;
		for(i=0;i<list.size();i++){
			for(j=0;j<next_r[list[i]].size();j++){
				tmp.push_back(next_r[list[i]][j]);
				isF=false;
			}
		}
		if(isF){
			printf("%.2lf %d",P*pow(1+double(r)/100,level-1),list.size());
			break;
		}
		list.assign(tmp.begin(),tmp.end());
		tmp.clear();
		level++;
	}
	return 0;
}
