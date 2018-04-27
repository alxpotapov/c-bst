#include "tree.h"

template<typename TKey, typename TValue>
void Tree<TKey, TValue>::Insert(TKey key, TValue value)
{
    if (!root)
    {
        root = make_shared<Node<TKey, TValue>>(key, value);
        return;
    }
    root = Node<TKey, TValue>::Insert(root, key, value);
}

template<typename TKey, typename TValue>
void Tree<TKey, TValue>::Delete(TKey key)
{
   root = Node<TKey, TValue>::Delete(root, key);
}

template<typename TKey, typename TValue>
bool Tree<TKey, TValue>::Find(TKey key, TValue &value)
{
    return Node<TKey, TValue>::Find(root, key, value);
}

template<typename TKey, typename TValue>
string Tree<TKey, TValue>::String()
{
    if (!root)
    {
        return "()";
    }
    return root->String();
}

template<typename TKey, typename TValue>
TValue Tree<TKey, TValue>::operator[](const TKey &key) const
{
            TValue value;
            if (Node<TKey, TValue>::Find(root, key, value))
            {
                return value;
            }
            return TValue();
}


