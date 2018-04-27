#include <boost/test/unit_test.hpp>

#include "node.h"
#include <memory>
using  namespace std;

BOOST_AUTO_TEST_CASE(Node_test)
{
    shared_ptr<Node<int, int>> node = make_shared<Node<int, int>>(1, 1);
    BOOST_CHECK(node != nullptr);
}

BOOST_AUTO_TEST_CASE(SetValue_test)
{
    shared_ptr<Node<int, int>> node = make_shared<Node<int, int>>(1, 1);
    node.get()->SetValue(2);
    BOOST_CHECK_EQUAL(node.get()->Value(), 2);
}

BOOST_AUTO_TEST_CASE(Insert_test)
{
    shared_ptr<Node<int, int>> node = make_shared<Node<int, int>>(1, 1);
    node = Node<int, int>::Insert(node, 2, 2);
    node = Node<int, int>::Insert(node, 0, 0);
    BOOST_CHECK_EQUAL(node.get()->Value(), 1);
}

BOOST_AUTO_TEST_CASE(String_test)
{
    shared_ptr<Node<int, int>> node = make_shared<Node<int, int>>(1, 1);
    node = Node<int, int>::Insert(node, 2, 2);
    node = Node<int, int>::Insert(node, 0, 0);
    BOOST_CHECK_EQUAL(node.get()->String(), "((0:0)1:1(2:2))");
}

BOOST_AUTO_TEST_CASE(Delete_test)
{
    shared_ptr<Node<int, int>> node = make_shared<Node<int, int>>(1, 1);
    node = Node<int, int>::Insert(node, 0, 0);
    node = Node<int, int>::Insert(node, 3, 3);
    node = Node<int, int>::Insert(node, 2, 2);
    node = Node<int, int>::Insert(node, 5, 5);
    node = Node<int, int>::Insert(node, 4, 4);
    node = Node<int, int>::Insert(node, 6, 6);
    node = Node<int, int>::Insert(node, 7, 7);
    BOOST_CHECK_EQUAL(node.get()->String(), "((0:0)1:1((2:2)3:3((4:4)5:5(6:6(7:7)))))");
    node = Node<int, int>::Delete(node, 3);
    BOOST_CHECK_EQUAL(node.get()->String(), "((0:0)1:1((2:2)4:4(5:5(6:6(7:7)))))");
    node = Node<int, int>::Delete(node, 7);
    BOOST_CHECK_EQUAL(node.get()->String(), "((0:0)1:1((2:2)4:4(5:5(6:6))))");
    node = Node<int, int>::Delete(node, 1);
    BOOST_CHECK_EQUAL(node.get()->String(), "((0:0)2:2(4:4(5:5(6:6))))");
    node = Node<int, int>::Delete(node, 5);
    BOOST_CHECK_EQUAL(node.get()->String(), "((0:0)2:2(4:4(6:6)))");
    node = Node<int, int>::Delete(node, 2);
    BOOST_CHECK_EQUAL(node.get()->String(), "((0:0)4:4(6:6))");
    node = Node<int, int>::Delete(node, 7);
    BOOST_CHECK_EQUAL(node.get()->String(), "((0:0)4:4(6:6))");
    node = Node<int, int>::Delete(node, 0);
    BOOST_CHECK_EQUAL(node.get()->String(), "(4:4(6:6))");
    node = Node<int, int>::Delete(node, 4);
    BOOST_CHECK_EQUAL(node.get()->String(), "(6:6)");
    node = Node<int, int>::Delete(node, 6);
    BOOST_CHECK_EQUAL(node.get()->String(), "()");
    node = Node<int, int>::Delete(node, 20);
    BOOST_CHECK_EQUAL(node.get()->String(), "()");
}

BOOST_AUTO_TEST_CASE(Find_test)
{
    shared_ptr<Node<int, int>> node = make_shared<Node<int, int>>(1, 1);
    node = Node<int, int>::Insert(node, 0, 0);
    node = Node<int, int>::Insert(node, 3, 3);
    node = Node<int, int>::Insert(node, 2, 2);
    node = Node<int, int>::Insert(node, 5, 5);
    node = Node<int, int>::Insert(node, 4, 4);
    node = Node<int, int>::Insert(node, 6, 6);
    node = Node<int, int>::Insert(node, 7, 7);
    BOOST_CHECK_EQUAL(node.get()->String(), "((0:0)1:1((2:2)3:3((4:4)5:5(6:6(7:7)))))");
    int value;
    auto found = Node<int, int>::Find(node, 3, value);
    BOOST_CHECK(found);
    BOOST_CHECK_EQUAL(value, 3);
    found = Node<int, int>::Find(node, 10, value);
    BOOST_CHECK(!found);
    found = Node<int, int>::Find(node, 1, value);
    BOOST_CHECK(found);
    BOOST_CHECK_EQUAL(value, 1);
    found = Node<int, int>::Find(node, 0, value);
    BOOST_CHECK(found);
    BOOST_CHECK_EQUAL(value, 0);
    found = Node<int, int>::Find(node, 4, value);
    BOOST_CHECK(found);
    BOOST_CHECK_EQUAL(value, 4);
}

