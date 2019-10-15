#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool isWhiteSpace(char symbol){
  return symbol == ' ' || symbol == '\t' || symbol == '\n';
}

int main() {

  string fileName;
  cin >> fileName;

  ifstream inputFile;
  inputFile.open(fileName);

  int bytesSize = 0;
  int newLinesCount = 0;
  int wordsCount = 0;
  char symbol;

  while (inputFile.get(symbol)) {

    bytesSize++;

    if (symbol == '\n') {
      newLinesCount++;
    }

    if (!isWhiteSpace(symbol)) {

      if (inputFile.peek() == EOF || isWhiteSpace(inputFile.peek())) {
        wordsCount++;
      }
    }
  }

  inputFile.close();

  cout << bytesSize << ' ' << wordsCount << ' ' << newLinesCount << endl;

  return 0;
}