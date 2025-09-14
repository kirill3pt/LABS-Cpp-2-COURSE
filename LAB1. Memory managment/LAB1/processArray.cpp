#include <stdio.h>
#include <locale.h>
#include <iomanip>
#include <iostream>
#include <conio.h>
#include <string>
#include "Tasks.h"

using namespace std;

int tasks::processArray(int arr[], int result[], int n, int& count) {
    count = 0;
    int pow2 = 2;
    int pow3 = 3;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {          
            arr[i] = pow2;
            pow2 *= 2;
        }
        else {                  
            arr[i] = pow3;
            pow3 *= 3;
        }

        if (arr[i] >= 10 && arr[i] <= 99) {
            result[count++] = arr[i];
        }
    }
    return 0;
}