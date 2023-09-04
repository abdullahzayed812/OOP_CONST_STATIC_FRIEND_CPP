// #ifdef CLASS_STATIC
// #define CLASS_STATIC

// class Test_Static
// {
// public:
//   static int x;

//   int sayHello();
// };

class Test
{
public:
  int y;
  static int x;

  // Static can't access non-static member.
  static int factorial(int n);
};

// int Test::x = 10;

// #endif