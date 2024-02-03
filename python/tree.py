class TreeNode():
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
class Tree():
    def __init__(self, node):
        self.root = node


def preorder(root):
    if root == None:
        return
    print(root.val)
    preorder(root.left)
    preorder(root.right)
def inorder(root):
    if root == None:
        return
    inorder(root.left)
    print(root.val)
    inorder(root.right)
def postorder(root):
    if root == None:
        return
    postorder(root.left)
    postorder(root.right)
    print(root.val)

def search(root, x):
    if root == None:
        return "No item"
    if root.val == x:
        return root
    elif root.val < x:
        return search(root.right, x)
    else:
        return search(root.left, x)
    
# ppt 에 있는 return 사용 방식
def insert(root, x):
    if root == None:
        new_node = TreeNode(x)
        return new_node
    elif x == root.val:
        return
    elif x < root.val:
        new_subtree = insert(root.left, x)
        root.left = new_subtree
        return root
    else:
        new_subtree = insert(root.right, x)
        root.right = new_subtree
        return root

def search_parent(root, x):
    if root == None:
        return
    elif root.val == x:
        return 
    
    if root.left.val == x or root.right.val == x:
        return root
    elif root.val > x:
        return search_parent(root.left, x)
    elif root.val < x:
        return search_parent(root.right, x)

def delete(root, x):
    if search(root, x) is None:
        return
    parent = search_parent(root, x)
    target = search(root, x)
    
    # target is leaf
    if target.left is None and target.right is None:
        if parent.left == target:
            parent.left = None
        elif parent.right == target:
            parent.right = None
    # target has one leaf
    elif target.left is None:
        target.val = target.right.val
        target.left = target.right.left
        target.right = target.right.right
    elif target.right is None:
        target.val = target.left.val
        target.right = target.left.right
        target.left = target.right.left
    # target has two leaf
    else:
        succeeder = success(target) # 왼쪽의 가장 오른쪽
        succ_parent = search_parent(root, succeeder.val)
        target.val = succeeder.val
        if succeeder.left == None:
            succ_parent.right = None
        else:
            succeeder.val = succeeder.left.val
            succeeder.right = succeeder.left.right
            succeeder.left = succeeder.left.left
            
def success(root):
    root = root.left
    while root.right is not None:
        root = root.right
    return root
    