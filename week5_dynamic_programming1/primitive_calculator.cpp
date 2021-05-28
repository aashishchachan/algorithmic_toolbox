#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using std::vector;

vector <int> sequence_dp(int m) {
  vector <pair <int,int>> sol(m+1);
  sol[0]={0,0}; sol[1]=make_pair(0,0); 
  for(int i=2; i<=m; i++){
    pair <int, int> temp= make_pair(INT_MAX, 0);
    if(i>=1 && sol[i-1].first+1 < temp.first) temp= make_pair(sol[i-1].first+1, i-1);
    if(i%2==0 && sol[i/2].first+1 < temp.first) temp=make_pair(sol[i/2].first+1, i/2);
    if(i%3==0 && sol[i/3].first+1 < temp.first) temp=make_pair(sol[i/3].first+1, i/3);
    sol[i]=temp;
  }
  int nums=sol[m].first;
  vector <int> sequence;
  for(int i=m; i!=0;){
    sequence.push_back(i);
    i=sol[i].second;
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = sequence_dp(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
