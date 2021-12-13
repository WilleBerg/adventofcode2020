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

int main(){
    vector<string> data;
    readInput(&data); 

    return 0;
}