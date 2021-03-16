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

int main() {
    ll n;
    cin >> n;
    vi a(n);
    cin >> a;

    ll startIdx = 0, repeatCnt = 0;
    for (ll i = 0; i < n-1; i++) {
    	if (a[i] > a[i+1]) {
    		startIdx = i;
    		break;
    	}
    	if (a[i] == a[i+1]) repeatCnt++;
    	else repeatCnt = 0;
    }
    startIdx-=repeatCnt;
    
    ll endIdx = startIdx;
    ll i = startIdx;
    while (startIdx != -1 && i < n-1 && a[i] >= a[i+1]) {
    	endIdx++;
    	i++;
    }

    bool res = true;
    for (ll i = endIdx; i > startIdx; i--) {
    	if (a[i] > a[i-1]) {
    		res = false;
    		break;
    	}
    }
    if (res && endIdx < n-1) {
	    if (a[startIdx] > a[endIdx+1]) res = false;
    }
    if (res && startIdx > 0) {
    	if (a[endIdx] < a[startIdx-1]) res = false;
    }

    if (res) {
    	for (ll i = endIdx+1; i < n-1; i++) {
	    	if (a[i] > a[i+1]) {
	    		res = false;
	    		break;
	    	}
	    }
    }

    eval(res);
    if (res)
   		cout << startIdx+1 << " " << endIdx+1 << nL;

	return 0;
}