#include <iostream>
#include <vector>

using std::vector;

long long merge(vector <int> &a, int left, int mid, int right){
  if(left>=right) return 0;
  long long inv=0;
  vector <int> b;
  for(int i=left, j=mid+1; ;){
    if(i>mid && j >right) break;
    else if(i>mid && j<=right){
      b.push_back(a[j]);
      j++;
    }
    else if(i<=mid && j>right){
      b.push_back(a[i]);
      i++;
    } 
    else if(a[i]>a[j]){
      inv+= mid-i+1;
      b.push_back(a[j]);
      j++;
    }
    else{
      b.push_back(a[i]);
      i++;
    }
  }
  for(int i=0, j=left; i<b.size(); i++, j++){
    a[j]=b[i];
  }
  return inv;
}

long long mergeSort(vector <int> &a, int left, int right){
  if(left>=right) return 0;
  int mid = left + (right-left)/2;
  long long inv=0;
  inv += mergeSort(a, left, mid);
  inv += mergeSort(a, mid+1, right);
  inv += merge(a, left, mid, right);
  return inv;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  return number_of_inversions;
}

int main() {  
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << mergeSort(a, 0, a.size()-1)<< '\n';
}
