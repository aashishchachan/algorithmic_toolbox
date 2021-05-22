#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(int a, int b){
  if(a>b) {int t=b; b=a; b=t;}
  for(int i=1; i<=a; i++ ){
    if( ((long long)b*i) % a == 0) return (long long)b*i;
  }
  return (long long)b*a;
}

void stress_test(){
  while(1){
    int a, b;
    a= rand()%10000000+1;
    b= rand()%10000000+1;  
    std::cout<<a<<" ";
    std::cout<<b;
    std::cout<<"\n";
    int res1=lcm_naive(a,b);
    int res2=lcm_fast(a,b);
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
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
