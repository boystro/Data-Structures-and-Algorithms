#include <iostream>
#include <memory>
#include <vector>
#include <queue>

// Declarations
namespace BinaryTree
{
	struct BinaryTreeNode;
	struct BinaryTree;

	void inOrderTraversal(const std::shared_ptr<BinaryTreeNode>, std::vector<int>&);
	void preOrderTraversal(const std::shared_ptr<BinaryTreeNode>, std::vector<int>&);
	void postOrderTraversal(const std::shared_ptr<BinaryTreeNode>, std::vector<int>&);
	void levelOrderTraversal(const std::shared_ptr<BinaryTreeNode>, std::vector<int>&);
	void sumReplacement(const std::shared_ptr<BinaryTreeNode>);
	void rightView(const std::shared_ptr<BinaryTreeNode>, std::vector<int>&);
	void leftView(const std::shared_ptr<BinaryTreeNode>, std::vector<int>&);
	void flattenTree(const std::shared_ptr<BinaryTreeNode>);
	void addBinarySearchTreeNode(std::shared_ptr<BinaryTreeNode>&, int);
	
	int sumOfNodesAtNthLevel(const std::shared_ptr<BinaryTreeNode>, int N);
	int sumOfAllNodes(const std::shared_ptr<BinaryTreeNode>);
	int countNodes(const std::shared_ptr<BinaryTreeNode>);
	int height(const std::shared_ptr<BinaryTreeNode>);
	int diameter(const std::shared_ptr<BinaryTreeNode>); // O(n^2)	
	int diameter(const std::shared_ptr<BinaryTreeNode>, int*); // O(n)
	int findDistance(const std::shared_ptr<BinaryTreeNode>, int, int);
	int distanceBetweenNodes(const std::shared_ptr<BinaryTreeNode>, int, int);

	bool isBalanced(const std::shared_ptr<BinaryTreeNode>); // O(n^2)
	bool isBalanced(const std::shared_ptr<BinaryTreeNode>, int*); // O(n)

	std::shared_ptr<BinaryTreeNode> rootNodeFromPreOrderAndInOrderArray(std::vector<int>&, std::vector<int>&, int, int);
	std::shared_ptr<BinaryTreeNode> rootNodeFromPostOrderAndInOrderArray(std::vector<int>&, std::vector<int>&, int, int);
	std::shared_ptr<BinaryTreeNode> lowestCommonAncestor(const std::shared_ptr<BinaryTreeNode>, int, int);

	BinaryTree binaryTreeFromPreOrderAndInOrderArray(std::vector<int>&, std::vector<int>&);
	BinaryTree binaryTreeFromPostOrderAndInOrderArray(std::vector<int>&, std::vector<int>&);
	BinaryTree binarySearchTree(std::vector<int>&);

}

// Definations
namespace BinaryTree
{
	struct BinaryTreeNode {
		int data;
		std::shared_ptr<BinaryTreeNode> left;
		std::shared_ptr<BinaryTreeNode> right;

		BinaryTreeNode(int value)
			: data(value), left(nullptr), right(nullptr) {}

		BinaryTreeNode(int value, std::shared_ptr<BinaryTreeNode>& left, std::shared_ptr<BinaryTreeNode>& right)
			: data(value), left(left), right(right) {}
	};

	struct BinaryTree {
		std::shared_ptr<BinaryTreeNode> root;

		BinaryTree()
			: root(nullptr) {}

		BinaryTree(int value)
			: root(std::shared_ptr<BinaryTreeNode>(new BinaryTreeNode(value))) {}

		BinaryTree(std::shared_ptr<BinaryTreeNode> root)
			: root(root) {}

		const void logInOrderTraversal() const 
		{
			std::cout << "[BINARY TREE IN-ORDER TRAVERSAL]\n";
			std::vector<int> vec;
			inOrderTraversal(root, vec);
			for (int data : vec) std::cout << data << " ";
			std::cout << std::endl;
		}

