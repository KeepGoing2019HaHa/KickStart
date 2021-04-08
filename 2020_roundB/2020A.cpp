#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1) {
        int n,ans=0,p1,p2,p;
        cin>>n>>p1>>p2;
        for(int i=2;i<n;i++){
            cin>>p;
            if(p2>p&&p2>p1)ans++;
            p1=p2;
            p2=p;
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}