#include <iostream>
#include<vector>
using namespace std;
#include <chrono>


void mergesort(std::vector<int>& arr, int left, int right);
void merge(std::vector<int>& arr, int left, int mid, int right);


int main(int argc, char* argv[]) {

    //Create vector x the size of argc minus the prompt
    vector<int> x(argc - 1);
    
    //For i = 1(After the prompt), the vector x is set equal to argv
    for(int i = 1; i < argc; i++){
        x[i - 1] = std::stoi(argv[i]);
    }
    
    //Time the sort using high resolution clock
    auto start = std::chrono::high_resolution_clock::now();
    mergesort(x,0,static_cast<int>(x.size()) - 1);
    auto end = std::chrono::high_resolution_clock::now();

    //Prints sorted list in vector
    for (int i = 0; i < static_cast<int>(x.size()); i++){
            std::cout << x[i] << " ";
    }
    //Prints Elasped time of sort
    std:chrono::duration<double> elasped = end - start;
    std::cout<<"\nElasped Time: " << elasped.count() << " seconds";
}
 /*Splits the range [left, right] into two halves, recursively sorts them,
 * and merges the results.
 */
void mergesort(std::vector<int>& arr, int left, int right){
    //Base case for mergesort
    if (left < right){
        //Recursion to get to ends of arr
        int mid = left + (right - left)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
        
    }

}
//
void merge(std::vector<int>& arr, int left, int mid, int right){

    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    std::vector<int> temp(leftSize);
    std::vector<int> temp2(rightSize);
    //For loops create a temporary copy of left and right side of vector array
    for(int i = 0; i < leftSize; i++){
        temp[i] = arr[left + i];
    }
    for(int j = 0; j < rightSize; j++){
        temp2[j] = arr[mid + 1 + j];
    }
    
    int i = 0;
    int j = 0;
    int k = left;
    //Sort temp variables into array from least to greatest
    while(i < leftSize && j < rightSize){
        if(temp[i] < temp2[j]){
            arr[k] = temp[i];
            i++;
        }
        else{
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }    
    //Adds last element if one side is larger than other
    while(i < leftSize){
        arr[k] = temp[i];
        i++;
        k++;
        
    }
    while(j < rightSize){
        arr[k] = temp2[j];
        j++;
        k++;
    }
            
}
