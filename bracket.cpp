#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 500010;
int n,idx,h[N],e[N],ne[N];
long long f[N],g[N];
int stk[N],p[N],top;
char str[N];

void add(int a,int b){
    e[idx] = a;ne[idx] = b;h[a] = idx++;
}

void dfs(int u){
    if(str[u] == '('){
        stk[++top] = u;
        f[u] = f[p[u]];
        for(int i = h[u];~i;i=ne[u]) dfs(e[i]);
        top--;
    }else{
        if(!top){
            f[u]=f[p[u]];
            for(int i = h[u];~i;i=ne[u]) dfs(e[i]);
        }else{
            int t = stk[top--];
            g[u] = g[p[t]] + 1;
            f[u] = f[p[u]] + g[u];
            for(int i = h[u];~i;i=ne[u]) dfs(e[i]);
            stk[++top] = t;
        }
    }
}

int main() {
    scanf("%d", &n);scanf("%s", str+1);
    memset(h,-1,sizeof(h));
    for(int i = 2;i<=n;i++){
        scanf("%d", &p[i]);
        add(p[i],i);
    }
    dfs(1);
    long long res = 0;
    for(int i = 1;i<=n;i++){
        res ^= f[i]*i;
    }
    printf("%lld\n", res);
    
    return 0;
}
