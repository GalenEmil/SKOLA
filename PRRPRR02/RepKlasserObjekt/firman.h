#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Bil {
public:
    Bil(string regNummer, string modell, string märke, bool uthyrd)
    : regNummer(regNummer), modell(modell), märke(märke), uthyrd(uthyrd)
    {};
    /*this-> behövs inte egentligen om man inte har samma namn på variablerna. Men det är bra praxis*/
    void setRegNummer(string nummer) {
        this->regNummer = nummer;
    };
    void setModell(string modell){
        this->modell = modell;
    };
    void setMärke(string märke){
        this->märke=märke;
    };
    void setUthyrd(bool uthyrd){
        this->uthyrd=uthyrd;
    };
    string getRegNummer(){
        return regNummer;
    };
    string getModell(){
        return modell;
    };
    string getMärke(){
        return märke;
    };
    bool getUthyrd(){
        return uthyrd;
    };
private:
    string regNummer;
    string modell;
    string märke;
    bool uthyrd;
};

class Skåpbil : public Bil{
public:
    Skåpbil(string regNummer, string modell, string märke, bool uthyrd, int last) : Bil(regNummer, modell, märke, uthyrd), last(last)
    {};
    void setLast(int last){
        this->last=last;
    }
    int getLast(){
        return last;
    }
private:
    int last;
};

class Personbil : public Bil{
public:
    Personbil(string regNummer, string modell, string märke, bool uthyrd) : Bil(regNummer, modell, märke, uthyrd)
    {};
};

class Firman{
public:
    Firman()
    {};
    /*push_back är som append fast med vector*/
    void läggTillBil(Bil *bil){
        Bilar.push_back(bil);
    };
    

    /*string searchForCar(string märke, string modell);*/

private:
    vector<Bil*> Bilar;
};