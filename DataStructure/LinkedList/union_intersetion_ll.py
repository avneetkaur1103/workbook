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

def union(a, b):
    lookup = dict()
    result = LinkedList()
    node = a.head
    while node:
        result.push(node.data)
        lookup[node.data] = True
        node = node.next

    node = b.head
    while node:
        if not lookup.get(node.data, None):
            lookup[node.data] = True
            result.push(node.data)
        node = node.next

    return result

if __name__ == '__main__':
    ll1 = LinkedList()
    ll2 = LinkedList()

    for i in range(1,11):
        ll1.push(i)
    
    for i in range(7,17):
        ll2.push(i)

    print('First: ')
    ll1.printll()

    print('Second: ')
    ll2.printll()

    result = union(ll1,ll2)
    result.printll()

