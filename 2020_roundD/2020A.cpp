#include "unordered_map"
#include "vector"
#include "iostream"
#include "stdio.h"
#include "string.h"
using namespace std;
typedef long long ll;

int a[200001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1) {
        int n,res=0;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        int max_v=-1;
        for(int i=0;i<n;i++){
            if(a[i]>max_v&&(i==n-1||a[i]>a[i+1])) res++;
            max_v=max(max_v,a[i]);
        }
        cout << "Case #" << t << ": " << res << "\n";
    }
    return 0;
}