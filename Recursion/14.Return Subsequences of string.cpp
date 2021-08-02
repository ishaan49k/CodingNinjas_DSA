#include <bits/stdc++.h> 
using namespace std;

// FXN
int subs(string input, string output[]) {
	if (input.empty()) {
		output[0] = "";
		return 1;
	}
  
  // recursion
	int smallOutputSize = subs(input.substr(1), output);
  
	for (int i = 0; i < smallOutputSize; i++) {
		output[i + smallOutputSize] = input[0] + output[i];
	}
	return 2 * smallOutputSize;
}




int main() {
	string input;
	cin >> input;
  int len = input.size();
	string* output = new string[pow(2, len)];
	int count = subs(input, output);
  
	for (int i = 0; i < count; i++) {
		cout << output[i] << endl;
	}
  
}
