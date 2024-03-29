#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

struct sides{
  long long a;
  long long b;
  long long c;
};

// Add any helper functions you may need here

sides sortSides(sides triangle)
{
    long long arr[3];
    arr[0]=triangle.a;
    arr[1]=triangle.b;
    arr[2]=triangle.c;
    sort(arr,arr+3);
    triangle.a=arr[0];
    triangle.b=arr[1];
    triangle.c=arr[2];
    return triangle;
}
int countDistinctTriangles(vector <sides> arr) {
  // Write your code here
  int counting=1;
  for(int x=0; x<arr.size(); x++)
  {
      arr[x]=sortSides(arr[x]);
  }
  sides aux;
    if(arr.size()>0)
        aux=arr[0];
    for(int x=1; x<arr.size();)
    {
        while(aux.a==arr[x].a &&aux.b==arr[x].b && aux.c==arr[x].c && x<arr.size())
        {
            x++;
        }
        aux=arr[x];
        if(x<arr.size())
            counting++;

    }
    return counting;
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

  vector<sides> arr_1 = {{7, 6, 5}, {5, 7, 6}, {8, 2, 9}, {2, 3, 4}, {2, 4, 3}};
  int expected_1 = 3;
  int output_1 = countDistinctTriangles(arr_1);
  check(expected_1, output_1);

  vector<sides> arr_2 = {{3, 4, 5}, {8, 8, 9}, {7, 7, 7}};
  int expected_2 = 3;
  int output_2 = countDistinctTriangles(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here

}
