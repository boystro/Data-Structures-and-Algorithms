from typing import *;
from typing_extensions import *;
import queue;

class Node:
  def __init__(self:Self, val:int, left:Self|None=None, right:Self|None=None) -> None:
    self.val = val
    self.left = left
    self.right = right

  def __str__(self:Self) -> str:
    r = "";
    q:queue.Queue[Node] = queue.Queue();
    q.put(self);
    while not q.empty():
      cur = q.get();
      r += f"Node[{cur.val}]\n";
      if cur.left is not None: q.put(cur.left);
      if cur.right is not None: q.put(cur.right);

    return r;

def main() -> None:
  tree = Node(1,
    Node(2,
      Node(3),
      Node(4)
    ),
    Node(5,
      Node(6),
      Node(7)
    )
  )

  print(tree)

# Main
if __name__ == "__main__": main();