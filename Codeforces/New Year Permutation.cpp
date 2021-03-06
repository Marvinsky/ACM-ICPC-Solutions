#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define pill pair<int, long long>
#define mii map<int, int>
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define popb pop_back
#define all(v) v.begin(),v.end()
#define mod(x, m) ((x % m) + m) % m
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cerr<<#x<<" : "<<x<<endl
#define debug2(x,y) cerr<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cerr<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const int MAX = 300;

int n;
string s;
vi g(MAX + 5);
vi p(MAX + 5);
map<int, vi> m;

int find(int u) {
    return g[u] == u ? u : g[u] = find(g[u]);
}

void join(int u, int v) {
    g[find(u)] = find(v);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        g[i] = i;
        cin >> p[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '1') {
                join(i, j + 1);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        m[find(i)].pb(p[i]);
    }
    map<int, vi>::iterator it = m.begin();
    while (it != m.end()) {
        sort(all(it->se));
        ++it;
    }
    for (int i = 1; i <= n; ++i) {
        cout << m[find(i)][0];
        m[find(i)].erase(m[find(i)].begin(), m[find(i)].begin() + 1);
        if (i < n) cout << " ";
    }
    cout <<"\n";
}