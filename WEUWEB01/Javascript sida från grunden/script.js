let knapp = document.getElementById("changeColorButton")
let valAvFarg = document.getElementById("colorInput")

console.log(valAvFarg.value)


let themes = {
    whiteBlack : { background: "black", text: "white" },
    yellowBlue: { background: "yellow", text: "blue" },
    redWhite: { background: "red", text: "white" }
}

document.getElementById("changeColorButton").addEventListener("click", function(){
    document.body.style.backgroundColor = themes[valAvFarg.value].background
    document.body.style.color = themes[valAvFarg.value].text
});

/*
body
{
    animation-duration: 3s;
    animation-name: slide-in;
    animation-iteration-count: infinite;
    animation-direction: alternate;
}

#kaos
{
    display: block;
}


@keyframes slide-in {
    from {
    translate: 150vw 0;
    scale: 200% 1;
    }

    to {
        translate: 0 0;
        scale: 100% 1;
    }} 
Försök att få denna css kod att köras när man klickar på kaos knappen
*/
let kaosKnapp = document.getElementById("kaos")
let body = document.body

kaosKnapp.addEventListener("click", function(){
    body.style.animationDuration = "3s"
    body.style.animationName = "slide-in"
    body.style.animationDirection = "alternate"
    body.style.animationIterationCount = "infinite"
});

/* RESET css knapp*/
let resetKnapp = document.getElementById("resetKnapp")

resetKnapp.addEventListener("click", function(){
    body.style.backgroundColor = "white"
    body.style.color = "black"
    body.style.animationIterationCount = "0"
});