		const void logPreOrderTraversal() const 
		{
			std::cout << "[BINARY TREE PRE-ORDER TRAVERSAL]\n";
			std::vector<int> vec;
			preOrderTraversal(root, vec);
			for (int data : vec) std::cout << data << " ";
			std::cout << std::endl;
		}

		const void logPostOrderTraversal() const 
		{
			std::cout << "[BINARY TREE POST-ORDER TRAVERSAL]\n";
			std::vector<int> vec;
			postOrderTraversal(root, vec);
			for (int data : vec) std::cout << data << " ";
			std::cout << std::endl;
		}

		const void logLevelOrderTraversal() const
		{
			std::cout << "[BINARY TREE LEVEL-ORDER TRAVERSAL]\n";
			std::vector<int> vec;
			levelOrderTraversal(root, vec);
			for (int data : vec) std::cout << data << " ";
			std::cout << std::endl;
		}

		const void log() const
		{
			logInOrderTraversal();
			logPreOrderTraversal();
			logPostOrderTraversal();
			logLevelOrderTraversal();
		}

		const void logRightView() const
		{
			std::cout << "[Right View]\n";
			std::vector<int> vec;
			rightView(root, vec);
			for (int data : vec) std::cout << data << " ";
			std::cout << std::endl;
		}

		const void logLeftView() const
		{
			std::cout << "[Left View]\n";
			std::vector<int> vec;
			leftView(root, vec);
			for (int data : vec) std::cout << data << " ";
			std::cout << std::endl;
		}


		void doSumReplacement()
		{
			sumReplacement(root);
		}

		void flatten()
		{
			flattenTree(root);
		}


		int getSumOfNodesAtNthLevel(int level) const
		{ return sumOfNodesAtNthLevel(root, level); }

		int getSumOfAllNodes() const
		{
			return sumOfAllNodes(root);
		}

		int getNumberOfNodes() const
		{
			return countNodes(root);
		}

		int getHeight() const
		{
			return height(root);
		}

		int getDiameter() const
		{
			int h=0;
			return diameter(root, &h);
		}

		int getDistanceBetweenNodes(int n1, int n2) const
		{
			return distanceBetweenNodes(root, n1, n2);
		}


		bool isTreeBalanced()
		{
			int height=0;
			return isBalanced(root, &height);
		}
	};

	// Used by Traversal Functions
	int search(std::vector<int>& inOrder, int start, int end, int data)
	{
		for (int i = start; i <= end; i++)
			if (inOrder[i] == data)
				return i;

		return -1;
	}

	// Binary Tree Traversal in the form [LEFT] [ROOT] [RIGHT]
	void inOrderTraversal(const std::shared_ptr<BinaryTreeNode> node, std::vector<int>& vec)
	{
		if (node == nullptr) return;

		inOrderTraversal(node->left, vec);
		vec.emplace_back(node->data);
		inOrderTraversal(node->right, vec);
	}

	// Binary Tree Traversal in the form [ROOT] [LEFT] [RIGHT]
	void preOrderTraversal(const std::shared_ptr<BinaryTreeNode> node, std::vector<int>& vec)
	{
		if (node == nullptr) return;

		vec.emplace_back(node->data);
		preOrderTraversal(node->left, vec);
		preOrderTraversal(node->right, vec);
	}

	// Binary Tree Traversal in the form [LEFT] [RIGHT] [ROOT]
	void postOrderTraversal(const std::shared_ptr<BinaryTreeNode> node, std::vector<int>& vec)
	{
		if (node == nullptr) return;

		postOrderTraversal(node->left, vec);
		postOrderTraversal(node->right, vec);
		vec.emplace_back(node->data);
	}

	// Binary Tree Traversal where each level is printed first [LEVEL 1] [LEVEL 2] . . .
	void levelOrderTraversal(const std::shared_ptr<BinaryTreeNode> root, std::vector<int>& vec)
	{
		if (root == nullptr)
			return;

		std::queue<std::shared_ptr<BinaryTreeNode>> q;
		q.push(root);
		q.push(nullptr);

		while (!q.empty())
		{
			std::shared_ptr<BinaryTreeNode> currentNode = q.front();
			q.pop();

			if (currentNode != nullptr)
			{
				vec.emplace_back(currentNode->data);

				if (currentNode->left != nullptr)
					q.push(currentNode->left);

				if (currentNode->right != nullptr)
					q.push(currentNode->right);
			}

			else if (!q.empty())
				q.push(nullptr);
		}
	}

