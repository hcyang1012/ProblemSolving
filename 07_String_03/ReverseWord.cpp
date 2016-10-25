#include <string>
#include <iostream>

using namespace std;

string reverseString(const string& str,const char token) {
	string resultString = "";
	const char *pStr = str.c_str();
	int wordLength = 0;
	for (int strIndex = str.length() - 1; strIndex >= -1; strIndex--) {
		
		if (pStr[strIndex] != token && strIndex != -1) {
			wordLength++;
		}
		else {
			for (int copyIndex = 1; copyIndex <= wordLength; copyIndex++) {
				resultString += pStr[strIndex + copyIndex];
			}
			if (strIndex != -1) {
				resultString += " ";
			}
			wordLength = 0;
		}
	}
	return resultString;
}

int main() {
	
	cout << "==" << reverseString("Do or do not, there is no try.", ' ') << "==" << endl;
	return 0;
}