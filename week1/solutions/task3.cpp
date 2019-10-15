#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main() {

  string fileName;
  cin >> fileName;

  char wantedSymbol;
  cin >> wantedSymbol;

  ifstream inputFile;
  inputFile.open(fileName);

  int row = 0;
  int column = 0;
  char symbol;

  while (inputFile.get(symbol)) {
    if (symbol == wantedSymbol) {

      cout << row << ' ' << column << endl;
    }

    column++;

    if (symbol == '\n') {
      row++;
      column = 0;
    }
  }

  inputFile.close();

  return 0;
}