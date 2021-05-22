#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b){
  int cur_gcd=1;
  if(a<b){
    int t=a;
    a=b;
    b=t;
  }
  while(cur_gcd<=a && cur_gcd<=b){
    int t=b;
    b=a%b;
    if(b==0) return t;
    a=t;
  }
  return cur_gcd;
}

void stress_test(){
  while(1){
    int n= rand()%10 +2;
    std::cout<<n<<" \n";
    int a, b;
    a= rand()%1000000;
    b= rand()%1000000;  
    std::cout<<a<<" ";
    std::cout<<b;
    std::cout<<"\n";
    int res1=gcd_naive(a,b);
    int res2=gcd_fast(a,b);
    if(res1!=res2){
      std::cout<<"Wrong Answer: "<<res1<<" "<<res2<<" \n";
      break;
    }
    else std:: cout<<"OK\n";
  }
}


int main() {
  //stress_test();
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
