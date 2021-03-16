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

void eval(bool condition) { cout << (condition ? "yes" : "no") << nL; }
void Eval(bool condition) { cout << (condition ? "Yes" : "No") << nL; }
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

ll arrive(ll a, ll b, ll tm) {
	return a-b+tm;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
    	ll n;
    	cin >> n;
    	vector<pair<ll, ll> > ab;
    	for (ll i = 0; i < n; i++) {
    		ll a, b;
    		cin >> a >> b;
    		ab.pb({a, b});
    	}
    	vector<ll> tm(n);
    	cin >> tm;

    	ll time = arrive(ab[0].first, 0, tm[0]);
    	for (ll i = 0; i < n-1; i++) {
    		ll og = time;
    		while (time < ab[i].second || time-og < (double)(ab[i].second-ab[i].first)/2)
    			time++;
			time+=arrive(ab[i+1].first, ab[i].second, tm[i+1]);
    	}

    	cout << time << nL;
    }

	return 0;
}