	// Replace each node with sum of all child nodes and self
	void sumReplacement(const std::shared_ptr<BinaryTreeNode> root)
	{
		if (root == nullptr)
			return;

		sumReplacement(root->left);
		sumReplacement(root->right);

		if (root->left != nullptr)
			root->data += root->left->data;

		if (root->right != nullptr)
			root->data += root->right->data;
	}

	// Right View of Binary Tree
	void rightView(const std::shared_ptr<BinaryTreeNode> root, std::vector<int>& vec)
	{
		if (root == nullptr)
			return;

		std::queue<std::shared_ptr<BinaryTreeNode>> q;
		q.push(root);

		while (!q.empty())
		{
			int n = q.size();
			for (int i = 0; i < n; i++)
			{
				std::shared_ptr<BinaryTreeNode> currentNode = q.front();
				q.pop();
				
				if (i == n - 1)
					vec.emplace_back(currentNode->data);

				if (currentNode->left != nullptr)
					q.push(currentNode->left);

				if (currentNode->right != nullptr)
					q.push(currentNode->right);
			}
		}
	}

	// Left View of Binary Tree
	void leftView(const std::shared_ptr<BinaryTreeNode> root, std::vector<int>& vec)
	{
		if (root == nullptr)
			return;

		std::queue<std::shared_ptr<BinaryTreeNode>> q;
		q.push(root);

		while (!q.empty())
		{
			int n = q.size();
			for (int i = 0; i < n; i++)
			{
				std::shared_ptr<BinaryTreeNode> currentNode = q.front();
				q.pop();

				if (i == 0)
					vec.emplace_back(currentNode->data);

				if (currentNode->left != nullptr)
					q.push(currentNode->left);

				if (currentNode->right != nullptr)
					q.push(currentNode->right);
			}
		}
	}

	// Flatten a binary tree or -> converting BT to Linked List by rearranging the nodes
	void flattenTree(const std::shared_ptr<BinaryTreeNode> root)
	{
		if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return;

		if (root->left != nullptr)
		{
			flattenTree(root->left);
			std::shared_ptr<BinaryTreeNode> temp = root->right;
			root->right = root->left;
			root->left = nullptr;

			std::shared_ptr<BinaryTreeNode> temp2=root->right;
			while (temp2->right != nullptr) temp2 = temp2->right;
			temp2->right = temp;
		}
		flattenTree(root->right);
	}

	// Find nodes at distance K
	void findNodesInSubtreeAtDistance(const std::shared_ptr<BinaryTreeNode> root, int k, std::vector<int>& vec)
	{
		if (root == nullptr || k < 0) return;

		if (root->data == k)
		{
			vec.emplace_back(root->data);
			return;
		}

		findNodesInSubtreeAtDistance(root->left, k - 1, vec);
		findNodesInSubtreeAtDistance(root->right, k - 1, vec);
	}

	// Add Binary Search Tree (bst) node
	void addBinarySearchTreeNode(std::shared_ptr<BinaryTreeNode>& root, int val)
	{
		if (root == nullptr)
		{
			root = std::shared_ptr<BinaryTreeNode>(new BinaryTreeNode(val));
			std::cout << root->data;
			return;
		}

		if (val < root->data)
			addBinarySearchTreeNode(root->left, val);
		if (val >= root->data)
			addBinarySearchTreeNode(root->right, val);
	}


	// Returns all nodes at distance K from Root
	int findNodesAtK(const std::shared_ptr<BinaryTreeNode> root, const std::shared_ptr<BinaryTreeNode> target, int k, std::vector<int>& vec)
	{
		if (root == nullptr) return -1;

		if (root == target)
		{
			findNodesInSubtreeAtDistance(root, k, vec);
			return 0;
		}

		int dl = findNodesAtK(root->left, target, k, vec);
		if (dl != -1)
		{
			if (dl + 1 == k) vec.emplace_back();
		}
		findNodesAtK(root->right, target, k, vec);
	}

