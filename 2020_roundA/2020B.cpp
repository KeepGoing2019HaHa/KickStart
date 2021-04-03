#include <bits/stdc++.h>

using namespace std;

int N,K,P,values[50][30],dp[51][1501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1) {
        cin>>N>>K>>P;
        for(int i=0;i<N;i++)for(int j=0;j<K;j++)cin>>values[i][j];
        memset(dp,0,size(dp));

        for(int j=1;j<=min(K,P);j++) dp[0][j]=dp[0][j-1]+values[0][j-1];
        for(int i=1;i<N;i++){
            memcpy(dp[i],dp[i-1],sizeof(dp[i]));
            for(int j=1;j<=min(K*(i+1),P);j++) {
                int cnt=0;
                for(int k=1;k<=min(j,K);k++) {
                    cnt+=values[i][k-1];
                    dp[i][j]=max(dp[i][j],dp[i-1][j-k]+cnt);
                }
            }
        }

        cout << "Case #" << t << ": " << dp[N-1][P] << "\n";
    }
    return 0;
}