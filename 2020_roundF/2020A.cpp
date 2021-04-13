#include "unordered_map"
#include "vector"
#include "iostream"
#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "math.h"
#include "numeric"
using namespace std;
typedef long long ll;

//int a[100001];
pair<int,int> b[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1) {
        int n,k,tmp;
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>tmp,b[i]={ceil((tmp+0.0)/k),i+1};
        sort(b,b+n);
        cout << "Case #" << t << ": ";
        for(int i=0;i<n;i++)cout<<b[i].second<<(i==n-1?"\n":" ");
    }
    return 0;
}