#include<iostream>
#include<map>

using namespace std;

int D,N;
double capa,davg,ALL;
map<int,double> station;
double total=0;

int find(map<int,double>::iterator low,map<int,double>::iterator high,double fuel){
	map<int,double>::iterator iter;
	map<int,double>::iterator itmin;
	double cheap=999999,next;
	cout<<low->first<<" "<<high->first<<endl;
	if(low==high){
		return 0;
	}
	/*
	if(high==station.end()){
		next=D;
	}else{
		iter=high;
		iter--;
		next=iter->first;
	}
	*/
	iter=low;
	while(iter!=high){
		if(iter->second<cheap){
			cheap=iter->second;
			itmin=iter;
		}
		iter++;
	}
	find(low,itmin,0);
	iter=high;
	iter--;
	if(iter->first-itmin->first<=ALL){
		total+=(iter->first-itmin->first)/davg*itmin->second;
		return 0;
	}
	
	while(true){
			
	}
	/*
	if(D-itmin->first<=ALL){
		total+=(D-itmin->first)/davg*itmin->second;
	}else{
		iter--; 
		if(iter==itmin){
			iter++;
			if(iter->first-itmin->first>ALL){
				printf("The maximum travel distance = %.2lf",itmin->first+ALL);
				return -1;
			}
		}
		total+=capa*itmin->second;
	}
	find(itmin,high);
	*/
	return 0;
}

int main(){
	int i,max,dis;
	double pri,mid;
	cin>>capa>>D>>davg>>N;
	ALL=capa*davg;
	for(i=0,max=0;i<N;i++){
		cin>>pri>>dis;
		station.insert(pair<int,double>(D,999999));
	}
	mid=find(station.begin(),station.end(),0);
	if(mid==0){
		return 0;
	}else{
		printf("%.2lf",total);
	}
	return 0;
}
