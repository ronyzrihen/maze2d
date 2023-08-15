#include "MazeCompression.h"



vector<int> MazeCompression::comprress(vector<int> arr){

    vector<int> compressed;
    int counter = 0;
    int curr;
    for(auto num : arr){
        if(counter == 0){
            curr = num;
            compressed.push_back(curr);
            counter++;
            continue;
        }

        if( curr == num ){
            counter++;
            continue;
        }

        compressed.push_back(counter);
        curr = num;
        compressed.push_back(curr);
        counter = 1;

    }

    return compressed;
}


vector<int> MazeCompression::deComprress(vector<int> arr){

    vector<int> decompressed;

    int curr;
    int counter;
    int check = 0;
    for(auto num : arr){
       if(check % 2 == 0){
        curr = num;
        decompressed.push_back(curr);
        check++;
        continue;
       }

        for(int i = 1 ; i < num ; i++ ){
            decompressed.push_back(curr);
        }
        check++;
    }

    return decompressed;


}
