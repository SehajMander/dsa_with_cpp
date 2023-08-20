#include <iostream>
using namespace std;

int main() {
  char a;
  cout<<"Enter the value of a : ";
  cin >> a;

  if (a >= 'a' && a <= 'z') {
    cout << "This is lowercase." << endl;
  } else if (a >= 'A' && a <= 'Z') {
    cout << "This is uppercase" << endl;
  } else {
    cout << "This is numeric." << endl;
  }

  return 0;
}