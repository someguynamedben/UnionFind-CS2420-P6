#include "UnionFind.h"

UnionFind::UnionFind(){
    findCount = 0;
    unionCount = 0;
    dayCount = 0;
    peopleArray.resize(NUM_PEOPLE);

    // initialize all roots to -1 because they all point to themselves
    for(int i = 0; i < NUM_PEOPLE; i++){
        peopleArray[i] = -1;
    }
}

void UnionFind::nodeUnion(int numOne, int numTwo){
    // find the root of both numbers
    int rootOne = findParent(numOne);
    int rootTwo = findParent(numTwo);

    // already friends if they have the same root
    if(rootOne == rootTwo){
        std::cout << "Day " << dayCount + 1 << ": ";
        std::cout << "Person " << numOne << " and " << numTwo << " are already friends." << std::endl;
    }else{
        if (peopleArray[rootOne] < peopleArray[rootTwo]){
            // add child count to rootOne since it's the new root for both
            peopleArray[rootOne] += peopleArray[rootTwo];
            // point rootTwo to rootOne
            peopleArray[rootTwo] = rootOne;
        }else{
            // add child count to rootTwo since it's the new root for both
            peopleArray[rootTwo] += peopleArray[rootOne];
            // point rootOne to rootTwo
            peopleArray[rootOne] = rootTwo;
        }

        unionCount += 1;
        std::cout << "Day " << dayCount + 1 << ": ";
        std::cout << "Friendship union of " << numOne << " and " << numTwo << " was successful!" << std::endl;
    }
}

int UnionFind::find(int toFind){    // random index
    return findParent(peopleArray[toFind]); // return root
}

int UnionFind::findParent(int currIndex){
    findCount += 1;
    if(peopleArray[currIndex] < 0) return currIndex;  // if currIndex is root
    // follow next parent recursively and then compress the height on the way out once the root is found
    peopleArray[currIndex] = findParent(peopleArray[currIndex]);

    return peopleArray[currIndex]; // root
}

void UnionFind::run() {
    while(unionCount != NUM_PEOPLE - 1){
        // union random people in the array
        nodeUnion(rand() % NUM_PEOPLE, rand() % NUM_PEOPLE);
        dayCount++;
    }

    std::cout << "Total unions: " << unionCount << std::endl;
    std::cout << "total finds: " << findCount << std::endl;
}
