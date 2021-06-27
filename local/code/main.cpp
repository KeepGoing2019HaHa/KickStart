#include "unordered_map"
#include "vector"
#include "iostream"
#include "stdio.h"
#include "string.h"
#include "map"
typedef long long ll;
using namespace std;

int main() {
//    std::cout << (ll(1)<<33) << std::endl;
//    double ans = 0.00000001;
//    cout << "Case #" << ans << "\n";
//    printf("Case #%lf\n", ans);

//    map<vector<int>,double>memo;
//    vector<int>target(6, 0);
//    target[4]=1,target[5]=2;
//    memo[target]=1.0;
//    cout << memo[target] << endl;
//    cout << memo.count(target) << endl;
    string s = "1";
    cout<< typeid(s.length()).name()<<endl;
    cout<<(s.length()-3)<<" "<<(0<(s.length()-3))<<endl;
    cout<<(int(s.size())-3)<<" "<<(0<(s.size()-3))<<endl;
    return 0;
}
