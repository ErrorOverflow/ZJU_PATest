#include<iostream> 
#include<set>
using namespace std;

int main(){
	int N,t,i,j,m,n;
	bool isFind=false;
	multiset<unsigned short int> list;
	cin>>N;
	for(i=0;i<N;i++){
		cin>>t;
		list.insert(t);
	}
	for(i=0;i<N;i++){
		for(j=1;j<N;j++){
			if(j*(j+i)==N){
				m=j+i;
				n=j;
				isFind=true;
				break;
			}
		}
		if(isFind) break;
	}
	unsigned short int res[m][n];
	auto iter=list.rbegin();
	for(i=n;i>1;i-=2){
		for(j=(n-i)/2;j<i+(n-i)/2 && j<n;j++){
			//cout<<(n-i)/2<<" "<<j<<endl;
			res[(n-i)/2][j]=*iter;
			iter++;
		}
		for(j=(n-i)/2+1;j<m-(n-i)/2 && j<m;j++){
			//cout<<j<<" "<<n-(n-i)/2-1<<endl;
			res[j][n-(n-i)/2-1]=*iter;
			iter++;
		}
		for(j=i+(n-i)/2-2;j>=(n-i)/2 && j<n;j--){
			//cout<<m-1-(n-i)/2<<" "<<j<<endl;
			res[m-1-(n-i)/2][j]=*iter;
			iter++;
		}
		for(j=m-(n-i)/2-2;j>(n-i)/2 && j<m;j--){
			//cout<<j<<" "<<(n-i)/2<<endl;
			res[j][(n-i)/2]=*iter;
			iter++;
		}		
	}
	if(i==1){
		for(j=(n-1)/2;j<m-(n-1)/2;j++){
			res[j][(n-1)/2]=*iter;
			iter++;
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cout<<res[i][j];
			if(j!=n-1){
				cout<<" ";
			}
		}
		if(i!=m-1){
			cout<<endl;
		}
	}
	return 0;
}
