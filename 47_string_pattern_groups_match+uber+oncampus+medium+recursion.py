
"""
def xpattern_match_helper(c, target, c_map):
	if c in c_map:
			if not prefix_target_matches_c(c_map[c], target):
				return false
			else:
				#return pattern_match_helper(target[len(c_map[c]]:)
			

def xpattern_match(pattern, target, c_map):
	for c in pattern:
		for i in enumerate(target):
			c_map[c] = target[:i]
			
			if (pattern_match(pattern[1:], target[i:], c_map)):
				


			#if (!target):
			#	pattern_match(pattern[1:], target, c_map)
			#else:
			#	break
"""	
"""
Problem is that:
1) abba => HotPotPotHot is true, because "a" matches "Hot" and "b" matches "Pot".

2) aabba => HelloHelloOhOhLoll is False.
"""

def pattern_match(pattern, target, c_map):
	print pattern, target, c_map
	if pattern == "":
		return target == ""
	
	c = pattern[0]
	if c in c_map:
		if target.startswith(c_map[c]):
			return pattern_match(pattern[1:], target[len(c_map[c]):], c_map)
		else:
			del(c_map[c])
			return False
	else:
		for i in range(1, len(target)):
			c_map[c] = target[:i]
			if pattern_match(pattern[1:], target[i:], c_map):
				return True		
	return False


c_map = {}
print pattern_match("abba", "hegghe", c_map)

c_map = {}
print pattern_match("aabb", "hothotcoldcold", c_map)

