#include<iostream>
#include<cstring>
using namespace std;
char s[85];

int main(){
  cin>>s;
  int n = 0,sum = 0;
  int len = strlen(s);
  for(int i=0;i<len;i++){
    if(s[i]=='O'){
      sum += ++n;
      if(s[i+1]=='X'){
        n = 0;
      }
    }
  }
  cout<<sum<<endl;

  return 0;
}
