template<class T>
using ordered_set = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
#define pb push_back 
#define eb pop_back
#define pll pair<ll,ll>
#define vi vector<ll>
#define mp_ make_pair 
#define all(v) v.begin(),v.end()
#define f(i,start,end) for(ll i=start;i<end;i++)  
#define vii vector<vector<ll>>
#define vip vector<pair<ll,ll>>
#define mp unordered_map<ll,ll>

class SEGtree{
    vi seg;
public:
    SEGtree(ll n){
        seg.resize(4*n+1);
    }   
    void build(ll index,ll low,ll high,vi& arr){
    if(low==high){
        seg[index] = arr[low];
        return;
    }

    ll mid = (high+low)/2;
    build(2*index+1,low,mid,arr);
    build(2*index+2,mid+1,high,arr);
    seg[index] = min(seg[2*index+1],seg[2*index+2]);
   }

    int query(ll index,ll low,ll high,ll l,ll r,vi& arr){
    //no overlap
    if(low>r || high<l){
        return INT_MAX;
    }

    //complete overlap
    if(low>l && high<r){
        return seg[index];
    }

    //partial overlap
    ll mid = (high+low)/2;
    ll left = query(2*index+1,low,mid,l,r,arr);
    ll right = query(2*index+2,mid+1,high,l,r,arr);
        return seg[index] = min(left,right);
    }
    
    void update(ll index,ll low,ll high,ll ind,ll value,vi& arr){
        if(low==high){
            seg[index] = value;
            return;
        }
    
        ll mid = (high+low)/2;
        if(mid>=ind){
            update(2*index+1,low,mid,ind,value,arr);
        }
        else{
            update(2*index+2,mid+1,high,ind,value,arr);
        }
        seg[index] = min(seg[2*index+1],seg[2*index+2]);
    
    }


};
