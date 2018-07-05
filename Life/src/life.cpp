// This is the CPP file you will edit and turn in. (Remove this comment!)

#include <iostream>
#include "console.h"
#include <fstream> // standard library pkg for files
#include "filelib.h" // contains helpful methods
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

// function that animates file
// show new generations (= # of frames) with
// screen clear and 100ms pause before each
void animatefile(string file, string frames){
    return;
}

// function that ticks file
void tickfile(string file) {
    return;
}

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
    } else {
        quitfile(file);
    }

    cout << "testpass";

    return 0;
}
