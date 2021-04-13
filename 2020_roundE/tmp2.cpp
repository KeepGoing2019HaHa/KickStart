#include "unordered_map"
#include "vector"
#include "iostream"
#include "stdio.h"
#include "string.h"
#include "queue"
#include <utility>
#include "numeric"
using namespace std;
typedef long long ll;

int n;
ll enjoy[100001], remember[100001];

pair<int,int> solve2() {
    vector<int> e(n + 1), r(n + 1);
    priority_queue<pair<int, int>> pq;
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        e[i]=enjoy[i],r[i]=remember[i];
        pq.push({e[i] + r[i], i});
        sum += e[i];
    }
    ll csum = sum;
    while (!pq.empty()) {
        int val = pq.top().first, i = pq.top().second;
        if (val <= csum)
            break;
        else {
            pq.pop();
            csum -= e[i];
        }
    }
    if (!pq.empty()) {
        printf("%d INDEFINITELY\n", n - (int)pq.size());
        return {n - (int)pq.size(), -1};
    }
    ll max_val = csum = sum, min_del = 0, cdel = 0, cval = sum;
    for (int i = 1; i <= n; ++i) {
        if (e[i] + r[i] <= csum) {
            cval += e[i];
            pq.push({e[i] + r[i], i});
            if (cval > max_val) {
                max_val = cval;
                min_del = cdel;
            }
        } else {
            csum -= e[i];
            cval -= e[i];
            cdel++;
            while (!pq.empty() && pq.top().first > csum) {
                int val = pq.top().first, j = pq.top().second;
                pq.pop();
                csum -= e[j];
                cval -= 2 * e[j];
                cdel++;
            }
        }
    }
//    printf("%lld %lld\n", min_del, max_val);
    return {min_del, max_val};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>enjoy[i]>>remember[i];
        priority_queue<pair<ll,ll>> pq;

        ll su=accumulate(enjoy,enjoy+n,ll(0)), res=0;
        ll val=su,max_val=su, max_remove=0;
        for(int i=0;i<n;i++){
            if(su-enjoy[i]>=remember[i]){
                pq.push({remember[i],enjoy[i]});
                val+=enjoy[i];
            } else {
                res++;
                su-=enjoy[i];
                val-=enjoy[i];
                while(!pq.empty() && pq.top().first>su-pq.top().second) {
                    res++;
                    su-=pq.top().second;
                    val-=2*pq.top().second;
                    pq.pop();
                }
            }

            if(val>max_val){
                max_val=val;
                max_remove=res;
            }
        }

        pair<int,int> res2 = solve2();
        if(pq.empty()) {
            if(res2.first!=max_remove||res2.second!=max_val){
                cout<<"sadd";
            }
        } else {
            if(res2.first!=n-pq.size()){
                cout<<"sadd";
            }
        }
//        if(pq.empty()) cout << "Case #" << t << ": " << max_remove << " " << max_val << "\n";
//        else cout << "Case #" << t << ": " << n-pq.size() << " INDEFINITELY" << "\n";
    }
    return 0;
}