
#include <bits/stdc++.h>
using namespace std;

int x[] = {-1, 0, 1, 1 };
int y[] = { 1, 1, 0, 1 };

int letras[40][40][21];
char grid[41][41];
int l, c;
int letrasBuenas = 0;

bool search2D(int row, int col, string word, int codigo){
	if (grid[row][col] != word[0]){
		return false;
	}
	int len = word.length();

	for (int dir = 3; dir >=0; dir--) {
		int k, rd = row + x[dir];
		int cd = col + y[dir];

		if (rd+(x[dir]*len) > l+1 || cd+(y[dir]*len) > c+1){
			continue;
		}

		for (k = len-1; k >= 1; k++) {
			if (rd >= l || rd < 0 || cd >= c || cd < 0)
				break;
			if (grid[rd][cd] != word[k])
				break;
			rd += x[dir];
			cd += y[dir];
		}
		if (k == len){
			//cout << "Founded" << endl;
			if (letras[row][col][codigo] == 0){
				letras[row][col][codigo] = 1;
				letras[row][col][0] += 1;
				if (letras[row][col][0] > 1)
					letrasBuenas += 1;
			}
			int k, rd = row + x[dir];
			int cd = col + y[dir];
			for (k = len-1; k >= 1; k--){
				if (letras[rd][cd][codigo] == 0){
					letras[rd][cd][codigo] = 1;
					letras[rd][cd][0] += 1;
					if (letras[rd][cd][0] > 1)
						letrasBuenas += 1;
				}
				rd += x[dir];
				cd += y[dir];
			}
			return true;
		}
	}
	return false;
}

void patternSearch(string word, int codigo){
	for (int row = 0; row < l; row++){
		for (int col = 0; col < c; col++){
			search2D(row, col, word, codigo);
		}
	}
}

int main(){
	cin.tie(0); ios_base::sync_with_stdio(0);
  cin >> l >> c;
  for (int i=0; i<l; i++){
    for (int j=0; j<c; j++){
			cin >> grid[i][j];
    }
  }
	int n;
  cin >> n;
  string palabra;
  for (int i=0; i<n; i++){
    cin >> palabra;
		sort(palabra.begin(), palabra.end());
    do{
			patternSearch(palabra, i+1);
		}while(next_permutation(palabra.begin(), palabra.end()));
  }
	/*
	int letrasBuenas = 0;
	*
	for (int i=0; i<40; i++){
		for (int j=0; j<40; j++){
			cout << letras[i][j][0] << " ";
			if (letras[i][j][0] > 1){
				//letrasBuenas += 1;
			}
		}
		cout << endl;
	}
	*/
	cout << letrasBuenas << endl;
	return 0;
}
