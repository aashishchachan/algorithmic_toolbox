#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int refills=0;
    int travelled=0;
    for(int i=0; i<stops.size(); i++){  
        if(stops[i]-travelled > tank){
            refills=-1;
            break;
        }
        if(dist-travelled <=tank) break;
        while(i<stops.size() && stops[i]-travelled <=tank) i++; 
        i-=1;
        travelled=stops[i];
        refills++;
    }
    if(dist-travelled > tank) return -1;

    return refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
