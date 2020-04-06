#include<iostream>
#include<string>
#include<cctype>
using namespace std;
double sum;
const double d[]={0,0,12.01,0,0,0,0,1.008,0,0,0,0,0,14.01,16.00};
string s;

int main(){
  cin>>s;
  for(int i = 0;i<s.length();i++){
    if(isalpha(s[i])){
      if(isdigit(s[i+1])){
        if(isdigit(s[i+2])){
          sum+=(d[s[i]-'A'])*((s[i+1]-'0')*10+(s[i+2]-'0'));
          continue;
        }
        sum+=(d[s[i]-'A'])*(s[i+1]-'0');
      }else{
        sum+=d[s[i]-'A'];
      }
    }
  }
  cout<<sum;

  return 0;
}
