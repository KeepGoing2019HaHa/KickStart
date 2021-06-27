#include "unordered_map"
#include "vector"
#include "iostream"
#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "math.h"
#include "queue"
using namespace std;
typedef long long ll;

//pair<int,int> a[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int t_ = 1; t_ <= T; t_ += 1) {
        int n,k,tmp1,tmp2;
        cin>>n>>k;
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;
        for(int i=0;i<n;i++){cin>>tmp1>>tmp2,pq.push({tmp1,tmp2});}
        int res=0;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int cover=ceil((top.second-top.first+0.0)/k);
            res+=cover;
            int s=top.first,t=top.first+cover*k;
            while(!pq.empty() && t>=pq.top().first){
                top=pq.top();
                pq.pop();
                if(t<top.second){
                    pq.push({t+1,top.second});
                }
            }
        }

        cout << "Case #" << t_ << ": " << res << endl;
    }
    return 0;
}