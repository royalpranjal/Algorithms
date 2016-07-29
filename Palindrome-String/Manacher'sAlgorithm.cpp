#include<iostream>
#include<string>
#include<vector>

/*
    i is looking for the next palindrome. C is the center of the largest palindrome. We are making use of the property that the palindrome is symmetric about its center.
    By computing the values of the right from the left by using the mirror, we compute the minimum length of the palindrome on the right side & then expand it further.
*/

using namespace std;

int main(){

    string inputStr, myStr;
    int center = 0, right = 0, mirror;
    int maxVal = 0;

    cout << "Enter the string : " << endl;
    getline(cin, inputStr);

    for(int i = 0; i < inputStr.size(); i++){
        myStr = myStr + "#";
        myStr = myStr + inputStr[i];
    }

    myStr = myStr + "#";

    vector<int> val(myStr.size(), 0);

    for(int i = 1; i < myStr.size()-1; i++){
        mirror = 2*center - i;
        if(i < right){
            val[i] = min(right-i, val[mirror]);
        }
        while(myStr[i-(1+val[i])] == myStr[i+(1+val[i])]){
            val[i]++;
            if(val[i] > maxVal){
                maxVal = val[i];
            }
            if((1 + val[i]) > i){
                break;
            }
        }
        if((i + val[i]) > right){
            center = i;
            right = i + val[i];
        }
    }

    cout << "The longest palindrome is of length : " << maxVal << endl << "The vector is as below :-" << endl;


    for(int i = 0; i < myStr.size(); i++){
        cout << myStr[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < myStr.size(); i++){
        cout << val[i] << " ";
    }
    cout << endl;

    return 0;
}
