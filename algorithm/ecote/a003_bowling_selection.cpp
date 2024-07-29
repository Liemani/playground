#include <cstdio>

class Solution {

public :
  Solution();

  void solve();

private :
  int _numberOfWeights[11];
  int _numberOfBowlingBall;

  void _readInput();

  void _printf_numberOfWeights() const;

};

Solution::Solution()
{
  for (int i = 0; i < 11; ++i) {
    _numberOfWeights[i] = 0;
  }
}

void Solution::_readInput() {
  scanf("%d %*d", &_numberOfBowlingBall) ;

  int weightOfBowlingBall;
  for (int i = 0; i < _numberOfBowlingBall; ++i) {
    scanf("%d", &weightOfBowlingBall);

    ++_numberOfWeights[weightOfBowlingBall];
  }
}

void Solution::_printf_numberOfWeights() const {
  for (int i = 0; i < 11; ++i) {
    printf("%d ", _numberOfWeights[i]);
  }
  printf("\n");
}

void Solution::solve() {
//  _printf_numberOfWeights();
  _readInput();
//  _printf_numberOfWeights();

  int answer = _numberOfBowlingBall * (_numberOfBowlingBall - 1) / 2;

  for (int i = 1; i < 11; ++i) {
    int numberOfWeight = _numberOfWeights[i];
    if (numberOfWeight > 1) {
      answer -= numberOfWeight * (numberOfWeight - 1) / 2;
    }
  }

  printf("%d", answer);

}

int main() {
  Solution solution = Solution();
  solution.solve();

  return 0;
}
