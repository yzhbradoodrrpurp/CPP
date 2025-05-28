//
// Created by 易治行 on 2025/5/28.
//

#include <iostream>
#include <set>
#include <algorithm>
#include <numeric>

class GradeManagement {

private:
    std::multiset<int> grades;

public:
    GradeManagement(){}
    ~GradeManagement(){}

    void add(int grade) {
        grades.insert(grade);
    }

    void remove(int grade) {
        grades.erase(grade);
    }

    static int accumulate_strategy(int accumulated_value, int next_value) {
        return accumulated_value + next_value;
    }

    double avg() {
        auto sum = std::accumulate(grades.begin(), grades.end(), 0, GradeManagement::accumulate_strategy);

        return double(sum) / grades.size();
    }

    int count(int target) {
        int times = 0;

        for (auto grade : grades) {
            if (grade == target)
                times++;
        }

        return times;
    }

    int highest() {
        // NOTE: `multiset` 中元素是自动升序排列的
        return *grades.rbegin();
    }

    int lowest() {
        // NOTE: `multiset` 中元素是自动升序排列的
        return *grades.begin();
    }

};



int main(void) {

    auto mg = new GradeManagement();

    mg->add(100);
    mg->add(97);
    mg->add(87);
    mg->add(88);
    mg->add(90);
    mg->add(87);
    mg->add(99);

    std::cout << "avg: " << mg->avg() << std::endl;
    std::cout << "highest: " << mg->highest() << std::endl;
    std::cout << "lowest: " << mg->lowest() << std::endl;
    std::cout << "87 appears " << mg->count(87) << " times" << std::endl;

    std::cout << "remove 100" << std::endl;
    mg->remove(100);

    std::cout << "avg: " << mg->avg() << std::endl;
    std::cout << "highest: " << mg->highest() << std::endl;

    delete mg;

    return 0;
}