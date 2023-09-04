#include <iostream>
#include <vector>

#include "./header/Rectangle.h"
// #include "./header/Static.h"
using namespace std;

/*************** Static Member ***************/
class Test {
 private:
  int y;
  static int x;

 public:
  // Static can't access non-static member.
  static int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
      result += i;
    }
    return result;
  }
};

int Test::x = 10;
// int Test::factorial(int n)

class Employee {
 private:
  string name;
  static int employeesCount;

 public:
  Employee(string name) : name(name) { ++Employee::employeesCount; }

  static int getEmployeesCount() { return Employee::employeesCount; }
};

int Employee::employeesCount = 0;

class A {};

class B {
 private:
  int f;

 public:
  B(int a, int b) { this->f = 100; }
  int getF() { return this->f; }
};

class C {
 public:
  static vector<int> v;
  static int arr[10];
  static A a;
  static B *b;
};
vector<int> C::v = vector<int>(20);
int C::arr[10];
A C::a;
B *C::b = new B(10, 20);

/*************** Friend Class & Functions ***************/
class D;
class E;

class D {
 private:
  int d1Private = 10;
  int d2Private = 20;

  void hidden() { cout << "It's a private member function.\n"; }

 public:
  // Class E is friend to D,  Access private members in D
  friend class E;
  // Only friendFun in class E can access private members in D.
  // friend void E::friendFun(D &d);
};

class E {
 public:
  void accessD1(D &d) {
    cout << "Access private member function for D class." << d.d1Private
         << "\n";
  }
  void accessD2(D &d) {
    cout << "Access private member function for D class." << d.d1Private
         << "\n";
    d.hidden();
  }
  void friendFun(D &d) { cout << d.d1Private; }
};

int main() {
  Rectangle r0(3, 3);
  Rectangle *r1 = new Rectangle(2.3, 3.2);
  Rectangle *r3 = new Rectangle(1, 2);
  // const data.
  const Rectangle *r2 = new Rectangle(5, 2);
  // r2 is a const object, that can't be change data by access modifiers that
  // modify data as setters. r2->setHeight(39);
  r2 = &r0;

  Rectangle *const r5 = new Rectangle(10, 10);
  // can't change address, const pointer.

  // const pointer and data
  const Rectangle *const r8 = new Rectangle(30, 30);
  const Rectangle *const r9 = &r0;

  // Test_Static::x;

  // cout << Test::x;

  Employee *emp1 = new Employee("Ahmed");
  Employee *emp2 = new Employee("Mohamed");
  Employee *emp3 = new Employee("Ali");

  cout << Employee::getEmployeesCount() << " is created.";

  cout << C::b->getF();

  E e;
  D d;

  e.accessD1(d);

  return 0;
}