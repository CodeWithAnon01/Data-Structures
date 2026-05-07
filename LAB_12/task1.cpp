#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calculateStringHash(const string& textValue) {
    int calculatedHashValue = 0;
    for (char characterValue : textValue) {
        calculatedHashValue += characterValue;
    }
    return calculatedHashValue;
}

struct HashNodeElement {
    string tagIdentifier;
    int occurrenceCount;
    HashNodeElement* nextNodeLink;
    HashNodeElement(string identifier) : tagIdentifier(identifier), occurrenceCount(1), nextNodeLink(nullptr) {}
};

class SeparateChainingHashTable {
private:
    vector<HashNodeElement*> bucketArrayContainer;
    int totalAvailableBuckets;

    int getChainLength(int bucketIndex) {
        int chainLength = 0;
        HashNodeElement* currentNode = bucketArrayContainer[bucketIndex];
        while (currentNode != nullptr) {
            chainLength++;
            currentNode = currentNode->nextNodeLink;
        }
        return chainLength;
    }

public:
    SeparateChainingHashTable(int maximumCapacity) {
        totalAvailableBuckets = maximumCapacity;
        bucketArrayContainer.resize(maximumCapacity, nullptr);
    }

    void insertTrendingTag(string newTagIdentifier) {
        int targetHashIndex = calculateStringHash(newTagIdentifier) % totalAvailableBuckets;
        HashNodeElement* currentActiveNode = bucketArrayContainer[targetHashIndex];

        while (currentActiveNode != nullptr) {
            if (currentActiveNode->tagIdentifier == newTagIdentifier) {
                currentActiveNode->occurrenceCount++;
                cout << "Tag '" << newTagIdentifier << "' count incremented to " << currentActiveNode->occurrenceCount << endl;
                return;
            }
            currentActiveNode = currentActiveNode->nextNodeLink;
        }

        HashNodeElement* freshNodeElement = new HashNodeElement(newTagIdentifier);
        freshNodeElement->nextNodeLink = bucketArrayContainer[targetHashIndex];
        bucketArrayContainer[targetHashIndex] = freshNodeElement;
        cout << "Inserted '" << newTagIdentifier << "' at bucket " << targetHashIndex << endl;

        int currentChainLength = getChainLength(targetHashIndex);
        if (currentChainLength > 5) {
            cout << "System Overload: Chain at bucket " << targetHashIndex << " has " << currentChainLength << " nodes!" << endl;
        }
    }

    int retrieveTagCount(string requestedTagIdentifier) {
        int targetHashIndex = calculateStringHash(requestedTagIdentifier) % totalAvailableBuckets;
        HashNodeElement* currentActiveNode = bucketArrayContainer[targetHashIndex];

        while (currentActiveNode != nullptr) {
            if (currentActiveNode->tagIdentifier == requestedTagIdentifier) {
                return currentActiveNode->occurrenceCount;
            }
            currentActiveNode = currentActiveNode->nextNodeLink;
        }
        return 0;
    }

    void deleteBannedTag(string bannedTagIdentifier) {
        int targetHashIndex = calculateStringHash(bannedTagIdentifier) % totalAvailableBuckets;
        HashNodeElement* currentActiveNode = bucketArrayContainer[targetHashIndex];
        HashNodeElement* previousVisitedNode = nullptr;

        while (currentActiveNode != nullptr) {
            if (currentActiveNode->tagIdentifier == bannedTagIdentifier) {
                if (previousVisitedNode == nullptr) {
                    bucketArrayContainer[targetHashIndex] = currentActiveNode->nextNodeLink;
                } else {
                    previousVisitedNode->nextNodeLink = currentActiveNode->nextNodeLink;
                }
                delete currentActiveNode;
                cout << "Deleted banned tag '" << bannedTagIdentifier << "' from bucket " << targetHashIndex << endl;
                return;
            }
            previousVisitedNode = currentActiveNode;
            currentActiveNode = currentActiveNode->nextNodeLink;
        }
        cout << "Tag '" << bannedTagIdentifier << "' not found." << endl;
    }

    int findLongestChainLength() {
        int longestChainFound = 0;
        int longestChainBucketIndex = 0;
        for (int bucketIndex = 0; bucketIndex < totalAvailableBuckets; bucketIndex++) {
            int currentLength = getChainLength(bucketIndex);
            if (currentLength > longestChainFound) {
                longestChainFound = currentLength;
                longestChainBucketIndex = bucketIndex;
            }
        }
        cout << "Longest chain: " << longestChainFound << " nodes at bucket " << longestChainBucketIndex << endl;
        return longestChainFound;
    }

    void displayEntireTable() {
        for (int bucketIndex = 0; bucketIndex < totalAvailableBuckets; bucketIndex++) {
            cout << "Bucket " << bucketIndex << ": ";
            HashNodeElement* currentNode = bucketArrayContainer[bucketIndex];
            if (currentNode == nullptr) {
                cout << "[empty]";
            }
            while (currentNode != nullptr) {
                cout << "[" << currentNode->tagIdentifier << ":" << currentNode->occurrenceCount << "] -> ";
                currentNode = currentNode->nextNodeLink;
            }
            cout << endl;
        }
    }

    ~SeparateChainingHashTable() {
        for (int bucketIndex = 0; bucketIndex < totalAvailableBuckets; bucketIndex++) {
            HashNodeElement* currentNode = bucketArrayContainer[bucketIndex];
            while (currentNode != nullptr) {
                HashNodeElement* nodeToDelete = currentNode;
                currentNode = currentNode->nextNodeLink;
                delete nodeToDelete;
            }
        }
    }
};

int main() {
    SeparateChainingHashTable trendingTracker(7);

    cout << "=== Inserting Trending Tags ===" << endl;
    trendingTracker.insertTrendingTag("coding");
    trendingTracker.insertTrendingTag("gaming");
    trendingTracker.insertTrendingTag("music");
    trendingTracker.insertTrendingTag("sports");
    trendingTracker.insertTrendingTag("coding");
    trendingTracker.insertTrendingTag("travel");
    trendingTracker.insertTrendingTag("food");
    trendingTracker.insertTrendingTag("fitness");
    cout << endl;

    cout << "=== Hash Table State ===" << endl;
    trendingTracker.displayEntireTable();
    cout << endl;

    cout << "=== Searching Tags ===" << endl;
    cout << "Count of 'coding': " << trendingTracker.retrieveTagCount("coding") << endl;
    cout << "Count of 'music': " << trendingTracker.retrieveTagCount("music") << endl;
    cout << "Count of 'unknown': " << trendingTracker.retrieveTagCount("unknown") << endl;
    cout << endl;

    cout << "=== Finding Longest Chain ===" << endl;
    trendingTracker.findLongestChainLength();
    cout << endl;

    cout << "=== Deleting Banned Tag 'gaming' ===" << endl;
    trendingTracker.deleteBannedTag("gaming");
    cout << endl;

    cout << "=== Final Hash Table State ===" << endl;
    trendingTracker.displayEntireTable();

    return 0;
}
