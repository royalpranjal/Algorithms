// In Insertion sort, we first compare the first element with other n-1. Then the second with n-2 & so on...
// By doing this, in first iteration of the outer for loop, we get the smallest number at the first index.
// In the second iteration, we get the second smallest iteration at the second index & so on....
// Since, each number takes n iterations. So, for a total of n numbers, it takes O(n^2) time. The total number of swaps are O(n^2)

// ****Insertion Sort => inserting the next smallest element out of the available at the right index in the array & iterating over the index.

#include<iostream>
#include<vector>

using namespace std;

void swap(int &large, int &small){
    int temp = large;
    large = small;
    small = temp;
}

void insertionSort(vector<int>& myArr){
    for(int index = 0; index < myArr.size()-1; index++){
        for(int temp = index+1; temp < myArr.size(); temp++){
            if(myArr[index] > myArr[temp]){
                swap(myArr[index], myArr[temp]);
            }
        }
    }
}

void printArray(vector<int> myArr){
    for(int index = 0; index < myArr.size(); index++){
        cout << myArr[index] << " ";
    }
}

int main(){

    vector<int>myArr;
    int number, index, input;

    cout << "Enter the number of elements : ";
    cin >> number;

    for(index = 0; index < number; index++){
        cin >> input;
        myArr.push_back(input);
    }

    insertionSort(myArr);

    cout << "The sorted array in ascending order is" << endl;

    printArray(myArr);
    return 0;
}
