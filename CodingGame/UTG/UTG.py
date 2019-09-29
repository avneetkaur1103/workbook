import sys
import math
from collections import defaultdict
import random

# Deliver more ore to hq (left side of the map) than your opponent. Use radars to find ore but beware of traps!

# height: size of the map
width, height = [int(i) for i in input().split()]
pods = list()
radars = list()
traps = list()
holes = list()
opp_pod = list()

radars_stations = [(8,9)(11,4),(14,4),(17,4),(20,9),(23,11),(26,9)]
trap_stations = []
random_dig_flag = [False]*5

class Pod:
	def __init__(self, id, pos, item):
		self.id = id 
		self.pos = pos
		self.item = item
		self.radar_pos = None
		self.pick_radar = False
		self.pick_trap = False
		self.assigned_ore = None
		self.nearest_ores = None
		self.distance_from_home = pos[0]

	def assign_radar(self, pos):
		self.radar_pos = pos
		self.pick_radar = True

	def assign_trap(self, pos):
		self.trap_pos = pos
		self.pick_trap = True

	def assign_ore(self, ore):
		self.assigned_ore = ore

class Radar:
	def __init__(self, id, pos, item):
		self.id = id 
		self.pos = pos
		self.item = item

class Trap:
	def __init__(self, id, pos, item):
		self.id = id 
		self.pos = pos
		self.item = item

class Ore:
	def __init__(self, x, y, count):
		self.pos = x, y
		self.count = count

def dist(a, b):
	return math.sqrt((a[0]-b[0])**2 - (a[1]-b[1])**2)		

def min_dist(pos, ores):
	d_min = float('inf')
	nearest = ores[0]
	for ore in ores:
		d = dist(ore.pos, pos)
		if d < d_min:
			d_min = d
			nearest = ore
	return nearest

def get_random_pos():
	x = random.randint(0,30)
	y = random.randint(0,15)
	return x, y

