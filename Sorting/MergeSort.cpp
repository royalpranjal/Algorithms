// In Merge sort, we first divide the arrays into sub-arrays. These sub arrays are then sorted & merged on to form a bigger array.
// We need an extra O(n) space for this sort. Besides that the time complexity from turns out to be O(nlog(n))
// This is due to the recurrence relation T(n) = 2T(n/2) + O(n)
// That is the time to sort the 2 sub-arrays + time to merge these 2
// *****Merge Sort => recursively divide the array into sub-arrays & sort them. Then merge them to get the sorted array.

#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& myArr, int start, int mid, int end){
    int initial, temp_initial, middle;
    int combined[50];

    initial = start;
    temp_initial = start;
    middle = mid+1;
    while(initial <= mid && middle <= end){
        if(myArr[initial] < myArr[middle]){
            combined[temp_initial] = myArr[initial];
            initial++;
            temp_initial++;
        }
        else{
            combined[temp_initial] = myArr[middle];
            middle++;
            temp_initial++;
        }
    }
    while(initial <= mid){
        combined[temp_initial] = myArr[initial];
        temp_initial++;
        initial++;
    }
    while(middle <= end){
        combined[temp_initial] = myArr[middle];
        temp_initial++;
        middle++;
    }
    for(int i = start; i <= end; i++){
        myArr[i] = combined[i];
    }
}

void mergeSort(vector<int>& myArr, int start, int end){
    int mid;
    if(start < end){
        mid = (start+end)/2;
        mergeSort(myArr, start, mid);
        mergeSort(myArr, mid+1, end);
        merge(myArr, start, mid, end);
    }
}

void mergeSort(vector<int>& myArr){
    mergeSort(myArr, 0, myArr.size()-1);
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

    mergeSort(myArr);

    cout << "The sorted elements in ascending order are" << endl;

    printArray(myArr);

    return 0;
}
