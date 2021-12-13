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

pair<string, string> split(string s, char delim){
    string tmp = "";
    pair<string,string> result;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != delim)
        {
            tmp += s[i];
        } else {
            result.first = tmp;
            tmp = "";
        }
    }
    result.second = tmp;
    return result; 
}

void fixInput(vector<pair<int,int>> *pairs, vector<char> *c, vector<string> *passw, vector<string> data){
    int counter = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (counter == 0)
        {
            pairs->push_back(pair<int,int>(stoi(split(data[i], '-').first), stoi(split(data[i], '-').second))); 
            counter++;
        } else if (counter == 1)
        {
            c->push_back(data[i][0]); 
            counter++;
        } else {
            passw->push_back(data[i]);
            counter = 0;
        }
    }
}

int main(){
    vector<string> data;
    readInput(&data);
    vector<pair<int,int>> pairs;
    vector<char> c;
    vector<string> passw;    
    fixInput(&pairs, &c, &passw, data);

    int validPassw = 0;

    for (int i = 0; i < passw.size(); i++)
    {
        int min = pairs[i].first;
        int max = pairs[i].second;
        char car = c[i];
        int count = 0;
        if (passw[i][min - 1] == car)
        {
            count++;
        }
        if (passw[i][max - 1] == car)
        {
            count++;
        }
        if (count == 1)
        {
            validPassw++;
        }
    }
    
    cout << validPassw << endl;

    return 0;
}