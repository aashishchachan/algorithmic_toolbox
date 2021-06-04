#include <bits/stdc++.h>

using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  long long n = exp.length();
  long long m[n][n];
  long long M[n][n];

  for (int i = 0, j = 0; i < n; i+=2, j+=2 ){
    m[i][i] = exp[i] - '0';
    M[i][i] = exp[i] - '0';
  }
  for (int s = 2; s< exp.length(); s+=2){
    for (int i = 0, j = i + s; j<exp.length(); i += 2, j += 2){
      long long mn = LLONG_MAX;
      long long mx = LLONG_MIN;
      for (int k = i + 1; k < j; k += 2){
        long long a = eval(m[i][k-1], m[k+1][j], exp[k]);
        long long b = eval(M[i][k-1], M[k+1][j], exp[k]);
        long long c = eval(m[i][k-1], M[k+1][j], exp[k]);
        long long d = eval(M[i][k-1], m[k+1][j], exp[k]);
        mn = min({mn, a, b, c, d});
        mx = max({mx, a, b, c, d});
      }
      m[i][j] = mn;
      M[i][j] = mx;
    }
  }
  return M[0][exp.length()-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
