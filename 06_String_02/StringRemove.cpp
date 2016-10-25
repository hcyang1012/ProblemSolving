#include <string>
#include <iostream>
#include <set>

using namespace std;

string removeChars(const string&str, const string& remove) {
	string resultString = "";
	set<char> removeSet;
	for (string::const_iterator itor = remove.begin(); itor != remove.end(); ++itor) {
		removeSet.insert(*itor);
	}

	for (string::const_iterator itor = str.begin(); itor != str.end(); ++itor) {
		if (removeSet.find(*itor) == removeSet.end()) {
			resultString += *itor;
		}
	}

	return resultString;
}

int main() {
	cout << removeChars("Battle of the Vowels: Hawaii vs. Grozny", "aeiou") << endl;
}
