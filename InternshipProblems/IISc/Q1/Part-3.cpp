// Importing necessary header files
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cmath>

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

// Function to remove the unnecessary data and store the required data in an array
vector<Trip> parseCSV(string filename) {
    // Making a trips variable of type Trip
    vector<Trip> trips;
    ifstream file(filename);
    int total = 100;
    string line;

    // skip header line
    getline(file, line);
    
    // Traversing the whole file line-by-line
    while (total > 0 && getline(file, line)) {
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
        trips.emplace_back(trip);
        total--;
    }
    return trips;
}

// Function to calculate the unique depots in the first 100 entries
void uniqueDepots(vector<Trip>& trips, vector<pair<double, double>>& depots) {
    for(int i = 0; i < 100; i++) {
        if(find(depots.begin(), depots.end(), make_pair(trips[i].start_lat, trips[i].start_lng)) == depots.end()) {
            depots.emplace_back(make_pair(trips[i].start_lat, trips[i].start_lng));
        }
        else if(find(depots.begin(), depots.end(), make_pair(trips[i].end_lat, trips[i].end_lng)) == depots.end()) {
            depots.emplace_back(make_pair(trips[i].end_lat, trips[i].end_lng));
        }
    }
}

// Function to calculate the Euclidean's distance between two points
double distance(double lat1, double lon1, double lat2, double lon2) {
    const double pi = 3.14159265358979323846;
    const double R = 6371e3;
    double phi1 = lat1 * pi / 180.0;
    double phi2 = lat2 * pi / 180.0;
    double delta_phi = (lat2 - lat1) * pi / 180.0;
    double delta_lambda = (lon2 - lon1) * pi / 180.0;

    double a = sin(delta_phi/2) * sin(delta_phi/2) +
               cos(phi1) * cos(phi2) *
               sin(delta_lambda/2) * sin(delta_lambda/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    double d = R * c;
    return d;
}

// Main Function
int main() {
    // Initialising inital time when program gets started
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    // providing path of the file and parsing the file
    vector<Trip> trips = parseCSV("D:\\Coding\\Git\\GitHub\\C-plus-plus\\Q1\\bike_data_new.csv");
    cout << "Total number of trips: " << trips.size() << endl;

    // Making the depots array containing the longitude and latitude
    vector<pair<double, double>> depots;
    uniqueDepots(trips, depots);
    int n = depots.size();
    cout << "Total number of depots: " << n << endl;

    
    // Calculate the distance between all the depots
    vector<vector<double>> distances(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            distances[i][j] = distance(depots[i].first, depots[i].second, depots[j].first, depots[j].second);
            // Below code line is due to lower triangle of the matrix is also showing the same distance as upper
            distances[j][i] = distances[i][j];
        }
    }
    
    // Initialising the variables
    double total_distance = 0.0;
    double max_distance = 0.0;
    double min_distance = numeric_limits<double>::max();

    // Calculate the minimum, maximum & total distances
    for(int i = 0; i < distances.size(); i++) {
        for(int j = i+1; j < distances.size(); j++) {
            if(distances[i][j] > max_distance)
                max_distance = distances[i][j];
            if(distances[i][j] < min_distance)
                min_distance = distances[i][j];
            total_distance += distances[i][j];
        }
    }
    

    // Final time of the program
    chrono::steady_clock::time_point end = chrono::steady_clock::now();

    // Output of the program
    cout << "Minimum Distance : " << min_distance << endl;
    cout << "Maximum Distance : " << max_distance << endl;
    cout << "Total Distance : " << total_distance << endl;
    cout << "Time taken: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " ms" << endl;
    return 0;
}
