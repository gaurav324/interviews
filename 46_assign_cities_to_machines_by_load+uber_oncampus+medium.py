"""
Problem states that there are a bunch of cities, and each city has load assoicated with it.
Load is an estimate that how many cars are running there.

We need to distribute N cars to M machines. So that each city is only processed by one machine.
There is another constraint that we have cities which are close enough (< threshold distance).

SOLUTION:
1) We create clusters of the city, such that all the cities within threshold are in the same group.
2) Then we sum up load of all the cities in that group, and group act like on entity.
3) Then we reverse sort all the groups by threshold. Then we start allocating these groups to
   machines, one by one and then we keep on adding more and more the cities to machines.
	(Add cities to machines/pods code is not written.)

"""
def cluster(city_load_map, threshold):
  ans = {}

	groups = []
	for city in city_load_map:
		group.append([city])

  for city in city_load_map:
		matching = []
		for group in groups:
			for c in group:
				if (match(city, c, threshold)):
					matching.append(group)
					break
		new_group = []
		for g in matching:
			new_group.extend(g)
			del(groups[g])
		groups.append(new_group)

		for g in groups:
			load = 0
			for c in g:
				load += city_load_map[c]
			ans[g] = load
	return ans
			

city_load_map = {2 : 5, 6 : 2, 8 : 1, 11 : 1}
threshold = 3

new_city_load_map = cluster(city_load_map, threshold)
pods = 2

allocations = match_city_pod(new_city_load_map, pods)
