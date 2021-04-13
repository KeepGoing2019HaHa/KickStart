#include "unordered_map"
#include "vector"
#include "iostream"
#include "stdio.h"
#include "string.h"
#include "queue"
#include <utility>
#include "numeric"
#include "algorithm"
#include "bitset"
#include "exception"
using namespace std;
typedef long long ll;


int W,N;
ll a[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int case_ = 1; case_ <= T; case_ += 1) {
        cin>>W>>N;
        for(int i=0;i<W;i++) cin>>a[i];
        sort(a, a+W);
        ll res = 0;
        int i=0;
        while(i<W && a[i]-a[0]<=N-(a[i]-a[0])) i++,res+=a[i]-a[0];
        int j=i--;


        cout << "Case #" << case_ << ": " << solve(st, RA,PA, RB,PB, 0) << endl;
    }
    return 0;
}