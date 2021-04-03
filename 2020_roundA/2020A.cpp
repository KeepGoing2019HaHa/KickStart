#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1) {
        int N, B, ans = 0;
        cin >> N >> B;
        vector<int> A(N);
        for(int& x:A) cin>>x;
        sort(A.begin(), A.end());
        for(int& x:A) {
            if(B>=x) {
                ans++;
                B-=x;
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}