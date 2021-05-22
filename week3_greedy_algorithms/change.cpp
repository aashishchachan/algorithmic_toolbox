#include <iostream>

int get_change(int m) {
  //write your code here
  int n=0;
  int coins[3]={10,5,1};
  for(int i=0; i<3; i++){
    n+=(m/coins[i]);
    m%=coins[i];
 }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}