
#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set= tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

vector <int> findMedian(vector <int> arr) {
  // Write your code here
  ordered_set<int> elements;
  vector<int> ans;
  int len=0;
  int middle;
  for(int x=0; x<arr.size(); x++)
  {
   elements.insert(arr[x]);
    len++;
    if(len%2==0)
    {
      int average= ((*elements.find_by_order(len/2)) + (*elements.find_by_order(len/2-1)));
      average/=2;
      ans.push_back(average);
    }else
    {
      ans.push_back(*elements.find_by_order(len/2));
    }
  }

  return ans;
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
  vector <int> arr_1{5, 15, 1, 3};
  vector <int> expected_1{5, 10, 5, 4};
  vector <int> output_1 = findMedian(arr_1);
  check(expected_1, output_1);

  vector <int> arr_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{2, 3, 4, 3, 4, 3};
  vector <int> output_2 = findMedian(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here

}
