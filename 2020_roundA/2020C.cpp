#include <bits/stdc++.h>

using namespace std;

int a[100001];

bool ok(int p[], int n, int mid, int k) {
    for(int i=1;i<n;i++){
        int tmp=ceil((p[i]-p[i-1]+0.0)/mid)-1;
        k-=tmp;
        if(k<0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1) {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>a[i];

        int lo=0,hi=*max_element(a,a+n);
        int res=hi;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(ok(a,n,mid,k)){
                res=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        cout << "Case #" << t << ": " << res << "\n";
    }
    return 0;
}


