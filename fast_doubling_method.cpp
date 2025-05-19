#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
#define int long long
#define pb push_back 
#define eb pop_back
#define pll pair<int,int>
#define vi vector<int>
#define mp_ make_pair 
#define all(v) v.begin(),v.end()
#define f(i,start,end) for(int i=start;i<end;i++)  
#define vii vector<vector<int>>
#define vip vector<pair<int,int>>
#define mp unordered_map<int,int>


pair<int,int> fibonacci(int n){
    if(n==0){
        return {0,1};
    }
    auto p = fibonacci(n>>1);
    int a = p.first*p.first+p.second*p.second;
    int b = p.first*(2*p.second-p.first);
    if(n%2==1){
        return {a,a+b};
    }
    return {b,a};
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef file_io
            freopen("input.txt", "r", stdin);
            freopen("output1.txt", "w", stdout);
    #endif
    int t = 1;
    auto p = fibonacci(4);
    cout<<p.first<<endl;
    while(t--){

        
    }

}
