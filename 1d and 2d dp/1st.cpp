#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

// Function to convert a decimal number to scientific notation
string toScientificNotation(double num) {
  stringstream ss;
  if (num == 0) {
    ss << "0.0e0";
  } else {
    double mantis = abs(num);
    int exponent = 0;
    while (mantis >= 10) {
      mantis /= 10;
      exponent++;
    }
    int digitSum = 0;
    while (mantis > 0) {
      digitSum += int(mantis) % 10;
      mantis = floor(mantis / 10.0);
    }
    int reducedExponent = abs(exponent) % 10;
    if (num < 0) {
      ss << "-";
    }
    ss << mantis << '.' << digitSum % 10 << "e" << (exponent >= 0 ? '+' : '-') << reducedExponent;
  }
  return ss.str();
}

// Function to generate the first string (S1)
string generateS1(string scientificNotation) {
  string s1 = "";
  for (char c : scientificNotation) {
    if (isalpha(c)) {
      s1 += c;
    } else if (c == '.') {
      s1 += "zer";
    } else if (c == 'e') {
      s1 += "ee";
    }
  }
  return s1;
}

// Function to generate the second string (S2)
string generateS2(string name, int digit) {
  string s2 = "";
  for (int i = 0; i < name.length(); ++i) {
    if ((i + 1) % 2 == digit) {
      s2 += name[i];
    }
  }
  return s2;
}

int main() {
  int testCases;
  cin >> testCases;

  while (testCases--) {
    double number;
    string name;
    cin >> number >> name;

    if (!isalpha(name[0])) {
      cout << "Invalid" << endl;
      continue;
    }

    string scientificNotation = toScientificNotation(number);
    string s1 = generateS1(scientificNotation);
    int digit = abs(scientificNotation[scientificNotation.length() - 1] - '0') % 2;
    string s2 = generateS2(name, digit);

    cout << s1 << "@" << s2 << endl;
  }

  return 0;
}
