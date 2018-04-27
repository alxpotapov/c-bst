#ifndef TREE_H_
#define TREE_H_
#include <memory>
#include <string>
#include "node.h"
using namespace std;

template <typename TKey, typename TValue>
class Tree {
    shared_ptr<Node<TKey, TValue>> root;
public:
    Tree(){}
    void Insert(TKey key, TValue value);
    void Delete(TKey key);
    bool Find(TKey key, TValue &value);
    string String();
    TValue operator[](const TKey &key) const;
};

#include "../src/tree.cpp"

#endif
