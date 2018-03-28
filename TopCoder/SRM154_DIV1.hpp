#pragma once

#include <iostream>
#include <limits>
#include <climits>
#include <fstream>
#include <string.h>
#include <exception>
#include <stdlib.h>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

int width = 0;
int height = 0;

static const int maxWidth = 1024;
static const int maxHeight = 1024;
char** grid = new char*[maxHeight];
unordered_set<string> visited;

pair<int,int> findPlayer(char player);

int parseInputRow(char* row)
{
    int len = strlen(row);
    grid[height] = new char[len+1];
    strncpy(grid[height],row,len+1);
    cout << grid[height] << endl;
    return len;
}

struct step
{
    int xPlayerA;
    int yPlayerA;
    int xPlayerB;
    int yPlayerB;
    int stepsN;

    bool operator==(const step& other) const
    {
        return (makeKey() == other.makeKey());            
    }

    string makeKey() const
    {
        string key;
        {
            key.push_back(xPlayerA);
            key.push_back('+');
            key.push_back(yPlayerA);
            key.push_back('+');
            key.push_back(xPlayerB);
            key.push_back('+');
            key.push_back(yPlayerB);
        }

        return key;
    }
};

int minStepsSRM154DIV1()
{    
    std::ifstream input;
    input.exceptions(ifstream::badbit);
    
    try
    {         
        char row[1024] = {0};        
        input.open("C://topcoder/SRM154.txt", std::ios::in);    
        while (!input.eof() && input.good())
        { 
            input.getline(row, 1024);
            if (row[0] == '\0') continue;

            int currentWidth = parseInputRow(row);
            if (width && currentWidth != width)
            {
                throw std::runtime_error("incossistent width of input");
            }
            else
            {                
                width = currentWidth;
                height++;
            }
        }        
    }
    catch (const std::exception& e)
    {
        std::cerr << "\nException while processing file feed: [" 
                  << e.what() << "]";        
    }

    if (input.is_open())
        input.close();

    //init visited grid

    try
    {
        if (width > maxWidth || height > maxHeight)
            throw std::runtime_error("the input is too big!");
        
        pair<int,int> playerA = findPlayer('A');
        pair<int,int> playerB = findPlayer('B');

        step start;
        {
            start.xPlayerA = playerA.first;
            start.yPlayerA = playerA.second;
            start.xPlayerB = playerB.first;
            start.yPlayerB = playerB.second;
            start.stepsN = 0;
        }

        queue<step> path;
        path.push(start);
        visited.insert(start.makeKey());

        while (!path.empty())
        {
            step current = path.front();
            path.pop();


            if (current.xPlayerA < 0 || current.xPlayerA > (width - 1)  ||
                current.yPlayerA < 0 || current.yPlayerA > (height - 1) ||
                current.xPlayerB < 0 || current.xPlayerB > (width - 1)  ||
                current.yPlayerB < 0 || current.yPlayerB > (height - 1))
            {
                cout << "players are outside the grid! Ignore this step" << endl;
                continue;
            }

            /*if ((start.yPlayerA > start.yPlayerB && current.yPlayerA < current.yPlayerB) ||
                (start.yPlayerA < start.yPlayerB && current.yPlayerA > current.yPlayerB))
            {
                cout << "players are above each other!" << endl;
                continue;
            }*/

            if (start.xPlayerA == current.xPlayerB && 
                start.yPlayerA == current.yPlayerB &&
                start.xPlayerB == current.xPlayerA &&
                start.yPlayerB == current.yPlayerA)
            {
                cout << "found " << current.stepsN << " steps required to exchange players A and B" << endl;
                return current.stepsN;
            }

            
            for (int xADelta = -1; xADelta <= 1; xADelta++)
             for (int yADelta = -1; yADelta <= 1; yADelta++)
              for (int xBDelta = -1; xBDelta <= 1; xBDelta++)
                for (int yBDelta = -1; yBDelta <=1; yBDelta++)
                {
                    step next;
                    next.xPlayerA = current.xPlayerA + xADelta;
                    next.yPlayerA = current.yPlayerA + yADelta;
                    next.xPlayerB = current.xPlayerB + xBDelta;
                    next.yPlayerB = current.yPlayerB + yBDelta;
                    next.stepsN = current.stepsN+1;

                    if (next.xPlayerA == current.xPlayerB && 
                        next.yPlayerA == current.yPlayerB &&
                        next.xPlayerB == current.xPlayerA &&
                        next.yPlayerB == current.yPlayerA)
                    {
                        cout << "cannot swap A and B!" << endl;                        
                    }

                    if (visited.find(next.makeKey()) == visited.end())
                    {
                        visited.insert(next.makeKey());
                        path.push(next);
                    }
                }
        }        
    }
    catch (const std::exception& e)
    {
          std::cerr << "\nException while solving the problem: [" 
                    << e.what() << "]";  
    }

    return -1;
}


pair<int,int> findPlayer(char player)
{
    pair<int,int> position(-1,-1);    

    for (int x = 0; x < width; x++)
      for (int y = 0; y < height; y++)
        {
            if (grid[y][x] == player)
            {
                position.first = x;
                position.second = y;
            }
        }
    
    if (position.first >= 0 && position.second >= 0)
    {
        cout << "Found player " << player << " at positions x/y:[" 
             <<  position.first + 1 << "/" << position.second + 1 << "]" << endl;
    }
    else
    {
        throw runtime_error("cannot find player in the grid on the start");
    }

    return position;
}