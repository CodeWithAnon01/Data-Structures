#include <iostream>
using namespace std;

int findMaximumScore(int scores[], int count) {
    int maximum = scores[0];
    for (int i = 1; i < count; i++) {
        if (scores[i] > maximum)
            maximum = scores[i];
    }
    return maximum;
}

void sortByDigitPlace(int scores[], int count, int digitPlace) {
    int output[count];
    int frequency[10] = {0};
    
    for (int i = 0; i < count; i++)
        frequency[(scores[i] / digitPlace) % 10]++;
    
    for (int i = 1; i < 10; i++)
        frequency[i] += frequency[i - 1];
    
    for (int i = count - 1; i >= 0; i--) {
        int digit = (scores[i] / digitPlace) % 10;
        output[frequency[digit] - 1] = scores[i];
        frequency[digit]--;
    }
    
    for (int i = 0; i < count; i++)
        scores[i] = output[i];
}

void performRadixSort(int scores[], int count) {
    int maximumScore = findMaximumScore(scores, count);
    
    for (int place = 1; maximumScore / place > 0; place *= 10) {
        sortByDigitPlace(scores, count, place);
    }
}

void displayScoresWithRanks(int scores[], int count) {
    cout << "\nStudent Scores with Rankings:\n";
    cout << "==============================\n";
    cout << "Rank\tScore\n";
    cout << "==============================\n";
    
    for (int i = 0; i < count; i++) {
        cout << i + 1 << "\t" << scores[i] << endl;
    }
}

int main() {
    int totalStudents = 50;
    int examScores[50];
    
    cout << "Enter " << totalStudents << " integer scores (0 to 100):\n\n";
    
    for (int i = 0; i < totalStudents; i++) {
        cout << "Student " << i + 1 << " score: ";
        cin >> examScores[i];
    }
    
    cout << "\nSorting scores using Radix Sort...\n";
    performRadixSort(examScores, totalStudents);
    
    displayScoresWithRanks(examScores, totalStudents);
    
    return 0;
}