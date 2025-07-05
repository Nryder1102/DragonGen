#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<string>
#include<chrono>
#include<thread>
#include<sstream>
#include <fstream>
using namespace std;

//Name List
vector<string> names;

//Title List
vector<string> titles;

//Technology List
vector<string> technology;

//Type List
vector<string> types = {"Chromatic","Metallic","Gem","Planar","Catastrophic","Epic","Miscellaneous","Extra","Drake"};
vector<string> chromatic = {"Red","Blue","Black","White","Green","Brown","Purple","Gray","Yellow","Pink"};
vector<string> metallic = {"Gold","Silver","Bronze","Copper","Brass","Electrum","Mercury","Platinum","Steel"};
vector<string> gem = {"Amethyst","Crystal","Emerald","Obsidian","Sapphire","Topaz","Ruby"};
vector<string> planar = {"Adamantine","Astral","Battle","Blight","Chaos","Ethereal","Howling","Mirage","Oceanus","Pyroclastic","Radiant","Rust","Shadow","Styx"};
vector<string> catastrophic = {"Blizzard","Earthquake","Volcanic"};
vector<string> epic = {"Force","Prismatic","Time"};
vector<string> miscellaneous = {"Sea Serpent", "Dracolich","Wyvern","Rock Wyrm","Dragon Eel","Dragon Tortoise","Draconic Creature","Black Firedrake","Hellfire Wyrm"};
vector<string> extra = {"Faerie","Mist","Song","Brainstealer","Elder Brain"};
vector<string> drake = {"Ambush","Earth","Fire","Ice","Magma","Ooze","Smoke","Water","Crested","Spitting","Greater","Guard","Mind","Portal","Rage","Space","Storm","Vulture"};


//Roll a Dice
int roll(int max)
{
    return(rand() % max + 1);
}

//Select a Choice from a List
string select(vector<string> selectList)
{
    return(selectList[rand() % selectList.size()]);
}

//Import Names From a File
void importNames(){
    fstream myfile;
    // open file
    myfile.open("Names.txt");

    if (myfile.is_open()) {
        // checking if the file is open
        string str;

        // read data from file object
        // and put it into string.
        while (getline(myfile, str)) {
            names.push_back(str);
        }
        // close the file object.
        myfile.close();
    }
}

//Import Titles From a File
void importTitles(){
    fstream myfile;
    // open file
    myfile.open("Titles.txt");

    if (myfile.is_open()) {
        // checking if the file is open
        string str;

        // read data from file object
        // and put it into string.
        while (getline(myfile, str)) {
            titles.push_back(str);
        }
        // close the file object.
        myfile.close();
    }
}


//Import Tech From a File
void importTech(){
    fstream myfile;
    // open file
    myfile.open("Technology.txt");

    if (myfile.is_open()) {
        // checking if the file is open
        string str;

        // read data from file object
        // and put it into string.
        while (getline(myfile, str)) {
            technology.push_back(str);
        }
        // close the file object.
        myfile.close();
    }
}

int main()
{
    //Generate random seed
    srand(time(0));
    importNames();
    importTitles();
    importTech();

    string name1 = select(names);
    string name2 = select(names);
    string title = " ";

    if(roll(4) == 1){
        title = select(titles);
    }

    string type = select(types);
    string type2 = " ";
    if(type == "Chromatic"){type2 = select(chromatic) + " Dragon";}
    if(type == "Metallic"){type2 = select(metallic) + " Dragon";}
    if(type == "Gem"){type2 = select(gem) + " Dragon";}
    if(type == "Planar"){type2 = select(planar) + " Dragon";}
    if(type == "Catastrophic"){type2 = select(catastrophic) + " Dragon";}
    if(type == "Epic"){type2 = select(epic) + " Dragon";}
    if(type == "Miscellaneous"){type2 = select(miscellaneous);}
    if(type == "Extra"){type2 = select(extra) + " Dragon";}
    if(type == "Drake"){type2 = select(drake) + " Drake";}

    if(title != " "){
        if(roll(2) == 1){
            cout << "NAME: " << name1 + " '" + title + "' " + name2 << endl;
        }else if(title.find("The")){
            cout << "NAME: " << name1 + " " + name2 + ", " + title << endl;
        }else{
            cout << "NAME: " << name1 + " " + name2 + ", The " + title << endl;
        }
    }else{
        cout << "NAME: " << name1 + " " + name2 << endl;
    }
    
    cout << "TYPE: " + type2 << endl;

    //Roll Technology
    string tech = select(technology);
    if(roll(10) == 1){
        cout << "TECH: " + tech << endl;
    }
    
}