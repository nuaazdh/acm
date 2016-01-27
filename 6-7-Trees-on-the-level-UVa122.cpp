//
// Created by luerfeng on 2016/01/25.
// Description:
// copyright (c) luerfeng 2016, all rights reserved
//

#include <iostream>
#include <vector>

struct btnode {
    int val;
    btnode *left;
    btnode *right;

    btnode(int v) : val(v), left(NULL), right(NULL) { }
};

void tree_on_level(btnode *root) {
    std::vector<btnode *> tree;
    bool flag = true;
    tree.push_back(root);
    int i = 0;
    while (1) {
        if (i > tree.size() - 1) {
            break;
        }
        if (tree[i] == NULL) {
            flag = false;
            break;
        }
        if (tree[i]->val == 0) {
            flag = false;
            break;
        }
//        std::cout<<"root: "<<tree[i]->val;
        if (tree[i]->left) {
            tree.push_back(tree[i]->left);
//            std::cout<<"\tleft:"<<tree[i]->left->val;
        }
        if (tree[i]->right) {
            tree.push_back(tree[i]->right);
//            std::cout<<"\tright:"<<tree[i]->right->val<<"\n";
        }
        ++i;
    }
    if (flag) {
        for (i = 0; i < tree.size(); ++i) {
            if (i) std::cout << " ";
            std::cout << tree[i]->val;
            delete tree[i];
        }
    } else {
        std::cout << "not complete";
    }
    std::cout << "\n";
}

int main() {
    std::string line;
    while (std::cin >> line) {
        btnode *root = new btnode(0);
        bool valid = true;
        do {
            int val = 0;
            int i;
            for (i = 1; i < line.length() && line[i] != ','; ++i) {
                val = val * 10 + (line[i] - '0');
            }
            if (val == 0) { valid = false; }
            btnode *ptr = root;
            for (++i; i < line.length(); ++i) {
                if (line[i] == 'L') {
                    if (ptr->left == NULL) {
                        ptr->left = new btnode(0);
                    }
                    ptr = ptr->left;
                } else if (line[i] == 'R') {
                    if (ptr->right == NULL) {
                        ptr->right = new btnode(0);
                    }
                    ptr = ptr->right;
                } else {

                }
            }
            if (ptr->val != 0) {
                valid = false;
            }
            ptr->val = val;
        } while (std::cin >> line && line != "()");
        if (valid) tree_on_level(root);
        else {
            std::cout << "not complete\n";
        }
    }
}
