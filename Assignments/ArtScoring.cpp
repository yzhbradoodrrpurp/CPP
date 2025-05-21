//
// Created by 易治行 on 2025/5/14.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


double accumulate_add(double accumulated_value, double next_value) {
    return accumulated_value + next_value;
}


class ArtScoring {

private:
    std::vector<double> scores;

public:
    ArtScoring() {}
    ~ArtScoring(){}

    void add_score(double score) {
        scores.push_back(score);
    }

    std::vector<double> valid_scores() {
        auto valid(scores);

        std::sort(valid.begin(), valid.end());
        valid.pop_back();
        valid.erase(valid.begin() + 0);

        return valid;
    }

    double valid_avg() {
        auto valid = valid_scores();

        auto valid_sum = std::accumulate(valid.begin(), valid.end(), 0.0, accumulate_add);
        int length = valid.size();

        return valid_sum / length;
    }

};


int main() {
    auto vase1 = new ArtScoring();
    auto vase2 = new ArtScoring();
    auto vase3 = new ArtScoring();
    auto vase4 = new ArtScoring();
    auto vase5 = new ArtScoring();

    vase1->add_score(100);
    vase1->add_score(97);
    vase1->add_score(87);
    vase1->add_score(88);
    vase1->add_score(90);

    vase2->add_score(99);
    vase2->add_score(96);
    vase2->add_score(83);
    vase2->add_score(89);
    vase2->add_score(90);

    vase3->add_score(98);
    vase3->add_score(95);
    vase3->add_score(84);
    vase3->add_score(88);
    vase3->add_score(90);

    vase4->add_score(97);
    vase4->add_score(94);
    vase4->add_score(85);
    vase4->add_score(89);
    vase4->add_score(90);

    vase5->add_score(96);
    vase5->add_score(93);
    vase5->add_score(86);
    vase5->add_score(89);
    vase5->add_score(90);

    auto valid_avg1 = vase1->valid_avg();
    auto valid_avg2 = vase2->valid_avg();
    auto valid_avg3 = vase3->valid_avg();
    auto valid_avg4 = vase4->valid_avg();
    auto valid_avg5 = vase5->valid_avg();

    std::cout << "valid avg: " << valid_avg1 << std::endl;
    std::cout << "valid avg: " << valid_avg2 << std::endl;
    std::cout << "valid avg: " << valid_avg3 << std::endl;
    std::cout << "valid avg: " << valid_avg4 << std::endl;
    std::cout << "valid avg: " << valid_avg5 << std::endl;

    delete vase1;
    delete vase2;
    delete vase3;
    delete vase4;
    delete vase5;

    return 0;
}