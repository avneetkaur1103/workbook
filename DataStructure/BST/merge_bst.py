""" Merge 2 BSTs with limited extra space """

class Node:
    def __init__(self,key):
        self.key = key
        self.left = self.right = None

class Stack:

    def __init__(self):
        self.data = list()

    def push(self, val):
        self.data.append(val)

    def pop(self):
        if not len(self):
            raise Exception('Empty Stack')
        return self.data.pop()

    def __len__(self):
        return len(self.data)

    def top(self):
        if not len(self):
            raise Exception('Empty Stack')
        return self.data[-1]

    def __bool__(self):
        return bool(self.data)

def inorder(root):
    if root:
        inorder(root.left)
        print(root.key, end=' ')
        inorder(root.right)

def merge_bst(root1, root2):
    if not root1:
        inorder(root2)
    elif not root2:
        inorder(root1)

    stack1 = Stack()
    stack2 = Stack()

    curr1 = root1
    curr2 = root2

    while curr1 or curr2 or stack1 or stack2:
        if curr1:
            while curr1:
                stack1.push(curr1)
                curr1 = curr1.left

        if curr2:
            while curr2:
                stack2.push(curr2)
                curr2 = curr2.left

        if not (stack1 and stack2):
            if stack1:
                while stack1:
                    temp1 = stack1.pop()
                    temp1.left = None
                inorder(temp1)
                break

            elif stack2:
                while stack2:
                    temp2 = stack2.pop()
                    temp2.left = None
                inorder(temp2)
                break

        temp1 = stack1.top()
        temp2 = stack2.top()

        if temp1.key < temp2.key:
            temp1 = stack1.pop()
            print(temp1.key, end=' ')
            curr1 = temp1.right

        elif temp2.key < temp1.key:
            temp2 = stack2.pop()
            print(temp2.key, end=' ')
            curr2 = temp2.right

if __name__ == '__main__':
    root1 = Node(3)
    root1.left = Node(1)
    root1.right = Node(5)
  
    """ Let us create the following tree as second tree  
            4  
        / \  
        2 6  
    */
    """
    root2 = Node(4);  
    root2.left = Node(2);  
    root2.right = Node(6);  
  
    merge_bst(root1, root2);  




