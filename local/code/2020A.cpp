#include <bits/stdc++.h>

using namespace std;

int a[200001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1) {
        int n,k,res=0;
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>a[i];
        int i=0;
        while(i<n) {
            int target=k;
            while(i<n&&a[i]==target)i++,target--;
            if(target==0)res++;
            if(a[i]!=k)i++;
        }

        cout << "Case #" << t << ": " << res << "\n";
    }
    return 0;
}