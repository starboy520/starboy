#!/usr/bin/python

#Traveling Salesman Problem
#s is the set that contain all the points.
#c(s,k) represent point 1 travel the set point in set s with min length, and stop at point k;
#if there is only element k in s: c(s,k) = d[0][k]
#                            else:  c(s,k) = min{c(s/{k},m)+d[m][k]}    m in s/{k}
s = [1,2,3,4,5]
d = [[0,10,20,30,40,50],[12,0,18,30,25,21],[23,19,0,5,10,15],[34,32,4,0,8,16],[45,27,11,10,0,18],[56,22,26,20,12,0]]

def c(s, k):
	if len(s) == 1:
		return d[0][k]
	else:
		t = [i for i in s]     #list is mutable!!!! here I just used t=s then it got wrong
		t.remove(k)
		mini = 10000
		for m in t:
			if c(t,m)+d[m][k] < mini:
				mini = c(t,m) + d[m][k]
		return mini
	
def min_travel():
	mini = 10000
	for k in s:
		if c(s,k)+d[k][0]< mini:
			mini = c(s,k) + d[k][0]
	return mini
	
if __name__ == '__main__':
	print min_travel()
