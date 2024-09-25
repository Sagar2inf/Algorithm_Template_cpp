// for kth ancestor of node x in any tree

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds; 

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<long long,long long> pll;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second
#define setbits(x) __builtin_popcount(x)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> // for multiset: less_equal
#define all(x, l, r) x.begin() + l, x.begin() + r
#define rall(x, l, r) x.rbegin() + l, x.rbegin() + r 
#define psort(x, n) partial_sort(x.begin(), x.begin() + n, x.end())
#define mxe *max_element
#define mne *min_element

const ll inf = 1e18;
const ll mod0 = 1e9 + 7;
const ll mod1 = 998244353;
const char nl = '\n';

vector<int> vis, dpt;
vector<vector<int>> up;
const int mod = 20;
void dfs(vector<vector<int>> & adj, int s){
    vis[s] = 1;
    for(int u: adj[s]){
        if(!vis[u]){
            vis[u] = 1;
            up[u][0] = s;
            dpt[u] = dpt[s] + 1;
            for(int i = 1; i < mod; i++){
                up[u][i] = up[up[u][i - 1]][i - 1];
            }
            dfs(adj, u);
        }
    }
}


void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for(int i = 2; i <= n; i++){
        cin >> a[i];
        adj[i].pb(a[i]);
        adj[a[i]].pb(i);
    }     
    up.assign(n + 1, vector<int> (mod + 1));
    vis.assign(n + 1, 0);
    dpt.assign(n + 1, 0);
    dfs(adj, 1);
    while(q--){
        int x, k; cin >> x >> k; // Kth ancestor of node x
        if(dpt[x] < k){ // if there is no Kth ancestor return -1
            cout << -1 << nl; continue;
        }
        for(int i = 0; i <= mod; i++){ 
            if(k & (1 << i)){
                x = up[x][i];
            }
        }
        cout << x << nl;
    } 

}


int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

ios::sync_with_stdio(false);
cin.tie(nullptr);

int T = 1; //cin >> T;
for(int testcase = 1; testcase <= T; testcase++){
    solve();
}

return 0;
}
