//
// Created by luerfeng on 2016/01/26.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <iostream>
#include <vector>
#include <sstream>

const int max_size = 10100;

int inorder[max_size];
int postorder[max_size];
int min_path, min_node;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

TreeNode *build_tree(int in_beg, int in_end, int post_beg, int pos_end) {
    if (in_end < in_beg || pos_end < post_beg || (pos_end - post_beg != in_end - in_beg))
        return NULL;
    TreeNode *root = new TreeNode(postorder[pos_end]);
    int root_pos = in_beg;
    while (inorder[root_pos] != postorder[pos_end] && root_pos <= in_end) ++root_pos;
    if (root_pos > in_end)
        return root;
    root->left = build_tree(in_beg, root_pos - 1, post_beg, post_beg + (root_pos - in_beg) - 1);
    root->right = build_tree(root_pos + 1, in_end, pos_end - (in_end - root_pos), pos_end - 1);
    return root;
}

void find_min_path(TreeNode *root, int parent) {
    if (!root)
        return;
    if (!(root->left || root->right)) {
        if (min_node == 0) {
            min_node = root->val;
        }
        if (parent + root->val < min_path) {
            min_path = parent + root->val;
            min_node = root->val;
        } else if (parent + root->val == min_path && min_node > root->val) {
            min_node = root->val;
        }
    }
    find_min_path(root->left, parent + root->val);
    find_min_path(root->right, parent + root->val);
}

void free_root(TreeNode *root) {
    if (!root)
        return;
    if (!(root->left || root->right)) {
        delete root;
        root = NULL;
        return;
    }
    if(root->left) free_root(root->left);
    if(root->right) free_root(root->right);
    delete root;
    root = NULL;
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        min_path = 0, min_node = 0;
        std::stringstream ss(line);
        int i = 0;
        while (ss >> inorder[i]) { min_path += inorder[i], ++i; }
        std::getline(std::cin, line);
        std::stringstream ss2(line);
        i = 0;
        while (ss2 >> postorder[i]) ++i;
        TreeNode *root = build_tree(0, i - 1, 0, i - 1);
        find_min_path(root, 0);
        std::cout << min_node << std::endl;
        free_root(root);
    }
}