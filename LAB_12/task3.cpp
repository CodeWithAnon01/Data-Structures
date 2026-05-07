#include <iostream>
#include <vector>

using namespace std;

class QuadraticProbingHashTable {
private:
    vector<int> seatBookingArray;
    int totalAvailableSeats;
    int currentlyOccupiedSeatCount;

public:
    QuadraticProbingHashTable(int primeMaximumCapacity) {
        totalAvailableSeats = primeMaximumCapacity;
        currentlyOccupiedSeatCount = 0;
        seatBookingArray.resize(primeMaximumCapacity, -1);
    }

    double calculateCurrentLoadFactor() {
        return (double)currentlyOccupiedSeatCount / totalAvailableSeats;
    }

    void reserveTheaterSeat(int incomingBookingIdentifier) {
        double currentSystemLoadFactor = calculateCurrentLoadFactor();
        cout << "Current load factor: " << currentSystemLoadFactor << endl;

        if (currentSystemLoadFactor > 0.5) {
            cout << "WARNING: Load factor exceeds 0.5! Rehash is needed to maintain performance." << endl;
            cout << "Booking for ID " << incomingBookingIdentifier << " rejected." << endl;
            return;
        }

        int initialTargetIndex = incomingBookingIdentifier % totalAvailableSeats;
        int currentProbeNumber = 0;

        while (currentProbeNumber < totalAvailableSeats) {
            int calculatedTargetIndex = (initialTargetIndex + currentProbeNumber * currentProbeNumber) % totalAvailableSeats;
            cout << "Probe " << currentProbeNumber << ": checking seat " << calculatedTargetIndex;

            if (seatBookingArray[calculatedTargetIndex] == -1) {
                seatBookingArray[calculatedTargetIndex] = incomingBookingIdentifier;
                currentlyOccupiedSeatCount++;
                cout << " -> BOOKED" << endl;
                return;
            }
            cout << " -> occupied by " << seatBookingArray[calculatedTargetIndex] << endl;
            currentProbeNumber++;
        }
        cout << "No available seat found for booking " << incomingBookingIdentifier << endl;
    }

    void displaySeatArrangement() {
        for (int seatIndex = 0; seatIndex < totalAvailableSeats; seatIndex++) {
            cout << "Seat " << seatIndex << ": ";
            if (seatBookingArray[seatIndex] == -1) {
                cout << "[AVAILABLE]";
            } else {
                cout << "Booking #" << seatBookingArray[seatIndex];
            }
            cout << endl;
        }
    }
};

int main() {
    QuadraticProbingHashTable theaterBookingSystem(11);

    cout << "=== Prime-Sized Theater Booking System (size=11) ===" << endl << endl;

    cout << "--- Booking Seats ---" << endl;
    theaterBookingSystem.reserveTheaterSeat(22);
    cout << endl;
    theaterBookingSystem.reserveTheaterSeat(33);
    cout << endl;
    theaterBookingSystem.reserveTheaterSeat(44);
    cout << endl;
    theaterBookingSystem.reserveTheaterSeat(55);
    cout << endl;
    theaterBookingSystem.reserveTheaterSeat(66);
    cout << endl;

    cout << "=== Seat Arrangement ===" << endl;
    theaterBookingSystem.displaySeatArrangement();
    cout << endl;

    cout << "--- Attempting 6th booking (should trigger load factor warning) ---" << endl;
    theaterBookingSystem.reserveTheaterSeat(77);
    cout << endl;

    cout << "=== Final Seat Arrangement ===" << endl;
    theaterBookingSystem.displaySeatArrangement();

    return 0;
}
