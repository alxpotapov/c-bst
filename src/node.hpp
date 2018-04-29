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
    static bool Search(shared_ptr<Node<TKey, TValue>> root, TKey key, TValue &value);
};

template <typename TKey, typename TValue>
Node<TKey, TValue>::Node(TKey key, TValue value)
{
    this->key = key;
    this->value = value;
}

template<typename TKey, typename TValue>
TValue Node<TKey, TValue>::Value() const
{
    return this->value;
}

template<typename TKey, typename TValue>
void Node<TKey, TValue>::SetValue(TValue value)
{
    this->value = value;
}

template<typename TKey, typename TValue>
string Node<TKey, TValue>::String()
{
    if (!this)
    {
        return "()";
    }
    string s = "";
    if (this->children[Child::LEFT])
    {
        s += this->children[Child::LEFT].get()->String();
    }
    s += to_string(this->key) + ":" + to_string(this->value);
    if (this->children[Child::RIGHT])
    {
        s += this->children[Child::RIGHT].get()->String();
    }
    return "(" + s + ")";
}

template<typename TKey, typename TValue>
shared_ptr<Node<TKey, TValue> > Node<TKey, TValue>::Insert(shared_ptr<Node<TKey, TValue> > root, TKey key, TValue value)
{
    if (!root)
    {
        return make_shared<Node<TKey, TValue>>(key, value);
    }

    if (root.get()->key == key)
    {
        root.get()->SetValue(value);
        return root;
    }
    if (root.get()->key > key)
    {
        root.get()->children[Child::LEFT] = Insert(root.get()->children[Child::LEFT], key, value);
        return root;
    }
    if (root.get()->key < key)
    {
        root.get()->children[Child::RIGHT] = Insert(root.get()->children[Child::RIGHT], key, value);
        return root;
    }
    return root;
}
template<typename TKey, typename TValue>
shared_ptr<Node<TKey, TValue> > Node<TKey, TValue>::Delete(shared_ptr<Node<TKey, TValue> > root, TKey key)
{
    if (!root)
    {
        return nullptr;
    }
    if (root.get()->key == key)
    {
        // no children
        if (!root.get()->children[Child::RIGHT] && !root.get()->children[Child::LEFT])
        {
            return nullptr;
        }
        // only right
        if (!root.get()->children[Child::LEFT])
        {
            return root.get()->children[Child::RIGHT];
        }
        // only left
        if (!root.get()->children[Child::RIGHT])
        {
            return root.get()->children[Child::LEFT];
        }
        // two children
        auto node = Minimum(root.get()->children[Child::RIGHT]);
        root.get()->key = node.get()->key;
        root.get()->value=node.get()->value;
        root.get()->children[Child::RIGHT] = Delete(root.get()->children[Child::RIGHT], node.get()->key);
        return root;
    }
    if (root.get()->key > key)
    {
        root.get()->children[Child::LEFT] = Delete(root.get()->children[Child::LEFT], key);
        return root;
    }
    if (root.get()->key < key)
    {
        root.get()->children[Child::RIGHT] = Delete(root.get()->children[Child::RIGHT], key);
        return root;
    }
    return root;
}
template<typename TKey, typename TValue>
bool Node<TKey, TValue>::Search(shared_ptr<Node<TKey, TValue> > root, TKey key, TValue &value)
{
    if (!root)
    {
        return false;
    }
    if (root.get()->key == key)
    {
        value = root.get()->value;
        return true;
    }
    if (root.get()->key > key)
    {
        return Search(root.get()->children[Child::LEFT], key, value);
    }
    if (root.get()->key < key)
    {
        return Search(root.get()->children[Child::RIGHT], key, value);

    }
    return false;
}

template <typename TKey, typename TValue>
shared_ptr<Node<TKey, TValue> > Node<TKey, TValue>::Minimum(shared_ptr<Node<TKey, TValue> > root)
{
    if (root.get()->children[Child::LEFT])
    {
        return Minimum(root.get()->children[Child::LEFT]);
    }
    return root;

}


#endif // NODE_H
