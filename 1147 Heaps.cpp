#include<vector>
#include<iostream>

using namespace std;
int n,m;
vector<int> v;
int post(int p){
	if(p>=n){
		return 0;
	}
	post(p*2+1);
	post(p*2+2);
	printf("%d%c",v[p],p==0?'\n':' ');
	return 0;
}
int main(){
	scanf("%d%d",&m,&n);
	v.resize(n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &v[j]);
        int flag = v[0] > v[1] ? 1 : 2;
 		for(int i=0;i<=(n-1)/2;i++){
			if((((i*2+1<n && v[i]>v[i*2+1]) || (i*2+2<n && v[i]>v[i*2+2])) && flag==2) || (((i*2+1<n && v[i]<v[i*2+1]) || (i*2+2<n &&v[i]<v[i*2+2])) && flag==1)){
				flag=0;
				break;
			}
		}
        if (flag == 0) printf("Not Heap\n");
        else printf("%s Heap\n", flag == 1 ? "Max" : "Min");
        post(0);
    }
	return 0;
}
