import queue

class BinaryTreeNode:
	"""
	BinaryTreeNode : Object representing each node in a binary tree
	"""
	def __init__(self : object, data : int, left=None, right=None, /) -> None:
		"""
		ARGUMENTS
		---------------------------------------
		value : value contained by the node. by default it is set to integer
		left : the node connected to the left of the current node.
		right : the node connected to the right of the current node.
		"""
		self.data : int = data
		self.left : self = left
		self.right : self = right

class BinaryTree:
	"""
	BinaryTree: Object representing and containing methods for binary tree.
	"""
	def __init__(self : object, value : int = None) -> None:
		"""
		ARGUMENTS
		--------------------------------
		value : value of root node
		"""
		if not ( value == None ):
			self.root = BinaryTreeNode(value)
		else:
			self.root = None

	def __str__(self) -> str:
		"returns IN-ORDER-TREE-TRAVERSAL"
		def traverse(root : BinaryTreeNode, output : list):
			if (root==None):
				return
			traverse(root.left, output)
			output.append(root.data)
			traverse(root.right, output)

		output = []
		traverse(self.root, output)
		return str(output)

	@property
	def preOrder(self) -> str:
		"returns PRE-ORDER-TREE-TRAVERSAL"
		def traverse(root : BinaryTreeNode, output : list):
			if (root==None):
				return
			output.append(root.data)
			traverse(root.left, output)
			traverse(root.right, output)

		output = []
		traverse(self.root, output)
		return str(output)

	@property
	def postOrder(self) -> str:
		"returns POST-ORDER-TREE-TRAVERSAL"
		def traverse(root : BinaryTreeNode, output : list):
			if (root==None):
				return
			traverse(root.left, output)
			traverse(root.right, output)
			output.append(root.data)

		output = []
		traverse(self.root, output)
		return str(output)

	@property
	def levelOrder(self) -> str:
		"returns LEVEL-ORDER-TREE-TRAVERSAL"
		def traverse(root : BinaryTreeNode, output : list):
			if (root==None):
				return

			q : queue.Queue = queue.Queue()
			q.put(root)
			q.put(None)

			while (not q.empty()):
				current : BinaryTreeNode = q.get()
				if (current != None):
					output.append(current.data)
					if (current.left != None):
						q.put(current.left)
					if (current.right != None):
						q.put(current.right)
				elif (not q.empty()):
					q.put(None)

		output = []
		traverse(self.root, output)
		return str(output)

	def flattenTree(self):
		def flatten(root : BinaryTreeNode):
			if (root==None or (root.left==None and root.right==None)):
				return;

			if (root.left!=None):
				flatten(root.left)
				temp = root.right
				root.right = root.left
				root.left = None

				temp2 = root.right
				while temp.right!=None:
					temp2 = temp2.right
				temp2.right = temp

			flatten(root.right)

	def isBalanced(self):
		def balance(root : BinaryTreeNode, height: list):
			if root==None:
				height[0] = 0
				return True

			left, right = [0], [0]
			if (not balance(root.left, left)):
				return False
			if (not balance(root.right, right)):
				return False

			height[0]  = max(left[0], right[0]) + 1
			print(height, left, right)
			if abs(left[0]-right[0]) <= 1:
				return True
			return False

		base_height = [0]
		return balance(self.root, base_height)

def main():
	bt = BinaryTree(50)
	bt.root.left = BinaryTreeNode(25)
	bt.root.right = BinaryTreeNode(75)
	bt.root.left.left = BinaryTreeNode(12)
	bt.root.left.right = BinaryTreeNode(38)
	bt.root.right.right = BinaryTreeNode(88)

	print(bt)
	print(bt.preOrder)
	print(bt.postOrder)
	print(bt.levelOrder)
	print(bt.isBalanced())


if __name__ == '__main__':
	main()