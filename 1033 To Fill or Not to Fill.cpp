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
	//cout<<low->first<<" "<<high->first<<" "<<total<<endl;
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
	if(high->first-itmin->first<=ALL){
		total+=(high->first-itmin->first)/davg*itmin->second;
		//cout<<itmin->first<<"->"<<high->first<<" "<<total<<endl;
		return 0;
	}
	total+=capa*itmin->second;
	p=itmin;
	q=high;
	while(true){
		p++;
		if(p==q){
			p--;
			printf("The maximum travel distance = %.2lf",p->first+ALL);
			exit(0);
		}
		p--;
		cheap=999999;
		iter=p;
		iter++;
		while(iter!=q){
			if(iter->second<cheap){
				itmin=iter;
				cheap=iter->second;
			}
			iter++;
		}
		//cout<<p->first<<"->"<<itmin->first<<" "<<total<<endl;
		if(q->first-itmin->first<=ALL){
			total+=((q->first-itmin->first)/davg-(capa-(itmin->first-p->first)/davg))*itmin->second;
			//cout<<itmin->first<<"->"<<q->first<<" "<<total<<endl;
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
	mid=find(station.begin(),--station.end());
	printf("%.2lf",total);
	return 0;
}