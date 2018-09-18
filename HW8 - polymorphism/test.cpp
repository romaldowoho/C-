/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
Filename: test.cpp

Memory leaked: 0 bytes (0%); potentially leaked: 0 bytes (0%)
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
            NOTHING CAN BE CHANGED BELOW
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "employee.h"
#include "salariedemployee.h"
#include "commissionemployee.h"
#include "basepluscommissionemployee.h"

/*----------------------------------------------------------------
testEmployee
-----------------------------------------------------------------*/
void testEmployee() {
  employee e1("jag", "vasudevamurthy", "678-90");
  cout << e1 << endl;
  employee e2("bob", "ericission", "178-90");
  cout << e2 << endl;
  employee e3(e1);
  cout << e3 << endl;
  e2 = e3;
  cout << e3 << endl;
  cout << e2 << endl;
}

void testEmployee1() {
  const int N = 5 ;
  employee* e[N] ;
  for (int i = 0; i < 5; ++i) {
    char fname[10] ;
    char lname[10] ;
    char ssn[10] ;
    char a[2] ;
    a[0] = i + '0' ;
    a[1] = '\0' ;
    strcpy(fname,"jag") ;
    strcat(fname,a) ;
    strcpy(lname,"Vas") ;
    strcat(lname,a) ;
    strcpy(ssn,"46-78-") ;
    strcat(ssn,a) ;
    e[i] = new employee(fname,lname,ssn);
    const employee& ei = *(e[i]);
    cout << ei << endl;
  }
  for (int i = 0; i < N; ++i) {
    cout << *(e[i]) << endl ;
  }
  *(e[0]) = *(e[1]) = *(e[2]) ;
  for (int i = 0; i < N; ++i) {
    cout << *(e[i]) << endl ;
    delete e[i] ;
  }
}

/*----------------------------------------------------------------
testSalariedemployee
-----------------------------------------------------------------*/
void testSalariedemployee() {
  salariedemployee e1("jag", "vasudevamurthy", "678-90", "Xilinx", 56000);
  cout << e1 << endl;
  salariedemployee e2("bob", "ericission", "178-90", "ATT", 3456000);
  cout << e2 << endl;
  salariedemployee e3(e1);
  cout << e3 << endl;
  e2 = e3;
  cout << e3 << endl;
  cout << e2 << endl;
}

/*----------------------------------------------------------------
test Commission employee
-----------------------------------------------------------------*/
void testCommissionemployee() {
  commissionemployee e1("jag", "vasudevamurthy", "678-90", "BELL", 560);
  cout << e1 << endl;
  commissionemployee e2("bob", "ericission", "178-90", "UCSC", 345);
  cout << e2 << endl;
  commissionemployee e3(e1);
  cout << e3 << endl;
  e2 = e3;
  cout << e3 << endl;
  cout << e2 << endl;
}

/*----------------------------------------------------------------
test Basepluscommissionemployee
-----------------------------------------------------------------*/
void testBasepluscommissionemployee() {
  basepluscommissionemployee e1("jag", "vasudevamurthy", "678-90", "BELL", 560, "abc", 89);
  cout << e1 << endl;
  basepluscommissionemployee e2("bob", "ericission", "178-90", "UCSC", 345, "xyz", 90);
  cout << e2 << endl;
  basepluscommissionemployee e3(e1);
  cout << e3 << endl;
  e2 = e3;
  cout << e3 << endl;
  cout << e2 << endl;
}

/*----------------------------------------------------------------
test
-----------------------------------------------------------------*/
void polymorphism() {
  vector<employee *> v;
  {
    employee* e1 = new employee("jag", "vasudevamurthy", "678-90");
    v.push_back(e1);
    employee* e2 = new employee("bob", "ericission", "178-90");
    v.push_back(e2);
  }
  {
    salariedemployee*  e1 = new salariedemployee("alex", "wong", "678-89", "Men", 24);
    v.push_back(e1);
    salariedemployee* e2 = new salariedemployee("bob", "john", "478-90", "XYX", 345);
    v.push_back(e2);
  }

  {
    commissionemployee* e1 = new commissionemployee("hale", "tom", "589-78", "xil", 560000);
    v.push_back(e1);
    commissionemployee* e2 = new commissionemployee("jon", "snith", "478-90", "UCB", 9);
    v.push_back(e2);
  }

  {
    basepluscommissionemployee* e1 = new basepluscommissionemployee("amy", "vmay", "878-90", "synp", 160, "nvida", 809);
    v.push_back(e1);
    basepluscommissionemployee* e2 = new basepluscommissionemployee("fake", "guy", "878-60", "mu", 345, "spy", 190);
    v.push_back(e2);
  }

  {
    for (auto i = 0; i < v.size(); ++i) {
      cout << i << ": " << *(v[i]) << endl;
    }
  }
  {
    for (auto i : v) {
      delete i;
    }
  }
}


/*----------------------------------------------------------------

-----------------------------------------------------------------*/
int main() {
#ifdef _WIN32
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  employee::setShow(true);
  testEmployee();
  testEmployee1();
  testSalariedemployee();
  testCommissionemployee();
  testBasepluscommissionemployee();
  polymorphism();
  return 0;
}