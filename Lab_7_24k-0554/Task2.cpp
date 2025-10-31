#include <iostream>
#include <string>
using namespace std;

struct Runner {
    string name;
    int finishTime;
};

void combineArrays(Runner runners[], int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    
    Runner* leftArray = new Runner[leftSize];
    Runner* rightArray = new Runner[rightSize];
    
    for (int i = 0; i < leftSize; i++)
        leftArray[i] = runners[left + i];
    for (int j = 0; j < rightSize; j++)
        rightArray[j] = runners[middle + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < leftSize && j < rightSize) {
        if (leftArray[i].finishTime <= rightArray[j].finishTime) {
            runners[k] = leftArray[i];
            i++;
        } else {
            runners[k] = rightArray[j];
            j++;
        }
        k++;
    }
    
    while (i < leftSize) {
        runners[k] = leftArray[i];
        i++;
        k++;
    }
    
    while (j < rightSize) {
        runners[k] = rightArray[j];
        j++;
        k++;
    }
    
    delete[] leftArray;
    delete[] rightArray;
}

void performMergeSort(Runner runners[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        
        performMergeSort(runners, left, middle);
        performMergeSort(runners, middle + 1, right);
        
        combineArrays(runners, left, middle, right);
    }
}

void displayTopRunners(Runner runners[], int totalRunners, int topCount) {
    cout << "\nTop " << topCount << " Fastest Runners:\n";
    cout << "-------------------------------\n";
    cout << "Rank\tName\t\tTime (seconds)\n";
    cout << "-------------------------------\n";
    
    for (int i = 0; i < topCount && i < totalRunners; i++) {
        cout << i + 1 << "\t" << runners[i].name << "\t\t" << runners[i].finishTime << endl;
    }
}

int main() {
    int totalParticipants = 10;
    Runner marathonRunners[10];
    
    cout << "Enter details of " << totalParticipants << " marathon participants:\n\n";
    
    for (int i = 0; i < totalParticipants; i++) {
        cout << "Participant " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> marathonRunners[i].name;
        cout << "Finish time (in seconds): ";
        cin >> marathonRunners[i].finishTime;
        cout << endl;
    }
    
    performMergeSort(marathonRunners, 0, totalParticipants - 1);
    
    displayTopRunners(marathonRunners, totalParticipants, 5);
    
    return 0;
}