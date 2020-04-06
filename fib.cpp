#include <iostream>
using namespace std;
int fib[100005];

int main(){
	fib[0]=1;fib[1]=1;
	cout<<"Input n:\n"<<endl;
	int n; cin>>n;
	for(int i=2;i<=n;i++){
		fib[i]=fib[i-1] + fib[i-2];
	}
	cout<<fib[n-1]<<endl;
	return 0;
}
