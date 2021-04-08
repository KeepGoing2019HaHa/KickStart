#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll D,a[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1) {
        cin>>N>>D;
        for(int i=0;i<N;i++)cin>>a[i];

        ll ans=D;
        for(int i=N-1;i>=0;i--){
            ans=ans/a[i]*a[i];
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}