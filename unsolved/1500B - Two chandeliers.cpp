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

/*ll gcd(ll a, ll b) {
	if (a == 0)
		return b;
	return gcd(b%a, a);
}

ll lcm(ll a, ll b) {
	return a*b/gcd(a, b);
}*/

int main() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<int> a(n);
    cin >> a;
    vector<int> b(m);
    cin >> b;

    int days = n*m, diff = 0;
    vector<bool> isDiff(days, false);
    for (int i = 1; i <= days; i++) {
    	if ( a[( (i-1) % n)] != b[( (i-1) % m)]) {
    		diff++;
    		isDiff[i-1] = true;
    	}
    }

    ll res = (k/diff)*days;
    if (k % diff == 0) {
    	for (int i = days-1; i >= 0; i--) {
    		if (!isDiff[i])
    			res--;
    		else
    			break;
    	}
    } else {
    	int cnt = 0;
	    int i = 0;
	    while (cnt < k%diff) {
	    	if (isDiff[i])
	    		cnt++;
	    	i++;
	    }
	    res+=i;
    }
    
    cout << res << nL;

	return 0;
}