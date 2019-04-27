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
        while node is not None:
            print(node.data, end='->')
            node = node.next
        print('X')

    def reverse_util(self, rest, prev):
        if rest is None:
            self.head = prev
            return
        self.reverse_util(rest.next, rest)
        rest.next = prev

    def reverse(self):
        if self.head is None:
            return
        self.reverse_util(self.head, None)

    def delete_smaller_prev_nodes(self):
        if self.head:
            self.reverse()
            curr = self.head.next
            prev = self.head

            while curr:
                if curr.data < prev.data:
                    prev.next = curr.next
                else:
                    prev = prev.next
                curr = curr.next
            self.reverse()
        else:
            print('Empty list')

if __name__ == '__main__':
    ll = LinkedList()
    for i in range(1,11):
        ll.push(i)

    ll.printll()
    ll.delete_smaller_prev_nodes()
    ll.printll()