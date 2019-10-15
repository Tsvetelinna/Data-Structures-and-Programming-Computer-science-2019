#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main() {

  ifstream inputFile;

  string fileName;

  cin >> fileName;

  inputFile.open(fileName);

  int bytesSize = 0;
  char symbol;

  while(inputFile.get(symbol)) {
    bytesSize++;
  }

  inputFile.close();

  cout << bytesSize << endl;

  return 0;
}