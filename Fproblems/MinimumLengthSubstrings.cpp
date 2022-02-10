
#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


int minLengthSubstring(string s, string t) {
  // Write your code here

  vector<vector<int>> sums (s.length(), vector<int>(26,0));

  sums[0][s[0]-'a']++;
  for(int x=1; s[x]; x++)
  {
   sums[x]= sums[x-1];
    sums[x][s[x]-'a']++;
  }

  int f,e;
  f=0; e=s.length();
  e--;

  vector<int> counting_sort(26,0);

  for(int x=0; t[x]; x++)
    counting_sort[t[x]-'a']++;

 bool band=true;
 while(band)
 {
   for(int x=0; x<26; x++)
     if(counting_sort[x]>sums[e][x])
     {
       band=false;
     }

   if(band)
     e--;
 }
  e++;
  if(e>=s.length())
    return -1;

   bool finish=true;
 while(finish)
 {
   for(int x=0; x<27; x++)
     if(counting_sort[x]>sums[e][x]-sums[f][x])
     {
       finish=false;
     }

   if(finish)
     f++;
 }
  f--;

  return e-f;
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

  string s_1 = "dcbefebce";
  string t_1 = "fd";
  int expected_1 = 5;
  int output_1 = minLengthSubstring(s_1, t_1);
  check(expected_1, output_1);

  string s_2 = "bfbeadbcbcbfeaaeefcddcccbbbfaaafdbebedddf";
  string t_2 = "cbccfafebccdccebdd";
  int expected_2 = -1;
  int output_2 = minLengthSubstring(s_2, t_2);
  check(expected_2, output_2);

  // Add your own test cases here

}
