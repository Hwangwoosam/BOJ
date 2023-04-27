#include <iostream>
#include <vector>

class Node{
    public:
        char left;
        char right;
};

int N;
std::vector<Node> tree(26);

//root -> left -> right;
void preorder(char root){
    if(root == '.') return;

    std::cout << root;
    preorder(tree[root].left);
    preorder(tree[root].right);
}

//left -> root -> right;
void inorder(char root){
    if(root == '.') return;
    
    inorder(tree[root].left);
    std::cout << root ;
    inorder(tree[root].right);
}

//left -> right -> root
void postorder(char root){
    if(root == '.') return;

    postorder(tree[root].left);
    postorder(tree[root].right);
    std::cout << root;
}


int main(){
    std::cin >> N;
    
    for(int i = 0; i < N; i++){
        char root, lchild, rchild;
        std::cin >> root >> lchild >> rchild;
        
        tree[root].left = lchild;
        tree[root].right = rchild;
    }

    preorder('A');
    std::cout << "\n";

    inorder('A');
    std::cout << "\n";

    postorder('A');
    std::cout << "\n";
    
    return 0;
}
