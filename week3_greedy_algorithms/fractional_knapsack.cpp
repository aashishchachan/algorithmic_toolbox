#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using std::vector;
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector <pair <double, int>> v;
  for(int i=0; i<weights.size(); i++){
    v.push_back(make_pair((double)values[i]/weights[i], weights[i]));
  }
  sort(v.begin(), v.end());
for(int i=v.size()-1; i>-1; i--){
  int w=min(capacity, v[i].second);
  //cout<<w<<" ";
  value+= (double) w*(v[i].first);
  capacity-=w;
  if(capacity==0) break;
}
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
