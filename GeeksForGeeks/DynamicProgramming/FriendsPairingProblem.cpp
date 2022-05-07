// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  bool contains4(int N)
  {
      string cad= to_string(N);
      for(int x=0; cad[x]; x++)
      if(cad[x]=='4')return true;
      return false;
  }
    int countNumberswith4(int N) {
        // code here
        int times=0;
        for(int x=1 ; x<=N; x++)
            times+=contains4(x);
        return times;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.countNumberswith4(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
