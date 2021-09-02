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
	#ifndef ONLINE_JUDGE
		freopen("io/input.txt", "r", stdin);
		freopen("io/output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
    	int a, b;
    	cin >> a >> b;
    	string s;
    	cin >> s;

    	int n = a+b;
    	//int cntA = 0, cntB = 0;
    	bool res = true;
    	for (int i = 0; i < n/2; i++) {
    		if (s[i] == '0') {
    			a--;
    			if (s[n-i-1] == '0')
    				a--;
    			else if (s[n-i-1] == '?') {
    				a--;
    				s[n-i-1] = '0';
    			} else {
    				res = false;
    				break;
    			}
    		}
    		else if (s[i] == '1') {
    			b--;
    			if (s[n-i-1] == '1')
    				b--;
    			else if (s[n-i-1] == '?') {
    				b--;
    				s[n-i-1] = '1';
    			} else {
    				res = false;
    				break;
    			}
    		} else {
    			if (s[n-i-1] == '1') {
    				b-=2;
    				s[i] = '1';
    			}
    			else if (s[n-i-1] == '0') {
    				a-=2;
    				s[i] = '0';
    			}
    		}
    	}

        for (int i = 0; i < n/2; i++) {
            if (s[i] == '?') {
                if (a > 1) {
                    s[i] = '0';
                    s[n-i-1] = '0';
                    a -= 2;
                } else if (b > 1) {
                    s[i] = '1';
                    s[n-i-1] = '1';
                    b -= 2;
                } else {
                    res = false;
                    break;
                }
            }
        }

        if (n % 2 == 1 && s[n/2] == '?') {
            if (a == 1) {
                s[n/2] = '0';
                a--;
            }
            else {
                s[n/2] = '1';
                b--;
            }
        } else if (n % 2 == 1 && s[n/2] == '0')
            a--;
        else if (n % 2 == 1 && s[n/2] == '1')
            b--;

    	if (!res || b > 0 || a > 0)
    		cout << -1 << nL;
    	else
    		cout << s << nL;
    }

	return 0;
}