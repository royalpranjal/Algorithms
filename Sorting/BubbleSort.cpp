// In Bubble sort, we take an element at an index & then swap in the remaining the sub-array.
// As we keep on moving towards the current index from the end, we get the smallest element in the sub-array
// Hence, we get the correct position of one element per iteration.
// Hence, for correct position of n elements, we need n iterations. Each iteration has n comparisons.
// So, time complexity for the algorithm is O(n^2)
// *****Bubble Sort => choosing an index & in each iteration, finding the right value for that index. Forming a bubble of all the values on the right of that index & swapping
// inside that so as to get the lowest value at the start of the bubble.

#include<iostream>
#include<vector>

using namespace std;

void swap(int &small, int &large){
    int temp = large;
    large = small;
    small = temp;
}

void bubbleSort(vector<int>& myArr){
    for(int index = 0; index < myArr.size()-1; index++){
        bool swapped = false;
        for(int temp = myArr.size()-2; temp >= index; temp--){
            if(myArr[temp] > myArr[temp+1]){
                swap(myArr[temp+1], myArr[temp]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }
}

void printArray(vector<int> myArr){
    for(int index = 0; index < myArr.size(); index++){
        cout << myArr[index] << " ";
    }
}
int main(){

    vector<int> myArr;
    int index, number, input;

    cout << "Enter the number of elements in the array : ";
    cin >> number;

    for(int index = 0; index < number; index++){
        cin >> input;
        myArr.push_back(input);
    }

    bubbleSort(myArr);

    cout << "The sorted elements in ascending order are" << endl;

    printArray(myArr);

    return 0;
}
