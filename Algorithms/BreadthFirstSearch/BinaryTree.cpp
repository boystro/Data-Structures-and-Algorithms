#include <iostream>
#include <string>
#include <queue>
#include <vector>

class Node
{
  int val;
  Node* left;
  Node* right;

public:

  Node(int val, Node* left = nullptr, Node* right = nullptr)
    : val(val), left(left), right(right) { }

  ~Node()
  {
    if (left != nullptr) delete left;
    if (right != nullptr) delete right;
  }

  std::vector<int> Print()
  {
    std::vector<int> returnSequence;
    std::queue<Node*> q;
    q.push(this);
    while (!q.empty())
    {
      if (q.front() == nullptr) {
        q.pop();
        continue;
      }
      returnSequence.emplace_back(q.front()->val);
      q.push(q.front()->left);
      q.push(q.front()->right);
      q.pop();
    }

    return returnSequence;
  }
};

std::ostream& operator<<(std::ostream& stream, const std::vector<int>& vec)
{
  stream << "{ ";
  for (int i = 0; i < vec.size(); i++) stream << vec[i] << (i == vec.size()-1 ? "" : ", ");
  stream << " }";
  return stream;
}

int main() 
{
  Node* root = new Node(1,
    new Node(2,
      new Node(4),
      new Node(5)
    ),
    new Node(3,
      new Node(6),
      new Node(7)
    )
  );

  std::cout << root->Print() << std::endl;

  delete root;

  return 0;
}