from typing import *

class Edge:
  def __init__(self, fr:int, to:int, wt:int = 1) -> None:
    self.fr:int = fr
    self.to:int = to
    self.wt:int = wt

class Graph:
  def __init__(self, edgelist:List[Edge]|None = None) -> None:
    self.adjacencyList:Dict[int,Set[Edge]] = dict()
    if edgelist == None: return
    for edge in edgelist:
      self.AddNode(edge.fr)
      self.AddNode(edge.to)
      self.AddEdge(edge)
    return

  def AddNode(self, node:int) -> None:
    if node in self.adjacencyList: return
    self.adjacencyList[node] = set()
    return

  def AddEdge(self, edge) -> None:
    self.adjacencyList[edge.fr].add(edge)
    return

  def PrintAdjacencyList(self) -> None:
    for element in self.adjacencyList:
      print(element, sep="", end=" -> ")
      for edge in self.adjacencyList[element]:
        print(f"{edge.to}({edge.wt})", sep="", end=" -> ")
      print("X")
    return

  def DFS(self, root:int|None = None) -> List[int]:
    sequence:List[int] = []
    def traverse(root: int) -> None:
      if root in sequence: return
      sequence.append(root)
      for edge in self.adjacencyList[root]:
        traverse(edge.to)
      return
    traverse(root or list(self.adjacencyList.keys())[0])
    return sequence

edgelist = [
  Edge(1, 2),
  Edge(1, 3), 
  Edge(1, 4),
  Edge(2, 3),
  Edge(3, 4),
  Edge(3, 5),
  Edge(4, 5),
]

gr = Graph(edgelist)

gr.PrintAdjacencyList()

print(gr.DFS())