# This is the text editor interface. 
# Anything you type or change here will be seen by the other person in real time.

# 6 9 3 / + => 6 + ( 9 / 3 ) ==> 9
# 6 9 + 3 / => (6 + 9) / 3 ==> 5

# operators: +, -, /, *
# If input == "", print nothing.
# If Math Error, print "MathError".
# If there are no operators available for operands, "OperatorMissing".
# If there are no operands available, return "OperandMissing"
def calculate(input):
    if (input == ""): return ""
    
    input = input.split(" ")
    stack = []
    for val in input:
        if val in ['*', '+', '-', '/']:
            if (len(stack) > 0):
                op1 = stack.pop()
            else:
                return "OperandMissing"
            
            if (len(stack) > 0):
                op2 = stack.pop()
            else:
                return "OperandMissing"
                
            try:
                out = eval(str(op2) + val + str(op1))
            except ZeroDivisionError:
                return "MathError"
                
            stack.append(out)
        else:
            val = float(val)
            stack.append(val)
    
    if (len(stack) > 1):
        return "OperatorMissing"
    return stack.pop()
    

print calculate("6 9 + 3 /")
print calculate("6 9 3 / +")
print calculate("1 0 /")
print calculate("")
print calculate("7 3 /")
print calculate("4 0 - 7 3 / +")
print calculate("3 5 *")
print calculate("4.5 1.5 /")
print calculate("100 5 6 10 5 / * + -")

print calculate("3 3") # OperatorMissing.
print calculate("3 +") # OperandMissing.
print calculate("+ + -") # OperandMissing.
