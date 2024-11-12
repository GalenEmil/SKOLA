import pygame

fruits = ["Nektarin", "Persika", "Drakfrukt", "Mango", "Kiwi", "Papaya", "Persilja"]

# For loop som skriver ut alla frukter
# Simpelt sätt att skriva på men kan inte ändras i lika stor utsträckning
#for fruit in fruits:
#    print(f"Antal bokstäver i {fruit}: {len(fruit)}" )

#print("")

# Alternativt sätt att skriva samma sak
# Denna metod är bättre för man kan ändra mer i koden och ändra saker i listan
# Eftersom vi inte tar ur listan i loopen
#for i in range(len(fruits)):
#    fruit = fruits[i]
#    print(f"Antal bokstäver i {fruit}: {len(fruit)}")

#print("")

# Skriver ut antalet index i listan
# 0, 1, 2, 3, 4, 5, 6 = 7 index
#print(len(fruits))

# 2D listor
grid = [
    [1, 2, 3], # Index 0
    [4, 5, 6], # Index 1
    [7, 8, 9], # Index 2
]#   0  1  2

#print("Borde vara 8: " + str(grid[2][1]) )
#for i in range(len(grid)):
#    list_in_list = grid[i]
#    for num in list_in_list:
#        print(num)

#databas = [
#    ["jakob", 19, 1200]
#    ["emil", 18,]
#]

# Ett pygame spel där man kan röra på en fyrkant
pygame.init()

win = pygame.display.set_mode((500, 500))
pygame.display.set_caption("Första pygame spelet")

x = 50
y = 50
width = 40
height = 60
vel = 5

run = True
while run:
    pygame.time.delay(100)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False
    
    keys = pygame.key.get_pressed()

    if keys[pygame.K_LEFT]:
        x -= vel
    if keys[pygame.K_RIGHT]:
        x += vel
    if keys[pygame.K_UP]:
        y -= vel
    if keys[pygame.K_DOWN]:
        y += vel
    
    win.fill((0, 0, 0))
    pygame.draw.rect(win, (255, 0, 0), (x, y, width, height))
    pygame.display.update()

pygame.quit()