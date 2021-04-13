#include "unordered_map"
#include "vector"
#include "iostream"
#include "stdio.h"
#include "string.h"
using namespace std;
typedef long long ll;

struct Node{int l,r,val;};
int a[100005];
Node segtree[400020];
int N,Q;

void build(int cur, int l, int r) {
    segtree[cur].l = l;
    segtree[cur].r = r;
    if(l==r) {segtree[cur].val=a[l];return;}
    int m = (l+r)/2;
    build(cur<<1, l, m);
    build(cur<<1|1, m+1, r);
    segtree[cur].val = max(segtree[cur<<1].val, segtree[cur<<1|1].val);
}

int query(int cur, int l, int r) {
    if(segtree[cur].l==l && segtree[cur].r==r) return segtree[cur].val;
    if(segtree[cur<<1].r>=r) return query(cur<<1,l,r);
    else if(segtree[cur<<1|1].l<=l) return query(cur<<1|1,l,r);
    else return max(query(cur<<1,l,segtree[cur<<1].r), query(cur<<1|1,segtree[cur<<1|1].l, r));
}

bool ok(int s, int k, int left) {
    int L=s-left, R=s+(k-left);
//    if(L<0||R>N) return false;
    int maxL = query(1, L, s-1);
    int maxR = query(1, s, R);
    return maxL < maxR;
}

int binary_search(int s, int k) {
    if(k<0) return s;
//    int lo=1,hi=k,left=0;
    int lo=max(1,k-(N-s)),hi=min(s-1,k),left=0;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(ok(s,k,mid)){
            left = mid;
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    int left_idx=s-left-1, right_idx=s+(k-left)+1;
    return a[left_idx]<a[right_idx-1]?left_idx:right_idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int case_ = 1;  case_<= T; case_ += 1) {
        int s,k;
        cin>>N>>Q;
        for(int i=1;i<N;i++)cin>>a[i];
        a[0] = a[N] = 0x3f3f3f3f;

        build(1, 0, N);
        cout << "Case #" << case_ << ": ";
        for(int i=1;i<=Q;i++) {
            cin>>s>>k;
            cout << binary_search(s, k-2);
            if(i!=Q) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}