	// Sum of nodes present at level N
	int sumOfNodesAtNthLevel(const std::shared_ptr<BinaryTreeNode> root, int N)
	{
		if (root == nullptr)
			return -1;

		std::queue<std::shared_ptr<BinaryTreeNode>> q;
		q.push(root);
		q.push(nullptr);

		int level = 0;	// Level of current Traversal
		int sum = 0;	// Sum of all nodes at Nth Level

		while (!q.empty())
		{
			std::shared_ptr<BinaryTreeNode> node = q.front();
			q.pop();

			if (node != nullptr)
			{
				if (level == N)
					sum += node->data;

				if (node->left != nullptr)
					q.push(node->left);
				if (node->right != nullptr)
					q.push(node->right);
			}
			else if (!q.empty())
			{
				q.push(nullptr);
				level++;
			}
		}

		return sum;
	}

	// Sum of All Nodes
	int sumOfAllNodes(const std::shared_ptr<BinaryTreeNode> node)
	{
		if (node == nullptr)
			return 0;
		return sumOfAllNodes(node->left) + sumOfAllNodes(node->right) + node->data;
	}

	// Returns the number of nodes in tree
	int countNodes(const std::shared_ptr<BinaryTreeNode> node)
	{
		if (node == nullptr)
			return 0;
		return 1 + countNodes(node->left) + countNodes(node->right);
	}

	// Calculates the max distance between the root and any leaf of the tree
	int height(const std::shared_ptr<BinaryTreeNode> root)
	{
		if (root == nullptr) return 0;
		int lheight = height(root->left);
		int rheight = height(root->right);
		return std::max(lheight, rheight) + 1;
	}

	// Calculates the max distance between two leaf nodes ( which may or may not pass through root node ) // O(n^2)
	int diameter(const std::shared_ptr<BinaryTreeNode> root)
	{
		if (root == nullptr) return 0;

		int leftHeight = height(root->left);
		int rightHeight = height(root->right);

		int currentDiameter = leftHeight + rightHeight + 1;
		int leftDiameter = diameter(root->left);
		int rightDiameter = diameter(root->right);

		return std::max(currentDiameter, std::max(leftDiameter, rightDiameter));
	}

	// Diameter with time complexity O(n)
	int diameter(const std::shared_ptr<BinaryTreeNode> root, int* height)
	{
		if (root == nullptr)
		{
			*height = 0;
			return 0;
		}

		int lh = 0;
		int rh = 0;

		int ldia = diameter(root->left, &lh);
		int rdia = diameter(root->right, &rh);

		int curh = lh + rh + 1;
		*height = std::max(lh, rh) + 1;

		return std::max(curh, std::max(lh, rh));
	}

	// Returns distance between root and child node
	int findDistance(const std::shared_ptr<BinaryTreeNode> root, int k, int currentDistance)
	{
		if (root == nullptr) return -1;
		if (root->data == k) return currentDistance;

		int left = findDistance(root->left, k, currentDistance + 1);
		if (left != -1) return left;

		return findDistance(root->right, k, currentDistance + 1);
	}

	// Calculates distance between two nodes
	int distanceBetweenNodes(const std::shared_ptr<BinaryTreeNode> root, int n1, int n2)
	{
		std::shared_ptr<BinaryTreeNode> lca = lowestCommonAncestor(root, n1, n2);

		int d1 = findDistance(root, n1, 0);
		int d2 = findDistance(root, n2, 0);

		if (d1 != -1 && d2 != -1) return d1 + d2;
		return -1;
	}


	// Checks if the Binary Tree is balanced i.e. | no. of left nodes - no. of right nodes | <= 1
	bool isBalanced(const std::shared_ptr<BinaryTreeNode> root)
	{
		if (root == nullptr)
			return true;

		if (!isBalanced(root->left)) return false;
		if (!isBalanced(root->right)) return false;

		int lh = height(root->left);
		int rh = height(root->right);

		if (std::abs(rh - lh) <= 1) return true;
		return false;
	}

