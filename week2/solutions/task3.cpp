#include <iostream>
#include <string.h>
#include <stack>
using namespace std;



bool isOpeningBracket(char bracket) {

  return bracket == '(' || bracket == '[' || bracket == '{' || bracket == '<';
}

bool isClosingBracket(char bracket) {

  return bracket == ')' || bracket == ']' || bracket == '}' || bracket == '>';
}

bool areBracketsOfSameType(char openingBracket, char closingBracket) {

  return (openingBracket == '(' && closingBracket == ')') ||
         (openingBracket == '[' && closingBracket == ']') ||
         (openingBracket == '{' && closingBracket == '}') ||
         (openingBracket == '<' && closingBracket == '>');
}

bool areBracketsCorrect(char* data, int n) {


  stack<char> openingBrackets;

  for (int i = 0; i < n; i++) {

    if(isOpeningBracket(data[i])) {
      openingBrackets.push(data[i]);
    }

    if (isClosingBracket(data[i])) {

      if (openingBrackets.empty()) {
        return false;
      }

      if (areBracketsOfSameType(openingBrackets.top(), data[i])) {
        openingBrackets.pop();
      }

      else {
        return false;
      }
    }
  }

  return openingBrackets.empty();
}

int main() {

  int n;
  char data[1024];


  cin >> data;
  n = strlen(data);

  cout << boolalpha << areBracketsCorrect(data, n) << endl;

  return 0;
}