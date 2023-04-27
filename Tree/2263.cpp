#include <iostream>

int N;

int inorder[100001];
int preorder[100001];
int postorder[100001];
int idx[100001];

void get_preorder(int in_start,int in_end,int po_start,int po_end){
    if(in_start > in_end || po_start > po_end) return;

    int root_idx = idx[postorder[po_end]];
    int left_size = root_idx - in_start;
    int right_size = in_end - root_idx;

    std::cout << inorder[root_idx] << ' ';
    get_preorder(in_start,root_idx-1,po_start,po_start+left_size-1);
    get_preorder(root_idx+1,in_end,po_start + left_size,po_end-1);
}

int main(){
    std::cin >> N;

    for(int i = 1; i <= N; i++){
        std::cin >> inorder[i];
        idx[inorder[i]] = i;
    }

    for(int i = 1; i <= N; i++){
        std::cin >> postorder[i];
    }

    get_preorder(1,N,1,N);

    return 0;
}