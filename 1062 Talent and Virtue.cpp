#include<iostream>
#include<map>
#include<set>
#include<vector>

using namespace std;

struct PEOPLE{
	string ID;
	int virtue;
	int talent;
};

map<string,PEOPLE> namelist;
map<int,map<int,set<string>>> sage;
map<int,map<int,set<string>>> noble;
map<int,map<int,set<string>>> fool;
map<int,map<int,set<string>>> small;

int main(){
	int i,j,N,L,H,virtue,talent;
	string name;
	map<int,map<int,set<string>>>::iterator it1;
	map<int,set<string>>::iterator it2;
	set<string>::iterator it3;
	cin>>N>>L>>H;
	for(i=0,j=0;i<N;i++){
		cin>>name>>virtue>>talent;
		if(virtue<L || talent<L){
			continue;
		}
		else if(virtue>=H && talent>=H){
			auto tmp_iter = sage.find(talent+virtue);
			namelist.insert(pair<string,PEOPLE>(name,PEOPLE{name,virtue,talent}));
			if(tmp_iter==sage.end()){
				map<int,set<string>> tmpmap;
				set<string> tmpset;
				tmpset.insert(name);
				tmpmap.insert(pair<int,set<string>>(virtue,tmpset));
				sage.insert(pair<int,map<int,set<string>>>(talent+virtue,tmpmap));
			}else{
				auto iter = tmp_iter->second.find(virtue);
				if(iter==tmp_iter->second.end()){
					set<string> tmpset;
					tmpset.insert(name);
					tmp_iter->second.insert(pair<int,set<string>>(virtue,tmpset));
				}else{
					iter->second.insert(name);
				}
			}
		}
		else if(virtue>=H && talent<H){
			auto tmp_iter = noble.find(talent+virtue);
			namelist.insert(pair<string,PEOPLE>(name,PEOPLE{name,virtue,talent}));
			if(tmp_iter==noble.end()){
				map<int,set<string>> tmpmap;
				set<string> tmpset;
				tmpset.insert(name);
				tmpmap.insert(pair<int,set<string>>(virtue,tmpset));
				noble.insert(pair<int,map<int,set<string>>>(talent+virtue,tmpmap));
			}else{
				auto iter = tmp_iter->second.find(virtue);
				if(iter==tmp_iter->second.end()){
					set<string> tmpset;
					tmpset.insert(name);
					tmp_iter->second.insert(pair<int,set<string>>(virtue,tmpset));
				}else{
					iter->second.insert(name);
				}
			}
		}
		else if(virtue<H && talent<H && virtue>talent){
			auto tmp_iter = small.find(talent+virtue);
			namelist.insert(pair<string,PEOPLE>(name,PEOPLE{name,virtue,talent}));
			if(tmp_iter==small.end()){
				map<int,set<string>> tmpmap;
				set<string> tmpset;
				tmpset.insert(name);
				tmpmap.insert(pair<int,set<string>>(virtue,tmpset));
				small.insert(pair<int,map<int,set<string>>>(talent+virtue,tmpmap));
			}else{
				auto iter = tmp_iter->second.find(virtue);
				if(iter==tmp_iter->second.end()){
					set<string> tmpset;
					tmpset.insert(name);
					tmp_iter->second.insert(pair<int,set<string>>(virtue,tmpset));
				}else{
					iter->second.insert(name);
				}
			}
		}
		else{
			auto tmp_iter = fool.find(talent+virtue);
			namelist.insert(pair<string,PEOPLE>(name,PEOPLE{name,virtue,talent}));
			if(tmp_iter==fool.end()){
				map<int,set<string>> tmpmap;
				set<string> tmpset;
				tmpset.insert(name);
				tmpmap.insert(pair<int,set<string>>(virtue,tmpset));
				fool.insert(pair<int,map<int,set<string>>>(talent+virtue,tmpmap));
			}else{
				auto iter = tmp_iter->second.find(virtue);
				if(iter==tmp_iter->second.end()){
					set<string> tmpset;
					tmpset.insert(name);
					tmp_iter->second.insert(pair<int,set<string>>(virtue,tmpset));
				}else{
					iter->second.insert(name);
				}
			}
		}
		j++;
	} 
	cout<<j<<endl;
	if(sage.size()>0){
		it1=sage.end();
		do{
			it1--;
			it2=it1->second.end();
			do{
				it2--;
				it3=it2->second.begin();
				while(it3!=it2->second.end()){
					cout<<*it3<<" "<<namelist.find(*it3)->second.virtue<<" "<<namelist.find(*it3)->second.talent<<endl;
					it3++;
				}
			}while(it2!=it1->second.begin());
		}while(it1!=sage.begin());		
	}
	if(noble.size()>0){
		it1=noble.end();
		do{
			it1--;
			it2=it1->second.end();
			do{
				it2--;
				it3=it2->second.begin();
				while(it3!=it2->second.end()){
					cout<<*it3<<" "<<namelist.find(*it3)->second.virtue<<" "<<namelist.find(*it3)->second.talent<<endl;
					it3++;
				}
			}while(it2!=it1->second.begin());
		}while(it1!=noble.begin());		
	}
	if(small.size()>0){
		it1=small.end();
		do{
			it1--;
			it2=it1->second.end();
			do{
				it2--;
				it3=it2->second.begin();
				while(it3!=it2->second.end()){
					cout<<*it3<<" "<<namelist.find(*it3)->second.virtue<<" "<<namelist.find(*it3)->second.talent<<endl;
					it3++;
				}
			}while(it2!=it1->second.begin());
		}while(it1!=small.begin());		
	}
	if(fool.size()>0){
		it1=fool.end();
		do{
			it1--;
			it2=it1->second.end();
			do{
				it2--;
				it3=it2->second.begin();
				while(it3!=it2->second.end()){
					cout<<*it3<<" "<<namelist.find(*it3)->second.virtue<<" "<<namelist.find(*it3)->second.talent<<endl;
					it3++;
				}
			}while(it2!=it1->second.begin());
		}while(it1!=fool.begin());			
	}
	return 0;
}
