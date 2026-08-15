#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <numeric>
#include <iomanip>
#include <fstream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
bool compare(pair<string, int> x, pair<string, int> y) {
    return x.second < y.second;
}
int main() {
    int n; cin >> n;
    vector<pair<string,int>>a(n);
    ofstream ofs("G:\\マイドライブ\\TestFile.csv");
    ofs << "生徒,点数,クラス\n";
    rep(i,n){
    cin >> a[i].first >> a[i].second;
    }
   sort(a.begin(), a.end(), compare);
    int min_diff = 2e9;
    int min_advance = 2e9;
    int ans = -1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i].second == a[i + 1].second)continue;
        int nomal = i + 1;
        int advance = n - nomal;
        int diff = abs(advance - nomal);
        if (min_diff > diff) {
            min_diff = diff;
            min_advance = advance;
            ans = a[i + 1].second;
        }
        else if (min_diff == diff && min_advance > advance) {
            min_advance = advance;
            ans = a[i + 1].second;
        }
    }
    rep(i,n){
        if(a[i].second < ans)ofs << a[i].first << "さん," << a[i].second << "点," << "Aクラス\n"; 
        else ofs << a[i].first << "さん," << a[i].second << "点," << "Sクラス\n"; 
    }
    ofs.close();
}