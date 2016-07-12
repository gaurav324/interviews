# # # # Create a function that prints to the terminal a spiral,
# # # # and can take two inputs, width and height, which indicate the size of the spiral
# # # # 
# # # # '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
# # # # '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
# # # # '@', ' ', '@', '@', '@', '@', '@', '@', '@', '@'
# # # # '@', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', '@'
# # # # '@', ' ', '@', ' ', '@', '@', '@', '@', ' ', '@'
# # # # '@', ' ', '@', ' ', ' ', ' ', ' ', '@', ' ', '@'
# # # # '@', ' ', '@', ' ', ' ', ' ', ' ', '@', ' ', '@'
# # # # '@', ' ', '@', '@', '@', '@', '@', '@', ' ', '@'
# # # # '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@'
# # # # '@', '@', '@', '@', '@', '@', '@', '@', '@', '@'
# 

cur_dir_index = -1
dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]
def get_next_dir():
    global cur_dir_index
    cur_dir_index = (cur_dir_index + 1) % 4
    return dirs[cur_dir_index]

col_steps = 0
row_steps = 0
def get_steps():
    global col_steps, row_steps
    if cur_dir_index == 0 or cur_dir_index == 2:
        ans = col_steps
        col_steps -= 2
        return ans
    else:
        ans = row_steps
        row_steps -= 2
        return ans
    
def printSpiral(w, h):
    global col_steps, row_steps
    col_steps = h
    row_steps = w
    arr = []
    for i in range(h):
        temp = []
        for j in range(w):
            temp.append(' ')
        arr.append(temp)
    
    cur_dir_index = 0
    ptr = [0, 0]
    count = 0
    while(True):
        di = get_next_dir()
        steps = get_steps()
        
        if (steps <= 2):
            break
        while(steps != 0):
            print di, ptr
            arr[ptr[0]][ptr[1]] = '@'
            ptr[0] = ptr[0] + di[0]
            ptr[1] = ptr[1] + di[1]
            steps -= 1
        
        ptr[0] = ptr[0] - di[0]
        ptr[1] = ptr[1] - di[1]
        count += 1
        
    for row in arr:
        print row
        
               
printSpiral(14, 10)
