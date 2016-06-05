// In shell sort, we choose a gap (generally half of array size). Then we compare the values at a distance of gap.
// We sort the the distances which are separated by gap. Then we reduce the gap by 2 & do it until the gap is 1.
// The last step where gap is 1 is merely insertion sort. Hence, we reduce the number of comparisons by sorting the distances at a particular gap.
// Time complexity is O(n^1.5)
// ****Shell sort => Choose a gap & sort the elements in that particular gap. Keep reducing the gap until it is 1

#include<iostream>
#include<vector>

using namespace std;

void swap(int &small, int &large){
    int temp = large;
    large = small;
    small = temp;
}

void shellSort(vector<int>& myArr){
    int gap = myArr.size()/2;
    while(gap > 0){
        for(int index = gap; index < myArr.size(); index++){
            for(int j = index; j >= gap; j-=gap){
                if(myArr[j] < myArr[j-gap]){
                    swap(myArr[j], myArr[j-gap]);
                }
                else{
                    break;
                }
            }
        }
        gap = gap/2;
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

    shellSort(myArr);

    cout << "The sorted elements in ascending order are" << endl;

    printArray(myArr);

    return 0;
}
