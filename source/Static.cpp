#include "../header/Static.h"

int Test::factorial(int n) {
  int result = 1;
  for (int i = 2; i <= n; i++) result += i;
}

int Test::x = 10;