#include "unordered_map"
#include "vector"
#include "iostream"
#include "stdio.h"
#include "string.h"
using namespace std;
typedef long long ll;

class SegTree {
public:
    ll *A;
    int n;
    SegTree(ll *A_inp, const int n_inp){
        this->A = A_inp;
        this->n = n_inp;
    }
    void add(int i,ll val){
        while(i<=n){
            A[i]+=val;
            i+=i&-i;
        }
    }
    ll sum(int i) {
        ll sum=0;
        while(i>0){
            sum+=A[i];
            i-=i&-i;
        }
        return sum;
    }
};

int a[200002];
ll t1[200002],t2[200002],t3[200002],t4[200002];
char q;
int q1,q2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1) {
        int N,Q;
        cin>>N>>Q;
        for(int i=1;i<=N;i++)cin>>a[i];
        ll ans=0;

        memset(t1,0,(N+1)*sizeof(t1[0]));
        memset(t2,0,(N+1)*sizeof(t2[0]));
        memset(t3,0,(N+1)*sizeof(t3[0]));
        memset(t4,0,(N+1)*sizeof(t4[0]));
        SegTree st1(t1,N),st2(t2,N),st3(t3,N),st4(t4,N);
        for(int i=1;i<=N;i++){
            if(i%2==1) st1.add(i,a[i]*i),st2.add(i,-a[i]*i),st3.add(i,a[i]),st4.add(i,-a[i]);
            else st1.add(i,-a[i]*i),st2.add(i,a[i]*i),st3.add(i,-a[i]),st4.add(i,a[i]);
        }

        for(int i=0;i<Q;i++){
            cin>>q>>q1>>q2;
            if(q=='U'){
                if(q1%2==1) st1.add(q1,q1*q2-q1*a[q1]),st2.add(q1,-q1*q2+q1*a[q1]),st3.add(q1,q2-a[q1]),st4.add(q1,-q2-a[q1]);
                else st1.add(q1,-q1*q2+q1*a[q1]),st2.add(q1,q1*q2-q1*a[q1]),st3.add(q1,-q2-a[q1]),st4.add(q1,q2-a[q1]);
                a[q1]=q2;
            } else {
                if(q1%2==1) ans+=st1.sum(q2)-st1.sum(q1-1)-(q1-1)*(st3.sum(q2)-st3.sum(q1-1));
                else ans+=st2.sum(q2)-st2.sum(q1-1)-(q1-1)*(st4.sum(q2)-st4.sum(q1-1));
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}