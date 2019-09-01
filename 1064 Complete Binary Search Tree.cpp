#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int num[1001],N;

int BFS(int a, int b){
	int i,j,t,left,right,mid,flag=0;
	vector<int> l[2];
	vector<int> h[2];
	l[flag].push_back(a);
	h[flag].push_back(b);
	while(!l[flag].empty()){
		l[1-flag].clear();
		h[1-flag].clear();
		for(i=0;i<l[flag].size();i++){
			int low=l[flag][i];
			int high=h[flag][i];
			if(low==high){
                if(N==1)
                    printf("%d",num[low]);
                else
				    printf(" %d",num[low]);
				continue;
			}else if(low>high){
				continue;
			}
			for(t=1;pow(2,t)-1<=high-low+1;t++);
			left=pow(2,t-2)>high-low+1-(pow(2,t-1)-1)?high-low+1-(pow(2,t-1)-1):pow(2,t-2);
			right=pow(2,t-2)>high-low+1-(pow(2,t-1)-1)?0:high-low+1-(pow(2,t-1)-1)-pow(2,t-2);
			//cout<<low<<" "<<high<<" "<<left<<" "<<right<<endl;
			if((high-low+1-left-right)%2==0){
				mid=(high-right+low+left)/2+1;
			}else{
				mid=(high-right+low+left)/2;
			}
			l[1-flag].push_back(low);
			l[1-flag].push_back(mid+1);
			h[1-flag].push_back(mid-1);
			h[1-flag].push_back(high);
			if(high-low==N-1){
				printf("%d",num[mid]);
			}else{
				printf(" %d",num[mid]);
			}			
		}
		flag=1-flag;
	}
	return 0;
}

int main(){
	int i,j,a;
	cin>>N;
	for(i=0;i<N;i++){
		//cin>>num[i];
		scanf("%d",&num[i]);
	}
	sort(num,num+N);
	BFS(0,N-1);
	return 0;
}
