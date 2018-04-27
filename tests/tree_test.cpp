#define BOOST_TEST_MODULE TreeTest
#include <boost/test/unit_test.hpp>
#include "tree.h"
#include <memory>
using  namespace std;

BOOST_AUTO_TEST_CASE(Tree_test)
{
    shared_ptr<Tree<int, int>> tree = make_shared<Tree<int, int>>();
    BOOST_CHECK(tree != nullptr);

}

BOOST_AUTO_TEST_CASE(TreeInsert_test)
{
    shared_ptr<Tree<int, int>> tree = make_shared<Tree<int, int>>();
    tree->Insert(2, 2);
    tree->Insert(1, 1);
    tree->Insert(3, 3);
    BOOST_CHECK_EQUAL(tree->String(), "((1:1)2:2(3:3))");
}


BOOST_AUTO_TEST_CASE(TreeDelete_test)
{
    shared_ptr<Tree<int, int>> tree = make_shared<Tree<int, int>>();
    tree->Insert(2, 2);
    tree->Insert(1, 1);
    tree->Insert(5, 5);
    tree->Insert(4, 4);
    tree->Insert(8, 8);
    tree->Insert(7, 7);
    tree->Insert(9, 9);
    BOOST_CHECK_EQUAL(tree->String(), "((1:1)2:2((4:4)5:5((7:7)8:8(9:9))))");
    tree->Delete(5);
    BOOST_CHECK_EQUAL(tree->String(), "((1:1)2:2((4:4)7:7(8:8(9:9))))");
}

BOOST_AUTO_TEST_CASE(TreeFind_test)
{
    shared_ptr<Tree<int, int>> tree = make_shared<Tree<int, int>>();
    tree->Insert(2, 2);
    tree->Insert(1, 1);
    tree->Insert(5, 5);
    tree->Insert(4, 4);
    tree->Insert(8, 8);
    tree->Insert(7, 7);
    tree->Insert(9, 9);
    BOOST_CHECK_EQUAL(tree->String(), "((1:1)2:2((4:4)5:5((7:7)8:8(9:9))))");

    int value;

    BOOST_CHECK(tree->Find(5, value));
    BOOST_CHECK_EQUAL(value, 5);

    BOOST_CHECK(!tree->Find(10, value));

}

BOOST_AUTO_TEST_CASE(TreeFindByIndex_test)
{
    shared_ptr<Tree<int, int>> tree = make_shared<Tree<int, int>>();
    tree->Insert(2, 2);
    tree->Insert(1, 1);
    tree->Insert(5, 5);
    tree->Insert(4, 4);
    tree->Insert(8, 8);
    tree->Insert(7, 7);
    tree->Insert(9, 9);
    BOOST_CHECK_EQUAL(tree->String(), "((1:1)2:2((4:4)5:5((7:7)8:8(9:9))))");

    int value = (*tree)[5];
    BOOST_CHECK_EQUAL(value, 5);

}


