#include<iostream>
#include <cmath>
using namespace std;
string lowbit[]= {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string highbit[]= {"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int find1(string s[],string tmp){
    for(int i=0;i<13;i++){
        if(tmp==s[i]) return i;
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    getchar();
    for(int i=0;i<n;i++){
        string s;
        getline(cin,s);
        if(isdigit(s[0])){
            int num=0;
            for(int i=0;i<(int)s.size();i++){
                num += (s[i]-'0')*pow(10,(int)s.size()-i-1);
            }
            if(num<13) cout<<lowbit[num]<<endl;
            else{
                cout<<highbit[num/13];
                if(num%13) cout<<" "<<lowbit[num%13];
                cout<<endl;
            }
        }else{
            int spaceindex=0;
            while(spaceindex<(int)s.size() && s[spaceindex]!=' ') spaceindex++;
            if(spaceindex==(int)s.size()){
                int pos1=find1(lowbit,s);
                if(pos1!=-1) cout<<pos1<<endl;
                else{
                    int pos2=find1(highbit,s);
                    cout<<pos2*13<<endl;
                }
            }else{
                string s1=s.substr(0,spaceindex),s2=s.substr(spaceindex+1,(int)s.size()-1-(spaceindex+1)+1);
                int pos1=find1(highbit,s1),pos2=find1(lowbit,s2);
                cout<<(pos1*13+pos2)<<endl;
            }
        }
    }
    return 0;
} 
