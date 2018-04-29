#ifndef TREE_H_
#define TREE_H_
#include <memory>
#include <string>
#include "node.hpp"
using namespace std;

template <typename TKey, typename TValue>
class Tree {
    shared_ptr<Node<TKey, TValue>> root;
public:
    Tree(){}
    void Insert(TKey key, TValue value)
    {
        (root) ? root = Node<TKey, TValue>::Insert(root, key, value): root = make_shared<Node<TKey, TValue>>(key, value);
    }
    void Delete(TKey key)
    {
        root = Node<TKey, TValue>::Delete(root, key);
    }

    bool Search(TKey key, TValue &value)
    {
        return Node<TKey, TValue>::Search(root, key, value);
    }
    string String()
    {
        return (root) ? root->String() :"()";
    }
    TValue operator[](const TKey &key) const
    {
        TValue value;
        return (Node<TKey, TValue>::Search(root, key, value)) ? value: TValue();
    }
};



#endif
