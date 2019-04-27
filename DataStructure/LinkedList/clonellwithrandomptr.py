class Node:

    def __init__(self, data):
        self.data = data
        self.next = None
        self.random = None


class LinkedList:

    def __init__(self):
        self.head = None

    def push(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def copy(self, node):
        self.head = node

    def printll(self, prefix = ''):
        print(prefix, ':')
        
        node = self.head
        while node:
            print('Data: {}, Random: {}'.format(node.data, node.random.data))
            node = node.next


def clone(ll):
    node = ll.head

    while node:
        new_node = Node(node.data)
        new_node.next = node.next
        node.next = new_node
        node = node.next.next

    # copy random
    node = ll.head
    while node:
        node.next.random = node.random.next
        node = node.next.next

    # restore
    original_head = original = ll.head
    copy_head = copy = original.next
    while original and copy:
         original.next = original.next.next
         copy.next = copy.next.next if copy.next else copy.next
         original = original.next
         copy = copy.next

    copy_ll = LinkedList()
    copy_ll.copy(copy_head)
    return copy_ll

if __name__ == '__main__':
    original = LinkedList()

    for i in range(1,6):
        original.push(i)

    head = original.head
    head.random = head.next.next
    head.next.random = head
    head.next.next.random = head.next.next.next.next
    head.next.next.next.random = head.next.next.next.next
    head.next.next.next.next.random = head.next

    original.printll(prefix = 'Original')
    copy = clone(original)
    copy.printll(prefix = 'Copy')



