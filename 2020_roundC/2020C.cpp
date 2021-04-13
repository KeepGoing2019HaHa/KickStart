
#include "unordered_map"
#include "vector"
#include "iostream"
#include "stdio.h"
#include "string.h"
using namespace std;
typedef long long ll;

const int max_n=1*1e8+1;
int n, a[100001], c[max_n];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1) {
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        int offset=0;
        for(int i=0;i<n;i++) if(a[i]<0) offset-=a[i];
        memset(c, 0, max_n);
        c[offset]=1;
        ll sum=0,pos_sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(a[i]>0) pos_sum+=a[i];
            for(int j=0;j*j<=pos_sum;j++) if(sum-j*j+offset>=0) ans+=c[sum-j*j+offset];
            c[sum+offset]++;
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}