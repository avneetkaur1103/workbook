import sys
import math
from enum import Enum
import abc
import bisect
from collections import defaultdict
import random

def debug(*args, **kwargs):
    print(*args,**kwargs, file=sys.stderr)
# Send your busters out into the fog to trap ghosts and bring them home!
busters_per_player = int(input())  # the amount of busters you control
ghost_count = int(input())  # the amount of ghosts on the map
my_team_id = int(input())  # if this is 0, your base is on the top left of the map, if it is one, on the bottom right
debug(f'busters_per_player: {busters_per_player}, ghost_count: {ghost_count} my_team_id: {my_team_id}')
# code Manish
busters = dict()
ghosts = dict()
assignment_map = defaultdict(list)

class State(metaclass=abc.ABCMeta):
    states = Enum('states', 'Free Assigned Ready Captured')

    def __init__(self):
        self._state = self.states.Free

    @abc.abstractmethod
    def move(self):
        pass

    def update(self, state):
        self._state = state

def distance(pos1, pos2):
    result =  max(abs(pos1[0] - pos2[0]), abs(pos1[1] - pos2[1]))
    debug(f'Distance {result}')
    return result

def reassign(busters, ghosts):
    for key, value in ghosts.items():
        assignment_map[key] = sorted(list(busters.keys()), key=lambda buster_key: distance(busters[buster_key].pos, value.pos))

    for ghost_id, buster_ids in assignment_map.items():
        ghost = ghosts[ghost_id]
        debug(f'Assignment=>Ghost: {ghost_id} is_free: {ghost.free}, Busters: {buster_ids}')
        if ghost.free:
            for buster_id in buster_ids:
                buster = busters.get(buster_id)
                if not buster.assigned:
                    buster.assign(ghost_id)
                    ghost.free = False
                    break

class Ghost:
    def __init__(self, id, x, y, state, value):
        self.id = id
        self.pos = x, y
        self.state = state
        self.value = value
        self.free = True

class Buster(State):
    def __init__(self, id, x, y, state, value):
        super().__init__()
        self.id = id
        self.pos = x, y
        self.state = state
        self.value = value
        self.assigned = False
        self.target_ghost_id = None
        self.remaining_distance = float('inf')
        if state:
            self._state = State.states.Captured
            self.target_ghost_id = value

    def assign(self, ghost_id):
        self.assigned = True
        self._state = State.states.Assigned
        self.target_ghost_id = ghost_id
        self.remaining_distance = distance(self.pos, ghosts[ghost_id].pos)
        debug(f'Buster {self.id} assigned ghost {self.target_ghost_id}')

    def move_to_base(self):
        base = 0, 0 if not self.id else 16000, 9000
        if distance(self.pos, base) < 1600:
            print('MOVE 0 0') if not self.id else print('MOVE 16000 9000')
            return False
        return True

    def move_to_target(self):
        pos = ghosts[self.target_ghost_id].pos
        if distance(self.pos, pos) > 1760 or distance(self.pos, pos) < 900:
            print(f'MOVE {pos[0]} {pos[1]}')
            return False
        return True

    def bust_if_allowed(self):
        target_pos = ghosts[self.target_ghost_id].pos
        if distance(self.pos, target_pos) < 1760 or distance(self.pos, target_pos) > 900:
            print(f'BUST {self.target_ghost_id}')
            return True
        return False

    def move_random(self):
        print(f'MOVE {random.randrange(0, 16000)} {random.randrange(0, 9000)}')

    def move(self):
        debug(f'Buster: {self.id} Current State: {self._state}')
        if self._state == State.states.Captured:
            at_base = self.move_to_base()
            if at_base:
                print(f'RELEASE')
                self.state = State.states.Free

        elif self._state == State.states.Ready:
            result = self.bust_if_allowed()
            if not result:
                if self.assigned:
                    self._state = State.states.Assigned

        elif self._state == State.states.Assigned:
            in_range = self.move_to_target()
            if in_range:
                self._state = State.states.Ready

        elif self._state == State.states.Free:
            self.move_random()


# game loop
while True:
    entities = int(input())  # the number of busters and ghosts visible to you
    for i in range(entities):
        # entity_id: buster id or ghost id
        # y: position of this buster / ghost
        # entity_type: the team id if it is a buster, -1 if it is a ghost.
        # state: For busters: 0=idle, 1=carrying a ghost.
        # value: For busters: Ghost id being carried. For ghosts: number of busters attempting to trap this ghost.
        entity_id, x, y, entity_type, state, value = [int(j) for j in input().split()]
        debug(i, ":", f'entity_id: {entity_id} x:{x} y:{y} entity_type:{entity_type} state:{state} value:{value}')
        if entity_type != -1:
            if not busters.get(entity_id):
                busters[entity_id] = Buster(entity_id, x, y, state, value)
        else:
            if not ghosts.get(entity_id):
                ghosts[entity_id] = Ghost(entity_id, x, y, state, value)
        reassign(busters, ghosts)

    for i in range(busters_per_player):

        # Write an action using print
        # To debug: print("Debug messages...", file=sys.stderr)

        # MOVE x y | BUST id | RELEASE
        debug(f'Buster: {busters[i].id}')
        busters[i].move()