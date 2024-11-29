#include <cstdio>

class Problem {

public :
  Problem();

  void solve();

private :
  int _x;
  int _y;

};

Problem::Problem() {
  scanf("%d\n", &_x);
  scanf("%d\n", &_y);
}

void Problem::solve() {
  int output;

  if (_x > 0) {
    if (_y > 0) {
      output = 1;
    }
    else {
      output = 4;
    }
  }
  else {
    if (_y > 0) {
      output = 2;
    }
    else {
      output = 3;
    }
  }

  printf("%d", output);
}

int main() {
  Problem problem = Problem();
  problem.solve();

  return 0;
}
