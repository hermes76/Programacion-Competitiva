
#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


string rotationalCipher(string input, int rotationFactor) {
  // Write your code here
  int rotationFactorInteger=rotationFactor%10;
  int rotationFactorAlphabet= rotationFactor%26;
  int res;
  for(int x=0; x<input.length(); x++)
  {
      if(isdigit(input[x]))
      {
          input[x]+=rotationFactorInteger;
          if(input[x]>'9')
            input[x]='0'+(input[x]-'9')-1;
      }else if(islower(input[x])){
          if((int)input[x]+rotationFactorAlphabet>(int)'z')
            input[x]='a'+(((int)input[x]+rotationFactorAlphabet)-'z')-1;
            else
                input[x]+=rotationFactorAlphabet;
      }else if(isupper(input[x]))
      {
            input[x]+=rotationFactorAlphabet;
          if(input[x]>'Z')
            input[x]='A'+(input[x]-'Z')-1;
      }
  }
  return input;

}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(string& expected, string& output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printString(expected);
    cout << " Your output: ";
    printString(output);
    cout << endl;
  }
  test_case_number++;
}

int main() {

  string input_1 = "All-convoYs-9-be:Alert1.";
  int rotationFactor_1 = 4;
  string expected_1 = "Epp-gsrzsCw-3-fi:Epivx5.";
  string output_1 = rotationalCipher(input_1, rotationFactor_1);
  check(expected_1, output_1);

  string input_2 = "abcdZXYzxy-999.@";
  int rotationFactor_2 = 200;
  string expected_2 = "stuvRPQrpq-999.@";
  string output_2 = rotationalCipher(input_2, rotationFactor_2);
  check(expected_2, output_2);

  // Add your own test cases here

}
