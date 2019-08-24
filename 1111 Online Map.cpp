#include<iostream>
#include<vector>
#define concat(a, b) a ## b
using namespace std;

struct Node{
	vector<int> next;
	vector<int> length;
	vector<int> time;
};
struct Data{
	int n;
	int c;
};

int N,M,sou,des;
Node list[501];
vector<int> shortest;
vector<int> fastest;
vector<int> now;
int nowt,nowl,mint,minl;
int res[2][2];

void bfs(){
	
}

int main(){
	int i,j,v1,v2,one,l,t;
	cin>>N>>M;
	for(i=0;i<M;i++){
		cin>>v1>>v2>>one>>l>>t;
		Node[v1].next.push_back(v2);
		Node[v1].length.push_back(l);
		Node[v1].time.push_back(t);
		if(!one){
		Node[v2].next.push_back(v1);
		Node[v2].length.push_back(l);
		Node[v1].time.push_back(t);			
		}
	}
	cin>>sou>>des;
	int S[N+1],U[N+1];
	vector<Data> S;
	vector<Data> U;
	S.push_back(Data{sou,0});
	for(i=0;i<)
	while(true){
		
	}
	S.clear();
	U.clear();
	S.push_back(Data{sou,0});
	return 0;
}
