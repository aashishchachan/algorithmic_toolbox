#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int op (int W, int pos, vector<int> &w, vector <vector<int>> &hash){
  if(hash[pos][W] == -1){
    int temp1=0, temp2=0, temp3;
    if(w[pos]<=W) temp1 = op(W - w[pos], pos - 1, w, hash) + w[pos];
    temp2 = op(W, pos - 1, w, hash);
    if(temp1 > W ) temp3 = temp2;
    else if(temp2 > W) temp3 = temp1;
    else temp3 = temp1 > temp2 ? temp1 : temp2;
    hash[pos][W] = temp3;
  }
  return hash[pos][W];
}

int optimal_weight(int W, vector<int> &w) {
  
  vector<vector<int>> hash;
  for (int i = 0; i < w.size(); i++) {
    vector<int> temp;
    temp.push_back(0);
    for (int j = 1; j <= W; j++){
      if(i==0) temp.push_back(0);
      else temp.push_back(-1);
    }
    hash.push_back(temp);
  }
  return op(W, w.size() - 1, w, hash);
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n+1);
  w[0] = 0;
  for (int i = 1; i < n+1; i++){
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
