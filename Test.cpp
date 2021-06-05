#include "doctest.h"
#include "BinaryTree.hpp"
#include <random>
#include <sstream>
using namespace std;
using namespace ariel;

const int NUM_OF_ITERATIONS = 50;
const int BIG_TREE_SIZE = 100000;
const double MIN_DOUBLE_RANGE = 0;
const double MAX_DOUBLE_RANGE = 1000;

/*===============================================Generators=============================================*/

// generates a random integer
char generates_int()
{
    return rand();
}

// generates a random double
double generates_double(double min, double max)
{
    double value = (double)rand() / RAND_MAX;
    return min + value * (max - min);
}

// generates a random char
char generates_char()
{
    return 'a' + rand() % 26;
}

// generates a random boolean
bool generates_bool()
{
    int boolean = rand() % 2;
    if (boolean == 0)
    {
        return false;
    }
    return true;
}

/*===============================================Tests=============================================*/

TEST_CASE("initialization empty trees")
{
    CHECK_NOTHROW(BinaryTree<int> int_tree);
    CHECK_NOTHROW(BinaryTree<double> double_tree);
    CHECK_NOTHROW(BinaryTree<char> char_tree);
    CHECK_NOTHROW(BinaryTree<bool> bool_tree);
}

TEST_CASE("adding a root")
{
    // initializes
    BinaryTree<int> int_tree;
    BinaryTree<double> double_tree;
    BinaryTree<char> char_tree;
    BinaryTree<bool> bool_tree;

    for (size_t i = 0; i < NUM_OF_ITERATIONS; i++)
    {
        // generates random varibles
        int random_int = generates_int();
        double random_double = generates_double(MIN_DOUBLE_RANGE, MAX_DOUBLE_RANGE);
        char random_char = generates_char();
        bool random_bool = generates_bool();

        // adiing the roots
        CHECK_NOTHROW(int_tree.add_root(random_int));
        CHECK_NOTHROW(double_tree.add_root(random_double));
        CHECK_NOTHROW(bool_tree.add_root(random_bool));
        CHECK_NOTHROW(char_tree.add_root(random_char));
    }
}

TEST_CASE("adding sons to an empty tree")
{
    // initializes
    BinaryTree<int> int_tree;
    BinaryTree<double> double_tree;
    BinaryTree<char> char_tree;
    BinaryTree<bool> bool_tree;

    for (size_t i = 0; i < NUM_OF_ITERATIONS; i++)
    {
        // generates random varibles
        int first_random_int = generates_int();
        int second_random_int = generates_int();
        double first_random_double = generates_double(MIN_DOUBLE_RANGE, MAX_DOUBLE_RANGE);
        double second_random_double = generates_double(MIN_DOUBLE_RANGE, MAX_DOUBLE_RANGE);
        char first_random_char = generates_char();
        char second_random_char = generates_char();
        bool first_random_bool = generates_bool();
        bool second_random_bool = generates_bool();

        // try to add sons
        CHECK_THROWS(int_tree.add_right(first_random_int, second_random_int));
        CHECK_THROWS(int_tree.add_left(second_random_int, first_random_int));
        CHECK_THROWS(double_tree.add_right(first_random_double, second_random_double));
        CHECK_THROWS(double_tree.add_left(second_random_double, first_random_double));
        CHECK_THROWS(bool_tree.add_right(first_random_bool, second_random_bool));
        CHECK_THROWS(bool_tree.add_left(second_random_bool, first_random_bool));
        CHECK_THROWS(char_tree.add_right(first_random_char, second_random_char));
        CHECK_THROWS(char_tree.add_left(second_random_char, first_random_char));
    }
}

TEST_CASE("Building a big integer tree")
{
    BinaryTree<int> big_int_tree;
    int first_root = 0;
    // adds root
    big_int_tree.add_root(first_root);
    // adds right son
    for (int i = first_root + 1; i < BIG_TREE_SIZE / 2; i++)
    {
        CHECK_NOTHROW(big_int_tree.add_right(i - 1, i));
    }
    // adds left son
    for (int i = BIG_TREE_SIZE / 2; i < BIG_TREE_SIZE; i++)
    {
        CHECK_NOTHROW(big_int_tree.add_left(i - 1, i));
    }
}

