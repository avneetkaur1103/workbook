"""
    Suppose there is a circle. There are n petrol pumps on that circle. You are given two sets of data.
    The amount of petrol that every petrol pump has.
    Distance from that petrol pump to the next petrol pump.
    Calculate the first point from where a truck will be able to complete the circle (The truck will stop at each petrol pump and it has infinite capacity).
    Expected time complexity is O(n). Assume for 1-litre petrol, the truck can go 1 unit of distance.
"""
from collections import namedtuple, deque

Node = namedtuple('Node', ['petrol', 'distance'])


def check_path(input):
    residual = 0
    for i in range(len(input)):
        if residual + input[i].petrol - input[i].distance < 0:
            return i
        else:
            residual += input[i].petrol - input[i].distance
    else:
        return -1


def circular_tour(input):
    dq = deque(input)
    rotate = 0

    while rotate < len(dq):
        index = check_path(dq)
        if index >= 0:
            dq.rotate(-1*(index + 1))
            rotate += index + 1
        else:
            print('Start = ' + str(dq[0]))
            break
    else:
        print("Couldn't find a suitable start")


if __name__ == '__main__':
    petrol_pump = [(6, 4), (3, 6), (7, 3)];
    nt_pumps = list(map(Node._make, petrol_pump))
    circular_tour(nt_pumps)
