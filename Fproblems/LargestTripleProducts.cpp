
#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


vector <int> findMaxProduct(vector <int> arr) {
  // Write your code here
  vector<int> output;
  multiset<int> sliding_window;
  int res;
  if(arr.size()>=1)
  {
    output.push_back(-1);
  }
  if(arr.size()>=2)
  {
    output.push_back(-1);
  }
  if(arr.size()>2)
  {
    for(int x=0; x<3; x++)
      sliding_window.insert(arr[x]);
          res=1;
      for(auto element: sliding_window)
      {
        res*=element;
      }
          output.push_back(res);
    for(int x=3; x<arr.size(); x++)
    {
      if(*sliding_window.begin()<arr[x])
      {
        sliding_window.erase(sliding_window.begin());
        sliding_window.insert(arr[x]);
      }
      res=1;
      for(auto element: sliding_window)
      {
        res*=element;
      }
      output.push_back(res);
    }
  }
  return output;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printIntegerVector(vector <int> array) {
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      cout << ", ";
    }
   cout << array[i];
  }
  cout << "]";
}

int test_case_number = 1;

void check(vector <int>& expected, vector <int>& output) {
  int expected_size = expected.size();
  int output_size = output.size();
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected);
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl;
  }
  test_case_number++;
}

int main() {
  vector <int> arr_1{1, 2, 3, 4, 5};
  vector <int> expected_1{-1, -1, 6, 24, 60};
  vector <int> output_1 = findMaxProduct(arr_1);
  check(expected_1, output_1);

  vector <int> arr_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{-1, -1, 56, 56, 140, 140};
  vector <int> output_2 = findMaxProduct(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here

}
