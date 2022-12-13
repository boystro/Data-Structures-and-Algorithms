#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>

struct Edge
{
  int fr;
  int to;
  int wt;

  Edge(int fr, int to, int wt = 1)
    : fr(fr), to(to), wt(wt) { }

  Edge Copy()
  {
    return Edge(fr, to, wt);
  }
};

struct Graph
{
  std::unordered_map<int, std::vector<Edge>> adjacencyList;

  Graph() { }

  Graph(std::vector<Edge> edgelist)
  {
    for (Edge& edge : edgelist)
    {
      AddEdge(edge);
    }
  }

  void AddNode(int node)
  {
    if (adjacencyList.find(node) != adjacencyList.end()) return;
    adjacencyList[node] = std::vector<Edge>();
  }

  void AddEdge(Edge& edge)
  {
    AddNode(edge.fr);
    AddNode(edge.to);
    adjacencyList[edge.fr].emplace_back(edge.Copy());
  }

  void PrintAdjacencyList()
  {
    for (std::pair<int, std::vector<Edge>> pair : adjacencyList)
    {
      std::cout << pair.first << " : ";
      for (Edge edge : pair.second)
      {
        std::cout << edge.to << "(" << edge.wt << ")" << " -> ";
      }
      std::cout << "X\n";
    }
  }

  std::vector<int> GetBFSSequence()
  {
    int first;
    for (auto pair : adjacencyList) 
    {
      first = pair.first;
      break;
    }
    return GetBFSSequence(first);
  }

  std::vector<int> GetBFSSequence(int root)
  {
    std::vector<int> sequence;

    if (adjacencyList.begin() == adjacencyList.end()) {
      return sequence;
    }

    std::queue<int> q;
    for (std::pair<int, std::vector<Edge>> pair : adjacencyList) {
      q.push(pair.first);
      break;
    }

    while (!q.empty()) {
      if (std::find(sequence.cbegin(), sequence.cend(), q.front()) != sequence.cend()) {
        q.pop();
        continue;
      }
      sequence.emplace_back(q.front());
      for (Edge edge : adjacencyList[q.front()]) {
        if (std::find(sequence.cbegin(), sequence.cend(), edge.to) == sequence.cend())
          q.push(edge.to);
      }
      q.pop();
    }

    return sequence;
  }
};

int main()
{
  std::vector<Edge> edgelist = {
    Edge(1, 2),
    Edge(1, 3),
    Edge(1, 4),
    Edge(2, 3),
    Edge(3, 4),
    Edge(3, 5),
    Edge(4, 5),
  };

  Graph gr(edgelist);

  gr.PrintAdjacencyList();

  for (int val : gr.GetBFSSequence())
  {
    std::cout << val << " ";
  }
  std::cout << "\n";

  return 0;
}