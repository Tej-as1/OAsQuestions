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
int waysToPartition(vector<int>& v, int k = 0) {
    int n = v.size();
    int ans = 0, ct = 0;
    int sum = accumulate(v.begin(), v.end(), 0ll);
    map<int, int> prefMap, suffMap;
    int pref = 0, suff = 0;
    for (int i = 0; i < n - 1; i++) {
        pref += v[i];
        if (sum % 2 == 0 and pref == sum / 2)
            ct++;
    }
    ans = max(ans, ct);
    for (int i = n - 1; i >= 0; i--) {
        suff += v[i];
        suffMap[suff]++;
    }
    pref = 0;
    for (int i = 0; i < n; i++) {
        int req = (sum - v[i] + k);
        suffMap[suff]--;
        suff -= v[i];
        if(req % 2 == 0)
            ans = max(ans, prefMap[req / 2] + suffMap[req / 2]);
        pref += v[i];
        prefMap[pref]++;
    }
    return ans;
}
void solve(){
    int n;cin >> n;
    vi v(n);
    for(auto &i : v) cin >> i;
    cout << waysToPartition(v) << endl;
    
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