#include <iostream>
#include <string>

class Node {
public:
  int val;
  Node* left;
  Node* right;

  Node(int val, Node* left = nullptr, Node* right = nullptr)
    : val(val), left(left), right(right) { }

  ~Node() {
    if (left) { delete left; }
    if (right) { delete right; }
  }

  std::string String() { 
    std::string str = "";
    str += std::to_string(val);
    str += "[";
    str += (left ? left->String() : "-");
    str += "|";
    str += (right ? right->String() : "-");
    str += "]";
    return str;
  }
};

int main() {

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

  std::cout << root->String() << std::endl;

  delete root;

  return 0;
}