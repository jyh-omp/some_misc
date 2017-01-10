#!/usr/bin/env python
# coding:utf8


class TreeNode(object):
    def __init__(self, val=None, lchild=None, rchild=None):
        self._val = val
        self._lchild = lchild
        self._rchild = rchild


def calculate_tree_width(tree):
    if tree is None:
        return 0
    # 使用两个list来实现！也可以使用queue，但是使用两个list更Python
    list_1 = [tree]
    list_2 = []
    width = 1
    while len(list_1) > 0:
        for node in list_1:
            if node.lchild is not None:
                list_2.append(node.lchild)
            if node.rchild is not None:
                list_2.append(node.rchild)
        # Python里面变量都是引用，直接使用Python语法糖做交换。避免了deepcopy
        list_1, list_2 = list_2, list_1
        list_2.clear()
        if len(list_1) > width:
            width = len(list_1)

    return width
