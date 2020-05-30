/**
 * Copyright 2020 @author Anmol322
 */
#include <iostream>

#include "./binary_search_tree.cpp"

int main() {
    // BST<std::vector<int>> tree;
    // tree.insert({1, 2, 3, 4, 5, 6, 7, 8});
    // tree.insert({1, 2, 4, 6, 8, 9, 10, 11, 12});

    // if (!tree.find({1, 2, 4, 6, 8, 9, 10, 11, 12})) {
    //     std::cout << "no \n";
    // }
    // BST<std::vector<int>> tree;
    // tree.insert({1, 2});
    // if (tree.find({1, 2})) {
    //     std::cout << "yes \n";
    // }
    // tree.remove({1, 2, 4, 6, 8, 9, 10, 11, 12});
    BST<int> tree;
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.remove(6);
    auto pre = tree.preOrder();
    for (auto val : pre) {
        std::cout << val << '\n';
    }
    return 0;
}
