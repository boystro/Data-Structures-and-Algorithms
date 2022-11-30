class Edge:
  def __init__(self, fr, to, wt = 1):
    self.fr = fr
    self.to = to
    self.wt = wt

class Graph:
  def __init__(self, edgelist = None):
    self.adjacencyList = dict()
    if edgelist == None: return
    for edge in edgelist:
      self.addNode(edge.fr)
      self.addNode(edge.to)
      self.addEdge(edge)

  def addNode(self, node):
    if node in self.adjacencyList: return
    self.adjacencyList[node] = set()

  def addEdge(self, edge):
    self.adjacencyList[edge.fr].add(edge)

  def PrintAdjacencyList(self):
    for node in self.adjacencyList:
      print(node, sep='', end=' -> ')
      for edge in self.adjacencyList[node]:
        print(f"{edge.to}[{edge.wt}]", sep='', end=' -> ')
      print("X")

edgelist = [
  Edge(1, 2),
  Edge(1, 3),
  Edge(1, 4),
  Edge(2, 3),
  Edge(3, 4),
  Edge(3, 5),
  Edge(4, 5),
]

Graph(edgelist).PrintAdjacencyList()