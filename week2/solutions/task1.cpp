#include <iostream>
#include <fstream>
using namespace std;

struct Employee{

  char name[128];
  char occupation[128];
  double salary;
};

istream& operator>>(istream& in, Employee &employee){

  in.getline(employee.name, 128);
  in.getline(employee.occupation, 128);
  in >> employee.salary;
  in.ignore();

  return in;
}


int main() {

  ofstream outputFile;
  outputFile.open("employee.bin", ios::out | ios::binary);

  Employee employee;

  while (cin >> employee) {

    outputFile.write((const char*)(&employee), sizeof(employee));
  }

  outputFile.close();

  return 0;
}