#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct LockerSlotElement {
    int packageIdentifierCode;
    bool isSlotOccupied;
    bool isSlotMarkedDeleted;
    LockerSlotElement() : packageIdentifierCode(-1), isSlotOccupied(false), isSlotMarkedDeleted(false) {}
};

class LinearProbingHashTable {
private:
    vector<LockerSlotElement> lockerStorageArray;
    int totalAvailableLockers;

public:
    LinearProbingHashTable(int maximumCapacity) {
        totalAvailableLockers = maximumCapacity;
        lockerStorageArray.resize(maximumCapacity);
    }

    void storeDeliveryPackage(int incomingPackageIdentifier) {
        int initialTargetIndex = incomingPackageIdentifier % totalAvailableLockers;
        int totalProbesMade = 0;

        while (totalProbesMade < totalAvailableLockers) {
            int calculatedTargetIndex = (initialTargetIndex + totalProbesMade) % totalAvailableLockers;
            if (!lockerStorageArray[calculatedTargetIndex].isSlotOccupied || lockerStorageArray[calculatedTargetIndex].isSlotMarkedDeleted) {
                lockerStorageArray[calculatedTargetIndex].packageIdentifierCode = incomingPackageIdentifier;
                lockerStorageArray[calculatedTargetIndex].isSlotOccupied = true;
                lockerStorageArray[calculatedTargetIndex].isSlotMarkedDeleted = false;
                cout << "Stored package " << incomingPackageIdentifier << " at locker " << calculatedTargetIndex
                     << " (probes: " << totalProbesMade + 1 << ")" << endl;
                return;
            }
            totalProbesMade++;
        }
        cout << "All lockers are full. Cannot store package " << incomingPackageIdentifier << endl;
    }

    int locateStoredPackage(int requestedPackageIdentifier) {
        int initialTargetIndex = requestedPackageIdentifier % totalAvailableLockers;
        int totalProbesMade = 0;

        while (totalProbesMade < totalAvailableLockers) {
            int calculatedTargetIndex = (initialTargetIndex + totalProbesMade) % totalAvailableLockers;

            if (!lockerStorageArray[calculatedTargetIndex].isSlotOccupied && !lockerStorageArray[calculatedTargetIndex].isSlotMarkedDeleted) {
                return -1;
            }

            if (lockerStorageArray[calculatedTargetIndex].isSlotOccupied &&
                !lockerStorageArray[calculatedTargetIndex].isSlotMarkedDeleted &&
                lockerStorageArray[calculatedTargetIndex].packageIdentifierCode == requestedPackageIdentifier) {
                return calculatedTargetIndex;
            }
            totalProbesMade++;
        }
        return -1;
    }

    void dispatchDeliveryPackage(int dispatchingPackageIdentifier) {
        int foundLockerIndex = locateStoredPackage(dispatchingPackageIdentifier);
        if (foundLockerIndex != -1) {
            lockerStorageArray[foundLockerIndex].isSlotMarkedDeleted = true;
            lockerStorageArray[foundLockerIndex].isSlotOccupied = false;
            cout << "Package " << dispatchingPackageIdentifier << " dispatched from locker " << foundLockerIndex
                 << " (lazy deletion applied)" << endl;
        } else {
            cout << "Package " << dispatchingPackageIdentifier << " not found." << endl;
        }
    }

    void displayLockerStatus() {
        for (int lockerIndex = 0; lockerIndex < totalAvailableLockers; lockerIndex++) {
            cout << "Locker " << lockerIndex << ": ";
            if (lockerStorageArray[lockerIndex].isSlotMarkedDeleted) {
                cout << "[DELETED]";
            } else if (lockerStorageArray[lockerIndex].isSlotOccupied) {
                cout << lockerStorageArray[lockerIndex].packageIdentifierCode;
            } else {
                cout << "[EMPTY]";
            }
            cout << endl;
        }
    }
};

int main() {
    LinearProbingHashTable warehouseLockers(10);

    cout << "=== Storing Packages ===" << endl;
    warehouseLockers.storeDeliveryPackage(25);
    warehouseLockers.storeDeliveryPackage(35);
    warehouseLockers.storeDeliveryPackage(15);
    warehouseLockers.storeDeliveryPackage(45);
    warehouseLockers.storeDeliveryPackage(55);
    cout << endl;

    cout << "=== Locker Status ===" << endl;
    warehouseLockers.displayLockerStatus();
    cout << endl;

    cout << "=== Searching for Package 35 ===" << endl;
    int foundAtIndex = warehouseLockers.locateStoredPackage(35);
    if (foundAtIndex != -1) {
        cout << "Package 35 found at locker " << foundAtIndex << endl;
    }
    cout << endl;

    cout << "=== Dispatching Package 35 (Lazy Deletion) ===" << endl;
    warehouseLockers.dispatchDeliveryPackage(35);
    cout << endl;

    cout << "=== Locker Status After Deletion ===" << endl;
    warehouseLockers.displayLockerStatus();
    cout << endl;

    cout << "=== Searching for Package 45 (should skip deleted slot) ===" << endl;
    foundAtIndex = warehouseLockers.locateStoredPackage(45);
    if (foundAtIndex != -1) {
        cout << "Package 45 found at locker " << foundAtIndex << endl;
    } else {
        cout << "Package 45 not found." << endl;
    }
    cout << endl;

    cout << "=== Inserting Package 65 (should reuse deleted slot) ===" << endl;
    warehouseLockers.storeDeliveryPackage(65);
    cout << endl;

    cout << "=== Final Locker Status ===" << endl;
    warehouseLockers.displayLockerStatus();

    return 0;
}
