#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
using namespace std;

pair <int, int> partition(vector <int> &a, int left, int right){
  if(left>=right) return make_pair(left,left);  
  int m1=left, m2=left;
  int piv = rand()%(right-left+1) +left;
  swap(a[piv], a[left]);
  for(int i=left+1; i<=right ;i++){
    if(a[i]<a[left]) {
      swap(a[i], a[m1+1]); m1++;
      if(m2>=m1) {swap(a[i], a[m2+1]); m2++;}
      else if(m2<m1) m2++;
    }
    else if(a[i]==a[left]) {swap(a[i], a[m2+1]); m2++;}
  }
  swap(a[left], a[m1]);
  m1--;

  return make_pair(m1, m2);
}

void quick_sort(vector <int> &a, int left, int right){
  if(left>=right) return;
  pair <int, int> part;
  part= partition(a, left, right);
  quick_sort(a, left, part.first);
  quick_sort(a, part.second+1, right);
  return;
}


int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
