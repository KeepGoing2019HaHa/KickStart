#include "unordered_map"
#include "vector"
#include "iostream"
#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "math.h"
using namespace std;
typedef long long ll;

pair<int,int> a[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int t_ = 1; t_ <= T; t_ += 1) {
        int n,k,tmp1,tmp2;
        cin>>n>>k;
        for(int i=0;i<n;i++){cin>>tmp1>>tmp2,a[i]={tmp1,tmp2};}
        sort(a,a+n);
        int res=0,i=0;
        while(i<n){
            int cover=ceil((a[i].second-a[i].first+0.0)/k);
            res+=cover;
            int s=a[i].first,t=a[i].first+cover*k;
            while(i<n && s<=a[i].first && t>=a[i].second) i++;
        }

        cout << "Case #" << t_ << ": " << res << endl;
    }
    return 0;
}