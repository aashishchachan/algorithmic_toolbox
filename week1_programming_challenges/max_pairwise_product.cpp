#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<long long>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
    int max1=0, max2=0; 
    for (int first = 0; first < n; ++first) {
        if(numbers[first] > numbers[max1]) max1=first;
    }
    if (max1==0) max2=1;
    for (int first = 0; first < n; ++first) {
        if((numbers[first] > numbers[max2]) &&( first!=max1)) max2=first;
    }
    max_product = numbers[max1]*numbers[max2];
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
