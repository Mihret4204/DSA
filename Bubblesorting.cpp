#include<iostream>
#include<vector>
using namespace std;
//Bubble sort is a sorting algorithm done by swaping two consicative elt of a list;
//Bubble sort has quadratic time complexity;
//one of well knowen sorting mechanism
vector<int> bubblesort(vector<int>& vec);
int main(){
    int nums;
    vector<int> vec;

    //To accept a list of numbers to be sorted
    cout<<"Enter how many numbers you want to insert. ";
    cin>>nums;
    int j;
    for(int i=0;i<nums;i++){
        cout<<"Enter number: ";
        cin>>j;
        vec.push_back(j);
    }

    //print unsorted list
    cout<<"unsorted list is ";
    for(int k=0;k<nums;k++){
        cout<<vec[k]<<",";
    }
    //sort and print sorted list
    bubblesort(vec);
    cout<<"\nsorted list is ";
    for(int m=0;m<nums;m++){
        cout<<vec[m]<<",";
    }
};
// a method accept(unsorted list/vector) and return a sorted list; 
vector<int> bubblesort(vector<int>& vec){
    int k=0;
    int n=vec.size();
    //two for loop to swap numa 
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if (vec[j]>vec[j+1]){
                k=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=k;
            }
        }
    }
    return vec;
    
}