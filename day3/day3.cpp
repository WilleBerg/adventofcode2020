#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void readInput(vector<string> *d){
    fstream file;
    file.open("input.txt");
    if (file.is_open())
    {
        while (file)
        {
            string tmp;
            file >> tmp;
            if (tmp != "")
            {
                d->push_back(tmp);
            }
        }
    }
}

int traverseSlope(vector<string> data, int xStep, int yStep){
    int x = 0;
    int y = 0;
    int boundX = data[0].size() - 1;
    int boundY = data.size() - 1;
    long treeCount = 0;
    while (true)
    {
        if (data[y][x] == '#')
        {
            treeCount++;
            //data[y][x] = 'X';
        } else {
            //data[y][x] = 'O';
        }
        if (x + xStep <= boundX)
        {
            x += xStep;
        } else {
            for (int i = 0; i < xStep; i++)
            {
                if (x + 1 <= boundX)
                {
                    x++;
                } else {
                    x = 0;
                }
            }  
        }
        y += yStep;
        if (y >= boundY)
        {
            if (data[y][x] == '#')
            {
                treeCount++;
                //data[y][x] = 'X';
            } else {
                //data[y][x] = 'O';
            }
            
            break;
        }
        
    }
    return treeCount;
}

int main(){
    vector<string> data;
    readInput(&data);
    
    
    
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].length(); j++)
        {
            cout << data[i][j];
        }
        cout << endl; 
    }
    long long b = traverseSlope(data, 1, 1);
    long long c = traverseSlope(data, 3, 1);
    long long d = traverseSlope(data, 5, 1);
    long long e = traverseSlope(data, 7, 1);
    long long f = traverseSlope(data, 1, 2);
    long long a = (b * c * d * e * f);
    cout << a << endl;

    return 0;
}