	bool isBalanced(const std::shared_ptr<BinaryTreeNode> root, int* height)
	{
		if (root == nullptr)
		{
			height = 0;
			return true;
		}

		int lh = 0, rh = 0;
		if (!isBalanced(root->left, &lh)) return false;
		if (!isBalanced(root->right, &rh)) return false;

		*height = std::max(lh, rh) + 1;

		if (std::abs(lh - rh) <= 1) return true;
		return false;
	}


	// Returns a Binary Tree Root Pointer built from preorder and inorder array of the tree
	std::shared_ptr<BinaryTreeNode> rootNodeFromPreOrderAndInOrderArray(std::vector<int>& preOrder, std::vector<int>& inOrder, int start, int end)
	{
		if (start > end) return nullptr;

		static int currentNodeIndex = 0; // Index of currently processing node from the 'preOrder' list

		std::shared_ptr<BinaryTreeNode> node(new BinaryTreeNode(preOrder[currentNodeIndex]));
		currentNodeIndex++;
		if (start == end) return node;

		int position = search(inOrder, start, end, node->data);
		node->left = rootNodeFromPreOrderAndInOrderArray(preOrder, inOrder, start, position - 1);
		node->right = rootNodeFromPreOrderAndInOrderArray(preOrder, inOrder, position + 1, end);

		return node;
	}

	// Returns a Binary Tree Root Pointer built from postorder and inorder array of the tree
	std::shared_ptr<BinaryTreeNode> rootNodeFromPostOrderAndInOrderArray(std::vector<int>& postOrder, std::vector<int>& inOrder, int start, int end)
	{
		if (start > end) return nullptr;

		static int currentNodeIndex = postOrder.size() - 1;

		std::shared_ptr<BinaryTreeNode> node(new BinaryTreeNode(postOrder[currentNodeIndex]));
		currentNodeIndex--;
		if (start == end) return node;

		int position = search(inOrder, start, end, node->data);
		node->right = rootNodeFromPostOrderAndInOrderArray(postOrder, inOrder, position + 1, end);
		node->left = rootNodeFromPostOrderAndInOrderArray(postOrder, inOrder, start, position - 1);

		return node;
	}

	// LCA or lowest common ancestor
	std::shared_ptr<BinaryTreeNode> lowestCommonAncestor(std::shared_ptr<BinaryTreeNode> root, int n1, int n2)
	{
		if (root == nullptr) return nullptr;
		
		if (root->data == n1 || root->data == n2) return root;

		std::shared_ptr<BinaryTreeNode> left = lowestCommonAncestor(root->left, n1, n2);
		std::shared_ptr<BinaryTreeNode> right = lowestCommonAncestor(root->right, n1, n2);

		if (left != nullptr && right != nullptr) return root;
		if (left == nullptr && right == nullptr) return nullptr;
		if (left != nullptr) return left;
		return right;
	}


	// Returns a Binary Tree Object built from PreOrder and In Order Arrays of the tree
	BinaryTree binaryTreeFromPreOrderAndInOrderArray(std::vector<int>& preOrder, std::vector<int>& inOrder)
	{
		if (preOrder.size() != inOrder.size()) return BinaryTree();
		return BinaryTree(rootNodeFromPreOrderAndInOrderArray(preOrder, inOrder, 0, preOrder.size()-1));
	}

	// Returns a Binary Tree Object built from PostOrder and In Order Arrays of the tree
	BinaryTree binaryTreeFromPostOrderAndInOrderArray(std::vector<int>& postOrder, std::vector<int>& inOrder)
	{
		if (postOrder.size() != postOrder.size()) return BinaryTree();
		return BinaryTree(rootNodeFromPostOrderAndInOrderArray(postOrder, inOrder, 0, postOrder.size() - 1));
	}

