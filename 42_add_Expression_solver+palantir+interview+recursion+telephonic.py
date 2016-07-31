# This is the text editor interface. 
# Anything you type or change here will be seen by the other person in real time.

"""
 ONE   231
+ONE  +231
----  ----
 TWO   462
 
 FOUR   5239
+FOUR  +5239
-----  -----
EIGHT  10478
 
FOUR   8140
+ONE   +139
----   ----
FIVE   8279

"""

class Expression(object):
    # Gets a set of all the characters in the problem.
    # () -> [O, N, E, T, W]
    def get_chars(self):
        raise NotImplementedError("This is an interface")
 
    # Checks whether or not the proposedSolution is correct.
    # ({O: 2, N:3, E:1, T:4, W:6}) -> true
    def evaluate(self, proposed_solution):
        raise NotImplementedError("This is an interface")
        
        
def convertStringToNumber(s, mapping):
    ans = 0
    i = 0
    for c in s[::-1]:
        ans += mapping[c] * pow(10, i)
        i += 1
    return ans

class AdditionExpression(Expression):
 
    # create whatever instance variables / private methods you wish
 
    def __init__(self, first="ONE", second="ONE", result="TWO"):
        self.first_ = first
        self.second_ = second
        self.result_ = result
     
    def get_chars(self):
        chars = set()
        for x in [self.first_, self.second_, self.result_]:
            for c in x:
                chars.add(c)
        return list(chars)
     
    def evaluate(self, proposed_solution):
        no1 = convertStringToNumber(self.first_, proposed_solution)
        no2 = convertStringToNumber(self.second_, proposed_solution)
        expected_result = convertStringToNumber(self.result_, proposed_solution)

        if no1+no2 == expected_result:
            return True
        else:
            return False

def construct_map(chars, values):
    mp = {}
    for i, c in enumerate(chars):
        mp[c] = values[i]
    return mp

class Solver(object):
    def solve(self, expr):
        chars = expr.get_chars()
        nos = [1] * len(chars)
        return self.solve_helper(chars, nos, 0)
        
    def solve_helper(self, chars, values, i):
        if i == len(values):
            return False
        
        for j in range(1, 10):
            mp = construct_map(chars, values)
            if (expr.evaluate(mp)):
                return mp
                
            values[i] = j
            self.solve_helper(chars, values, i+1)
            
        return False
            
expr = AdditionExpression("OX", "OX", "GB")
s = Solver()
print s.solve(expr)

'''
expr = AdditionExpression("ONE", "ONE", "TWO")
print expr.get_chars()
print expr.evaluate({'O': 2, 'N':3, 'E':1, 'T':4, 'W':6})

expr = AdditionExpression("FOUR", "FOUR", "EIGHT")
print expr.get_chars()
print expr.evaluate({'O': 2, 'F': 5, 'U': 3, 'R': 9, 'E' : 1, 'I': 0, 'G' : 4, 'H' : 5, 'T' : 8})

expr = AdditionExpression("ONE", "", "ONE")
print expr.evaluate({'O': 2, 'N':3, 'E':1 })
'''
