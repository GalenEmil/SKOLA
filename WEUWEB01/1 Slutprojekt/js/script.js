const knapp = document.getElementById("nightModeButton");

knapp.addEventListener("click", function(){
    document.body.classList.toggle("night");
})