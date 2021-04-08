#include "unordered_map"
#include "vector"
#include "iostream"
#include "stdio.h"
#include "string.h"
#include "math.h"
using namespace std;
typedef long long ll;

int a[10001];

// the rule of update budget will be complex!
int helper1(int n) {
    int res=0;
    int budget=3,cur=1;
    for(int i=1;i<n;i++){
        if(a[i]>a[i-1]){
            if(cur==4) res++,cur=1,budget=3;
            else cur++;
            if(cur==4) budget=0;
        } else if(a[i]<a[i-1]) {
            if(cur==1){
                if(budget>0) budget--;
                else res++,cur=1,budget=3;
            } else {
                budget=max(budget,cur-1-1);
                cur=1;
            }
        }
    }
    return res;
}

int helper2(int n) {
    int res=0,inr=1,dec=1;
    for(int i=1;i<n;i++){
        if(a[i]>a[i-1]){
            inr++;
            dec=1;
        }else if(a[i]<a[i-1]){
            inr=1;
            dec++;
        }
        if(inr==5) res++,inr=1;
        if(dec==5) res++,dec=1;
    }

    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
//    cin >> T;
//    for (int t = 1; t <= T; t += 1) {
//        int n,res;
//        cin>>n;
//        for(int i=0;i<n;i++)cin>>a[i];
//        int res1=helper1(n);
//        int res2=helper2(n);
////        cout<<res1<<" "<<res2<<endl;
//        cout << "Case #" << t << ": " << res1 << "\n";
////        cout << "Case #" << t << ": " << res2 << "\n";
//    }

    int count = 0;
    int n=10;
    while(true) {
        for(int i=0;i<n;i++)a[i]=rand()%100;
        int res1=helper1(n);
        int res2=helper2(n);
        count++;
        cout<<count<<" "<<res1<<" "<<res2<<endl;
        if(res1!=res2) break;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    int res1=helper1(n);
    int res2=helper2(n);
    return 0;
}