
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>


#define forr(n,m,p) for(int x=n; x<m; x+=p)
#define ll long long int
#define dll double
#define all(x) x.begin(),x.end()
#define INF 1e9
#define MOD 10000009
using namespace std;
vector <ll> vll;
int main()
{
    ll t;
    for t in range(int(input())):
	a, b, c = map(int, input().split())
	print("1" + "0" * (a - 1), "1" * (b - c + 1) + "0" * (c - 1))
}
