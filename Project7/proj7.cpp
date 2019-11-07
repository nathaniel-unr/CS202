/**
 * This file is a test driver for the Dynamic Allocation MyString class
 * prescribed in Project 7 of CS-202
 */

#include <iostream>

#include "MyString.h"

using namespace std;

int main() {

  //(1)
  cout << endl << "Testing Default ctor" << endl;
  MyString ms_default;

  //(2)
  cout << endl << "Testing Parametrized ctor" << endl;
  MyString ms_parametrized("MyString parametrized constructor!");

  //(3)
  cout << endl << "Testing Copy ctor" << endl;
  MyString ms_copy(ms_parametrized);

  //(4)
  cout << endl
       << "Testing Dynamic Allocation with new / Deallocation with delete "
          "expressions"
       << endl;
  MyString *ms_Pt = new MyString("MyString to be deleted…");
  delete ms_Pt;
  ms_Pt = NULL;

  //(5),(6)
  cout << endl << "Testing Size and Length helper methods" << endl;
  MyString ms_size_length("Size and length test");
  cout << ms_size_length.size() << endl;
  cout << ms_size_length.length() << endl;

  //(7)
  cout << endl << "Testing c_str conversion helper method" << endl;
  MyString ms_toCstring("C-String equivalent successfully obtained!");
  cout << ms_toCstring.c_str() << endl;

  //(8)
  cout << endl << "Testing Equality operator==" << endl;
  MyString ms_same1("The same"), ms_same2("The same");
  if (ms_same1 == ms_same2)
    cout << "Equality: Same success" << endl;
  MyString ms_different("The same (NOT)");
  if (!(ms_same1 == ms_different))
    cout << "Equality: Different success" << endl;

  //(9)
  cout << endl << "Testing Assignment operator=" << endl;
  MyString ms_assign("MyString before assignment");
  cout << ms_assign << endl;
  ms_assign = MyString("MyString after performing assignment");
  cout << ms_assign << endl;

  //(10)
  cout << endl << "Testing operator+" << endl;
  MyString ms_append1("The first part");
  MyString ms_append2(" and the second");
  MyString ms_concat = ms_append1 + ms_append2;
  cout << ms_concat << endl;

  //(11)
  cout << endl << "Testing operator[]" << endl;
  MyString ms_access("Access successful (NOT)");
  ms_access[17] = 0;

  //(12)
  cout << ms_access << endl;
}
