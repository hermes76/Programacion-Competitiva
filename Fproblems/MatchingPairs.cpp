#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


int matchingPairs(string s, string t) {
  // Write your code here

  int res=0;
  set<pair<char,char>> set_s;
  vector<int> count(27,0);
  for(int x=0; s[x]; x++)
  {
   if(s[x]==t[x])res++;
    else{
      set_s.insert({s[x],t[x]});
      count[t[x]-'a']++;
    }
  }

  if(res==s.length())
    return res-2;

  for(int x=0; s[x]; x++)
    if(s[x]!=t[x])
    if(set_s.find({t[x],s[x]})!= set_s.end())
      return res+=2;

  for(int x=0; s[x]; x++)
  {
    if(s[x]!=t[x])
      if(count[s[x]]>0)
        return res+=1;
  }
  return res;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printInteger(int n) {
  cout << "[" << n << "]";
}

int test_case_number = 1;

void check(int expected, int output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printInteger(expected);
    cout << " Your output: ";
    printInteger(output);
    cout << endl;
  }
  test_case_number++;
}

int main() {
  string s_1 = "abcde";
  string t_1 = "adcbe";
  int expected_1 = 5;
  int output_1 = matchingPairs(s_1, t_1);
  check(expected_1, output_1);

  string s_2 = "abcd";
  string t_2 = "abcd";
  int expected_2 = 2;
  int output_2 = matchingPairs(s_2, t_2);
  check(expected_2, output_2);

  // Add your own test cases here

}