	// Generate a Binary Search Tree
	BinaryTree binarySearchTree(std::vector<int>& arr)
	{
		BinaryTree r;
		for (int data : arr)
			addBinarySearchTreeNode(r.root, data);

		return r;
	}
	
}

void testBinaryTree()
{
	std::cout << "Executing Binary Tree Test !\n";
	BinaryTree::BinaryTree bt(50);

	bt.root->left = std::shared_ptr<BinaryTree::BinaryTreeNode>(new BinaryTree::BinaryTreeNode(40));
	bt.root->left->left = std::shared_ptr<BinaryTree::BinaryTreeNode>(new BinaryTree::BinaryTreeNode(30));
	bt.root->left->right = std::shared_ptr<BinaryTree::BinaryTreeNode>(new BinaryTree::BinaryTreeNode(35));

	bt.root->right = std::shared_ptr<BinaryTree::BinaryTreeNode>(new BinaryTree::BinaryTreeNode(60));
	bt.root->right->right = std::shared_ptr<BinaryTree::BinaryTreeNode>(new BinaryTree::BinaryTreeNode(70));

	bt.log();

	int level = 2;
	std::cout << "Sum at Level " << level << " : " << bt.getSumOfNodesAtNthLevel(level) << "\n";
	std::cout << "Sum of All Nodes : " << bt.getSumOfAllNodes() << "\n";
	std::cout << "Number of nodes : " << bt.getNumberOfNodes() << "\n";
	std::cout << "Height of tree : " << bt.getHeight() << "\n";
	std::cout << "Diameter : " << bt.getDiameter() << "\n";
	std::cout << "Distance between 35 and 70 : " << bt.getDistanceBetweenNodes(35, 70) << std::endl;
}

void testBinaryTree2()
{
	std::cout << "\n\nExecuting Binary Tree from PreOrder and InOrder Array\n";

	std::vector<int> preOrder = { 1, 2, 4, 3, 5 };
	std::vector<int> inOrder = { 4, 2, 1, 5, 3 };

	BinaryTree::BinaryTree bt = BinaryTree::binaryTreeFromPreOrderAndInOrderArray(preOrder, inOrder);

	bt.log();
	bt.logRightView();
	bt.logLeftView();
}

void testBinaryTree3()
{
	std::cout << "\n\nExecuting Binary Tree form PostOrder and InOrder Array\n";

	std::vector<int> postOrder = { 4, 2, 5, 3, 1 };
	std::vector<int> inOrder = { 4, 2, 1, 5, 3 };

	BinaryTree::BinaryTree bt = BinaryTree::binaryTreeFromPostOrderAndInOrderArray(postOrder, inOrder);

	bt.log();
	std::cout << "Binary Tree is " << ( bt.isTreeBalanced() ? "blanced.\n" : "not balanced.\n");

	std::cout << "Done Sume Replacement\n";
	bt.doSumReplacement();
	bt.log();
}

void testBinaryTree4()
{
	BinaryTree::BinaryTree bt(4);
	bt.root->left = std::shared_ptr<BinaryTree::BinaryTreeNode>(new BinaryTree::BinaryTreeNode(9));
	bt.root->right = std::shared_ptr<BinaryTree::BinaryTreeNode>(new BinaryTree::BinaryTreeNode(5));
	bt.root->left->left = std::shared_ptr<BinaryTree::BinaryTreeNode>(new BinaryTree::BinaryTreeNode(1));
	bt.root->left->right = std::shared_ptr<BinaryTree::BinaryTreeNode>(new BinaryTree::BinaryTreeNode(3));
	bt.root->right->right = std::shared_ptr<BinaryTree::BinaryTreeNode>(new BinaryTree::BinaryTreeNode(6));

	bt.flatten();
	bt.logPreOrderTraversal();
}

void testBinaryTree5()
{
	std::vector<int> arr = { 5, 1, 3, 4, 2, 7 };
	BinaryTree::BinaryTree bt = BinaryTree::binarySearchTree(arr);

	bt.log();
}

int main()
{
	testBinaryTree();
	testBinaryTree2();
	testBinaryTree3();
	testBinaryTree4();
	testBinaryTree5();
}