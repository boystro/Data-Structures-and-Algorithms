class Node:
  def __init__(self, val, left=None, right=None) -> None:
    self.val=val
    self.left=left
    self.right=right

  # DFS Algorithm
  def __str__(self):
    return f"{self.val}[{str(self.left) if self.left else '-'}|{str(self.right) if self.right else '-'}]"
    
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