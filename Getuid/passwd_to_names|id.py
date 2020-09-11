file = open("/etc/passwd", "r")
file1 = open("names.txt", "w")
names = []
for line in file:
    temp = line.split(':')[0:3]
    names.append([temp[0], temp[2]])

for name in names:
    file1.write("{},{}\n".format(name[0], name[1]))

file.close()
file1.close()