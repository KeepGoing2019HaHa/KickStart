#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1) {
        string s;
        cin>>s;
        ll E=0,W=0,N=0,S=0;
        vector<ll>st{1};
        for(char c:s) {
            if(c=='E'){
                E+=st.back();
            } else if(c=='W'){
                W+=st.back();
            } else if(c=='N'){
                N+=st.back();
            } else if(c=='S'){
                S+=st.back();
            } else if(c>='2'&&c<='9'){
                ll tmp=c-'2'+2;
                tmp *= st.back();
                tmp %= mod;
                st.push_back(tmp);
            } else if(c==')'){
                st.pop_back();
            }
        }
        cout << "Case #" << t << ": " << ((E-W)%mod+mod)%mod+1 << " " << ((S-N)%mod+mod)%mod+1 << "\n";
    }
    return 0;
}


