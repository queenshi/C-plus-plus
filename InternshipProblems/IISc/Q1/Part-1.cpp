// Importing necessary header files
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <limits.h>
#include <bits/stdc++.h>

using namespace std;

// Making Trip Structure
struct Trip {
    string id;
    string started_at;
    string ended_at;
    double start_lat;
    double start_lng;
    double end_lat;
    double end_lng;
};

// Main Function
int main() {
    // Initialising inital time when program gets started
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    // providing path of the file
    string filename = "D:\\Coding\\Git\\GitHub\\C-plus-plus\\Q1\\bike_data_new.csv";
    ifstream file(filename);
    
    // Initialising variables
    string line;
    int num_trips = 0;
    int num_circular_trips = 0;
    int max_duration = 0;
    int min_duration = INT_MAX;
    int num_min_duration_trips = 0;
    int duration, start_time, end_time;

    // Skip the header line
    getline(file, line);
    
    // Traversing the whole file line-by-line
    while (getline(file, line)) {
        // Making a trip variable of type Trip
        Trip trip;
        stringstream ss(line);

        // Appending id to the trip variable
        getline(ss, trip.id, ',');

        // Appending start time of the trip
        getline(ss, trip.started_at, ',');
        
        // Appending the end time of trip
        getline(ss, trip.ended_at, ',');

        // Appending start latitude of the trip after converting to double
        getline(ss, line, ',');
        trip.start_lat = stod(line);

        // Appending start longitude of the trip after converting to double
        getline(ss, line, ',');
        trip.start_lng = stod(line);

        // Appending ending latitude of the trip after converting to double
        getline(ss, line, ',');
        trip.end_lat = stod(line);

        // Appending ending longitude of the trip after converting to double
        getline(ss, line, ',');
        trip.end_lng = stod(line);

        // Calculating the duration of the trip
        start_time = stoi(trip.started_at.substr(11, 2)) * 60 + stoi(trip.started_at.substr(14, 2));
        end_time = stoi(trip.ended_at.substr(11, 2)) * 60 + stoi(trip.ended_at.substr(14, 2));
        duration = end_time - start_time;

        // Removing the trip those time duration is Zero.
        if (duration == 0) {
            continue;
        }

        // Calculating the Maximum time duration of the trip
        if (duration > max_duration) {
            max_duration = duration;
        }

        // Calculating the Minimum time duration of the trip
        if (duration < min_duration) {
            min_duration = duration;
            num_min_duration_trips = 1;
        } else if (duration == min_duration) {
            num_min_duration_trips++;
        }

        // Calculating the number of the circular trips
        if (trip.start_lat == trip.end_lat && trip.start_lng == trip.end_lng) {
            num_circular_trips++;
        }
        num_trips++; // Note down the total number of trips except those whose duration is Zero
    }

    // Calculating the percentage of the circular trips
    double circular_trip_percent = (double)num_circular_trips / num_trips * 100.0;

    // Final time of the program
    chrono::steady_clock::time_point end = chrono::steady_clock::now();

    // Output of the program
    cout << "Maximum duration of the trip (in minutes): " << max_duration << endl;
    cout << "Minimum duration of the trip (in minutes): " << min_duration << endl;
    cout << "Total number of trips corresponding to the minimum duration: " << num_min_duration_trips << endl;
    cout << "Percentage of total circular trips: " << circular_trip_percent << " %" << endl;
    cout << "Time taken: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " ms" << endl;
    return 0;
}
