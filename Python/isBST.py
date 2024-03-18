class node:
    def _init_(self, data):
        self.data = data
        self.left = None
        self.right = None

def is_bst_helper(node, min_val, max_val):
    if node is None:
        return True
    
    if node.data <= min_val or node.data >= max_val:
        return False
    
    return (is_bst_helper(node.left, min_val, node.data) and
            is_bst_helper(node.right, node.data, max_val))

def check_binary_search_tree_(root):
    return is_bst_helper(root, float("-inf"), float("inf"))