#traverse a tree
from binarytree import Node

root=Node(1)
root.left=Node(4)
root.right=Node(7)
root.left.right=Node(8)
root.right.left=Node(9)
root.right.right=Node(6)
print "tree: "
print(root)

print "inorder ", root.inorder
print "postorder ", root.postorder
print "preorder ", root.preorder
print "levelorder ", root.levelorder
print "list root ", list(root)
