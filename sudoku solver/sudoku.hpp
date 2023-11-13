#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>
#include <sstream>
#include <fstream>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <map>
#include <set>
#include <utility>
#include <tuple>
using std::string; using std::vector; using std::tuple;


class SudokuGame {
    // TO DO: define your own private members/methods as needed
    private:
        vector<vector<int>> grid_;

    public:
        SudokuGame() = default;
        SudokuGame(string filename);

        const vector<vector<int>> & grid() const;
        void print() const;
        int size() const;
        int value(int row, int column) const;
        void value(int row, int column, int newValue);

        // TO DO: include "rule of three": 
        //          destructor
        //          copy constructor
        //          copy assignment operator

        ~SudokuGame();
        SudokuGame(const SudokuGame & obj);
        SudokuGame & operator=(const SudokuGame & obj);
};


class SudokuPlayer {
    // TO DO: define your own private members/methods as needed
    private:
        tuple<int, int> isValidSpot(const SudokuGame &) const;

    public:
        SudokuPlayer() = default;
        bool solve(SudokuGame & game);
};