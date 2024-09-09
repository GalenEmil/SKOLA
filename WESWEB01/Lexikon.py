studentName = "Bartolomeus"
studentAge = 18
studentProgram = "TE23"
studentCourses = ["Programmering 2", "Engelska 6", "Fysik 1"]

studentName2 = "Jesper"
studentAge = 17
studentProgram = "TE22"
studentCourses = ["Programmering 2", "Engelska 6", "Fysik 1"]

# Inte ett bra sätt att skriva data på

# Lexikon
# Lexikon är som listor fastän istället för index i heltal såsom 0, 1, 2. 
# Så är det en valfri string

student1 = {
    "name": "Bartolomeus",
    "age": 18,
    "program": "TE23",
    "courses": ["Programmering 2", "Engelska 6", "Fysik 1"]
}

student2 = {
    "name": "Jesper",
    "age": 17,
    "program": "TE22",
    "courses": ["Programmering 2", "Engelska 6", "Fysik 1"]
}

print(student1["name"], "går i programmet", student1["program"], "och är", student1["age"], "gammal")

# Lägga in flera dictionaries i en lista
students = [
    student1,
    student2,
]