#include <bits/stdc++.h>

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
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const ll MOD = 1e9 + 7;

void settings()__attribute__((constructor));

void eval(bool condition) { cout << (condition ? "yes" : "no") << nL; }
void Eval(bool condition) { cout << (condition ? "Yes" : "No") << nL; }
void EVAL(bool condition) { cout << (condition ? "YES" : "NO") << nL; }

int ipow(int a, int n) {
    if (n == 0) return 1;
    int x = ipow(a, n/2);
    if (n % 2 == 0) return x*x;
    return x*x*a;
}

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
	#ifdef LOCAL
		freopen("io/input.txt", "r", stdin);
		freopen("io/output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(0);
    cin.tie(0);
}


double res = 0;

double solve(double c, double m, double p, double v, 
	double f, double s, double t, int cnt) {
	cnt++;

	double _c = c, _m = m, _p = p;
	double _f = f, _s = s, _t = t;
	double r1 = 0, r2 = 0, r3 = 0;

	// C
	if (_c > 0) {
		if (_f <= 0) _f = 1;
		_f *= _c;
		if (_c <= v) {
			int valid = (_m > 0) + (_p > 0);
			if (_m > 0)
				_m += _c/valid;
			if (_p > 0)
				_p += _c/valid;
			_c = 0;
		} else {
			int valid = (_m > 0) + (_p > 0);
			if (_m > 0)
				_m += (v)/valid;
			if (_p > 0)
				_p += (v)/valid;
			_c -= v;
		}
		_f *= solve(_c, _m, _p, v, _f, _s, _t, cnt);
		r1 = _f;
	}

	// M
	_c = c, _m = m, _p = p;
	_f = f, _s = s, _t = t;

	if (_m > 0) {
	 if (_s <= 0) _s = 1;
		_s *= _m;
		if (_m <= v) {
			int valid = (_c > 0) + (_p > 0);
			if (_c > 0)
				_c += _m/valid;
			if (_p > 0)
				_p += _m/valid;
			_m = 0;
		} else {
			int valid = (_c > 0) + (_p > 0);
			if (_c > 0)
				_c += (v)/valid;
			if (_p > 0)
				_p += (v)/valid;
			_m -= v;
		}
		_s *= solve(_c, _m, _p, v, _f, _s, _t, cnt);
		r2 = _s;
	}

	// P
	_c = c, _m = m, _p = p;
	_f = f, _s = s, _t = t;
	_t *= _p;
	if (_p <= v) {
		int valid = (_c > 0) + (_m > 0);
		if (_c > 0)
			_c += _p/valid;
		if (_m > 0)
			_m += _p/valid;
		_p = 0;
	} else {
		int valid = (_c > 0) + (_m > 0);
		if (_c > 0)
			_c += (v)/valid;
		if (_m > 0)
			_m += (v)/valid;
		_p -= v;
	}
	r3 = _t*cnt;
	cout << "c: "<<cnt << nL;
	cout << r3 << nL;

	//cout << r1 << " " << r2 << " " << r3 << nL;

	return r1 + r2 + r3;
}

double solve(double c, double m, double p, double v, double addedP, int cnt) {
	cnt++;

	double _c = c, _m = m, _p = p;
	double r1 = 0, r2 = 0;

	// C
	if (_c > 1e-6) {
		if (_c <= v) {
			int valid = (_m > 1e-6) + (_p > 1e-6);
			if (_m > 1e-6)
				_m += _c/valid;
			if (_p > 1e-6)
				_p += _c/valid;
			_c = 0;
		} else {
			int valid = (_m > 1e-6) + (_p > 1e-6);
			if (_m > 1e-6)
				_m += (v)/valid;
			if (_p > 1e-6)
				_p += (v)/valid;
			_c -= v;
		}
		r1 = solve(_c, _m, _p, v, c*addedP, cnt);
	}

	// M
	_c = c, _m = m, _p = p;

	if (_m > 1e-6) {
		if (_m <= v) {
			int valid = (_c > 1e-6) + (_p > 1e-6);
			if (_c > 1e-6)
				_c += _m/valid;
			if (_p > 1e-6)
				_p += _m/valid;
			_m = 0;
		} else {
			int valid = (_c > 1e-6) + (_p > 1e-6);
			if (_c > 1e-6)
				_c += (v)/valid;
			if (_p > 1e-6)
				_p += (v)/valid;
			_m -= v;
		}
		r2 = solve(_c, _m, _p, v, m*addedP, cnt);
	}

	return r1+r2+addedP*p*cnt;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
    	double c, m, p, v;
    	cin >> c >> m >> p >> v;

    	//cout << fixed << setprecision(15) << solve(c, m, p, v, 0, 0, 1, 0) << nL;
    	cout << fixed << setprecision(15) << solve(c, m, p, v, 1, 0) << nL;
    }

	return 0;
}