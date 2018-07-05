// by Anisha Jain and Arshin Jain

#include <iostream>
#include "console.h"
#include <fstream> // standard library pkg for files
#include "filelib.h" // contains helpful methods
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "grid.h"

using namespace std;

// function that prints file
void printfile(string file) {
    ifstream stream(file);

    // test if file is opened
    if (!stream) {
        cout << "Unable to open that file.  Try again.";
    }

    string content;

    while(!stream.eof() & content != "#") {
        stream >> content;
        if (content != "#") {
            cout << content;
            cout << "\r\n";
        }
    }

    return;

}

// file to grid function: -1 if dead, 0 if alive goes below
Grid<int> filetogrid(string file) {
    ifstream stream(file);



    // test if file is opened
    if (!stream) {
        cout << "Unable to open that file.  Try again.";
    }

    // stores read data
    string content;

    // get grid dimensions
    // std:stoi convers string to int
    int row = std::stoi( stream >> content );
    int col = std::stoi( stream >> content );

    // grid minimum size = 3x3
    if (row < 3) { row = 3; }
    if (col < 3) { col = 3; }

    // create solution grid
    Grid<int> sol = Grid<int>(row, col);

    // process file data
    while(!stream.eof() & content != "#") {
        stream >> content; // first line of file
        if (content != "#") {
            // get grid dimensions
            // break line string into individual strings
            // add -1 or 0 to grid at that position
        }
    }

    return sol;
}

// ARSHIN: implement this one
// function that animates file
// show new generations (= # of frames) with
// screen clear and 100ms pause before each
void animatefile(string file, string frames){
    return;
}

// ARSHIN
// function that ticks file
void tickfile(string file) {
    return;
}

// ARSHIN: implement this one!
// function that quits file
void quitfile(string file) {
    return;
}


// main function: handles all prints and runs all functions
int main() {
    // TODO: Finish the program!

    cout << "Welcome to the CS 106B/X Game of Life!" << endl;
    cout << "This program simulates the lifecycle of a bacterial colony." << endl;
    cout << "Cells (X) Live and die by the following rules:" << endl;
    cout << "* A cell with 1 or fewer neighbors dies." << endl;
    cout << "* Locations with 2 neighbors remain stable." << endl;
    cout << "* Locations with 3 neighbors will create life." << endl;
    cout << "* A cell with 4 or more neighbors dies." << endl;

    string file;
    cout << "Grid input file name? ";
    cin >> file;

    // prints the original file
    printfile(file);

    // asks user for a, t, q
    string usercommand;
    cout << "a)nimate, t)ick, q)uit?";
    cin >> usercommand;

    while (usercommand != "q") {
        if (usercommand == "a") {
            string frames;
            cout << "How many frames?";
            cin >> frames;

            // check if valid int
            while (!isdigit(frames[0])) {
                cout << "Illegal integer format. Try again.";
                cout << "\r\n";
                cout << "How many frames?";
                cin >> frames;
            }

            animatefile(file, frames);

        } else if (usercommand == "t") {
            tickfile(file);
        }
        // ask again for a command
        cout << "a)nimate, t)ick, q)uit?";
        cin >> usercommand;
    }
    if (usercommand == "q") {
        quitfile(file);
    }

    // reached end of code
    cout << "testpass";

    return 0;
}
