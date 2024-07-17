/*Tejas Sharma*/
// Reference taken from a leetcode discuss solution
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Y { cout << "YES" << endl;}
#define N { cout << "NO" << endl;}
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vi>
#define mi map<int,int>
#define si set<int>
#define sc set<char>
#define maxheap1 priority_queue<int>
#define minheap1 priority_queue<int,vector<int>,greater<int>>
#define maxheap priority_queue<pair<int,int>>
#define minheap priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define bend(x) x.begin(),x.end()
#define rbend(x) x.rbegin(), x.rend()
const int M = 1e9+7;
const int MAX_N = 200000;
const int LOG = 20;
vector<int> adj[MAX_N];
int up[MAX_N][LOG]; // up[v][j] is 2^j-th ancestor of v
int depth[MAX_N];
map<pair<int,int>,int>weights;
vvi freq(MAX_N,vi(30,0));
void dfs(int a,int par = -1){
    for(auto &b : adj[a]){
        if(b == par) continue;
        up[b][0] = a;                // a is 2^0th parent of b
        depth[b] = depth[a] + 1;
        for(int j = 1;j < LOG;j++){
            up[b][j] = up[ up[b][j - 1] ][j - 1];
        }
        int w = weights[{b,a}];
        freq[b] = freq[a];
        freq[b][w]++;
        dfs(b,a);
    }
}
int get_lca(int a,int b){
    if(depth[a] < depth[b]) swap(a,b); //considering a is deeper than b
    int k = depth[a] - depth[b];        // we have to first bring a to the same level as b
    for(int j = LOG - 1;j >= 0;j--){    // uplifting a in powers of 2
        if(k >= (1 << j)){
            a = up[a][j];
            k -= (1 << j);
        }
    }
    if(a == b) return a;                // If both become same (i.e b was the lca) then return
    for(int j = LOG - 1;j >= 0;j--){    // Reaches till the next child of the ancestor
        if(up[a][j] != up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];                // since the node is just one level below the lca, return the 
                                    // next parent of node
}
void solve(){
    int n,q;cin >> n >> q;
    for(int i = 0;i < n - 1;i++){
        int a,b,c;cin >> a >> b >> c;
        --a;--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        weights[{a,b}] = c;
        weights[{b,a}] = c;
    }
    dfs(0,-1);
    while(q--){
        int ans = 0;
        int a,b;cin >> a >> b;
        --a;--b;
        int lca = get_lca(a,b);
        vector<int>weightCount(30,0);
        int totalEdges = 0;
        for(int i = 1;i < 30;i++){
          int weightFreq = freq[a][i] + freq[b][i] - 2 * freq[lca][i];
          weightCount[i] = weightFreq;
          totalEdges += weightFreq;
        }
        int mid = (totalEdges + 1) >> 1;
        int median = -1;
        for(int i = 1;i< 30;i++){
          if(weightCount[i] < mid) mid -= weightCount[i];
          else{
            median = i;
            break;
          }
        }
        for(int i = 1;i < 30;i++){
          if(weightCount[i] <= 0) continue;
          while(weightCount[i]--) ans += abs(median - i);
        }
        cout << ans << endl;
    }

    
}
int32_t main(){
  #ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cerr.tie(NULL);
  auto clk = clock();
  int t = 1;
  cin>>t;
  while(t--) solve();
  clk = clock() - clk;
  cerr << fixed << setprecision(6) << "\nTime: " << ((float)clk) / CLOCKS_PER_SEC << "\n";
  return 0; 
}
