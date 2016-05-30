# Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character. Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of 8 adjacent characters, but a word should not have multiple instances of same cell.

# Enter your code here. Read input from STDIN. Print output to STDOUT

# Input: words[] = {"GEEKS", "FOR", "QUIZ", "GO"};
#       boggle[][]   = {{'G','I','Z'},
#                       {'U','E','K'},
#                       {'Q','S','E'}};

# Output:  Following words are present
#         GEEKS
#         QUIZ

prefix_map = {}
def preprocess(words):
    for word in words:
        for i in range(len(word) - 1):
            if word[:i+1] not in prefix_map:
                prefix_map[word[:i+1]] = False
        prefix_map[word] = True
    return prefix_map

def get_directions(i, j, words):
    p_d = [(-1, -1), (0, -1), (1, -1), (-1, 0), (1, 0), (-1, 1), (0, 1), (1, 1)]
    ds = []
    for p in p_d:
        new_x = i + p[0]
        new_y = j + p[1]
        if (new_x < 0 or new_x >= len(words)):
            continue
        if (new_y < 0 or new_y >= len(words[new_x])):
            continue
        ds.append((new_x, new_y))
    return ds
        
#print get_directions(0, 0, ["giz", "uek"])

seen = []
def search_helper(prefix, i, j, words):
    if seen[i][j]:
        return
    #print i, j
    prefix_c = prefix + words[i][j]
    #print prefix_c
    if prefix_c in prefix_map:
        if prefix_map[prefix_c]:
            print prefix_c
            return
        else:
            seen[i][j] = True
            for di in get_directions(i, j, words):
                search_helper(prefix_c, di[0], di[1], words)
            seen[i][j] = False
    else:
        return

def reset_seen(words):
    for i in range(len(words)):
        seen.append([])
        for c in words[i]:
            seen[i].append(False)
    
def search_words(words):
    for i in range(len(words)):
        for j in range(len(words[i])):
            reset_seen(words)
            search_helper("", i, j, words)            

preprocess(["GEEKS", "FOR", "QUIZ", "GO"])
search_words(["GIZ", "UEK", "QSE"])
