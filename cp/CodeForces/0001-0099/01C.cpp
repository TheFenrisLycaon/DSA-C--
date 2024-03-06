#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <map>
#include <set>
#include <fstream>
#include <bitset>
#include <ctype.h>
#include <string.h>
#include <string>
#include <assert.h>
#include <typeinfo>
#include <sstream>
#include <time.h>
#include <numeric>
#include <limits.h>
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long LL;
#define sz(a) int((a).size())
#define pb push_back
#define tr(c, it) \
    for (typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define REP(i, n) \
    for (int i = 0; i < n; i++)
#define FOR(i, a, b) \
    for (int i = a; i <= b; i++)
#define sz(data) sizeof(data) / sizeof(data[0])
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define mk(i, j) make_pair(i, j)
#define pb(c, it) c.push_back(it)
#define INF 10000000
#define PI 3.141592
#define epsilon 1.0e-4
double angle(double x1, double y1, double x2, double y2)
{
    double m1 = sqrt(x1 * x1 + y1 * y1);
    double m2 = sqrt(x2 * x2 + y2 * y2);
    double dot = x1 * x2 + y1 * y2;
    if (dot < 0)
        dot *= -1;
    double arg = dot / (m1 * m2);
    return acos(arg);
}
int check(double ang, int n)
{
    double theta = 2 * PI / n;
    double nsides = ang / theta;
    double f = nsides - epsilon;
    if (f < (int)nsides)
        return 1;
    return 0;
}
double area(int n, double ang, double side)
{
    double r = sqrt(side * side / (2 * (1 - cos(ang))));
    double A = 0.5 * r * r * sin(2 * PI / n);
    return n * A;
}
vector<double> x;
vector<double> y;
int main()
{
    REP(i, 3)
    {
        double r, c;
        cin >> r >> c;
        pb(x, r);
        pb(y, c);
    }
    double res = INF;
    FOR(n, 3, 100)
    {
        double ang1 = angle(x[1] - x[0], y[1] - y[0], x[2] - x[0], y[2] - y[0]);
        double ang2 = angle(x[0] - x[1], y[0] - y[1], x[2] - x[1], y[2] - y[1]);
        if (check(2 * ang1, n) && check(2 * ang2, n))
        {
            double side = sqrt((x[2] - x[1]) * (x[2] - x[1]) + (y[2] - y[1]) * (y[2] - y[1]));
            res = min(res, area(n, 2 * ang1, side));
        }
    }
    printf("%.6f", res);
    return 0;
}