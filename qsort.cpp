#include <iostream>
using namespace std;
int x[100001];
void swap(int* a, int* b){
    int* t = a;
    a = b;
    b = t;
}

void quicksort(int l, int r){
    int i=0,j=0;
    int mid=x[(l+r)/2];
    if(l>=r) return;
    do{
        while(x[i]<mid) i++;//查找左半部分比中间数大的数
        while(x[j]>mid) j--;//查找右半部分比中间数小的数
        if(i<=j)//如果有一组不满足排序条件（左小右大）的数
        {
            swap(x[i],x[j]);//交换
            i++;
            j--;
        }
    }while(i<=j);//这里注意要有=
    if(l<j) quicksort(l,j);//递归搜索左半部分
    if(i<r) quicksort(i,r);//递归搜索右半部分
}

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    quicksort(1,n);
    for(int i=1;i<=n;i++)
        cout<<x[i]<<" "<<endl;
    
    return 0;
}
