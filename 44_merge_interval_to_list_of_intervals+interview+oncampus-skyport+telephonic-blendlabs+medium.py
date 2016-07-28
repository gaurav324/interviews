# Let (x,y) be the range from x to y such that x<y
# Let [(a,b), (c,d), ...] be a list of ranges such that a<b, b<c

# Write a function to merge (x,y) into the list such that the ordering property is preserved and every range is contained in the list

# (1,2), [(3,4)] => [(1,2), (3,4)]
# (1,4), [(0,1), (3,7)] => [(0,7)]
# (1, 4), [(0, 1), (3, 7), (9, 10)] = [(0, 7), (9, 10)]

def onLeft(first, second):
    return first[1] < second[0]

def canMerge(first, second):
    if onLeft(first, second) or onLeft(second, first):
        return False
    return True
    
def doMerge(first, second):
    return (min(first[0], second[0]), max(first[1], second[1])) 

def merge(tup, lst):
    ans = []
    for i, rng in enumerate(lst):
        if onLeft(tup, rng):
            ans.append(tup)
            ans.extend(lst[i:])
            return ans
        elif canMerge(tup, rng):
            tup = doMerge(tup, rng)
        else:
            ans.append(rng)
    ans.append(tup)
    return ans

print merge((1, 2),  [(3, 4)])
print merge((1, 4),  [(0, 1), (3, 7)])
print merge((1, 4),  [(0, 1), (3, 7), (9, 10)])
print merge((9, 10), [(0, 1), (3, 6)])
print merge((1, 5),  [(3, 7), (9, 11)])
print merge((6, 10), [(1, 3), (4, 5), (8, 11)])
print merge((1, 9),  [(2, 4), (5, 7), (9, 15)])



#--------------------
print merge((1,4) , [(-1,3), (7,10)]) == [(-1, 4), (7, 10)]
print merge((1,2) , [(2,3), (6,8), (100, 200)]) == [(1, 3), (6, 8), (100, 200)]
print merge((5,10) , [(2,3), (6,8), (100, 200)]) == [(2, 3), (5, 10), (100, 200)]
print merge((7,150) , [(2,3), (6,8), (100, 200)]) == [(2, 3), (6, 200)]
print merge((1,2) , []) == [(1, 2)]
print merge((10,20) , [(2,3), (4,8), (100, 200)]) == [(2, 3), (4, 8), (10, 20), (100, 200)]