class Game:
	def __init__(self):
		self.grid = [[-1 for _ in range(width)] for _ in range(height)]

	def play(self):
		for pod in pods:
			pod.distance_from_home = pod.pos[0]
			pod.nearest_ores = min_dist(pod.pos, ores)

		pods_near_home = sorted([pod for pod in pods if not pod.item == 4], key=lambda elem: abs(elem.pos[0]))
		best_points_for_radar = defaultdict(list())

		for rpos in radars_stations:
			best_points_for_radar[rpos].append(sorted([pod for pod in pods if pod.item == -1], key= lambda pod: pod.distance_from_home + abs(pod.pos[y]-rpos[1])))
		if radars_stations:  # Radar Plantation 
			for rpos in radars_stations:
				for nearest_pod in best_points_for_radar[rpos]: #check TODO
					if nearest_pod == pod:
						pod.assign_radar(rpos)
						radars_stations.remove(rpos)
					elif not nearest_pod.pick_radar:
						nearest_pod.assign_radar(rpos)

		for i, pod in enumerate(pods):
			if pod.item == 4:
				print(f'MOVE {0} {pod.y}')
			elif pod.item == 3: # check
				if abs(pod.pos[0]-pod.trap_pos[0]) + abs(pod.pos[1]-pod.trap_pos[0]) <= 1:
					print(f'DIG {pod.trap_pos[0]} {pod.trap_pos[1]}')
				else:
					print(f'MOVE {pod.trap_pos[0]} {pod.trap_pos[1]}')
			elif pod.item == 2: # check
				if abs(pod.pos[0]-pod.radar_pos[0]) + abs(pod.pos[1]-pod.radar_pos[0]) <= 1:
					print(f'DIG {pod.radar_pos[0]} {pod.radar_pos[1]}')
					pod.pick_radar = False
				else:
					print(f'MOVE {pod.radar_pos[0]} {pod.radar_pos[1]}')
			else:
				if pod.pick_radar: # make it false when planted
					if pod.pos[0] == 0:
						if not radarCooldown:
							print("REQUEST RADAR")
							radar_cooldown = 5
						else:
							print('WAIT') # wait at home
					else:
						for j in range(pod.pos[1], -1, -1):  #Y  pick point on the way to home
							if grid[pod.pos[0]][j] > 0:
								grid[pod.pos[0]][j] -= 1
							if grid[pod.pos[0]][j] == 0:
								ores.remove((pod.pos[0],y))
						print(f'MOVE {0} {pod.pos[1]}')

				if not pod.pick_radar: # Point collection
					pod.assign_ore(nearest_ores) if not pod.assigned_ore and ores else None # Assign ore if ores available and not assigned alreday
					if pod.assigned_ore:
						if abs(pod.pos[0]-pod.assign_ore.pos[0]) + abs(pod.pos[1]-pod.assign_ore.pos[0]) <= 1:
							print(f'DIG {pos.assigned_ore.pos[0]} {pos.assigned_ore.pos[1]}')
							pod.assigned_ore = None
							continue
						else:
							print(f'MOVE {pos.assigned_ore.pos[0]} {pos.assigned_ore.pos[1]}')
					else:
						debug(f'No ores assigned to pod {pod.id}')
						print('WAIT')

				if not pod.assigned_ore:
					for rpos in extra_radars_stations:
						best_points_for_extra_radar[rpos].append(sorted([pod for pod in pods if pod.item == -1], key= lambda pod: pod.distance_from_home + abs(pod.pos[y]-rpos[1])))
					if extra_radars_stations:  # Radar Plantation 
						for rpos in extra_radars_stations:
							for nearest_free_pod in best_points_for_extra_radar[rpos]: #check TODO
								if nearest_free_pod == pod:
									pod.assign_radar(rpos)
									radars_stations.remove(rpos)
								elif not nearest_free_pod.pick_radar:
									nearest_free_pod.assign_radar(rpos)
						if pod.pick_radar: # make it false when planted
							if pod.pos[0] == 0:
								if not radarCooldown:
								print("REQUEST RADAR")
								radar_cooldown = 5
							else:
								print('WAIT') # wait at home
						else:
							for j in range(pod.pos[1], -1, -1):  #Y  pick point on the way to home
								if grid[pod.pos[0]][j] > 0:
									grid[pod.pos[0]][j] -= 1
								if grid[pod.pos[0]][j] == 0:
									ores.remove((pod.pos[0],y))
							print(f'MOVE {0} {pod.pos[1]}')
					if not pod.pick_radar and not myScore: #Follow other radar pods
						follow = min([for p in pods if p.pick_radar and not p == pod], key=lambda p: dist(p.pos, pod.pos))
						if follow:
							print(f'MOVE {follow.pos[0]} {follow.pos[1]}')
							continue
						else:
							if random_dig_flag[i]:
								if pod.pos not in holes:
									print(f'DIG {pod.pos[0]} {pod.pos[1]}')
									random_dig_flag[i] = False
									continue
							x, y = get_random_pos()
							print(f'MOVE {x} {y}')


game = Game()
# game loop
while True:
    # my_score: Amount of ore delivered
    pods.clear()
    radars.clear()
    traps.clear()
    holes.clear()
    my_score, opponent_score = [int(i) for i in input().split()]
    for i in range(height):
        inputs = input().split()
        for j in range(width):
            # ore: amount of ore or "?" if unknown
            # hole: 1 if cell has a hole
            ore = inputs[2*j]
            hole = int(inputs[2*j+1])
            if hole:
            	grid[i][j] = -2
            	holes.append((j,i))
            elif not ore == '?':
            	grid[i][j] = int(ore)
            	ores.append(Ores(j, i, int(ore)))
    # entity_count: number of entities visible to you
    # radar_cooldown: turns left until a new radar can be requested
    # trap_cooldown: turns left until a new trap can be requested
    entity_count, radar_cooldown, trap_cooldown = [int(i) for i in input().split()]
    for i in range(entity_count):
        # id: unique id of the entity
        # type: 0 for your robot, 1 for other robot, 2 for radar, 3 for trap
        # y: position of the entity
        # item: if this entity is a robot, the item it is carrying (-1 for NONE, 2 for RADAR, 3 for TRAP, 4 for ORE)
        id, type, x, y, item = [int(j) for j in input().split()]
        if type == 0:
        	pods.append(Pod(id, (x, y), item))
        elif type == 1:
        	pass
        elif type == 2:
        	radars.append(Radar(id, (x, y), item))
        elif type == 3:
        	traps.append(Trap(id, (x, y), item))
    for i in range(5):

        # Write an action using print
        # To debug: print("Debug messages...", file=sys.stderr)

        # WAIT|MOVE x y|DIG x y|REQUEST item
        print("WAIT")