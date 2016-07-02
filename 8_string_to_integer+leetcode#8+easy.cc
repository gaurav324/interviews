// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
// Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits 
// as possible, and interprets them as a numerical value. The string can contain additional characters after those that 
// form the integral number, which are ignored and have no effect on the behavior of this function.

// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence 
// exists because either str is empty or it contains only whitespace characters, no conversion is performed.

// If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of 
// representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

#include <iostream>
using namespace std;

int atoi(string s) {
	  int index = 0;
  	while(true) {
  		if (!std::isspace(s[index])) {
  			break;
  		}
  		++index;
  	}
  	
  	int is_negative = 1;
  	if (s[index] == '+') {
  	    ++index;
  	} else if (s[index] == '-') {
  	    is_negative = -1;
        ++index;    	    
  	}
  	long long ans = 0;
  	for (int i=index; i < s.size(); ++i) {
  		if(!std::isdigit(s[i])) {
  			break;
  		}
  	
  		ans = ans * 10 + (s[i] - '0');
  		if (is_negative < 0) {
  		    if (ans * is_negative < INT_MIN) { return INT_MIN; }
  		} else {
  		    if (ans * is_negative > INT_MAX) { return INT_MAX; }
  		}
  	}
  	return ans * is_negative;
}

int main() {
	cout << "atoi(+0) = " << atoi("0") << endl;
	cout << "atoi(-232) = " << atoi("-232") << endl;
	cout << "atoi(-54534) = " << atoi("54534") << endl;
	cout << "atoi('') = " << atoi("") << endl;
	cout << "atoi(   +12323) = " << atoi("   +12323dfgdsg") << endl;
}
