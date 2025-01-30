function showExternalMessage() {
    alert('Hej från extern JavaScript!')
}

var num = 10;
let num2 = 25;
const num3 = 100;
// const num3 = 200; // Error // Eftersom const är konstant och kan inte ändras
console.log(num,num2,num3);

let bobin = 9;
const gobin = 10;
console.log(bobin, gobin);

const myName = 'Em(a)il';
let myAge = 18;
myAge = myAge + 5;
let isRaining = true;
let phrase = 'Jag är ' + myAge + ' år gammal';
let phrase2 = 'Jag är 20 år gammal';
phrase2 = 'Jag är 18 år gammal';
console.log(myName,myAge, isRaining, phrase, phrase2);

var stort = 913475092143862;
let litet = 0.58518086760965959403080205447623;

console.log(stort,"+",litet,"=",stort + litet);
console.log(stort,"-",litet,"=",stort - litet);
console.log(stort,"*",litet,"=",stort * litet);
console.log(stort,"/",litet,"=",stort / litet);

let x = 10;
let y = 20;
x == 10; // true
console.log(x == 10);
console.log(x != 290);
console.log(x > y);
console.log(x < y);
console.log("--------------------");
let isTodayThursday = true;
let isTodayFriday = false;
let isTodayVictor = true;

console.log(isTodayThursday && isTodayFriday); // false + true = false
console.log(isTodayThursday || isTodayFriday); // true + false = true
console.log(!isTodayThursday); // false
console.log(!isTodayFriday && isTodayVictor || isTodayThursday); // true + true = true

if(y > 10){
    console.log("y är större än 10");
}

function returnSum(a,b){
    return a + b;
}

console.log(returnSum(y,x));
document.getElementById('externalButton').addEventListener('click', showExternalMessage);
