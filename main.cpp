#include <iostream>
#include <fstream>
#include "../code/fundamentals.hpp"
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) 
{
    ifstream file;
    file.open(argv[1]);
    string line; 
    string companyName;
    string price; 
	double stockArray[5];
    stockInfo stocks[6]; 
    ofstream out_file(argv[2]); 
    int index = 0; 
    int stockindex; 
        while (getline(file, line))
        {
            stringstream ss(line); 
            getline(ss,companyName, ',');
            stockindex = 0; 
            while(getline(ss,price, ','))
            {
                stockArray[stockindex] = stod(price); 
                stockindex+=1;
                
            }  
            insertStockInfo(stocks, companyName, stockArray,index);
            displaySortedStocks(stocks[index], out_file);
            index+=1;
        } 
    return 0; 
}
