#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> a,b;
int N;

int downAdjust(int high){
	for(int i=0;i*2+1<high;i++){
		int j=i*2+1;
		if(j+1<high && b[j+1]>b[j]) j++;
		if(b[i]<b[j]) swap(b[i],b[j]);
	}
}

int main(){
	scanf("%d",&N);
	a.resize(N);
	b.resize(N);
	for(int i=0;i<N;i++) scanf("%d",&a[i]);
	for(int i=0;i<N;i++) scanf("%d",&b[i]);
	int mid,p;
	for(mid=1;mid<N && b[mid]>b[mid-1];mid++);
	for(p=mid;p<N && a[p]==b[p];p++);
	if(p==N){
		printf("Insertion Sort\n");
		sort(&b[0],&b[mid+1]);
		for(int i=0;i<N;i++) printf("%d%s",b[i],i==N-1?"":" ");
	}else{
		printf("Heap Sort\n");
		int i;
		for(i=N-1;i>=0 && b[i]>b[0];i--);
		swap(b[0],b[i]);
		downAdjust(i);
		for(int i=0;i<N;i++) printf("%d%s",b[i],i==N-1?"":" ");
	}
}
