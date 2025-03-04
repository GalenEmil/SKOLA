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