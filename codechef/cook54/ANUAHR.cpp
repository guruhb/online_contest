#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

struct greaterthan {
    template<class T> 
    bool operator() (T const &a, T const &b) const { return a > b; }
};


void max_area_from_rects(vector<int> &in, int n, int m, vector<long long> &r) {
    long long area = 0;
    vector<long long> a;

    for(int i = 0; i < in.size(); i+=2) {
        area = in[i] * in[i+1];
        a.push_back(area);
    }

    sort(a.begin(), a.end(), greaterthan());
    
    area = 0;
    //for(int i = 0; i < (n - m); ++i) {
      //  area += a[i];
   // }
   if(a.size() <= (a.size() - 1 - m)) 
        r.push_back(a[a.size() - 1 - m]);
    else 
        r.push_back(a[a.size() - 1]); 
}

int main() {
    int T;
    int N;
    int M;
    cin >> T;
    int p;
    vector<int> rects;
    vector<long long> result;
    for(int i = 0; i < T; ++i) {
        cin >> N ;
        cin >> M;
        for(int j = 0; j < (N * 2); ++j) {
            cin >> p; 
            rects.push_back(p);
        }
        max_area_from_rects(rects, N, M, result);
    }
    
    for(int i = 0; i < result.size(); ++i) 
        cout << result[i] << endl;
    
   return 0;
}
