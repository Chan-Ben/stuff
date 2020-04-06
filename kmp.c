#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void prefix_table(char pattern[], int prefix[], int n){
  prefix[0] = 0;
  int len   = 0;
  int i     = 1;
  while(i < n){
    if(pattern[i] == pattern[len]){
      len++;
      prefix[i]=len;
      i++;
    } else {
      if(len > 0) len = prefix[len - 1];
      else {
        prefix[i] = len;
        i++;
      }
    }
  }
  // Move prefix table
  for(int j = n-1;j > 0;--j){
    prefix[j] = prefix[j-1];
  }
  prefix[0] = -1;
}



void kmp_search(char text[], char pattern[]){//Search text for pattern
  int n = strlen(pattern);
  int m = strlen(text);
  int* prefix = malloc(sizeof(int) * n);
  prefix_table(pattern,prefix,n);//make prefix table
  // test[i]    len(text)    = m
  // pattern[j] len(pattern) = n
  int i = 0,j = 0;
  while(i < m){
    if(j==n-1 && text[i]==pattern[j]){
      printf("%d\n", i-j);
      j=prefix[j];
    }
    if(text[i] == pattern[j]){
      i++;j++;
    }else{
      j = prefix[j];
      if(j == -1){
        i++;j++;//move to next
      }
    }
  }
}

int main(){
  char text[1000], pattern[100];
  scanf("%s %s", &text, &pattern);
  kmp_search(text,pattern);
  return 0;
}
