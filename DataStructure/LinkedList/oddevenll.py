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

    def segregate_odd_even(self):
        # move to last:
        tail = self.head
        if not tail:
            print('Empty LinkedList')

        while tail.next:
            tail = tail.next

        # 2nd pass to handle odd heads
        end = tail
        if self.head.data & 1:
            tail.next = self.head
            tail = self.head
            while tail.next & 1:
                if tail is end:
                    print('All odds | returning ..')
                    return
                tail = tail.next
            self.head = tail.next
            tail.next = None

        # 3rd pass to handle odds after head
        node = self.head

        while not node.next is tail:
            if node.next.data & 1:
                # move next to the end
                tail.next = node.next
                node.next = node.next.next
                node = node.next
                tail = tail.next
                tail.next = None
            else:
                node = node.next


if __name__ == '__main__':
    ll = LinkedList()
    for i in range(1, 11):
        ll.push(i)
    ll.printll()
    ll.segregate_odd_even()
    ll.printll()
