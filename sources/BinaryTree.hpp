#include <iostream>

namespace ariel
{
    /*====================================Implementation-Of-A-Generic-Binary-Tree=============================*/
    template <typename T>
    class BinaryTree
    {
        /*===========================================Inner-Node-Class=========================================*/
        class Node
        {
        public:          // TODO: public?
            T value;     // the value of the node
            Node *left;  // left child
            Node *right; //right child
            // constructors
            Node()
            {
                Node *node = new Node();
                node->value = nullptr;
                node->left = nullptr;
                node->right = nullptr;
            }
            Node(T input_value)
            {
                Node *node = new Node();
                node->value = input_value;
                node->left = nullptr;
                node->right = nullptr;
            }
            // destructor
            ~Node();
        };

        /*===========================================Private-Methods=========================================*/

    private:
        Node *root; // the root of the tree

        // This function search the given node value in the tree and return a poniter to its node
        Node *search_node(T target_value)
        {
            Node *target_node = nullptr;
            // if (this->root == nullptr)
            // {
            //     // the tree is empty
            //     cout << "the tree is empty" << endl;
            // }
            // else
            // {
            //     // traverse through all the nodes in the tree
            //     // TODO: add code here
            //     // node found
            //     cout << "the node is found" << endl;
            //     // node is not found
            //     cout << "the node is notfound" << endl;
            // }
            return target_node;
        }

        /*===========================================Public-Methods=========================================*/

    public:
        // constructor
        BinaryTree()
        {
            // this.root = Node();
            // this->root = new Node();
        }

        /*===========================================Insert-Methods=========================================*/

        // gets an input and puts it at the root of the tree
        BinaryTree<T> &add_root(T new_root_value)
        {
            // this->root->value = new_root_value;
            return *this;
        }

        // adds a new node to be the left child of the exist given parent
        BinaryTree<T> &add_left(T parent, T left_child)
        {
            // Node<T> *p = nullptr;
            // p = search_node(parent);
            // if (p != nullptr)
            // {
            //     Node *child = Node(left_child); // TODO: ->

            //     p->left = child;
            // }
            return *this;
        }

        // adds a new node ot be the right child of the exist given parent
        BinaryTree<T> &add_right(T parent, T right_child)
        {
            // Node *p = nullptr;
            // p = search_node(parent);
            // if (p != nullptr)
            // {
            //     Node *child = Node(right_child); // TODO: ->
            //     p->right = child;
            // }
            return *this;
        }

        /*========================================Inner-Iterator-Class==================================*/

        class Iterator
        {
        private:
            Node *p;

        public:
            Iterator()
            {
            }

            T &operator*()
            {
                return p->value;
            }

            T *operator->()
            {
                return &(p->value);
            }

            // ++i;
            Iterator &operator++()
            {
                p = p->left;
                return *this;
            }

            // i++;
            const Iterator operator++(int)
            {
                Iterator temp = *this;
                p = p->left;
                return temp;
            }

            bool operator==(const Iterator &other)
            {
                return p == other.p;
            }

            bool operator!=(const Iterator &other)
            {
                return p != other.p;
            }
        };

        /*==========================================iterators-Methods===========================================*/

        Iterator begin()
        {
            return Iterator();
        }
        Iterator end()
        {
            return Iterator();
        }
        Iterator begin_preorder()
        {
            return Iterator();
        }
        Iterator end_preorder()
        {
            return Iterator();
        }
        Iterator begin_inorder()
        {
            return Iterator();
        }
        Iterator end_inorder()
        {
            return Iterator();
        }
        Iterator begin_postorder()
        {
            return Iterator();
        }
        Iterator end_postorder()
        {
            return Iterator();
        }

        /*========================================Operator-Overloading===========================================*/

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree &tree)
        {
            // TODO: add some code here
            return os;
        }
    };
}
