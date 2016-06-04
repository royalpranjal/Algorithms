// In Selection Sort, we pick an index & then select the smallest element from the sub-array which starts just after the current index.
// At the end of each iteration, we have the smallest number from the sub array.
// we replace the number at the current index with the smallest number from the sub-array
// The number of swaps are O(n) but since for each element, we make n comparisons, the total time complexity for n elements is
// O(n^2)

// *****Selection sort => Selecting the smallest element from the sub-array & replacing it with the element at the current index

#include<iostream>
#include<vector>

using namespace std;

void swap(int &smallest, int &large){
    int temp = large;
    large = smallest;
    smallest = temp;
}

void selectionSort(vector<int>& myArr){
    for(int index = 0; index < myArr.size()-1; index++){
        int smallest = index;
        for(int temp = index+1; temp < myArr.size(); temp++){
            // figuring out the smallest number in the sub-array(starts after current index)
            if(myArr[smallest] > myArr[temp]){
                smallest = temp;
            }
        }
        swap(myArr[smallest], myArr[index]);
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

    selectionSort(myArr);

    cout << "The sorted elements in ascending order are" << endl;

    printArray(myArr);

    return 0;
}
