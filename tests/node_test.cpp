#include <boost/test/unit_test.hpp>

#include "node.h"
#include <memory>
using  namespace std;

BOOST_AUTO_TEST_CASE(Node_test) {
    shared_ptr<Node<int, int>> node = make_shared<Node<int, int>>(1, 1);
    BOOST_CHECK(node != nullptr);
}

BOOST_AUTO_TEST_CASE(SetValue_test) {
    shared_ptr<Node<int, int>> node = make_shared<Node<int, int>>(1, 1);
    node.get()->SetValue(2);
    BOOST_CHECK_EQUAL(node.get()->Value(), 2);
}

BOOST_AUTO_TEST_CASE(Insert_test) {
    shared_ptr<Node<int, int>> node = make_shared<Node<int, int>>(1, 1);
    node = Node<int, int>::Insert(node, 2, 2);
    node = Node<int, int>::Insert(node, 0, 0);
    BOOST_CHECK_EQUAL(node.get()->Value(), 1);
}

BOOST_AUTO_TEST_CASE(String_test) {
    shared_ptr<Node<int, int>> node = make_shared<Node<int, int>>(1, 1);
    node = Node<int, int>::Insert(node, 2, 2);
    node = Node<int, int>::Insert(node, 0, 0);
    BOOST_CHECK_EQUAL(node.get()->String(), "((0:0)1:1(2:2))");
}
