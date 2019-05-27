#include<iostream>
#include<map>

using namespace std;

int D,N;
double capa,davg,ALL;
map<int,double> station;
double total=0;

int find(map<int,double>::iterator low,map<int,double>::iterator high){
	map<int,double>::iterator iter;
	map<int,double>::iterator itmin;
	map<int,double>::iterator p;
	map<int,double>::iterator q;
	double cheap=999999,next;
	cout<<low->first<<" "<<high->first<<endl;
	if(low==high){
		return 0;
	}
	iter=low;
	while(iter!=high){
		if(iter->second<cheap){
			cheap=iter->second;
			itmin=iter;
		}
		iter++;
	}
	find(low,itmin);
	iter=high;
	iter--;
	if(iter->first-itmin->first<=ALL){
		total+=(iter->first-itmin->first)/davg*itmin->second;
		return 0;
	}
	total+=capa*itmin->second;
	p=itmin;
	p++;
	q=high;
	q--;
	while(true){
		p++;
		if(p==q){
			p--;
			printf("The maximum travel distance = %.4lf",p->first+ALL);
			exit(0);
		}
		p--;
		cheap=999999;
		iter=p;
		while(iter!=q){
			if(iter->second<cheap){
				itmin=iter;
				cheap=iter->second;
			}
			iter++;
		}
		if(q->second<cheap){
			itmin=q;
			cheap=q->second;
		}
		if(q->first-itmin->first<=ALL){
			total+=((q->first-itmin->first)/davg-(capa-(itmin->first-p->first)/davg))*itmin->second;
			return 0;
		}
		total+=(itmin->first-p->first)/davg*itmin->second;
		p=itmin;
	}
	return 0;
}

int main(){
	int i,max,dis;
	double pri,mid;
	cin>>capa>>D>>davg>>N;
	ALL=capa*davg;
	station.insert(pair<int,double>(D,99999));
	for(i=0,max=0;i<N;i++){
		cin>>pri>>dis;
		station.insert(pair<int,double>(dis,pri));
	}
	mid=find(station.begin(),station.end());
	if(mid==0){
		return 0;
	}else{
		printf("%.2lf",total);
	}
	return 0;
}