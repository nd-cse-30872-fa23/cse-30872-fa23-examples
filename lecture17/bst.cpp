// bst: binary search tree

#include <iomanip>
#include <iostream>

using namespace std;

// Structures

typedef struct Node Node;
struct Node {
    int   value;
    Node *left;
    Node *right;
};

typedef struct Tree Tree;
struct Tree {
    Node *root;
};

// Functions

Node*	tree_insert_r(Tree *tree, Node *node, int value) {
    // Base case: No node, so create one
    if (node == nullptr) {
    	return new Node{value, nullptr, nullptr};
    }

    // Recursive: go left if value is than current node value
    if (value < node->value) {
    	node->left  = tree_insert_r(tree, node->left, value);
    } else {   // go right
    	node->right = tree_insert_r(tree, node->right, value);
    }

    return node;
}

void	tree_insert(Tree *tree, int value) {
    tree->root = tree_insert_r(tree, tree->root, value);
}

bool	tree_search_r(Tree *tree, Node *node, int value) {
    // Base case: No node, so missing
    if (node == nullptr) {
    	return false;
    }

    // Base case: Found
    if (value == node->value) {
    	return true;
    }

    // Recursive: go left if value is than current node value
    if (value < node->value) {
    	return tree_search_r(tree, node->left, value);
    } else {   // go right
    	return tree_search_r(tree, node->right, value);
    }
}

bool	tree_search(Tree *tree, int value) {
    return tree_search_r(tree, tree->root, value);
}

void	tree_print_r(Tree *tree, Node *node) {
    if (node == nullptr) {
    	return;
    }

    tree_print_r(tree, node->left);
    cout << node->value << endl;
    tree_print_r(tree, node->right);
}

void	tree_print(Tree *tree) {
    tree_print_r(tree, tree->root);
}

// Main Execution

int main(int argc, char *argv[]) {
    Tree *tree = new Tree();

    for (int i = 1; i < argc; i++) {
    	tree_insert(tree, atoi(argv[i]));
    }
    
    for (int i = 1; i < argc; i++) {
    	int number = atoi(argv[i]);
    	cout << number   << " " << boolalpha << tree_search(tree, number) << endl;
    	cout << 2*number << " " << boolalpha << tree_search(tree, 2*number) << endl;
    }

    tree_print(tree);

    return 0;
}
