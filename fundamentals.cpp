#include "fundamentals.hpp"
// insertStockInfo(stocks, "Apple", prices[0], 0); 
void insertStockInfo(stockInfo stocks[], string company_name, double stock_prices_arr[], int index) {
    // TODO
    stockInfo newCompany;
    newCompany.company_name = company_name;
    for (int t = 0; t < 5; ++t){
        newCompany.stock_prices_arr[t] = stock_prices_arr[t];
    }
    double total = 0;
    for (int i = 0; i <5; ++i){
        total = total + stock_prices_arr[i];
    }
    double average = total / 5;
    newCompany.average = average;
    stocks[index] = newCompany;
    return;
}

void displaySortedStocks(stockInfo stock, ofstream& file){
    // TODO
    for (int i = 0; i <4; ++i){
        for (int j = 0; j <4-i;++j){
            if(stock.stock_prices_arr[j]>stock.stock_prices_arr[j+1]){
                double val = stock.stock_prices_arr[j];
                stock.stock_prices_arr[j]= stock.stock_prices_arr[j+1];
                stock.stock_prices_arr[j+1] = val;
            }
        }
    }
    cout << stock.company_name << ",";
    cout << stock.average << ",";
    for (int i=0; i <5; ++i){
        cout << stock.stock_prices_arr[i];
        if (i <4){
            cout << ",";
        }
    }
    cout << endl;

    file << stock.company_name << ",";
    file << stock.average << ",";
    for (int i=0; i <5; ++i){
        file << stock.stock_prices_arr[i];
        if (i <4){
            file << ",";
        }
    }
    file << endl;
    return;
}




