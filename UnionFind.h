#ifndef UNIONFIND_UNIONFIND_H
#define UNIONFIND_UNIONFIND_H

#include <iostream>
#include <vector>

class UnionFind {
public:
    UnionFind();
    void nodeUnion(int numOne, int numTwo);
    int find(int toFind);
    void run();
private:
    const int NUM_PEOPLE = 1000;  // how many people in the network
    int findCount;  // how many calls
    int unionCount; // how many unions
    int dayCount;   // how many days
    int findParent(int currIndex);
    std::vector<int> peopleArray;
};


#endif //UNIONFIND_UNIONFIND_H
