#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <math.h>

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

void settings() {
	#ifndef ONLINE_JUDGE
		freopen("io/input.txt", "r", stdin);
		freopen("io/output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(0);
    cin.tie(0);
}


int main() {
    ll a, b, n;
    cin >> a >> b >> n;

	int digit = -1;
	for (int j = 0; j < 10; j++) {
		if ((a*10+j) % b == 0) {
			digit = j;
			a = (a*10+digit);
			cout << a;
			string s(n-1, '0');
			cout << s << nL;
			break;
		}
	}

	if (digit == -1)
    	cout << -1 << nL;

	return 0;
}