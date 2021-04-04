from math import sqrt
def dist(x1,y1, x2, y2):
	#dist:sqrt( ( x1 - x2 )^2 + ( y1 - y2 )^2 )
	x_sqr_diff = (x1 - x2)**2
	y_sqr_diff = (y1 - y2)**2
	dist = sqrt(x_sqr_diff + y_sqr_diff)
	return dist

print dist(1,0,1,2)