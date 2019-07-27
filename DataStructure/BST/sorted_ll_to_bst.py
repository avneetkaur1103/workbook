""" Search, Insert & Delete in binary tree """

class Node:
    def __init__(self,key):
        self.key = key
        self.left = self.right = None

class LLNode:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def size(self):
        return self.size

    def push(self, data):
        new_node = LLNode(data)
        new_node.next = self.head
        self.head = new_node
        self.size += 1

    def printll(self):
        node = self.head
        while node is not None:
            print(node.data, end='->')
            node = node.next
        print('X')

def preorder(root):
    if root:
        print(root.key, end=' ')
        preorder(root.left)
        preorder(root.right)

def ll_to_bst(head, n):
    if n:
        left, head = ll_to_bst(head, n//2)
        root = Node(head.data)
        root.left = left
        head = head.next
        right, head = ll_to_bst(head, n-n//2-1)
        root.right = right
        return root, head
    return None,head

if __name__ == '__main__':
    ll = LinkedList()
    for i in range(7, 0, -1):
        ll.push(i)

    print('LinkedList: ', end=' ')
    ll.printll()  

    root,_ = ll_to_bst(ll.head, ll.size)
    preorder(root)



