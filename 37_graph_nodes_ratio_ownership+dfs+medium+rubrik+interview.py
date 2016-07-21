'''
Company A owns 10% of Company B
Company B owns 5% of Company C
Company A owns 2% of Company C

How much of Company C does Company A own? 2.5%

Exercise:
1) Model this, assumptions
2) Implement getOwnership(source, target) # float
'''
# Interview question from rubrik telephonic interview round.

# [{A : [(b, .01), (c, .02)}, {B : [(c, .05)]}, {C : [(d, .02)]}]
class Node:
  def __init__(self):
    child = []
	  visited = False

cache = {}
def getOwnership(source, target):
  global cache
  # If we don't do this, we would have exponential complexity.
  # Because we have to do traverse same path over and over again.
  #    /\
  #    \/
  #    /\
  #    \/ and so on. 
  # Therefore, we would have to save the computations that we have done once.
  if (source, target) in cache:
    return cache[(source, target)]
    
  total = 0
  source.visited = True
  for child in source.child:
    if child[0] == target:
      total += child[1]
    else:
      if not child.visited:
        x = getOwnership(child[0], target)
        total += x * child[1]
  source.visited = False
  cache[(source, target)] = total
  return total
  
