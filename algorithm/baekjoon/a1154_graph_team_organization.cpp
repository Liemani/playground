#include <stdio.h>
#include <vector>
#include <set>

class Problem {

public :
  Problemn();

  void solve();

private :
  int studentCount;
  std::vector<int> team;

  int getTeamNumber(int studentNumber) const;
  void optimize();

};

Problemn::Problemn() {
  scanf("%d\n", &this->studentCount);

  for (int i = 0; i < this->studentCount + 1; ++i) {
    this->team.push_back(i);
  }

  int lhs;
  int rhs;
  while (true) {
    scanf("%d %d\n", &lhs, &rhs);

    if (lhs == -1 && rhs == -1) {
      break;
    }

    if (lhs < rhs) {
      this->team[rhs] = lhs;
    }
    else {
      this->team[lhs] = rhs;
    }
  }
}

void Problem::solve() {
  optimize();

  bool isPossible = true;
  int teamLeader = 0;

  std::set 
  for (int i = 2; i < this->studentCount + 1; ++i) {
  }

}

int Problem::getTeamNumber(int studentNumber) const {
  while(true) {
    const int teamNumber = this->team[studentNumber];
    if (teamNumber == studentNumber) {
      return studentNumber;
    }
    else {
      studentNumber = teamNumber;
    }
  }
}

void Problem::optimize() {
  for (int i = 3; i < this->studentCount + 1; ++i) {
    this->team[i] = getTeamNumber(i);
  }
}

int main() {
  Problem problem = Problem();
  problem.solve();

  return 0;
}
