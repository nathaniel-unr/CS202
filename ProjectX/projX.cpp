#include "SmartPtr.h"
#include <iostream>
using namespace std;

int main() {
  cout << endl << "Testing SmartPtr Default ctor" << endl;
  SmartPtr sp1; // Default-ctor
  sp1->setIntVal(1);
  sp1->setDoubleVal(0.25);
  cout << "Dereference Smart Pointer 1: " << *sp1 << endl;
  cout << endl << "Testing SmartPtr Copy ctor" << endl;
  SmartPtr sp2 = sp1; // Copy-initalization (Copy-ctor)
  sp2->setIntVal(2);
  sp2->setDoubleVal(0.5);
  cout << "Dereference Smart Pointer 1: " << *sp1 << endl;
  cout << "Dereference Smart Pointer 2: " << *sp2 << endl;
  cout << endl << "Testing SmartPtr Assignment operator" << endl;
  SmartPtr sp3;
  sp3 = sp1; // Assignment operator
  sp3->setIntVal(4);
  sp3->setDoubleVal(0.0);
  cout << "Dereference Smart Pointer 1: " << *sp1 << endl;
  cout << "Dereference Smart Pointer 2: " << *sp2 << endl;
  cout << "Dereference Smart Pointer 3: " << *sp3 << endl;
  cout << endl << "Testing SmartPtr Parametrized ctor with NULLdata" << endl;
  SmartPtr spNull(NULL); // NULL-data initialization
  cout << endl << "Testing SmartPtr Copy ctor with NULLdata SmartPtr" << endl;
  SmartPtr spNull_cpy(spNull); // NULL-data copy constructor
  cout << endl << "Testing SmartPtr Assignment with NULLdata SmartPtr" << endl;
  SmartPtr spNull_assign;
  spNull_assign = spNull; // NULL-data assign
  cout << endl
       << "End-of-Scope, Destructors called in reverse order of SmartPtr "
          "creation\n(spNull_assign, spNull_cpy, spNull, sp3, sp2, sp1): "
       << endl;
  return 0;
}