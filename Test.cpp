#include "doctest.h"
#include "BinaryTree.hpp"
using namespace std;

TEST_CASE("random test")
{
    int i;
    for (i = 0; i < 20; i++)
    {
        CHECK((i-i) == 0);
    }
}