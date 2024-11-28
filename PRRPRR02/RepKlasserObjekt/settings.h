#pragma once
#include <string>
#include <iostream>

using namespace std;

class Settings {
public:
    Settings(string resolution, bool autosave, string quickkey)
        : resolution(resolution),
        autoSave(autosave),
        quickKey(quickkey)
    {};
    /*this-> är en pointer för klassens värde istället för funktionens värde som har samma namn*/
    void setResolution(string resolution){
        this->resolution = resolution;
    };
    string getResolution(){
        return this->resolution;
    };
    void setAutoSave(bool autoSave){
        this->autoSave = autoSave;
    };
    bool getAutoSave(){
        return this->autoSave;
    };
    void setQuickKey(string quickKey){
        this->quickKey = quickKey;
    };
    string getQuickKey(){
        return this->quickKey;
    };
    void printSettings(){
        cout << "Resolution: " << resolution << endl;
        cout << "AutoSave: " << autoSave << endl;
        cout << "QuickKey: " << quickKey << endl;
        cout << "SettingsFile: " << settingsFile << endl;
    };
    /*
    void loadSettings(string settingsFile);
    void updateSettings(string settingsFile);
    */
    /*Inkapsling*/
private:
    string resolution;
    bool autoSave;
    string quickKey;
    string settingsFile = "file.csv";
};