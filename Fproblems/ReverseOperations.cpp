
#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int x) : data(x), next(NULL) {}
};

// Add any helper functions you may need here


Node* reverse(Node *head) {
  // Write your code here
  vector<vector<int>>nums;
  vector<int>aux;
  Node* headFill=head;
  Node*original =head;
  int index=0;
  while(head)
  {
      if(head->data%2==0)
        aux.push_back(head->data);
      else if(!aux.empty()){
        nums.push_back(aux);
        aux.clear();
      }
      head=head->next;
  }
  if(!aux.empty())
    nums.push_back(aux);
  while(headFill)
  {
      if(headFill->data%2==0)
      {
            reverse(nums[index].begin(), nums[index].end());
            for(int x=0; x<nums[index].size(); x++)
            {
                headFill->data=nums[index][x];
                headFill=headFill->next;
            }
            index++;
      }else{
          headFill=headFill->next;
      }
  }
  return original;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printLinkedList(Node *head) {
  cout << "[";
  while (head != NULL) {
    cout << head -> data;
    head = head -> next;
    if (head != NULL)
      cout << " ";
  }
  cout << "]";
}

int test_case_number = 1;

void check(Node *expectedHead, Node *outputHead) {
  bool result = true;
  Node *tempExpectedHead = expectedHead;
  Node *tempOutputHead = outputHead;
  while (expectedHead != NULL && outputHead != NULL) {
    result &= (expectedHead -> data == outputHead -> data);
    expectedHead = expectedHead -> next;
    outputHead = outputHead -> next;
  }
  if (!(expectedHead == NULL && outputHead == NULL)) result = false;

  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printLinkedList(tempExpectedHead);
    cout << " Your output: ";
    printLinkedList(tempOutputHead);
    cout << endl;
  }
  test_case_number++;
}

Node* createLinkedList(vector<int> arr) {
  Node *head = NULL;
  Node *tempHead = head;
  for (auto &v : arr) {
    if (head == NULL) head = new Node(v), tempHead = head;
    else {
      head -> next = new Node(v);
      head = head -> next;
    }
  }
  return tempHead;
}

int main() {

  Node *head_1 = createLinkedList({1, 2, 8, 9, 12, 16});
  Node *expected_1 = createLinkedList({1, 8, 2, 9, 16, 12});
  Node *output_1 = reverse(head_1);
  check(expected_1, output_1);

  Node *head_2 = createLinkedList({2, 18, 24, 3, 5, 7, 9, 6, 12});
  Node *expected_2 = createLinkedList({24, 18, 2, 3, 5, 7, 9, 12, 6});
  Node *output_2 = reverse(head_2);
  check(expected_2, output_2);

  // Add your own test cases here

}
