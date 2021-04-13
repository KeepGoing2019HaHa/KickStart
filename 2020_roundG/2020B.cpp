#include "unordered_map"
#include "vector"
#include "iostream"
#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "math.h"
using namespace std;
typedef long long ll;

int a[1001][1001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int t_ = 1; t_ <= T; t_ += 1) {
        int n;
        cin>>n;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
        ll res=0;
        for(int i=0;i<n;i++) {
            ll x=i,y=0,s=0;
            while(x<n&&y<n) s+=a[y][x],y++,x++;
            res=max(res,s);
        }
        for(int i=0;i<n;i++) {
            ll x=0,y=i,s=0;
            while(x<n&&y<n) s+=a[y][x],y++,x++;
            res=max(res,s);
        }
        cout << "Case #" << t_ << ": " << res << endl;
    }
    return 0;
}