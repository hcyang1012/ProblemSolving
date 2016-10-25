#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void){
	string inputString = "total";
	map<char,int> charMap;
	for(string::iterator itor = inputString.begin() ; itor != inputString.end() ; ++itor){	
		if(charMap.find(*itor) == charMap.end()){charMap[*itor] = 1;}
		else {charMap[*itor]++;}
	} 

	int minIndex = inputString.length();
	for(map<char,int>::iterator itor = charMap.begin() ; itor != charMap.end() ; ++itor){
		if(itor->second == 1){
			if(inputString.find(itor->first) < minIndex){minIndex = inputString.find(itor->first);}
		}
	} 

	if(minIndex != inputString.length()){
		cout << inputString[minIndex] << endl;
	}
	return 0;
}

