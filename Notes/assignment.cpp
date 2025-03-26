//
// Created by 易治行 on 2025/3/26.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Car {
private:
    string license;
    double fee;

public:
    Car(string id, double fee): license(id), fee(fee) {}

    int get_fee() {
        return this->fee;
    }

    string get_license() {
        return this->license;
    }

};

class Lane {

private:
    int lane_id;
    vector<Car*> cars;

public:
    Lane(int id) {
        this->lane_id = id;
    }

    void process_car(Car* car) {
        this->cars.push_back(car);
    }

    int number_car() {
        return this->cars.size();
    }

    double get_total_charge() {
        double total_fee = 0;

        for (auto car : this->cars)
            total_fee += car->get_fee();

        return total_fee;
    }

    int get_lane_id() {
        return this->lane_id;
    }

    void print_info() {
        int num_cars = this->number_car();
        double total_fee = this->get_total_charge();

        cout << "total cars: " << num_cars << endl;
        cout << "total fees: " << total_fee << endl;
    }
};


class Station {

private:
    vector<Lane*> lanes;

public:
    Station(){}

    void add_lane(Lane* lane) {
        this->lanes.push_back(lane);
    }

    void process_car(Car* car, int lane_id) {
        for (auto lane : this->lanes) {
            if (lane->get_lane_id() == lane_id) {
                lane->process_car(car);
            }
        }
    }

    void print_info() {
        int total_cars = 0;
        double total_fee = 0;

        for (auto lane : this->lanes) {
            cout <<  "lane " << lane->get_lane_id() << ": " << endl;
            lane->print_info();
            total_cars += lane->number_car();
            total_fee += lane->get_total_charge();
        }

        cout << "toll station: " << endl;
        cout << "total cars: " << total_cars << endl;
        cout << "total fee: " << total_fee << endl;
    }

};


int main() {
    Lane* lane1 = new Lane(1);
    Lane* lane2 = new Lane(2);
    Lane* lane3 = new Lane(3);

    Station toll_station = Station();

    toll_station.add_lane(lane1);
    toll_station.add_lane(lane2);
    toll_station.add_lane(lane3);

    Car* lamborghini = new Car("sdfdsfsdf", 120);
    Car* ferrari = new Car("retrebwwef", 130);
    Car* porsche = new Car("eur83regfrg", 100);
    Car* benz = new Car("sdfureiwroe", 95);

    lane1->process_car(lamborghini);
    lane2->process_car(ferrari);
    lane3->process_car(porsche);
    lane2->process_car(benz);

    toll_station.print_info();

    delete lamborghini;
    delete ferrari;
    delete porsche;
    delete benz;

    delete lane1;
    delete lane2;
    delete lane3;

    return 0;
}