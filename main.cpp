#include <vector>
#include "binarySearchTree.cpp"

using namespace std;

int main()
{
    vector<int> nums = { 3, 1 };
    BinarySearchTree<int> tree;

    tree.buildFromArray(nums);
    tree.print();

    return 0;
}