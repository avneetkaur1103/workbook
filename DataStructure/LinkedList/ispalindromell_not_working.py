from __future__ import print_function


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def push(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def printll(self):
        node = self.head
        while node:
            print(node.data, end='\n')
        print('X')

    def is_palindrome(self):
        self.check_palindrome(self.head, self.head)

    def check_palindrome(self, start, end):
        if end is None:
            return True

        result = self.check_palindrome(start, end.next)
        if not result:
            return False
        result = (end.data == start.data)
        start = start.next
        
        return result


if __name__ == '__main__':
    ll = LinkedList()

    ll.push(1)
    ll.push(2)
    ll.push(1)

    print("Is Palindrome: {}".format(ll.is_palindrome()))
