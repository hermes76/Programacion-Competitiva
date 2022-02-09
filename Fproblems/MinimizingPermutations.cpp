#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


int minOperations(vector <int> arr) {
  // Write your code here
  int n = arr.size();
 int aux=0;
  for(int x=0; x<n; x++)
  {
      if(arr[x] != x+1)
      {
          aux++;
        int y= x+1;
        for(; y<n; y++)
          if(arr[y]== x+1)
            break;
        reverse(arr.begin()+x, arr.begin()+y+1);
      }
  }
  return aux;
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

  int n_1 = 5;
  vector <int> arr_1{1, 4, 5 , 2 , 3};
  int expected_1 = 1;
  int output_1 = minOperations(arr_1);
  check(expected_1, output_1);

  int n_2 = 3;
  vector <int> arr_2{3, 1, 2};
  int expected_2 = 2;
  int output_2 = minOperations(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here

}
