class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def height(root: TreeNode) -> int:
    if root is None:
        return 0
    left_height = height(root.left)
    right_height = height(root.right)
    return 1 + max(left_height, right_height)



if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.right.left = TreeNode(4)
    root.right.right = TreeNode(5)

    print(height(root))  
