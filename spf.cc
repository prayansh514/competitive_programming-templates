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



int MAXN = 100100;
int spf[100100];

void spf_calculate(){
    spf[0] = spf[1] = 1;
    for(int i = 0;i<=MAXN;i++){
        spf[i] = i;
    }
    for(int i = 2;i<=MAXN;i++){
        if(spf[i]==i){
            //it is a prime factor
            for(int j = 2*i;j<=MAXN;j+=i){
                if(spf[j]==j){
                    //it hasnt been scouted by any smaller prime factor
                    spf[j] = i;
                }
            }
        }
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef file_io
            freopen("input.txt", "r", stdin);
            freopen("output1.txt", "w", stdout);
    #endif
    int t = 1;
    spf_calculate();
    while(t--){

        // solve();
    }

}
