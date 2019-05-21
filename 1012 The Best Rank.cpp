#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){
	int i,code,c,m,e,N,K,best_rank,now_rank,counter;
	char grade;
	vector<int> list;
	map<int,int> C,M,E,A;
	cin>>N>>K;
	for(i=0;i<N;i++){
		cin>>code>>c>>m>>e;
		C.insert(pair<int,int>(200-c,code));
		M.insert(pair<int,int>(200-m,code));
		E.insert(pair<int,int>(200-e,code));
		A.insert(pair<int,int>(200-(c+m+e)/3,code));
	}
	for(i=0;i<K;i++){
		cin>>code;
		list.push_back(code);
	}
	for(i=0;i<K;i++){
		
		best_rank=K+1;

		auto iter=A.begin();
		counter=0;
		while(iter!=A.end()){
			counter++;
			if(iter->second==list[i]){
				break;
			}
			iter++;
		}
		if(iter==A.end()){
			now_rank=-1;
		}else
			now_rank=counter;	
		
		if(now_rank==-1){
			cout<<"N/A";
		}else{
			if(now_rank<best_rank){
				grade='A';
				best_rank=now_rank;
			}
			
			iter=C.begin();
			counter=0;
			while(iter!=C.end()){
				counter++;
				if(iter->second==list[i]){
					break;
				}
				iter++;
			}
			now_rank=counter;				
			if(now_rank<best_rank){
				grade='C';
				best_rank=now_rank;
			}
			
			counter=0;
			iter=M.begin();
			while(iter!=M.end()){
				counter++;
				if(iter->second==list[i]){
					break;
				}
				iter++;
			}
			now_rank=counter;	
			if(now_rank<best_rank){
				grade='M';
				best_rank=now_rank;
			}
			
			counter=0;
			iter=E.begin();
			while(iter!=E.end()){
				counter++;
				if(iter->second==list[i]){
					break;
				}
				iter++;
			}
			now_rank=counter;	
			if(now_rank<best_rank){
				grade='E';
				best_rank=now_rank;
			}
			
			cout<<best_rank<<" "<<grade;			
		}
		if(i!=K-1){
			cout<<endl;
		}
	}
	return 0;
} 
