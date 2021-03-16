#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <cmath>
#include <iomanip>
#include <set>
#include <numeric>

using namespace std;

#define pb push_back
#define mp make_pair
#define nL '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const ll MOD = 10e9 + 7;

void settings()__attribute__((constructor));

void eval(bool condition) { cout << (condition ? "Yes" : "No") << nL; }
void EVAL(bool condition) { cout << (condition ? "YES" : "NO") << nL; }

template <typename T>
ostream& operator<<(ostream& stream, const vector<T>& v) {
	for (auto elem : v) 
		stream << elem << " ";
	return stream;
}

template <typename T>
istream& operator>>(istream& stream, vector<T>& v){
    for(auto &elem : v)
    	stream >> elem;
    return stream;
}

void settings() {
	#ifndef ONLINE_JUDGE
		freopen("io/input.txt", "r", stdin);
		freopen("io/output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(0);
    cin.tie(0);
}

ll gcd(ll a, ll b) {
	if (a == 0)
		return b;
	return gcd(b%a, a) % MOD;
}

bool div(vector<ll> a, ll n, ll d) {
	for (int i = 0; i < n; i++) {
		if (a[i] % d != 0)
			return false;
	}
	return true;
}

ll nextDiv(ll n, ll res) {
	for (int i = res; i < n; i++) {
		if (n % i == 0)
			return n/i;
	}
	return 1;
}

int main() {
    ll n, q;
    cin >> n >> q;

    vector<ll> a(n);
    cin >> a;
    while (q--) {
    	ll i, x;
    	cin >> i >> x;
    	a[i-1]*=x;

    	vector<ll> temp = a;
    	sort(all(temp));

	    ll res = temp[0];
	    ll og = res;
	    while (!div(temp, n, res) && res > 0) {
	    	res++;
	    	res = nextDiv(og, res);
	    	cout << res << nL;
	    }
	    cout << nL;
        cout << res << nL;
    }

	return 0;
}