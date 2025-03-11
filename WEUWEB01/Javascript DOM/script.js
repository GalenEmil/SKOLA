let titel = document.getElementById("titel")
titel.innerHTML = "Hej, världen och hallo Andreas"

let stolar = document.getElementsByClassName("stolar")
console.log(stolar)

for (let i = 0; i < stolar.length; i++) {
    stolar[i].style.backgroundColor = "blue";
}

let knapp = document.querySelector("button")
console.log(knapp)
knapp.style.color = "red"

let minBox = document.getElementById("minBox")
minBox.style.height = "100px"
minBox.style.width = "200px"
minBox.style.backgroundColor = "pink"

let content = document.getElementById("content")
content.innerHTML = "Det här är ett nytt innehåll"

let nytt = document.createElement("p")
nytt.innerHTML = ("Ny paragraf!")
document.body.appendChild(nytt)

// Skapa ett nytt element och lägg till det som det första barnet till en annan div.
// Skapa en ny div med texten "Ny div!" och lägg till den som det första barnet i en annan containerdiv.

let nyDiv = document.createElement("div")
nyDiv.textContent = "Ny div!"
nyDiv.id = "ParentDiv"
document.body.appendChild(nyDiv)

let nyDiv2 = document.createElement("div")
nyDiv2.textContent = "Ny div2!"
nyDiv2.id = "ChildDiv"
nyDiv.appendChild(nyDiv2)

// Skapa lista dynamiskt med tre element i
let lista = document.createElement("ul")
document.body.appendChild(lista)
let listItem1 = document.createElement("li")
let listItem2 = document.createElement("li")
let listItem3 = document.createElement("li")

listItem1.textContent = "Element 1"
listItem2.textContent = "Element 2"
listItem3.textContent = "Element 3"

document.querySelector("ul").appendChild(listItem1)
document.querySelector("ul").appendChild(listItem2)
document.querySelector("ul").appendChild(listItem3)

// Skapa en knapp som tar bort det sista elementet i listan
let knapp2 = document.createElement("button")
knapp2.textContent = "Ta bort sista elementet"
document.body.appendChild(knapp2)

knapp2.addEventListener("click", function() {
    document.querySelector("ul").removeChild(listItem3)
})