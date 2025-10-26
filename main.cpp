//Comsc-210|Ethan Aylard|Lab-23
//IDE Used: Visual Studio Code
//Program Description: This program is meant to keep track of goats by using a menu that allows the user to add, delete, or view all the goats.


#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

//Function Prototypes:
int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();



int main() {
    //making the program truly random:
    srand(time(0));
    //declaring a bool variable and the list of the goats:
    bool again = true;
    list<Goat> goats;

    //read & populate arrays for names and colors
    //Filling array names[] with all the names in names.txt
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();

    //Filling array colors[] with all the names in colors.txt
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    //The main brains of the program: depending on the choice of the user each case could be activated:
    while(again){
        switch(main_menu()){
            case 1:
                add_goat(goats, names, colors);
                break;
            
            case 2:
                delete_goat(goats);
                break;

            case 3:
                display_trip(goats);
                break;

            case 4:
                again = false;
                break;

            default:
                cout << "Error! Input does not match the width of the menu.";
        }

    }

    //clearing the list:
    goats.clear();


    return 0;
}

//main_menu(): This will display and loop a menu until the user inputs a valid choice.
//requires: none.
//returns: an int variable of the user's choice.


int main_menu (){
    int choice;
    bool valid = false;

    //Display the menu with a while loop.
    while (!valid){
        cout << "\n*** GOAT MANAGER 3001 ***\n";
        cout << "[1] Add a goat" << 
        endl << "[2] Delete a goat" << 
        endl << "[3] List goats" <<
        endl << "[4] Quit" <<
        endl << "Choice --> ";

        cin >> choice;
        if (!cin.fail()){
            
            if (choice < 1 || choice > 4){
                cout << "Invalid choice. Please try again." << endl;
            }
            else
            valid = true;
        }
        else{
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice. Please try again." << endl;
        }

    }


    return choice;
}

int select_goat(list<Goat> trip){
    int choice;
    bool valid;
    display_trip(trip);
    cout << "Which goat would you choose?" << endl;

    cin >> choice;
        if (!cin.fail()){

            if(choice > trip.size()){
            cout << "Invalid choice. Please try again." << endl;
            }

            else
            valid = true;
        
        }

        else{
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice. Please try again." << endl;
        }


    return choice;
}


void delete_goat(list<Goat> &trip){
auto it = trip.begin();
int pos = select_goat(trip) - 1;

advance(it, pos);
trip.erase(it);

}


void add_goat(list<Goat> &trip, string names [], string colors []){

    int age = rand() % MAX_AGE;
    string name = names[rand() % SZ_NAMES];
    string color = colors[rand() % SZ_COLORS];

    cout << "\nAdding goat: " << name << ", color: "
    << color << ", age: " << age << endl;
    
    trip.push_back(Goat(name, age, color));

}


void display_trip(list<Goat> trip){
    int i = 1;
    for(Goat g : trip){
        cout << "[" << i << "] " << g.get_name() 
        << " (" << g.get_age() << ", " << g.get_color() 
        << ")" << endl;

        i++;
    }

}
