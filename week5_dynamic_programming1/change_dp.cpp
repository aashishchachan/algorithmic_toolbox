#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int get_change(int m) {
  vector <int> sol(m+1);
  sol[0]=0; 
  for(int i=1; i<=m; i++){
    int temp=INT_MAX;
    if(i>=1 && sol[i-1]+1 < temp) temp=sol[i-1]+1;
    if(i>=3 && sol[i-3]+1 < temp) temp=sol[i-3]+1;
    if(i>=4 && sol[i-4]+1 < temp) temp=sol[i-4]+1;
    sol[i]=temp;
  }
  return sol[m];
}

int main() {
  int m;
  std::cin >> m;
  int s = get_change(m);
  std::cout << s << '\n';
}
