#include <iostream>
#include <vector>

using namespace std;

class DoubleHashingHashTable {
private:
    vector<int> secureVaultArray;
    int totalSecureVaults;
    int secondaryPrimeValue;

public:
    DoubleHashingHashTable(int maximumCapacity, int primeNumberValue) {
        totalSecureVaults = maximumCapacity;
        secondaryPrimeValue = primeNumberValue;
        secureVaultArray.resize(maximumCapacity, -1);
    }

    int computePrimaryHash(int keyValue) {
        return keyValue % totalSecureVaults;
    }

    int computeSecondaryHash(int keyValue) {
        return secondaryPrimeValue - (keyValue % secondaryPrimeValue);
    }

    void assignVaultCode(int incomingVaultIdentifier) {
        int primaryHashResult = computePrimaryHash(incomingVaultIdentifier);
        int secondaryHashStepSize = computeSecondaryHash(incomingVaultIdentifier);

        cout << "Hash1(" << incomingVaultIdentifier << ") = " << primaryHashResult
             << ", Hash2(" << incomingVaultIdentifier << ") = " << secondaryHashStepSize << endl;

        int currentProbeNumber = 0;

        while (currentProbeNumber <= totalSecureVaults) {
            int calculatedTargetIndex = (primaryHashResult + currentProbeNumber * secondaryHashStepSize) % totalSecureVaults;
            cout << "Probe " << currentProbeNumber << ": checking vault " << calculatedTargetIndex;

            if (secureVaultArray[calculatedTargetIndex] == -1) {
                secureVaultArray[calculatedTargetIndex] = incomingVaultIdentifier;
                cout << " -> ASSIGNED" << endl;
                return;
            }

            cout << " -> occupied by " << secureVaultArray[calculatedTargetIndex] << endl;
            currentProbeNumber++;

            if (currentProbeNumber > totalSecureVaults) {
                cout << "Vault Full: Checked more than " << totalSecureVaults
                     << " slots. Cannot assign vault for key " << incomingVaultIdentifier << endl;
                return;
            }
        }
    }

    int locateVaultByCode(int requestedVaultIdentifier) {
        int primaryHashResult = computePrimaryHash(requestedVaultIdentifier);
        int secondaryHashStepSize = computeSecondaryHash(requestedVaultIdentifier);
        int currentProbeNumber = 0;

        while (currentProbeNumber <= totalSecureVaults) {
            int calculatedTargetIndex = (primaryHashResult + currentProbeNumber * secondaryHashStepSize) % totalSecureVaults;
            if (secureVaultArray[calculatedTargetIndex] == -1) {
                return -1;
            }
            if (secureVaultArray[calculatedTargetIndex] == requestedVaultIdentifier) {
                return calculatedTargetIndex;
            }
            currentProbeNumber++;
        }
        return -1;
    }

    void displayAllVaults() {
        for (int vaultIndex = 0; vaultIndex < totalSecureVaults; vaultIndex++) {
            cout << "Vault " << vaultIndex << ": ";
            if (secureVaultArray[vaultIndex] == -1) {
                cout << "[EMPTY]";
            } else {
                cout << "Customer #" << secureVaultArray[vaultIndex];
            }
            cout << endl;
        }
    }
};

int main() {
    DoubleHashingHashTable bankVaultSystem(13, 7);

    cout << "=== High-Security Bank Vault System (size=13, prime=7) ===" << endl << endl;

    cout << "--- Assigning Vault Codes ---" << endl;
    bankVaultSystem.assignVaultCode(27);
    cout << endl;
    bankVaultSystem.assignVaultCode(40);
    cout << endl;
    bankVaultSystem.assignVaultCode(53);
    cout << endl;
    bankVaultSystem.assignVaultCode(14);
    cout << endl;
    bankVaultSystem.assignVaultCode(66);
    cout << endl;

    cout << "=== Vault Status ===" << endl;
    bankVaultSystem.displayAllVaults();
    cout << endl;

    cout << "=== Searching for Customer 53 ===" << endl;
    int foundVaultIndex = bankVaultSystem.locateVaultByCode(53);
    if (foundVaultIndex != -1) {
        cout << "Customer 53 found at vault " << foundVaultIndex << endl;
    } else {
        cout << "Customer 53 not found." << endl;
    }

    return 0;
}
