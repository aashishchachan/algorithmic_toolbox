#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using std::vector;
using namespace std;


int get_majority_element(vector<int> &a, int left, int right) {
  if (left > right) return -1;
  if(left == right) return a[left];

  int x= get_majority_element(a, left, left + (right-left)/2);
  int y= get_majority_element(a, left + 1+ (right-left)/2, right);

  if(x==y) return x;
  else{
    int count=0;
    if(y!=-1){
      for(int i=left; i<=right; i++){
        if(a[i]==y) count++;
      }
      if(count>(right-left+1)/2) return y;
    }  
    
    if(x!=-1){
      count=0;
      for(int i=left; i<=right; i++){
        if(a[i]==x) count++;
      }
      if(count>(right-left+1)/2) return x;
    }
    return -1;  
  }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  int x= (get_majority_element(a, 0, a.size()-1));
  if(x==-1) std::cout << 0 << '\n';
  else std::cout << 1 << '\n';
}
