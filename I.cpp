#include <iostream>
#include <vector>
#include <fstream>

class MaxHeap
{
    std::vector<int>* heapArray;

public:
    MaxHeap(){heapArray = new std::vector<int>;}

    void siftDown(int index);
    void swapElements(int index1, int index2);
    void addElement(int value);
    void removeAllElements();
    void removeMax(bool isFirstExtract);
};

void MaxHeap::swapElements(int index1, int index2)
{
    int temp = heapArray->at(index1);
    heapArray->at(index1) = heapArray->at(index2);
    heapArray->at(index2) = temp;
}

void MaxHeap::siftDown(int index)
{
    int heapSize = (*heapArray).size();
    int largest = index;
    int leftChild = index * 2 + 1, rightChild = index * 2 + 2;

    if (leftChild < heapSize && heapArray->at(largest) < heapArray->at(leftChild)){largest = leftChild;}
    if (rightChild < heapSize && heapArray->at(largest) < heapArray->at(rightChild)){largest = rightChild;}

    if (largest != index)
    {
        swapElements(index, largest);
        siftDown(largest);
    }
}

void MaxHeap::addElement(int value)
{
    heapArray->push_back(value);
}

void MaxHeap::removeAllElements()
{
    heapArray->clear();
}

void MaxHeap::removeMax(bool isFirstExtract)
{
    if ((*heapArray).size() == 0){std::cout << "CANNOT\n";}
    else
    {
        if (isFirstExtract)
        {
            for (int i = (*heapArray).size() / 2; i > -1; --i)
            {
                siftDown(i);
            }
        }
        this->swapElements(0, (*heapArray).size() - 1);
        std::cout << heapArray->at((*heapArray).size() - 1) << std::endl;
        heapArray->pop_back();
        siftDown(0);
    }
}

int main()
{
    MaxHeap maxHeap = MaxHeap();
    
    std::string inputLine;
    std::ifstream inputFile;
    bool isFirst = true;
    inputFile.open("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    while (getline(inputFile, inputLine))
    {
        if (inputLine == "CLEAR")
        {
            maxHeap.removeAllElements();
        }
        else if (inputLine == "EXTRACT")
        {
            maxHeap.removeMax(isFirst);
            isFirst = false;
        }
        else
        {
            isFirst = true;
            inputLine = inputLine.substr(4, inputLine.size() - 1);
            maxHeap.addElement(std::stoi(inputLine));
        }
    }

    inputFile.close();

    return 0;
}