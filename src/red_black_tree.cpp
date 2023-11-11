#include <fstream>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  // a node in the red-black-tree
  int key;
  int value;
  Node *parent;
  Node *left;
  Node *right;
  char color;
};

class MemTable
{
  // a red-black-tree based in-memory key-value buffer
private:
  Node *root;      // root
  Node *NULL_NODE; // dummy leave node
  uint size;       // number of nodes
  int min_key;
  int max_key;
};


void print_bst_level_order(Node *node){
    std::vector<Node> nodes_list;
    std::vector<std::vector<Node>> levels_list;
    std::vector<char> keys_list;

    if(node != NULL){
        nodes_list.push_back(*node);
    }

    Node current_node;
    while (!nodes_list.empty())
    {
        current_node = nodes_list.at(0);
        nodes_list.erase(nodes_list.begin());
        std::cout << "Current node is: " << current_node.key << std::endl;
        std::cout << "Length of list in the beginning of itereation: " << nodes_list.size() << std::endl;
        printf("\n");
        char current_key = '0' + current_node.key;
        keys_list.push_back(current_key);

        if (current_node.left != NULL)
        {
          std::cout << "Added as the left: " << current_node.left->key << std::endl;
          nodes_list.push_back(*current_node.left);
          printf("\n");
        }

        if (current_node.right != NULL)
        {
          std::cout << "Added as the right: " << current_node.right->key << std::endl;
          nodes_list.push_back(*current_node.right);
          printf("\n");
        }

        std::cout << "Length of list at the end of itereation: " << nodes_list.size() << std::endl;
        printf("elements at the end of iteration \n");
        for (size_t i = 0; i < nodes_list.size(); i++)
        {
          std::cout << nodes_list.at(i).key << " ";
        }
        
        printf("\n");
        printf("\n");
    }

    for (const auto& element : keys_list) {
        std::cout << element << " ";
    }
    printf("\n");
  
};

void left_rotate(Node *x){
  Node *right_child_of_rotator = x->right; // the right child of x

  if (right_child_of_rotator != NULL)
  {
    // left child of x's right subtree, becomes the new right child of x
    x->right = right_child_of_rotator->left;

    if (right_child_of_rotator->left != NULL)
    {
      right_child_of_rotator->parent = x;
    }
    // Now we are placing right child of x to x's original place
    right_child_of_rotator->parent = x->parent;

    if (x->parent != NULL)
    {
      Node *parent_of_x = x->parent;  // get the parent of x

      x->parent = right_child_of_rotator; // make right subtree of x, a child x's parent

      if (x->parent->right == x)
      {
        // x is the right child of its parent
        x->parent->right = right_child_of_rotator;
      }
      else{
        // x is the left child of its parent
        x->parent->left = right_child_of_rotator;
      }

      right_child_of_rotator->left = x;
      // x is now the left the child of its previous right subtree  
    }
    else{
      // TODO: We need to make it officially the root of the subtree!!!
      // x is the root
      // we make the right child of x, the new root
      right_child_of_rotator->color = 'b';
      // root's color must be black thus, we set the color to black
    }
    
  }
  

  
  
};

int main(){
    printf("hello\n");
    
    Node *n5 = new Node;
    n5->key = 5;
    Node *n6 = new Node;
    n6->key = 6;
    n5->right = n6;
    n6->parent = n5;

    Node *rotator = new Node;
    rotator->key = 1;
    rotator->parent = n5;
    n5->left = rotator;

    Node *n0 = new Node;
    n0->key = 0;
    n0->parent = rotator;
    rotator->left = n0;

    Node *n2 = new Node;
    n2->key = 2;
    n2->parent = rotator;
    rotator->right = n2;

    Node *t2 = new Node;
    t2->key = 2;

    print_bst_level_order(n5);
    printf("end\n");
    printf("test null control\n");
    if (t2->right == NULL && t2->left == NULL) {
        std::cout << "works" << std::endl;
    } else {
        std::cout << "it does not work" << std::endl;
    }
    return 0;

}
