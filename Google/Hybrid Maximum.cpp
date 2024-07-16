/*Tejas Sharma*/

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
int dp[1004][1004];
int help(int i,int j,int mx,int mn,vi &a,vi &b){
    int n = a.size(), m = b.size();
    if(i == n and j == m) return 0;
    if(~dp[i][j]) return dp[i][j];
    int ans = -1e9;
    //take element from A
    if(i < n){
        int new_max = max(mx,a[i]);
        int new_min = min(mn,a[i]);
        ans = max(ans, new_max - new_min + help(i + 1,j,new_max,new_min,a,b)); 
    }
    if(j < m){
        int new_max = max(mx,b[j]);
        int new_min = min(mn,b[j]);
        ans = max(ans, new_max - new_min + help(i, j + 1,new_max,new_min,a,b));
    } 
    return dp[i][j] = ans;
}
void solve(){
    memset(dp,-1,sizeof(dp));
    int n;cin >> n;
    vi a(n);
    for(auto &i : a) cin >> i;
    int m;cin >> m;
    vi b(m);
    for(auto &i : b) cin >> i;
    int max_sum = 0, min_sum = 0;
    cout << help(0,0,-1e9,1e9,a,b) << endl;
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