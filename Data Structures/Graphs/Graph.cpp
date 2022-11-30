#include <iostream>
#include <vector>
#include <map>

struct Edge
{
  int fr;
  int to;
  int wt;

  Edge(int fr, int to, int wt = 1)
    : fr(fr), to(to), wt(wt) { }
};

struct Graph
{
private:
  std::map<int, std::vector<std::pair<int, int>>> adjacencyList;

public:
  Graph() { }
  Graph(std::vector<Edge>& edgelist)
  {
    for (Edge edge : edgelist)
    {
      AddNode(edge.wt);
      AddNode(edge.to);
      AddEdge(edge);
    }
  }

  void AddNode(int node)
  {
    if (adjacencyList.find(node) != adjacencyList.end()) return;
    adjacencyList[node] = std::vector<std::pair<int, int>>();
  }

  void AddEdge(Edge& edge)
  {
    adjacencyList[edge.fr].push_back({edge.to, edge.wt});
  }

  void PrintAdjacencyList()
  {
    for (std::pair<int, std::vector<std::pair<int, int>>> element : adjacencyList)
    {
      std::cout << element.first << " --> ";
      for (std::pair<int, int> edge : element.second)
      {
        std::cout << edge.first << "[" << edge.second << "]" << " --> ";
      }
      std::cout << "X\n";
    }
  }
};

int main()
{
  std::vector<Edge> edgelist;
  
  edgelist.push_back({1, 2});
  edgelist.push_back({1, 3});
  edgelist.push_back({1, 4});
  edgelist.push_back({2, 3});
  edgelist.push_back({3, 4});
  edgelist.push_back({3, 5});
  edgelist.push_back({4, 5});

  Graph gr(edgelist);

  gr.PrintAdjacencyList();

  return 0;
}