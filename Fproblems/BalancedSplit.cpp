
#include<bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


bool balancedSplitExists(vector<int>& arr){
  // Write your code here
  sort(arr.rbegin(), arr.rend());
  int sumA,sumB;
  int sum=0;
  sumA=sumB=0;
  for(int x=0; x<arr.size(); x++)
    sum+=arr[x];
    if(sum%2==1)
        return 0;
    sum/=2;
    int x;
    for(x=0; x<arr.size() && sumB<sum; x++)
        sumB+=arr[x];
    if(arr[x]==arr[x-1])
        return 0;
    for(x; x<arr.size(); x++)
        sumA+=arr[x];
    if(sumA==sumB)
        return 1;
    return 0;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(bool expected, bool output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printf("%s", expected ? "true" : "false");
    cout << " Your output: ";
    printf("%s", output ? "true" : "false");
    cout << endl;
  }
  test_case_number++;
}

int main(){
  // Testcase 1
  vector<int> arr_1{2, 1, 2, 5};
  bool expected_1 = true;
  bool output_1 = balancedSplitExists(arr_1);
  check(expected_1, output_1);

  // Testcase 2
  vector<int> arr_2{3, 6, 3, 4, 4};
  bool expected_2 = false;
  bool output_2 = balancedSplitExists(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here

  return 0;
}
