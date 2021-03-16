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


int main() {
    int n;
    cin >> n;
    vi a(n);
    cin >> a;

    sort(all(a));

    vi s1;
    vi s2;
    vi s3;

    int n1 = 0, n2 = 0, n3 = 0;
    if (a.back() <= 0) {
		n2 += 2;
		n-=2;
		s2.pb(a[0]);
		a.erase(a.begin());
		s2.pb(a[0]);
		a.erase(a.begin());
    }

    for (int i = 0; i < n; i++) {
    	if (a[i] < 0) {
    		s1.pb(a[i]);
    		n1++;
    	} else if (a[i] > 0) {
    		s2.pb(a[i]);
    		n2++;
    	} else {
    		s3.pb(a[i]);
    		n3++;
    	}
    }

    if (s1.size() % 2 == 0) {
    	s3.pb(s1[0]);
    	s1.erase(s1.begin());
    	n1--;
    	n3++;
    }

    cout << n1;
    for (int i = 0; i < n1; i++) {
    	cout << " " << s1[i];
    }
    cout << nL;

    cout << n2;
    for (int i = 0; i < n2; i++) {
    	cout << " " << s2[i];
    }
    cout << nL;

    cout << n3;
    for (int i = 0; i < n3; i++) {
    	cout << " " << s3[i];
    }
    cout << nL;

	return 0;
}