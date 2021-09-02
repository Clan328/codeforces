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

struct pt {
    ll x, y;
};

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

ll orientedArea(pt p1, pt p2, pt p3) {
    return p1.x*p2.y-p2.x*p1.y+p2.x*p3.y-p3.y*p1.x+p1.y*p3.x-p3.x*p2.y;
}

bool cw(pt p1, pt p2, pt p3) {
    return orientedArea(p1, p2, p3) < 0;
}

bool ccw(pt p1, pt p2, pt p3) {
    return orientedArea(p1, p2, p3) > 0;
}

struct line {
    ll a, b, c;
 
    line(pt p1, pt p2) {
        a = p2.y-p1.y;
        b = p1.x-p2.x;
        c = -(a*p1.x+b*p1.y);
    }
};

bool isContained(pt p, pt p1, pt p2) {
    line l(p1, p2);
 
    return l.a*p.x+l.b*p.y+l.c == 0 && (p.x >= min(p1.x, p2.x) && p.x <= max(p1.x, p2.x) && p.y >= min(p1.y, p2.y) && p.y <= max(p1.y, p2.y));
}

int main() {
    int n;
    cin >> n;
    vector<pt> poly;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        poly.pb({x, y});
    }

    int m;
    cin >> m;
    vector<pt> polyB;
    for (int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        poly.pb({x, y});
        polyB.pb({x, y});
    }

    sort(all(poly), cmp);

    vector<pt> upperSet, lowerSet;
    pt a = poly[0], b = poly[poly.size()-1];
    upperSet.pb(a);
    lowerSet.pb(a);
    for (int i = 1; i < poly.size(); i++) {
        if (i == poly.size()-1 || cw(a, poly[i], b)) {
            while (upperSet.size() >= 2 && ccw(upperSet[upperSet.size()-2], upperSet[upperSet.size()-1], poly[i]))
                upperSet.pop_back();
            upperSet.push_back(poly[i]);
        }
        if (i == poly.size()-1 || ccw(a, poly[i], b)) {
            while (lowerSet.size() >= 2 && cw(lowerSet[lowerSet.size()-2], lowerSet[lowerSet.size()-1], poly[i])) {
                lowerSet.pop_back();
            }
            lowerSet.push_back(poly[i]);
        }
    }

    poly.clear();
    for (int i = 0; i < upperSet.size(); i++)
        poly.pb(upperSet[i]);
    for (int i = lowerSet.size()-2; i > 0; i--)
        poly.pb(lowerSet[i]);

    //         for (int i = 0; i < poly.size(); i++) {
    //     cout << poly[i].x << " " << poly[i].y << nL;
    // }

    sort(all(poly), cmp);

    bool ans = true;
    for (int i = 0; i < polyB.size() && ans; i++) {
        int lo = 0, hi = poly.size()-1, mid;
        while (lo <= hi) {
            mid = (lo+hi)/2;
            if (poly[mid].x == polyB[i].x && poly[mid].y == polyB[i].y) {
                ans = false;
                break;
            } else if (cmp(polyB[i], poly[mid]))
                hi = mid -1;
            else
                lo = mid + 1;
        }
    }

    EVAL(ans);

    return 0;
}