// Night mode knapp
const knapp = document.getElementById("nightModeButton");

knapp.addEventListener("click", function(){
    document.body.classList.toggle("night");
})

// Lägg till en counter för att räkna antalet produkter i kundvagnen
let count = 0;

// Lägg till i kundvagn popup
document.addEventListener("DOMContentLoaded", () => {
    const cartButtons = document.querySelectorAll(".addToCartButton");
    // När man har class istället för id så används querySelectorAll
    // för att hämta alla knappar med den klassen
    // Det är lite krångligare än med id
    // Men det behövdes för att vi har flera knappar
    // som ska göra samma sak
    cartButtons.forEach(button => {
        button.addEventListener("click", () => {
            showAddToCartPopup();
        });
    });

    function showAddToCartPopup() {
        const popup = document.createElement("div");
        popup.className = "cart-popup";
        popup.textContent = "Produkten har lagts i kundvagnen!";
        document.body.appendChild(popup);
        // Detta ska fungera som en timer tills popupen försvinner
        setTimeout(() => {
            popup.remove();
        }, 3000);
        // Counter för antal produkter i kundvagn
        count++;
    }
});

// Visa antal produkter i kundvagn
const knapp2 = document.getElementById("shoppingCartButton");

knapp2.addEventListener("click", function(){
    const popup = document.createElement("div");
    popup.className = "cart-popup";
    popup.textContent = "Du har " + count + " produkter i kundvagnen!";
    document.body.appendChild(popup);
})
