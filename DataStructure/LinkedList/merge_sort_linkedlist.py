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

    def merge_sort(self):
        self.head = self.merge_sort_util(self.head)

    def merge_sort_util(self, start):
        if not start or not start.next:
            return start
        start, mid = self.split(start)
        start = self.merge_sort_util(start)
        mid = self.merge_sort_util(mid)
        return self.sorted_merge(start, mid)

    def split(self, start):
        slow = start
        fast = slow.next  # type: Node

        while fast:
            fast = fast.next
            if fast:
                slow = slow.next
                fast = fast.next
        mid = slow.next
        slow.next = None
        return start, mid

    def sorted_merge(self, a, b):
        result = None
        if not a:
            return b
        elif not b:
            return a

        if a.data <= b.data:
            result = a
            result.next = self.sorted_merge(a.next, b)
        else:
            result = b
            result.next = self.sorted_merge(a, b.next)
        return result


if __name__ == '__main__':
    ll = LinkedList()
    for x in range(1, 10):
        ll.push(x)
    ll.printll()
    ll.merge_sort()
    ll.printll()
