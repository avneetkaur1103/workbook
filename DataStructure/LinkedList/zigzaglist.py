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
        count = 0
        while node:
            if count > 25:
                break
            print(node.data, end='->')
            node = node.next
            count += 1
        print('X')

    def to_zigzag(self):
        node = self.head

        while node and node.next:
            if node and node.next and node.data > node.next.data:
                print('Swaping {} & {}'.format(node.data, node.next.data), end='\n')
                node.data, node.next.data = node.next.data, node.data
            node = node.next
            if node and node.next and node.data < node.next.data:
                print('Swaping {} & {}'.format(node.data, node.next.data), end='\n')
                node.data, node.next.data = node.next.data, node.data
            node = node.next


if __name__ == '__main__':
    ll = LinkedList()
    for x in range(1, 10):
        ll.push(x)
    ll.printll()
    ll.to_zigzag()
    ll.printll()
