import sys
import math
from enum import Enum
from copy import deepcopy

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
def debug(*args, **kwargs):
    print(*args, **kwargs, file=sys.stderr)

Player = Enum('Player', 'P1 P2')

class Board:
    def __init__(self, size):
        self.matrix = [[-1 for _ in range(size)] for _ in range(size)]
        self.size
        self.moves = list()
        for i in range(size):
            for j in range(size):
                self.moves.append((i,j))
        self.next_player = 1

    def legal_moves(self):
        return self.moves

    def current_player(self):
        return self.next_player

    def next_state(self, move):
        i, j = move
        self.matrix[i][j] = self.next_player
        result = self.compact_state()
        self.matrix[i][j] = -1
        return result

    def play(self, move):
        self.moves.remove(move)
        i, j = move
        self.matrix[i][j] = self.next_player
        self.next_player ^= 1

    def winner(self):
        for i in self.size: #check rows n columns
            if sum(self.matrix[i]) == self.size or sum(self.matrix[:][i] == self.size):
                return 1 # Player 1
            elif sum(self.matrix[i]) == 0 or sum(self.matrix[:][i] == 0):
                return 0 # Player 0

        diag = [r[i] for i, r in enumerate(self.matrix)]
        rdiag = [r[-i-1] for i, r in enumerate(self.matrix)]
        if sum(diag) == self.size or sum(rdiag) == self.size:
            return 1 # Player 1
        elif sum(diag) == 0 or sum(rdiag) == 0:
            return 0 # Player 0

        return -1

    def compact_state(self):
        return str(self.matrix)


class MCTS:
    def __init__(self, board, **kwargs):
        self.board = board
        self.states = []
        seconds = kwargs.get('time', 30)
        self.calculation_time = datetime.timedelta(seconds=seconds)
        self.max_moves = kwargs.get('max_moves', 100)
        self.C = kwargs.get('C', 1.4)
        self.plays = set()
        self.wins = set()

    def update(self, state):
        self.states.append(state)

    def get_play(self):
        self.max_depth = 0
        state = self.board.compact_state()
        player = self.board.current_player()
        legal = self.board.legal_moves()

        # Bail out early if there is no real choice to be made.
        if not legal:
            return
        if len(legal) == 1:
            return legal[0]

        games = 0
        begin = datetime.datetime.utcnow()
        while datetime.datetime.utcnow() - begin < self.calculation_time:
            self.run_simulation()
            games += 1

        moves_states = [(p, self.board.next_state(p)) for p in legal]

        # Display the number of calls of `run_simulation` and the
        # time elapsed.
        # print games, datetime.datetime.utcnow() - begin

        # Pick the move with the highest percentage of wins.
        percent_wins, move = max(
            (self.wins.get((player, S), 0) /
             self.plays.get((player, S), 1),
             p)
            for p, S in moves_states
        )

        # Display the stats for each possible play.
        for x in sorted(
            ((100 * self.wins.get((player, S), 0) /
              self.plays.get((player, S), 1),
              self.wins.get((player, S), 0),
              self.plays.get((player, S), 0), p)
             for p, S in moves_states),
            reverse=True
        ):
            debug("{3}: {0:.2f}% ({1} / {2})".format(*x))

        debug(f"Maximum depth searched: {self.max_depth}")

        return move



    def run_simulation(self):
        # A bit of an optimization here, so we have a local
        # variable lookup instead of an attribute access each loop.
        plays, wins = self.plays, self.wins

        visited_states = set()
        vboard = deepcopy(self.board)
        states_copy = value.compact_state()
        player = vboard.current_player()

        expand = True
        for t in range(1, self.max_moves + 1):
            legal = vboard.legal_moves()
              moves_states = [(p, vboard.next_state(p)) for p in legal]

            if all(plays.get((player, S)) for p, S in moves_states):
                # If we have stats on all of the legal moves here, use them.
                log_total = math.log(
                    sum(plays[(player, S)] for p, S in moves_states))
                value, move, state = max(
                    ((wins[(player, S)] / plays[(player, S)]) +
                     self.C * sqrt(log_total / plays[(player, S)]), p, S)
                    for p, S in moves_states
                )
            else:
                # Otherwise, just make an arbitrary decision.
                move, state = choice(moves_states)
                vboard.play(move)

            states_copy.append(state)

            # `player` here and below refers to the player
            # who moved into that particular state.
            if expand and (player, state) not in plays:
                expand = False
                plays[(player, state)] = 0
                wins[(player, state)] = 0
                if t > self.max_depth:
                    self.max_depth = t

            visited_states.add((player, state))

            winner = vboard.winner()
            if not winner == -1:
                break

            player = vboard.current_player()

        for player, state in visited_states:
            if (player, state) not in plays:
                continue
            plays[(player, state)] += 1
            if player == winner:
                wins[(player, state)] += 1

        


# game loop
while True:
    opponent_size, opponent_col = [int(i) for i in input().split()]
    valid_action_count = int(input())
    for i in range(valid_action_count):
        size, col = [int(j) for j in input().split()]
        debug(f'size:{size}, col:{col}')
        

    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr)

    print("0 0")
