#include "TrainStation.h"
#include "BusStation.h"
#include "Country.h"
#include <random>;
#include <iostream>;
#include <locale>;
#include <string>;
#include <fstream>

using namespace std;

int GenerateRand(int begin, int end)
{
    random_device seed;     
    mt19937 engine(seed()); 
    uniform_int_distribution<int> uniformDist(begin, end);
    return uniformDist(engine);
}


int menu()
{
    Country country;
    Station* station;
    TrainStation trainStation;
    BusStation busStation;
    string cityName;

    int choice;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Insert station using insert() - The Train Station\n";
        std::cout << "2. Insert station using emplace() - The Bus Station\n";
        std::cout << "3. Get station using get()\n";
        std::cout << "4. Find station using find()\n";
        std::cout << "5. Erase station\n";
        std::cout << "6. Add station to city\n";
        std::cout << "8. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter city name: ";
            std::cin >> cityName;
            station = new TrainStation();
            country.insert(cityName, station);
            std::cout << "Station inserted using insert()\n";
            break;

        case 2:
            std::cout << "Enter city name: ";
            std::cin >> cityName;
            station = new BusStation();
            country.emplace(cityName, station);
            std::cout << "Station inserted using emplace()\n";
            break;

        case 3:
            std::cout << "Enter city name: ";
            std::cin >> cityName;
            station = country.get<TrainStation>(cityName);
            if (station != nullptr) {
                std::cout << "Train Station found using get<TrainStation>()\n";
                int action;


                Train train2(*trainStation.getTrain(0));
                Train train3;

                do {
                    cout << "Choose an option:" << endl;
                    cout << "1. Add vehicle " << endl;
                    cout << "2. Delete vehicle" << endl;
                    cout << "3. Edit vehicle" << endl;
                    cout << "4. Print vehicle" << endl;
                    cout << "5. Show <train 1> and its copy <train 2> (Copy constructor usage)" << endl;
                    cout << "6. Use operator '=' for trains" << endl;
                    cout << "7. Use operator '[]' for trains" << endl;
                    cout << "8. Use operator '<<' for trains" << endl;
                    cout << "9. Use operator '>>' for trains" << endl;
                    cout << "10. Clear screen" << endl;
                    cout << "0. Exit" << endl;
                    cin >> action;

                    switch (action) {
                    case 1: { // add train

                        station->addVehicle();
                        station->print();
                        break;
                    }
                    case 2: { // delete train
                        int index;
                        cout << "Enter the index of the train to delete: " << endl;
                        cin >> index;
                        station->deleteVehicle(index);
                        cout << "Train deleted." << endl;

                        station->print();
                        break;
                    }
                    case 3: { // edit train
                        int index;
                        cout << "Enter the index of the train to edit: " << endl;
                        cin >> index;
                        station->editVehicle(index);
                        station->print();
                        break;
                    }
                    case 4: {
                        station->print();
                        break;
                    }
                    case 5: {
                        cout << "Train 1" << endl;
                        trainStation.getTrain(0)->print();
                        cout << "Train COPY 2" << endl;
                        train2.print();
                        break;
                    }

                    case 6:
                    {
                        train2 = train3;
                        cout << "Train COPY 2" << endl;
                        train2.print();
                        break;
                    }

                    case 7:
                    {
                        if (train2[0] != NULL) cout << *train2[0];

                        break;
                    }
                    case 8:
                    {
                        cout << train2;
                        ofstream outfile("train_data.txt");

                        // Write the contents of myTrain to the output file
                        outfile << train2;

                        outfile.close();

                        break;
                    }

                    case 9:
                    {
                        Train train4;
                        train4.print();

                        ifstream infile("train_data.txt");
                        infile >> train4;

                        // Print the contents of the new Train object to verify that it was read correctly
                        train4.print();

                        infile.close();
                        break;
                    }

                    case 10:
                    {
                        system("CLS");
                    }
                    case 0:
                    {
                        system("CLS");
                        break;
                    }

                    default:
                        cout << "Invalid choice." << endl;
                        break;
                    }
                } while (action != 0);
            }
            else {
                station = country.get<BusStation>(cityName);
                if (station != nullptr) {
                    std::cout << "Bus Station found using get<BusStation>()\n";
                    int action;
                    Bus Bus2(*busStation.getBus(0));
                    Bus Bus3;

                    do {
                        cout << "Choose an option:" << endl;
                        cout << "1. Add vehicle " << endl;
                        cout << "2. Delete vehicle" << endl;
                        cout << "3. Edit vehicle" << endl;
                        cout << "4. Print vehicle" << endl;
                        cout << "5. Show <Bus 1> and its copy <Bus 2> (Copy constructor usage)" << endl;
                        cout << "6. Use operator '=' for Buss" << endl;
                        cout << "7. Use operator '[]' for Buss" << endl;
                        cout << "8. Use operator '<<' for Buss" << endl;
                        cout << "9. Use operator '>>' for Buss" << endl;
                        cout << "10. Clear screen" << endl;
                        cout << "0. Exit" << endl;
                        cin >> action;

                        switch (action) {
                        case 1: { // add Bus

                            station->addVehicle();
                            station->print();
                            break;
                        }
                        case 2: { // delete Bus
                            int index;
                            cout << "Enter the index of the Bus to delete: " << endl;
                            cin >> index;
                            station->deleteVehicle(index);
                            cout << "Bus deleted." << endl;

                            station->print();
                            break;
                        }
                        case 3: { // edit Bus
                            int index;
                            cout << "Enter the index of the Bus to edit: " << endl;
                            cin >> index;
                            station->editVehicle(index);
                            station->print();
                            break;
                        }
                        case 4: {
                            station->print();
                            break;
                        }
                        case 5: {
                            cout << "Bus 1" << endl;
                            busStation.getBus(0)->print();
                            cout << "Bus COPY 2" << endl;
                            Bus2.print();
                            break;
                        }

                        case 6:
                        {
                            Bus2 = Bus3;
                            cout << "Bus COPY 2" << endl;
                            Bus2.print();
                            break;
                        }

                        case 7:
                        {
                            if (Bus2[0] != NULL) cout << *Bus2[0];

                            break;
                        }
                        case 8:
                        {
                            cout << Bus2;
                            ofstream outfile("Bus_data.txt");

                            // Write the contents of myBus to the output file
                            outfile << Bus2;

                            outfile.close();

                            break;
                        }

                        case 9:
                        {
                            Bus Bus4;
                            Bus4.print();

                            ifstream infile("Bus_data.txt");
                            infile >> Bus4;

                            // Print the contents of the new Bus object to verify that it was read correctly
                            Bus4.print();

                            infile.close();
                            break;
                        }

                        case 10:
                        {
                            system("CLS");
                        }
                        case 0:
                        {
                            system("CLS");
                            break;
                        }

                        default:
                            cout << "Invalid choice." << endl;
                            break;
                        }
                    } while (action != 0);

                }
                else {
                    std::cout << "Station not found\n";
                }
            }
            break;

        case 4:
            std::cout << "Enter city name: ";
            std::cin >> cityName;
            if (country.find(cityName)) {
                std::cout << "Station found\n";
            }
            else {
                std::cout << "Station not found\n";
            }
            break;

        case 5:
            std::cout << "Enter city name: ";
            std::cin >> cityName;
            country.erase(cityName);
            std::cout << "Station erased\n";
            break;

        case 6:
            std::cout << "Enter city name: ";
            std::cin >> cityName;
            int stationType;
            std::cout << "Select station type:\n";
            std::cout << "1. Train Station\n";
            std::cout << "2. Bus Station\n";
            std::cout << "Enter your choice: ";
            std::cin >> stationType;

            if (stationType == 1) {
                station = new TrainStation();
            }
            else if (stationType == 2) {
                station = new BusStation();
            }
            else {
                std::cout << "Invalid station type\n";
                continue;
            }

            country.addStationToCity(cityName, station);
            std::cout << "Station added to city\n";
            break;

        case 8:
            std::cout << "Quitting...\n";
            return 0;

        default:
            std::cout << "Invalid choice\n";
            break;
        }

        std::cout << std::endl;
    }

    return 0;
}


        

    