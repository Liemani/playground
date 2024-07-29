#include <stdio.h>
#include <utility>  // std::pair
#include <queue>  // std::priority_queue
#include <vector> // std::vector

class Problem {

public :
  typedef std::pair<int /*distance*/, int /*nodeNumber*/> PriorityQueueElement;

  struct PriorityQueueGreater {
    bool operator()(const PriorityQueueElement& lhs, const PriorityQueueElement& rhs) const {
      return lhs.first > rhs.first;
    }
  };

  typedef std::priority_queue<PriorityQueueElement, std::vector<PriorityQueueElement>, PriorityQueueGreater> PriorityQueue;

  typedef std::pair<int /*end*/, int /*distance*/> Arrow;
  typedef std::vector<Arrow> Node;
  typedef std::vector<Node> Graph;

  Problem();

  void solve();

  void printGraph() const;

private :
  Graph graph;
  PriorityQueue priorityQueue;

  int nodeCount;
  int arrowCount;
  int entry;

};

Problem::Problem() {
  this->graph = Graph();
  this->priorityQueue = PriorityQueue();
  scanf("%d %d", &this->nodeCount, &this->arrowCount);
  scanf("%d", &this->entry);

  for (int i  = 0; i < this->nodeCount + 1; ++i) {
    this->graph.push_back(Node());
  }

  int startNodeNumber;
  int endNodeNumber;
  int distance;
  for (int i = 0; i < this->arrowCount; ++i) {
    scanf("%d %d %d", &startNodeNumber, &endNodeNumber, &distance);
    this->graph[startNodeNumber].push_back(Arrow(endNodeNumber, distance));
  }
}

void Problem::solve() {
}

void printArrow(const Problem::Arrow& arrow) {
  printf("(%d, %d)", arrow.first, arrow.second);
}

void Problem::printGraph() const {
  for (int i = 0; i < this->nodeCount + 1; ++i) {
    const Node node = this->graph[i];
    printf("[ ");
    for (Node::const_iterator it = node.begin(); it != node.end(); ++it) {
      const Arrow arrow = *it;
      printArrow(arrow);
      printf(", ");
    }
    printf(" ], ");
  }
}

int main() {
  Problem problem = Problem();
  problem.solve();

  return 0;
}
