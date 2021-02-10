# ABBB problem

# Rules: AB or BB, explotes a bomb, they have in common that they end in B
# It is like problems of balanced parenthesis [{()}], so a stack is used

# Algorithm:
# 1. If a B is read, then delete previous value
# 2. Else if there is no previous value, or an A is read, insert in stack
# 3. After the whole string is read, count the remaining letters inside the stack

# read number
numberOfWords = input()

# read each word
for i in range(numberOfWords):
    stack = []
    word = str(raw_input())

    # do the main logic for each word
    for j in range(len(word)):
        # if it as a B, check if there is a previous and delete it, else insert
        if word[j] == "B":
            if (len(stack) == 0):
                stack.append("B")
            else:
                stack.pop()
        else:
            stack.append("A")

    print(len(stack))
