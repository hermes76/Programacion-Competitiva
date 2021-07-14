#include <bits/stdc++.h>
using namespace std;

#include <algorithm>
int binary(int num, vector<int> &second)
{
   int l=-1;
    int r=second.size();
    int mid;
    while(r>l+1)
    {
        mid=(l+r)/2;
        if(second[mid]>=num)
            r=mid;
        else
            l=mid;
    }
    //cout<<second[r]<<endl;
    if(r>0)
        return min(abs(second[r]-num),abs(second[r-1]-num));
    return abs(second[r]-num);
}
int closestPair(vector<int>& first, vector<int>& second) {
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    int res=1e9;
    for(int x=0; x<first.size(); x++)
    {
        res=min(binary(first[x],second),res);
    }
    return res;
}

int main() {
    int n; cin >> n;
    vector<int> first, second;
    for (int i = 0; i < n; ++i) {
        int val; cin >> val;
        first.push_back(val);
    }
    for (int i = 0; i < n; ++i) {
        int val; cin >> val;
        second.push_back(val);
    }
    cout << closestPair(first, second) << "\n";
    return 0;
}
