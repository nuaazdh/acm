//
// Created by luerfeng on 2016/02/14.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(char c) : val(c), left(NULL), right(NULL) { }
};

TreeNode *recovery(char *preorder, int pbegin, int pend, char *inorder, int ibegin, int iend) {
    if (pbegin > pend || ibegin > iend)
        return NULL;
    TreeNode *root = new TreeNode(preorder[pbegin]);
    int root_pos = ibegin;
    while (inorder[root_pos] != preorder[pbegin]) ++root_pos;
    root->left = recovery(preorder, pbegin + 1, pbegin + (root_pos - ibegin), inorder, ibegin, root_pos - 1);
    root->right = recovery(preorder, pbegin + (root_pos - ibegin) + 1, pend, inorder, root_pos + 1, iend);
    return root;
}

void post_order(TreeNode *root) {
    if (root == NULL)
        return;
    if (root->left) post_order(root->left);
    if (root->right) post_order(root->right);
    printf("%c", root->val);
}

void post_order_traversal(TreeNode *root) {
    if (!root) return;
    std::stack<TreeNode *>s;
    s.push(root);
    TreeNode *prev = NULL;
    while (!s.empty()) {
        TreeNode *curr = s.top();
        if (!prev || prev->left == curr || prev->right == curr) {
            if (curr->left)
                s.push(curr->left);
            else if (curr->right)
                s.push(curr->right);
        } else if (curr->left == prev) {
            if (curr->right)
                s.push(curr->right);
        } else {
            printf("%c", curr->val);
            s.pop();
        }
        prev = curr;
    }
}

void free_tree(TreeNode *root) {
    if (root == NULL)
        return;
    if (root->left) free_tree(root->left);
    if (root->right) free_tree(root->right);
    delete root;
    root = NULL;
}

int main() {
    char preorder[30], inorder[30];
    int len;
    while (scanf("%s", preorder) != EOF) {
        scanf("%s", inorder);
        len = strlen(preorder);
        TreeNode *root = recovery(preorder, 0, len - 1, inorder, 0, len + 1);
        post_order_traversal(root);
        printf("\n");
        free_tree(root);
    }
    return 0;
}
