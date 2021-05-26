#include "doctest.h"
#include "BinaryTree.hpp"
using namespace std;

TEST_CASE("random test")
{
    int i, j;
    for (i = j = 0; i < 20; i++)
    {
        CHECK(i - j == 0);
    }
}