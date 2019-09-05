#build your own trees

from binarytree import Node

root            =Node(1)
root.left       =Node(2)
root.right      =Node(3)

root.left.right =Node(4)
root.right.left =Node(6)
root.right.right=Node(7)
root.left.right.left =Node(8)
print(root)

print "root height: ", root.height
print "root is balanced ", root.is_balanced
print "root.is_bst ",root.is_bst
print "root is complete ",root.is_complete
print "root is max heap ",root.is_max_heap
print "root is min heap ",root.is_min_heap
print "root leaf count ",root.leaf_count
print "root max leaf depth ",root.max_leaf_depth
print "root max node val ",root.max_node_value;
print "root min node val ",root.min_node_value
print "root min leaf depth ",root.min_leaf_depth
print "root size ",root.size
print "root leaves: ",root.leaves
print "root levels ", root.levels
