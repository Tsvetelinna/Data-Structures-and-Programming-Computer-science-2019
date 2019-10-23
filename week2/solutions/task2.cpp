#include <iostream>
#include <fstream>
using namespace std;

struct Employee{

  char name[128];
  char occupation[128];
  double salary;
};

ostream& operator<<(ostream &out, Employee employee){

  out << employee.name << ' ' << employee.occupation << ' ' << employee.salary;

  return out;
}


int main() {

  ifstream inputFile;
  inputFile.open("employee.bin", ios::in | ios::binary);

  Employee employee;

  while (inputFile.read((char*)(&employee), sizeof(employee))){

    cout << employee << endl;
  }

  inputFile.close();

  return 0;
}