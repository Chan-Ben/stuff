#include <iostream>
#include <cstdio>
using namespace std;
#define LEN 1000
int a[LEN],tree[LEN];

void build(int node,int start,int end){
  if(start==end){
    tree[node] = a[start];
  }
  else{
    int mid = (start+end)/2;
    int leftnode = node * 2+1;
    int rightnode = node * 2+2;
    build(leftnode,start,mid);
    build(rightnode,mid+1,end);
    tree[node]=tree[leftnode]+tree[rightnode];
  }
}

void query(int node,int start, int end, int idx, int val){
  if()
}

int main(){
  FILE* input = fopen("test.in","r");
  int n;cin>>n;
  for(int i=0;i<1000;i++) tree[i]=0;
  for(int i=0;i<n;i++) fscanf(input,"%d", &a[i]);
  build(0,0,n-1);


  return 0;
}
