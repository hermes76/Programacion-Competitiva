
#include <iostream>
#include <string>
using namespace std;

int holes[20];

int main(){
  //cin.tie(0); ios_base::sync_with_stdio(0);
  int par =0;
  for (int i=0; i<18; i++){
    cin >> holes[i];
    par += holes[i];
  }
  string stat;
  int total = 0;
  for (int i=0; i<18; i++){
    getline(cin,stat);
    cin.ignore();
    if (stat == "hole in one") {
      total += 1;
    }
    if (stat == "condor") {
      total += holes[i] - 4;
    }
    if (stat == "albatross") {
      total += holes[i] - 3;
    }
    if (stat == "eagle") {
      total += holes[i] - 2;
    }
    if (stat == "birdie") {
      total += holes[i] - 1;
    }
    if (stat == "par") {
      total += holes[i];
    }
    if (stat == "bogey") {
      total += holes[i] + 1;
    }
    if (stat == "double bogey") {
      total += holes[i] + 2;
    }
    if (stat == "triple bogey") {
      total += holes[i] + 3;
    }
  }

  cout << total << endl;
  return 0;
}
