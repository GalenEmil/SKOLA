let nummer = [1,2,3,4,5];
console.log(nummer);
nummer.push(7);
console.log("push 7");
console.log(nummer);
nummer.pop();
console.log("pop");
console.log(nummer);
nummer.unshift(-1);
console.log("unshift -1");
console.log(nummer);
nummer.shift();
console.log("shift");
console.log(nummer);

wordles =  ["Hemle", "Blämming", "Hallo", "Vem", "Varför"];
console.log("En loop av ord")
for(let i = 0; i < wordles.length; i++){
    console.log(wordles[i]);
}

let tal_Som_Är_Slumpmässade_Trots_Att_De_Egentligen_Är_Skrivna_Utav_Mig = [2,19,20,23,23,34,21,65,96,10]
console.log("En loop av siffror")
tal_Som_Är_Slumpmässade_Trots_Att_De_Egentligen_Är_Skrivna_Utav_Mig.forEach(tal_Som_Är_Slumpmässade_Trots_Att_De_Egentligen_Är_Skrivna_Utav_Mig => {
    console.log(tal_Som_Är_Slumpmässade_Trots_Att_De_Egentligen_Är_Skrivna_Utav_Mig)
})

console.log("Summan")
let sum = 0
tal_Som_Är_Slumpmässade_Trots_Att_De_Egentligen_Är_Skrivna_Utav_Mig.forEach(tal_Som_Är_Slumpmässade_Trots_Att_De_Egentligen_Är_Skrivna_Utav_Mig => {
    sum += tal_Som_Är_Slumpmässade_Trots_Att_De_Egentligen_Är_Skrivna_Utav_Mig
})
console.log(sum)

console.log("5 Eigenname")
let eigenname = ["Alvar", "Joel", "Olives", "Niagara", "Washington"]
for(let i = 0; i < eigenname.length; i++){
    console.log(eigenname[i])
}

/*
Övningar för att skapa och manipulera objekt:
Skapa ett objekt som representerar en bil (t.ex. egenskaper som färg, modell, år) och skriv ut värdena för varje egenskap i konsolen.

Lägg till en ny egenskap till ditt bil-objekt, till exempel pris och skriv ut objektet igen.
Ändra värdet på en egenskap i ett objekt (t.ex. ändra modell på bilen till en annan modell) och skriv ut objektet.
Ta bort en egenskap från ett objekt (t.ex. ta bort år från bil-objektet) och skriv ut objektet.
Övningar för att loopa genom objekt:
Skapa ett objekt med tre nyckel-värde-par (t.ex. namn, ålder, stad) och använd en for...in loop för att skriva ut varje nyckel och dess värde.
Skapa ett objekt med olika information om en person (t.ex. namn, ålder, favoritmat). Använd Object.entries() för att loopa genom objektet och skriv ut varje nyckel och värde.
*/

let bil = { färg: "röd", modell: "Volvo", år: 2020 }
console.log(bil)
bil.pris = 200000
console.log(bil)
bil.modell = "Saab"
console.log(bil)
delete bil.år
console.log(bil)

let person = { namn: "Alvar", ålder: 17, stad: "Karlstad" }
for(let nyckel in person){
    console.log(nyckel + ": " + person[nyckel])
}


let enAnnanPerson = { namn: "Joel", ålder: 89, favoritmat: "Köttbullar", favoritspel: "Terraria", favoritstol: "Fin köksstol" }
Object.entries(enAnnanPerson).forEach(([key, value]) => {
    console.log('Key: ' + key + ' Value: ' + value)
});