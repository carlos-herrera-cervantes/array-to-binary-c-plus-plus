#include <iostream>
#include <vector>
#include "nodeTree.cpp"

using namespace std;

template <typename T>
class BinarySearchTree
{
    Node<T>* root;
    int length;

    /** Inserts a new node
     * @param node Node object class
     * @param value Number value
     * @returns Node object class
    */
    Node<T>* insert(Node<T>* node, T value)
    {
        if (!node)
        {
            node = new Node<T>();
            node->data = value;
            node->left = node->right = NULL;
        }
        else if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insert(node->right, value);
        }

        return node;
    }

    /**
    * Creates a new binary search tree from sorted array
    * @param nums Sorted array
    * @param left Value for left node
    * @param right Value for right node
    */
    void buildFromArray(vector<int>& nums, int left, int right)
    {
        if (left > right) return;

        length++;

        int middle = left + (right - left) / 2;
        root = insert(root, nums[middle]);
        buildFromArray(nums, left, middle - 1);
        buildFromArray(nums, middle + 1, right);
    }

    /**
     * Prints the elements
     * @param node Node object class
     * @returns Void
     */
    void inorder(Node<T>* node)
    {
        if (!node) return;

        cout << node->data << ": ";

        if (node->left) cout << "L" << node->left->data << " ";
        if (node->right) cout << "R" << node->right->data << " ";

        cout << "\n";

        inorder(node->left);
        inorder(node->right);
    }

    /**
     * Deletes each node and its children
     * @param node Node object class
     * @returns Node object model
     */
    Node<T>* deleteTree(Node<T>* node)
    {
        if (!node)
            return NULL;
        {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }

        return NULL;
    }

    public:
        BinarySearchTree()
        {
            root = NULL;
            length = 0;
        }

        ~BinarySearchTree()
        {
            root = deleteTree(root);
            length = 0;
        }

        int getLength()
        {
            return length;
        }

        /**
         * Prints the elements to the console
         * @returns Void
         */
        void print()
        {
            inorder(root);
            cout << "\n";
        }

        /**
         * Inserts a new value
         * @param data Number value
         * @returns Void
         */
        void insert(int data)
        {
            root = insert(root, data);
            length++;
        }

        /**
         * Creates a new binary search tree from sorted array
         * @param nums Sorted array
         */
        void buildFromArray(vector<int>& nums)
        {
            buildFromArray(nums, 0, nums.size() - 1);
        }
};