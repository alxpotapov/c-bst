#define BOOST_TEST_MODULE TreeTest
#include <boost/test/unit_test.hpp>

#include "tree.h"
#include <memory>
using  namespace std;

BOOST_AUTO_TEST_CASE(constructor_test) {
    shared_ptr<Tree> tree = make_shared<Tree>();
    BOOST_CHECK(tree != nullptr);

}
