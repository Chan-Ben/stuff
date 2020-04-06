//
//  main.cpp
//  eq
//
//  Created by 陈贲 on 2020/3/23.
//  Copyright © 2020 陈贲. All rights reserved.
//

#include <iostream>
int ans[14], check[3][28] = {0}, sum = 0, n;
void eq(int line) {
  if (line > n) {
    sum++;
    if (sum > 3)
      return;
    else {
      for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
      printf("\n");
      return;
    }
  }
  for (int i = 1; i <= n; i++) {
    if ((!check[0][i]) && (!check[1][line + i]) && (!check[2][line - i + n])) {
      ans[line] = i;
      check[0][i] = 1;
      check[1][line + i] = 1;
      check[2][line - i + n] = 1;
      eq(line + 1);
      check[0][i] = 0;
      check[1][line + i] = 0;
      check[2][line - i + n] = 0;
    }
  }
}

int main(int argc, const char * argv[]) {
    // std::cin>>n;
    n = 6;
    eq(1);
    std::cout << sum;
    return 0;
}
