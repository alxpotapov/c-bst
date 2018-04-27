#ifndef NODE_H
#define NODE_H
#include <memory>
#include <string>

using namespace std;

template <typename TKey, typename TValue>
class Tree;

template <typename TKey, typename TValue>
class Node
{
    enum Child {LEFT, RIGHT};
    shared_ptr<Node> children[2];
    TKey key;
    TValue value;
    static shared_ptr<Node<TKey, TValue>> Minimum(shared_ptr<Node<TKey, TValue>> root);
    friend class Tree <TKey, TValue>;
public:
    Node(TKey key, TValue value);
    TValue Value()const;
    void SetValue(TValue value);
    string String();
    static shared_ptr<Node<TKey, TValue>> Insert(shared_ptr<Node<TKey, TValue>> root, TKey key, TValue value);
    static shared_ptr<Node<TKey, TValue>> Delete(shared_ptr<Node<TKey, TValue>> root, TKey key);
    static bool Find(shared_ptr<Node<TKey, TValue>> root, TKey key, TValue &value);
};

#include "../src/node.cpp"

#endif // NODE_H
