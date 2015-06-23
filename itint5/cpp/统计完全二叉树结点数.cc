//使用getLeftChildNode(TreeNode)获得左儿子结点
//使用getRightChildNode(TreeNode)获得右儿子结点
//使用isNullNode(TreeNode)判断结点是否为空

int left_depth(TreeNode root) {
    int res = 0;
    while (!isNullNode(root)) {
        res++;
        root = getLeftChildNode(root);
    }
    return res;
}

int right_depth(TreeNode root) {
    int res = 0;
    while (!isNullNode(root)) {
        res++;
        root = getRightChildNode(root);
    }
    return res;
}

int count_complete_binary_tree_nodes(TreeNode root) {
    if (isNullNode(root)) {
        return 0;
    }
    int ll = left_depth(root);
    int rr = right_depth(root);
    
    if (ll == rr) {
        return (1 << ll) - 1;
    } else {
        return 1 + 
            count_complete_binary_tree_nodes(getLeftChildNode(root)) +
            count_complete_binary_tree_nodes(getRightChildNode(root));
    }
}
