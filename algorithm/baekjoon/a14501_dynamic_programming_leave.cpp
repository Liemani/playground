#include <cstdio>
#include <vector>
#include <algorithm>

class Problem {

public :
  Problem();
  void solve();

private :
  int count;
  std::vector<int> times;
  std::vector<int> prices;

  std::vector<int> earns;

  void printMax() const;
  void printEarns() const;

};

Problem::Problem() {
  scanf("%d", &this->count);

  int time;
  int price;
  for (int i = 0; i < this->count; ++i) {
    scanf("%d %d", &time, &price);
    this->times.push_back(time);
    this->prices.push_back(price);
    this->earns.push_back(0);
  }
}

void Problem::solve() {
  for (int i = 0; i < this->count; ++i) {
    if (this->times[i] > this->count - i) {
      continue;
    }

    this->earns[i] = this->prices[i];

    for (int j = 0; j <i; ++j) {
      if (j + this->times[j] > i) {
        continue;
      }
      else {
        const int price = this->earns[j] + this->prices[i];
//        printf("%d %d %d %d %d\n", i, j, this->earns[j], this-> prices[i], price);
        this->earns[i] = std::max(this->earns[i], price);
      }
    }
  }

//  this->printEarns();
  this->printMax();
}

void Problem::printMax() const {
  int max = 0;
  for (int i = 0; i < this->count; ++i) {
    if (max < this->earns[i]) {
      max = this->earns[i];
    }
  }

  printf("%d", max);
}

void Problem::printEarns() const {
  for (int i = 0; i < this->count; ++i) {
    printf("%d\n", this->earns[i]);
  }
}

int main() {
  Problem problem = Problem();
  problem.solve();

  return 0;
}
