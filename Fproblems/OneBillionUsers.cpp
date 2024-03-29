
#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;
#define ll long long int
// Add any helper functions you may need here
float powT(float a, ll days)
{
    float res=1;
    for(ll x=0; x<days; x++)
        res*=a;
    return res;
}
bool findB(vector <float> growthRates, int days)
{
     ll goal=1000000000;
     ll sum=0;
     for(int x=0; x<growthRates.size(); x++)
        sum+=powT(growthRates[x],days);
    if(sum<goal)
        return 1;
     return 0;
}
int getBillionUsersDay(vector <float> growthRates) {
  // Write your code here
  int days=78;
  for(int x=50/2; x>0; x/=2)
    while(findB(growthRates,days+x))days+=x;
  return days+1;
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

  vector <float> test_1{1.1, 1.2, 1.3};
  int expected_1 = 79;
  int output_1 = getBillionUsersDay(test_1);
  check(expected_1, output_1);

  vector <float> test_2{1.01, 1.02};
  int expected_2 = 1047;
  int output_2 = getBillionUsersDay(test_2);
  check(expected_2, output_2);

  // Add your own test cases here

}
