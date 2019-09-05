##generate and print various types of binary trees
#each time random o/p
from binarytree import tree

my_tree=tree(height=3, is_perfect=False)
print my_tree
my_tree_per=tree(height=3, is_perfect=True)
print my_tree_per 

##       ____5__
##      /       \
##     1__       2___
##    /   \     /    \
##  _7     8   4     _9
## /      /         /  \
##10     3         11   12
