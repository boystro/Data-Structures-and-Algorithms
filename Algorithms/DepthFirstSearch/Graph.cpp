#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>

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
  std::unordered_map<int, std::vector<Edge>> adjacenclyList;

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
    if (adjacenclyList.find(node) != adjacenclyList.end()) return;
    adjacenclyList[node] = std::vector<Edge>();
  }

  void AddEdge(Edge& edge)
  {
    AddNode(edge.fr);
    AddNode(edge.to);
    adjacenclyList[edge.fr].emplace_back(edge.Copy());
  }

  void PrintAdjacencyList()
  {
    for (std::pair<int, std::vector<Edge>> pair : adjacenclyList)
    {
      std::cout << pair.first << " : ";
      for (Edge edge : pair.second)
      {
        std::cout << edge.to << "(" << edge.wt << ")" << " -> ";
      }
      std::cout << "X\n";
    }
  }

  std::vector<int> GetDFSSequence()
  {
    int first;
    for (auto pair : adjacenclyList) 
    {
      first = pair.first;
      break;
    }
    return GetDFSSequence(first);
  }

  std::vector<int> GetDFSSequence(int root)
  {
    std::vector<int> sequence;
    dfsTraversal(sequence, root);
    return sequence;
  }

private:
  void dfsTraversal(std::vector<int>& sequence, int root)
  {
    if (std::find(sequence.begin(), sequence.end(), root) != sequence.end()) return;
    sequence.push_back(root);
    for (Edge edge : adjacenclyList[root]) {
      dfsTraversal(sequence, edge.to);
    }
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

  for (int val : gr.GetDFSSequence())
  {
    std::cout << val << " ";
  }
  std::cout << "\n";

  return 0;
}