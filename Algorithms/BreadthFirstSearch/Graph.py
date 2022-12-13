from typing import *;
from typing_extensions import *;
import queue;

class Edge:
  def __init__(self:Self, fr:int, to:int, wt:int = 1) -> None:
    self.fr:int = fr;
    self.to:int = to;
    self.wt:int = wt;

class Graph:
  def __init__(self:Self, edgelist:List[Edge]|None = None) -> None:
    self.adjacencyList:Dict[int,Set[Edge]] = dict()
    if edgelist == None: return;
    for edge in edgelist:
      self.AddNode(edge.fr);
      self.AddNode(edge.to);
      self.AddEdge(edge);
    return;

  def AddNode(self:Self, node:int) -> None:
    if node in self.adjacencyList: return;
    self.adjacencyList[node] = set();
    return;

  def AddEdge(self:Self, edge:Edge) -> None:
    self.adjacencyList[edge.fr].add(edge);
    return;

  def PrintAdjacencyList(self:Self) -> None:
    for element in self.adjacencyList:
      print(element, sep="", end=" -> ");
      for edge in self.adjacencyList[element]: print(f"{edge.to}({edge.wt})", sep="", end="")
      print("X");
    return;

  def BFS(self:Self, root:int|None = None) -> List[int]:
    sequence:List[int] = [];

    if not self.adjacencyList:
      return sequence;

    q:queue.Queue[int] = queue.Queue();
    q.put(root or list(self.adjacencyList.keys())[0]);
    
    while not q.empty():
      cur:int = q.get();
      if cur in sequence:
        continue;
      sequence.append(cur);
      for edge in self.adjacencyList[cur]:
        if edge.to not in sequence:
          q.put(edge.to);

    return sequence;


def main() -> None:
  edgelist = [
    Edge(1, 2),
    Edge(1, 3), 
    Edge(1, 4),
    Edge(2, 3),
    Edge(3, 4),
    Edge(3, 5),
    Edge(4, 5),
  ];

  gr = Graph(edgelist);

  gr.PrintAdjacencyList();

  print(gr.BFS());

if __name__ == "__main__": main();