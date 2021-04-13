//#include "unordered_map"
//#include "vector"
#include "iostream"
//#include "stdio.h"
//#include "string.h"
//#include "algorithm"
//#include "math.h"
//#include "numeric"
using namespace std;
typedef long long ll;

//int a[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1) {
        string s;
        cin>>s;
        ll res=0,kick=0;
        for(int i=0;i<int(s.length())-4;i++){
            if(s.substr(i,4)=="KICK") kick+=1;
            if(s.substr(i,5)=="START") res+=kick;
        }
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}