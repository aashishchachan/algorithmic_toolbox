#include <iostream>
#include <string>
#include <bits/stdc++.h>

#define INT_MAX 2147483647

using namespace std;

pair <int, pair<int, int>> min_t(int i, int j, bool eq, vector<vector<int>> &arr){
  int temp=INT_MAX;
  pair<int, int> t;
  if (eq){
    if(arr[i-1][j-1]<temp) {
      temp = arr[i-1][j-1];
      t = make_pair(i - 1, j - 1);
    }
    if (arr[i][j - 1] + 1 < temp){
      temp = arr[i][j - 1] + 1;
      t = make_pair(i, j - 1);
    }
    if(arr[i-1][j]+1<temp) {
      temp = arr[i-1][j] + 1;
      t = make_pair(i - 1, j - 1);
    }
    return make_pair(temp, t);
  }
  else{
    if(arr[i-1][j-1] + 1 < temp) {
      temp = arr[i-1][j-1] + 1;
      t = make_pair(i - 1, j - 1);
    }
    if (arr[i][j - 1] + 1 < temp){
      temp = arr[i][j - 1] + 1;
      t = make_pair(i, j - 1);
    }
    if(arr[i-1][j] + 1 < temp) {
      temp = arr[i-1][j] + 1;
      t = make_pair(i - 1, j - 1);
    }
    return make_pair(temp, t);
  }
} 


int edit_distance(const string &str1, const string &str2) {
  vector<vector<int>> arr;
  for (int i = 0; i < str1.length() + 1; i++){
    vector<int> temp;
    for(int j = 0; j <str2.length()+1; j++){ 
      temp.push_back(0);
    }
    arr.push_back(temp);
  }

  for (int i = 0; i < str1.length() + 1; i++){
    arr[i][0] = i;
  }
  for (int i = 0; i< str2.length()+1; i++){
    arr[0][i] = i;
  }
  for (int i = 1; i< str1.length()+1; i++){
    for(int j = 1; j <str2.length()+1; j++){ 
      pair <int, pair <int, int>> temp = min_t(i,j, str1[i-1]==str2[j-1], arr);
      arr[i][j] = temp.first;
    }
  }
  return arr[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}