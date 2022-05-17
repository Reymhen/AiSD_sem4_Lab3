#pragma once
#include <fstream>
#include <stdexcept>
#include <string>
#include"Route.h"
#include"List.h"

using namespace std;


void parser(Route &listRoute, List<string> &helpList) {
	ifstream input ("flights.txt");
    if (!input.is_open())
        throw logic_error("Error opening file!\n");
    else
    {
        string inputStr, helpSrt;
        size_t position;
        while (getline(input, inputStr)) {
            string route1from, route1to, route2from, route2to;
            int price1, price2;

            //Enter in special lines the values ????of the places of arrival and departure
            helpSrt = inputStr;
            position = inputStr.find(';');
            helpSrt.assign(helpSrt, 0, position);
            helpList.push_back(helpSrt);
            route1from = helpSrt;
            route2to = helpSrt;
            inputStr.erase(0, position + 1);

            helpSrt = inputStr;
            position = inputStr.find(';');
            helpSrt.assign(helpSrt, 0, position);
            helpList.push_back(helpSrt);
            route1to = helpSrt;
            route2from = helpSrt;
            inputStr.erase(0, position + 1);

            // Enter the price of the flight
            helpSrt = inputStr;
            position = inputStr.find(';');
            helpSrt.assign(helpSrt, 0, position);
            if (helpSrt != "N/A")
            {
                price1 = stoi(helpSrt);
            }
            else price1 = -1;
            inputStr.erase(0, position + 1);
            helpSrt = inputStr;
            if (helpSrt != "N/A")
            {
                price2 = stoi(helpSrt);
            }
            else price2 = -1;
            inputStr.erase(0, position + 1);
            listRoute.push_back(route1from, route1to, price1);
            listRoute.push_back(route2from, route2to, price2);
        }
    }
}

int cheapFlight(string from, string to, Route& listRoute, List<string>& helpList) {
    if (from == to)  
        throw invalid_argument("You chose the wrong route\n");
    else 
    {
        int start = -1;
        int end = -1;
        helpList.calculateSizeMatrix();
        const int index = helpList.get_size();

        //Put down indices
        for (int i = 0; i < index; i++)
        {
            if (helpList.at(i)->date == from) start = i;
            if (helpList.at(i)->date == to) end = i;

            for (int j = 0; j < listRoute.get_size(); j++)
            {
                if (helpList.at(i)->date == listRoute.at(j)->from) listRoute.at(j)->indexLine = i;
                if (helpList.at(i)->date == listRoute.at(j)->to) listRoute.at(j)->indexColumn = i;
            }
        }

        //Creating an Adjacency Matrix
        int** matrix = new int* [index];
        for (int i = 0; i < index; i++) {
            matrix[i] = new int[index];
            for (int j = 0; j < index; j++) {
                if (listRoute.findIndex(i, j) != NULL) {
                    if (listRoute.findIndex(i, j)->price != -1)
                        matrix[i][j] = listRoute.findIndex(i, j)->price;
                    else
                        matrix[i][j] = INT_MAX;
                }
                else
                    matrix[i][j] = INT_MAX; // basically no way
            }
        }

        //Finding the minimum route
        size_t* minRoute = new size_t[index];
        for (int i = 0; i < index; i++) {
            minRoute[i] = INT_MAX;
        }
        minRoute[start] = 0;
        size_t temp;
        for (int vertex = 0; vertex < index; vertex++) {
            for (int i = 0; i < index; i++) {
                for (int j = 0; j < index; j++) {
                    if (matrix[i][j] == INT_MAX) continue;
                    temp = minRoute[i] + matrix[i][j];
                    if (temp < minRoute[j]) {
                        minRoute[j] = temp;
                    }
                }
            }
        }
        return minRoute[end];
    }
}


