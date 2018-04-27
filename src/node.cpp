#include "node.h"

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
    if (this == nullptr) {
        return "()";
    }
    string s = "";
    if (this->children[Child::LEFT] != nullptr)
    {
        s += this->children[Child::LEFT].get()->String();
    }
    s += to_string(this->key) + ":" + to_string(this->value);
    if (this->children[Child::RIGHT] != nullptr)
    {
        s += this->children[Child::RIGHT].get()->String();
    }
    return "(" + s + ")";
}

template<typename TKey, typename TValue>
shared_ptr<Node<TKey, TValue> > Node<TKey, TValue>::Insert(shared_ptr<Node<TKey, TValue> > root, TKey key, TValue value)
{
    if (root == nullptr)
    {
        return make_shared<Node<TKey, TValue>>(key, value);
    }

    if (root.get()->key == key)
    {
        root.get()->SetValue(value);
    }
    else if (root.get()->key > key)
    {
        root.get()->children[Child::LEFT] = Insert(root.get()->children[Child::LEFT], key, value);
    }
    else if (root.get()->key < key)
    {
        root.get()->children[Child::RIGHT] = Insert(root.get()->children[Child::RIGHT], key, value);
    }
    return root;
}
