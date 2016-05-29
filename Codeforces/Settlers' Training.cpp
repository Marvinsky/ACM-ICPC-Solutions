#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define popb pop_back
#define all(v) v.begin(),v.end()
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 101
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

int n, k, cnt = 0, updates = 0, ans = 0;
vi v(MAX);

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    while (cnt < n) {
        map<int, int> m;
        cnt = updates = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i] == k) cnt++;
            if (!m[v[i]] && v[i] < k) {
                m[v[i]] = 1;
                ++v[i];
                ++updates;
                if (v[i] == k) cnt++;
            }
        }
        if (updates > 0) {
            ++ans;
        }
    }
    cout << ans << "\n";
}