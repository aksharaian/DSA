# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def distanceK(self, root, target, k):
        """
        :type root: TreeNode
        :type target: TreeNode
        :type k: int
        :rtype: List[int]
        """
        conn=collections.defaultdict(list)
        def connect(parent,child):
            if parent and child:
                conn[parent.val].append(child.val)
                conn[child.val].append(parent.val)

            if child.left:
                connect(child,child.left)

            if child.right:
                connect(child,child.right)

        connect(None,root)
        bfs=[target.val]
        res=set(bfs)

        for i in range(k):
            new_level=[]
            for q_node_val in bfs:
                for connected_node_val in conn[q_node_val]:
                    if connected_node_val not in res:
                        new_level.append(connected_node_val)

            bfs=new_level
            res|=set(bfs)

        return bfs  