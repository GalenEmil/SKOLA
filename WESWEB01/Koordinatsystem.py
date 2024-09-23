import matplotlib.pyplot as plt
import numpy as np
import math

data = [
    [0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1], # 0
    [1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0], # 1
    [0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1], # 2
    [1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0], # 3
    [0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1], # 4
    [1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0], # 5
    [0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1], # 6
    [1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0], # 7
    [0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1], # 8 
    [1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0], # 9
    [0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1], # 10
    [1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0]  # 11
] #  0  1  2  3  4  5  6  7  8  9  10 11

# Ännu en ny grid
# 1000 x 1000
def setSize(size):
    global data
    data = []
    for i in range(size):
        data.append([1]*size)

setSize(500)

print(len(data))
print(len(data[0]))
# SKRIV DIN LÖSNING HÄR
# ---------------------
# Rensa skärmen till en färg
for i in range(len(data)):
    for j in range(len(data[i])):
        data[i][j] = 1

"""
# Alla hörn
# Funkar bara med grid 12x12
data[0][0] = 0
data[11][11] = 0
data[0][11] = 0
data[11][0] = 0

# 4 i mitten
# Funkar bara med grid 12x12
data[5][5] = 0
data[5][6] = 0
data[6][5] = 0
data[6][6]= 0

# Rektangel
# Funkar bara med grid 12x12

for j in range(len(data[0])):
    data[0][j] = 0

for j in range(len(data[0])):
    data[11][j] = 0

for x in range(len(data)):
    data[x][0] = 0

for x in range(len(data)):
    data[x][11] = 0

# Varannan rad
# Körs utan färgrensning först
for i in range(len(data)):
    for j in range(len(data[i])):
        data[i][j] = data[i][0]

#Varannan kolumn
for i in range(len(data)):
    for j in range(len(data[i])):
        if j%2 == 0:
            p = j
        data[i][p] = 0
"""
# Cirkel med trigonometri
# Anpassat för 500x500 grid, funkar sämre med mindre storlek
mitten = len(data)//2
# Skapa cirkel imitten av griden i vitt
for x in range(len(data)):
    for y in range(len(data[x])):
        if (x-mitten)**2 + (y-mitten)**2 < mitten**2:
            data[x][y] = 0

# Skapa mindre cirkel i mitten av griden i svart
for x in range(len(data)):
    for y in range(len(data[x])):
        if (x-mitten)**2 + (y-mitten)**2 < (mitten-15)**2:
            data[x][y] = 1

# ---------------------

grid = np.array(data)
fig, ax = plt.subplots()
cmap = plt.get_cmap('Greys')
ax.imshow(grid, cmap=cmap)

#ax.set_xticks(np.arange(-0.5, 12, 1), minor=True)
#ax.set_yticks(np.arange(-0.5, 12, 1), minor=True)
ax.grid(which='minor', color='black', linestyle='-', linewidth=2)

ax.tick_params(which='both', size=0, labelbottom=False, labelleft=False)

plt.show()