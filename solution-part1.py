f = open("puzzle_input.txt", "r")
text = f.read()
array = text.split("\n")
maxCals = 0
currentTotal = 0
for i in range(len(array)):
    if array[i] == '':
        if currentTotal > maxCals:
            maxCals = currentTotal
        currentTotal = 0
    else:
        currentTotal += int(array[i])
print(maxCals)