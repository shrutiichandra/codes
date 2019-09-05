#use bfs indices to manipulate nodes
from binarytree import Node

root=Node(1)
root.left=Node(4)
root.right=Node(7)
root.left.right=Node(8)
root.right.left=Node(9)
root.right.right=Node(6)
print "tree: "
print(root)

print "with indices "
root.pprint(index=True, delimiter=',')

idx=2
print "node/subtree at index ",idx, root[idx]
print "changing node val at ",idx
root[idx]=Node(20)
root.pprint(index=True, delimiter=',')

idx=4
print "changing subtree at ",idx
root[idx]=Node(40,left=Node(12), right=Node(80))
root.pprint(index=True, delimiter=',')

idx=1
print "delete at ",idx
del root[1]
root.pprint(index=True, delimiter=',')
