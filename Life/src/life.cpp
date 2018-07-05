// by Anisha Jain (anishax@stanford) and Arshin Jain (arshin@stanford)

#include <iostream>
#include "console.h"
#include <fstream> // standard library pkg for files
#include "filelib.h" // contains helpful methods
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "grid.h"
#include <iostream>   // std::cout
#include <string>     // std::string, std::stoi


using namespace std;

// function that prints file
// COMPLETED!!
void printfile(string file) {
    ifstream stream(file);

    // test if file is opened
    if (!stream) {
        cout << "Unable to open that file.  Try again." << endl;
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

// ARSHIN: finish this function
// file to grid function: -1 if dead, 0 if alive goes below
Grid<int> filetogrid(string file) {
    ifstream stream(file);

    cout << "File To Grid Function: " << endl;

    // test if file is opened
    if (!stream) {
        cout << "Unable to open that file.  Try again." << endl;
    }

    // stores read data
    string content;

    // get grid dimensions
    // std:stoi converts string to int
    stream >> content;
    int row = stoi(content);
    stream >> content;
    int col = stoi(content);
    Grid<int> sol;

    cout << "Row: " << row << ", Col: " << col << "\n" << endl;

    // grid minimum size = 3x3
    // if (row < 3) { row = 3; }
    // if (col < 3) { col = 3; }

    // create solution grid
    if (row < 3 && col < 3) {
        sol = Grid<int>(3, 3);
    } else if (row >= 3 && col < 3) {
        sol = Grid<int>(row, 3);
    } else if (row < 3 && col >= 3) {
        sol = Grid<int>(3, col);
    } else {
        sol = Grid<int>(row, col);
    }

    string dash = "-";
    string plus = "+";

    // for each row
    for (int i = 0; i < row; i++) {
        stream >> content;

        // for each col
        for (int j = 0; j < col; j++) {
            cout << "j: " << content[j] << endl;
            if (content[j] == '-') {
                sol[i][j] = -1;
            } else if (content[j] == '+') {
                sol[i][j] = 0;
            }
        }
    }

    cout << sol << endl;

    // process file data
    while(!stream.eof() & content != "#") {
        stream >> content; // first line of file
        if (content != "#") {
            // break line string into individual strings
            // add -1 or 0 to grid at that position
            //cout << content << "\n";
        }
    }

    stream.close();

    return sol;
}

// ARSHIN: implement this one
// function that animates file
// show new generations (= # of frames) with
// screen clear and 100ms pause before each
Grid<int> animatefile(Grid<int> grid, string frames){
    int tickcount = stoi(frames);
    for (int i = 0; i < tickcount; i++) {
        tickfile(grid);
    }
    return grid;
}

// ARSHIN: implement this one
// Moves on to next generation and prints output to console
Grid<int> tickfile(Grid<int> grid) {

    // New Grid
    Grid<int> newGrid(grid.numRows(), grid.numCols());
    newGrid = grid;

    // Track neighbors
    int neighbors = 0;

    for	(int r = 0;	r <	grid.numRows();	r++) {
        for	(int c = 0;	c <	grid.numCols();	c++) {
            // do something with grid[r][c];

            neighbors = 0;

            // compare with upper left diagonal: row-- col--
            if (grid[r--][c--] == 0) {
                neighbors++;
            }
            // compare with left: col--
            if (grid[r][c--] == 0) {
                neighbors++;
            }
            // compare with bottom left: row++ col--
            if (grid[r++][c--] == 0) {
                neighbors++;
            }
            // compare with bottom: row++
            if (grid[r++][c] == 0) {
                neighbors++;
            }
            // compare with bottom right: row++ col++
            if (grid[r++][c++] == 0) {
                neighbors++;
            }
            // compare with right: col++
            if (grid[r][c++] == 0) {
                neighbors++;
            }
            // compare with upper right: row-- col++
            if (grid[r--][c++] == 0) {
                neighbors++;
            }
            // compare with upper / top: row--
            if (grid[r--][c] == 0) {
                neighbors++;
            }

            // Update Grid with new life
            if (neighbors <= 1) {
                newGrid[r][c] = -1; // bacteria dies
            } else if (neighbors == 2) {
                // stable
            } else if (neighbors == 3) {
                newGrid[r][c] = 0;
            } else {
                newGrid[r][c] = -1;
            }
        }
    }

    return newGrid;
}

// function that quits file
// COMPLETED!!
void quitfile() {
    return;
}

// asks and processes a,t,q requests
// COMPLETED!!
void atq(Grid<int> grid){
    // asks user for a, t, q
    string usercommand;
    cout << "a)nimate, t)ick, q)uit?";
    cin >> usercommand;

    if (usercommand == "q" || usercommand == "Q") {
        quitfile();
        return;
    }

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

            animatefile(grid, frames);

        } else if (usercommand == "t") {
            tickfile(file);
        }
        // ask again for a command
        atq(grid);
    }

    return;
}

// runs commands
// COMPLETED!!
void run() {
    string file;
    cout << "Grid input file name? ";
    cin >> file;

    // prints the original file
    filetogrid(file);
    printfile(file);
    Grid<int> grid = filetogrid(file);
    atq(grid);
    return;
}

// Asks to restart game
// COMPLETED!!
string restart() {
    string q2;
    cout << "Load another file? (y/n)";
    cin >> q2;

    return q2;
}

// main function: handles all prints and runs all functions
// COMPLETED!!
int main() {
    // TODO: Finish the program!

    cout << "Welcome to the CS 106B/X Game of Life!" << endl;
    cout << "This program simulates the lifecycle of a bacterial colony." << endl;
    cout << "Cells (X) Live and die by the following rules:" << endl;
    cout << "* A cell with 1 or fewer neighbors dies." << endl;
    cout << "* Locations with 2 neighbors remain stable." << endl;
    cout << "* Locations with 3 neighbors will create life." << endl;
    cout << "* A cell with 4 or more neighbors dies." << endl;

    run();

    // ask user to load another file
    string q2 = restart();

    bool valid = false;

    while (valid == false) {
        if (q2 == "n") {
            cout << "Have a nice Life!";
            valid = true;
        } else if (q2 == "y") {
            run();
            q2 = restart();
            valid = false;
        } else {
            cout << "Please type 'Y' or 'N'."; // Note: changed text!
            cout << "Load another file? (y/n)";
            cin >> q2;
            valid = false;
        }
    }


    return 0;
}
