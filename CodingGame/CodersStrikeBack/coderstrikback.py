import sys
import math

# This code automatically collects game data in an infinite loop.
# It uses the standard input to place data into the game variables such as x and y.
# YOU DO NOT NEED TO MODIFY THE INITIALIZATION OF THE GAME VARIABLES.
last_x, last_y = None, None
BOOST_USED = False
def debug(*args, **kwargs):
	print(*args, **kwargs, file=sys.stderr)

def dist(x, y, ncx, ncy):
	return math.sqrt((x-ncx)**2 + (y-ncy)**2)

def next_pos(x, y, vx, vy, ncx, ncy, ncp_angle, thrust):
	max_d_parallel, min_d_perpendicular = float('-inf'), float('inf')
	angle = 0
	distance = dist(x, y, ncx, ncy)
	speed = math.sqrt(vx**2 + vy**2)
	for z in range(0, 180, 10):
		try:
			t = 2*speed*math.sin(ncp_angle)/(thrust*math.sin(z/180*math.pi))
			if t:
				z = -z if t < 0 else z
				dparallel = speed*math.sin(ncp_angle)*t + 0.5*thrust*math.cos(z/180*math.pi)*t*t
				dperpendicular= speed*math.sin(ncp_angle)*t + 0.5*thrust*math.sin(z/180*math.pi)*t*t
				#debug(f'z: {z}, diff:{dist(x,y, next_x, next_y)}, target:{distance}, time:{t}')
			else:
				return 0  # angle 0
		except ZeroDivisionError:
			continue
		if max_d_parallel < dparallel :
			#debug(f'diff: {diff}, min_d:{min_d}')
			angle = z
			max_d_parallel, min_d_perpendicular = dparallel, dperpendicular
	debug(f'angle: {angle}, max_d_parallel:{max_d_parallel} min_d_perpendicular:{min_d_perpendicular}')
	return angle

def calculate_thrust(x, y, ncpx, ncpy, angle):
	d = dist(x, y, ncpx, ncpy)
	debug(f'dist: {d}')
	thrust = 100
	if d < 1500:
		debug(f'dist: {d}')
		thrust = (thrust) * d//1500
	if angle == 90:
		thrust = 0
	return int(thrust)

# game loop
while True:

	x, y, next_checkpoint_x, next_checkpoint_y, ncp_dist, ncp_angle = [int(i) for i in input().split()]
	x_opp, y_opp = [int(i) for i in input().split()]
	debug(f'x,y{x,y} angle:{ncp_angle} dist:{dist(x,y,next_checkpoint_x,next_checkpoint_y)}')
	thrust = calculate_thrust(x, y, next_checkpoint_x, next_checkpoint_y, ncp_angle)
	projected_x, projected_y = next_checkpoint_x, next_checkpoint_y
	if last_x or last_y:
		vx, vy = (x - last_x)/1.5, (y-last_y)/1.5
		debug(f'vx, vy: {vx, vy}')
		angle = next_pos(x, y, vx, vy, next_checkpoint_x, next_checkpoint_y, ncp_angle, thrust)
		if True:
			d = dist(x, y, next_checkpoint_x, next_checkpoint_y)
			projected_x = int((next_checkpoint_x-x)*math.cos(angle) - (next_checkpoint_y-y)*math.sin(angle) + x)
			projected_y = int((next_checkpoint_y-y)*math.cos(angle) + (next_checkpoint_x-x)*math.sin(angle) + y)
			#projected_x = int(d*math.cos(angle))
			#projected_y = int(d*math.sin(angle))
	last_x, last_y = x, y
	
	if dist(x, y, next_checkpoint_x, next_checkpoint_y) > 8000 and not BOOST_USED and abs(ncp_angle) <= 20:
		print(f'{projected_x} {projected_y} BOOST')
		BOOST_USED = True
	else:
		print(f'{projected_x} {projected_y} {thrust}')
