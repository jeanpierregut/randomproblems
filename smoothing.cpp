// Example program

#include <iostream>
#include <string>

using namespace std;

void smooth(double values[], int size) {

    int i = 0;
    double temp = 0;
    double average = 0;
    static double temp1 = 0;
    
    while (i != size) {

        if (i == 0) { // beginning of array
            temp = temp1 = values[0];
            values[0] = (temp+values[1])/2;
        }
        
        else if (i == 1) { // start of function     
            temp = values[i];
            values[i] = (temp1 + values[i] + values[i+1])/3;
        }

        
        else if (i == size-1) { // end of array
            values[i] = (values[i]+temp)/2;
        }
        
        else { // regular function   
            temp = values[i];
            values[i] = (temp1 + values[i] + values[i+1])/3;
        }

        i++;
        
    }
    
    i = 0;
    
    while (i != size) { // printing new array
    
        cout << values[i] << " | ";
        i++;
    }

}

int main() {

    double testcase[]={40.82,6.62,33.90,5.18,11.80,5.76,97.65,93.31,16.74,58.66,36.65,67.90,1.16,68.99,78.99,73.41};
    int arraysize = sizeof(testcase)/sizeof(testcase[0]); // dynamically find arraysize

    smooth(testcase,arraysize);

}