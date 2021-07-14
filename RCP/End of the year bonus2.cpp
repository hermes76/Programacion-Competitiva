#include <bits/stdc++.h>
using namespace std;

long long per[100005];
long long bon[100005];

int main(){
  cin.tie(0); ios_base::sync_with_stdio(0);
  long long n, b;
  cin >> n >> b;
  for (int i=0; i<n; i++){
    cin >> per[i];
    if (per[i] > 0) bon[i] = 1;
  }

  for (int e=0; e<3; e++){
    if (per[1] > per[n-1]){
      if (per[0] > per[1]) bon[0] = bon[1] + 1;
      else if (per[0] > per[n-1]) bon[0] = bon[n-1] + 1;
    }
    if (per[n-1] > per[1]){
      if (per[0] > per[n-1]) bon[0] = bon[n-1] + 1;
      else if (per[0] > per[1]) bon[0] = bon[1] + 1;
    }
    if (per[n-1] == per[1]){
      if (per[0] == per[n-1]) bon[0] = bon[n-1];
      if (per[0] > per[n-1]) bon[0] = max(bon[n-1],bon[1])+1;
    }

    for (int i=1; i<n-1; i++){
      if (per[i-1] > per[i+1]){
        if (per[i] > per[i-1]) bon[i] = bon[i-1] + 1;
        else if (per[i] > per[i+1]) bon[i] = bon[i+1] + 1;
      }
      if (per[i+1] > per[i-1]){
        if (per[i] > per[i+1]) bon[i] = bon[i+1] + 1;
        else if (per[i] > per[i-1]) bon[i] = bon[i-1] + 1;
      }
      if (per[i+1] == per[i-1]){
        if (per[i] == per[i+1]) bon[i] = bon[i+1];
        if (per[i] > per[i+1]) bon[i] = bon[i+1] + 1;
      }
    }
    if (per[n-2] > per[0]){
      if (per[n-1] > per[n-2]) bon[n-1] = bon[n-2] + 1;
      else if (per[n-1] > per[0]) bon[n-1] = bon[0] + 1;
    }
    if (per[0] > per[n-2]){
      if (per[n-1] > per[0]) bon[n-1] = bon[0] + 1;
      else if (per[n-1] > per[n-2]) bon[n-1] = bon[n-2] + 1;
    }
    if (per[0] == per[n-2]){
      if (per[n-1] == per[0]) bon[n-1] = bon[0];
      if (per[n-1] > per[0]) bon[n-1] = bon[0] + 1;
    }

  }
/*
  if (per[n-1] > per[n-2]) bon[n-1] += 1;
  if (per[n-1] > per[0] && per[0] > per[n-2]) bon[n-1] += 1;
  for (int i=n-2; i>=0; i--){
    if (per[i] > per[i+1]) bon[i] += 1;
    if (per[i] > per[i-1] && per[i-1] > per[i+1]) bon[i] += 1;
  }
  if (per[0] > per[1]) bon[0] += 1;
  if (per[0] > per[n-1] && per[n-1] > per[1]) bon[0] += 1;
*/
  for (int i=0; i<n-1; i++){
    cout << bon[i]*b << " ";
  }
  cout << bon[n-1]*b;
  cout << endl;
  return 0;
}
