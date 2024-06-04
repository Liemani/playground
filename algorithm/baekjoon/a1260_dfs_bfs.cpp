#include <stdio.h>
#include <set>
#include <vector>
#include <queue>

using std::set;
using std::vector;

// GraphNode
struct GraphNode {
public :
  set<GraphNode*> linkedNodes;
  set<GraphNode*>::iterator searchTarget;

  bool isVisitedVariable;

  GraphNode();

  int number() const;

  bool isVisited() const;
  bool isTargetEnd() const;

  void forwardTarget();

  void clearSearchTarget();

  friend class Graph;

private :
  int _number;
};

inline GraphNode::GraphNode()
: linkedNodes(set<GraphNode*>()),
  isVisitedVariable(false)
{
}

inline int GraphNode::number() const {
  return this->_number;
}

inline bool GraphNode::isVisited() const {
  return this->searchTarget != this->linkedNodes.begin();
}

inline bool GraphNode::isTargetEnd() const {
  return this->searchTarget == this->linkedNodes.end();
}

inline void GraphNode::forwardTarget() {
  ++this->searchTarget;
}

inline void GraphNode::clearSearchTarget() {
  this->searchTarget = this->linkedNodes.begin();
}

inline void connect(GraphNode& lhs, GraphNode& rhs) {
  lhs.linkedNodes.insert(&rhs);
  rhs.linkedNodes.insert(&lhs);
}

inline void disconnect(GraphNode& lhs, GraphNode& rhs) {
  lhs.linkedNodes.erase(&rhs);
  rhs.linkedNodes.erase(&lhs);
}

// Graph
struct Graph {
  vector<GraphNode> nodes;

  Graph(int count);

  void constructGraphFromInput(int linkCount);
  void clearSearchHistory();
};

inline Graph::Graph(int count)
: nodes(vector<GraphNode>(count))
{
  for (int i = 0; i < count; ++i) {
    this->nodes[i]._number = i + 1;
  }
}

inline void Graph::constructGraphFromInput(int linkCount) {
  for (int i = 0; i < linkCount; ++i) {
    int lhsNumber;
    int rhsNumber;

    scanf("%d", &lhsNumber);
    const int lhsIndex = lhsNumber - 1;
    scanf("%d", &rhsNumber);
    const int rhsIndex = rhsNumber - 1;

    if (lhsIndex != rhsIndex) {
      GraphNode& lhs = this->nodes[lhsIndex];
      GraphNode& rhs = this->nodes[rhsIndex];
      connect(lhs, rhs);
    }
  }
  this->clearSearchHistory();
}

inline void Graph::clearSearchHistory() {
  for (int i = 0; i < this->nodes.size(); ++i) {
    GraphNode& node = this->nodes[i];
    node.clearSearchTarget();
  }
}

// DFS
class DFS {
public :
  DFS(Graph& graph, int entryNumber);
  ~DFS();

  void execute();

private :
  Graph& graph;

  GraphNode& entry();
  GraphNode** path;
  int pathEndIndex;
  GraphNode& last();

  void searchNode(GraphNode& node);
};

inline DFS::DFS(Graph& graph, int entryNumber)
: graph(graph), pathEndIndex(0)
{
  const int nodeCount = graph.nodes.size();
  this->path = new GraphNode*[nodeCount];

  const int entryINdex = entryNumber - 1;
  path[this->pathEndIndex++] = &graph.nodes[entryINdex];
}

inline DFS::~DFS() {
  delete [] this->path;
}

inline void DFS::execute() {
  const int nodeNumber = this->entry().number();
  printf("%d", nodeNumber);

  while (!this->entry().isTargetEnd()) {
    GraphNode& node = this->last();
    this->searchNode(node);
  }
}

inline void DFS::searchNode(GraphNode& node) {
  while (!node.isTargetEnd()) {
    GraphNode& searchTarget = **node.searchTarget;
    node.forwardTarget();

    if (!searchTarget.isVisited()) {
      const int targetNumber = searchTarget.number();
      printf(" %d", targetNumber);
      this->path[this->pathEndIndex++] = &searchTarget;
      return;
    }
  }
  --this->pathEndIndex;
}

inline GraphNode& DFS::entry() {
  return *this->path[0];
}

inline GraphNode& DFS::last() {
  return *this->path[this->pathEndIndex - 1];
}

// BFS
class BFS {
public :
  BFS(Graph& graph);

  void execute(int entryNumber);

private :
  Graph& graph;

  std::queue<GraphNode*> queue;

  bool isSearchEnded() const;

  void searchNode(GraphNode& node);
};

inline BFS::BFS(Graph& graph)
: graph(graph),
  queue(std::queue<GraphNode*>())
{
}

inline void BFS::execute(int entryNumber) {
  const int entryIndex = entryNumber - 1;
  GraphNode* const entryNode = &this->graph.nodes[entryIndex];
  queue.push(entryNode);
  entryNode->isVisitedVariable = true;

  while (!this->isSearchEnded()) {
    GraphNode& node = *this->queue.front();
    this->queue.pop();

    const int nodeNumber = node.number();
    if (nodeNumber != entryNumber) {
      printf(" %d", nodeNumber);
    }
    else {
      printf("%d", nodeNumber);
    }

    set<GraphNode*>::iterator it = node.linkedNodes.begin();
    while (it != node.linkedNodes.end()) {
      GraphNode* targetNode = *it;

      if (!targetNode->isVisitedVariable) {
        this->queue.push(targetNode);
        targetNode->isVisitedVariable = true;
      }

      ++it;
    }
  }
}

inline bool BFS::isSearchEnded() const {
  return this->queue.empty();
}

// main()
int main(void) {
  int nodeCount;
  int linkCount;
  int entryNumber;

  scanf("%d", &nodeCount);
  scanf("%d", &linkCount);
  scanf("%d", &entryNumber);

  Graph graph = Graph(nodeCount);
  graph.constructGraphFromInput(linkCount);

  DFS dfs = DFS(graph, entryNumber);
  dfs.execute();

  printf("\n");
  BFS bfs = BFS(graph);
  bfs.execute(entryNumber);

  return 0;
}
