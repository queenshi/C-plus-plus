// Importing necessary header files
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

// Making Trip Structure
struct Trip {
    int id;
    string started_at;
    string ended_at;
    double start_lat;
    double start_lng;
    double end_lat;
    double end_lng;
    int duration;
};

// Function read data and return the necessary data
vector<Trip> readTripsFromFile(string filename) {
    // Making a trips variable of type Trip
    vector<Trip> trips;
    ifstream file(filename);
    string line;

    // skip header line
    getline(file, line);
    
    // Traversing the whole file line-by-line
    while (getline(file, line)) {
        // Making a trip variable of type Trip
        Trip trip;

        stringstream ss(line);
        string token;
        // Appending id to the trip variable
        getline(ss, token, ',');
        trip.id = stoi(token);

        // Appending start time of the trip
        getline(ss, trip.started_at, ',');
        
        // Appending the end time of trip
        getline(ss, trip.ended_at, ',');

        // Appending start latitude of the trip after converting to double
        getline(ss, token, ',');
        trip.start_lat = stod(token);

        // Appending start longitude of the trip after converting to double
        getline(ss, token, ',');
        trip.start_lng = stod(token);

        // Appending ending latitude of the trip after converting to double
        getline(ss, token, ',');
        trip.end_lat = stod(token);

        // Appending ending longitude of the trip after converting to double
        getline(ss, token, ',');
        trip.end_lng = stod(token);

        // Calculating the duration of the trip
        int start_time = stoi(trip.started_at.substr(11, 2)) * 60 + stoi(trip.started_at.substr(14, 2));
        int end_time = stoi(trip.ended_at.substr(11, 2)) * 60 + stoi(trip.ended_at.substr(14, 2));
        int dur = end_time - start_time;
        trip.duration = dur;

        // Storing the necessary data if condition is satisfied
        if (trip.duration > 0 && trip.started_at.substr(11, 2) >= "06" && trip.started_at.substr(11, 2) <= "18") {
            trips.push_back(trip);
        }
    }
    return trips;
}

// Function to calculate the total numbers of Feasible pairs in the dataset
int countFeasiblePairs(const vector<Trip>& trips) {
    int count = 0;
    for (size_t i = 0; i < trips.size(); ++i) {
        for (size_t j = i + 1; j < trips.size(); ++j) {
            if (trips[i].end_lat == trips[j].start_lat && trips[i].end_lng == trips[j].start_lng && trips[i].ended_at <= trips[j].started_at) {
                count++;
            }
        }
    }
    return count;
}

// Main Function
int main() {
    // Initialising inital time when program gets started
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    // providing path of the file
    vector<Trip> trips = readTripsFromFile("D:\\Coding\\Git\\GitHub\\C-plus-plus\\Q1\\bike_data_new.csv");
    
    // Output of the program
    cout << "Total number of trips: " << trips.size() << endl;
    cout << "Total number of feasible pairs of trips: " << countFeasiblePairs(trips) << endl;

    // Final time of the program
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Time taken: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " ms" << endl;
    return 0;
}
