class Node:
	def __init__(self, c, left, right):
		self.c = c
		self.left = left
		self.right = right

def inorder_print(n):
	if n is None:
		return ""

	s = inorder_print(n.left)
  s = s + str(n.c) + inorder_print(n.right)
	return s

def inorder_iterative(n):
	stack = []
	s = ""
	while (n is not None or !stack.empty()):
		if n is not None:
			stack.push(n)
			n = n.left
		else:
			n = stack.pop()
			s.append(n.c)
			n = n.right
	return s
		

class TreeIterator:
	def __init__(self, n):
		self.stack_ = []
		self.n_ = n

	def has_next():
		if n_ is None and stack.empty():
			return false:
		return true
	
	def next():
		if not has_next():
			raise Exception("No more elements.")

		while(n_ is not None):
			stack_.push(n)
			n_ = n.left
		else:
			n_ = stack.pop()
			x = n_.c
		  n_ = n_.right
			return x		



inorder(check_eq(tree("gaurav"), "gaurav"))


n = Node('a', None, None)
inorder_print(n)
