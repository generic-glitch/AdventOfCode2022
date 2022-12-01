f = open("puzzle_input.txt", "r")
text = f.read()
array = text.split("\n")
totalCals = []
currentTotal = 0
for i in range(len(array)):
    if array[i] == '':
        totalCals.append(currentTotal)
        currentTotal = 0
    else:
        currentTotal += int(array[i])
totalCals = sorted(totalCals, reverse=True)
print(totalCals[0]+totalCals[1]+totalCals[2])