TEST_CASE("Building a big char tree")
{
    BinaryTree<char> big_char_tree;
    int first_root = 0;
    // adds root
    big_char_tree.add_root(first_root);
    // adds right son
    for (int i = first_root + 1; i < BIG_TREE_SIZE / 2; i++)
    {
        char first_random_char = generates_char();
        char second_random_char = generates_char();
        CHECK_NOTHROW(big_char_tree.add_right(first_random_char, second_random_char));
    }
    // adds left son
    for (int i = BIG_TREE_SIZE / 2; i < BIG_TREE_SIZE; i++)
    {
        char first_random_char = generates_char();
        char second_random_char = generates_char();
        CHECK_NOTHROW(big_char_tree.add_left(first_random_char, second_random_char));
    }
}

TEST_CASE("Building a big bool tree")
{
    BinaryTree<bool> big_bool_tree;
    int first_root = 0;
    // adds root
    big_bool_tree.add_root(first_root);
    // adds right son
    for (int i = first_root + 1; i < BIG_TREE_SIZE / 2; i++)
    {
        bool first_random_bool = generates_bool();
        bool second_random_bool = generates_bool();
        CHECK_NOTHROW(big_bool_tree.add_right(first_random_bool, second_random_bool));
    }
    // adds left son
    for (int i = BIG_TREE_SIZE / 2; i < BIG_TREE_SIZE; i++)
    {
        bool first_random_bool = generates_bool();
        bool second_random_bool = generates_bool();
        CHECK_NOTHROW(big_bool_tree.add_left(first_random_bool, second_random_bool));
    }
}

TEST_CASE("Pre-order traversal")
{
    ostringstream actual;
    string expected = "";

    // expected
    int root = generates_int();
    int left_son = generates_int();
    int right_son = generates_int();
    int left_left_son = generates_int();
    int left_right_son = generates_int();

    expected = to_string(root) + " " + to_string(left_son) + " " + to_string(left_left_son) +
               " " + to_string(left_right_son) + " " + to_string(right_son);

    // init and bulid the tree
    BinaryTree<int> int_tree;
    int_tree.add_root(root);
    int_tree.add_right(root, right_son);
    int_tree.add_left(root, left_son).add_left(left_son, left_left_son).add_right(left_son, left_right_son);

    for (auto it = int_tree.begin_preorder(); it != int_tree.end_preorder(); ++it)
    {
        actual << (*it) << " ";
    }

    CHECK_EQ(actual.str(), expected);
}

TEST_CASE("Post-order traversal")
{
    ostringstream actual;
    string expected = "";

    // expected
    int root = generates_int();
    int left_son = generates_int();
    int right_son = generates_int();
    int left_left_son = generates_int();
    int left_right_son = generates_int();

    expected = to_string(left_left_son) + " " + to_string(left_right_son) + " " + to_string(left_son) +
               " " + to_string(right_son) + " " + to_string(root);

    // init and bulid the tree
    BinaryTree<int> int_tree;
    int_tree.add_root(root);
    int_tree.add_right(root, right_son);
    int_tree.add_left(root, left_son).add_left(left_son, left_left_son).add_right(left_son, left_right_son);

    for (auto it = int_tree.begin_postorder(); it != int_tree.end_postorder(); ++it)
    {
        actual << (*it) << " ";
    }

    CHECK_EQ(actual.str(), expected);
}

TEST_CASE("In-order traversal")
{
    ostringstream actual;
    string expected = "";

    // expected
    int root = generates_int();
    int left_son = generates_int();
    int right_son = generates_int();
    int left_left_son = generates_int();
    int left_right_son = generates_int();

    expected = to_string(left_left_son) + " " + to_string(left_son) + " " + to_string(left_right_son) +
               " " + to_string(root) + " " + to_string(right_son);

    // init and bulid the tree
    BinaryTree<int> int_tree;
    int_tree.add_root(root);
    int_tree.add_right(root, right_son);
    int_tree.add_left(root, left_son).add_left(left_son, left_left_son).add_right(left_son, left_right_son);

    for (auto it = int_tree.begin_inorder(); it != int_tree.end_inorder(); ++it)
    {
        actual << (*it) << " ";
    }

    CHECK_EQ(actual.str(), expected);
}
