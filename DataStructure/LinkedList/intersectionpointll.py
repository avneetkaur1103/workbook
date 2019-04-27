from __future__ import print_function
import random


class Node:

    def __init__(self, data):
        self.data = data
        self.next = None

    def __repr__(self):
        return self.data.__str__()


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


def find_intersection_util(d, ll1, ll2):
    node1 = ll1.head
    node2 = ll2.head
    for i in range(0, d):
        if node1:
            node1 = node1.next
        else:
            print('Exception ..')
            break

    while node1 and node2:
        if node1 is node2:
            return node1
        node1 = node1.next
        node2 = node2.next
    return None


def find_intersection(ll1, ll2):
    len1 = get_count(ll1)
    len2 = get_count(ll2)

    d = len1 - len2
    if d > 0:
        result = find_intersection_util(d, ll1, ll2)
    else:
        result = find_intersection_util(d, ll2, ll1)

    return result


def get_count(ll):
    node = ll.head
    count = 0
    while node:
        count += 1
        node = node.next
    return count


if __name__ == '__main__':
    ll1 = LinkedList()
    ll2 = LinkedList()

    for x in range(1, 10):
        ll1.push(x)

    for x in range(10, 12):
        ll2.push(x)

    ll2.head.next.next = ll1.head.next.next.next.next
    ll1.printll()
    ll2.printll()

    result = find_intersection(ll1, ll2)
    print('Intersection @ {}'.format(result))
