#include <iostream>
#include <vector>

int Bottom_up_cut_rod(std::vector<int> p, int n){
    std::vector<int> r(0, n);
    for (int i =0; i < n; i++){
        int q = -100;
        for (int j = 0; j < i; j++){
            q = max(q, p[j] + r[i-j]);
        }
        r[i] = q;
    } 
    return r[n];
}
