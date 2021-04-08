#include <bits/stdc++.h>

using namespace std;

void get_count(int n, double *count) {
    double fm=0,fz=0;
    count[0] = 1;
    for(int i=1;i<n+1;i++){
        fm+=log(n-i+1);
        fz+=log(i);
//        fm*=n-i+1;
//        fz*=i;
        count[i]=exp(fm-fz);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(20);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1) {
        int W,H,L,U,R,D;
        cin>>W>>H>>L>>U>>R>>D;

        double pow[(W+H+3)];
        pow[0] = 1;
        for(int i=1;i<W+H+3;i++) pow[i]=pow[i-1]*0.5;

        int n = L+D-2;
        double count1[n+1];
        get_count(n, count1);

        n = R+U-2;
        double count2[n+1];
        get_count(n, count2);

        double ans=0;
        for(int i=L-1,j=D+1; i>=1&&j<=H; i--,j++){
            ans+=pow[i+j-2]*count1[i-1];
        }
        for(int i=R+1,j=U-1; i<=W&&j>=1; i++,j--){
            ans+=pow[i+j-2]*count2[i-1];
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}