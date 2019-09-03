#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int N;

int main(){
	int i,j,num;
	vector<int> list;
	string step;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		cin>>step;
		if(step=="PeekMedian"){
			if(list.size()==0){
				printf("Invalid\n");
			}else{
				vector<int> ranklist;
                ranklist.assign(list.begin(),list.end());
				sort(ranklist.begin(),ranklist.end());
				if(ranklist.size()%2==1){
					printf("%d\n",ranklist[ranklist.size()/2]);
				}else{
					printf("%d\n",ranklist[ranklist.size()/2-1]);
				}
			}
		}else if(step=="Push"){
			scanf("%d",&num);
			list.push_back(num);
		}
		else if(step=="Pop"){
			if(list.size()==0){
				printf("Invalid\n");
			}else{
				printf("%d\n",list[list.size()-1]);
				list.pop_back();			
			}
		}
	}
	return 0;
}
