//
// Created by 易治行 on 2025/5/14.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

double accumulate_add(double accumulated_value, double next_value) {
    return accumulated_value + next_value;
}

bool sort_strategy(double a, double b) {
    return a < b;
}


class ArtScoring {

private:
    std::vector<std::vector<double>> scores;

public:
    ArtScoring(int vase) {
        for (int i = 0; i < vase; i++)
        scores.push_back(std::vector<double>());
    }
    ~ArtScoring(){}

    void add(int idx, double score) {
        scores[idx].push_back(score);
    }

    std::vector<double> valid_scores(int idx) {
        std::sort(scores[idx].begin(), scores[idx].end(), sort_strategy);

        std::vector<double> valid;

        for (int i = 1; i < scores[idx].size() - 1; i++)
            valid.push_back(scores[idx][i]);

        return valid;
    }

    double valid_average_scores(int idx) {
        auto valid = valid_scores(idx);
        auto sum = std::accumulate(valid.begin(), valid.end(), 0,accumulate_add);
        int len = valid.size();

        return sum / len;
    }

};


int main() {
    auto as = ArtScoring(5);

    for (int vase = 0; vase < 5; vase++) {
        for (int judge = 0; judge < 5; judge++) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> distrib(0, 100);

            double score = distrib(gen);
            as.add(vase, score);
        }
    }

    for (int vase = 0; vase < 5; vase++) {
        auto valid_avg = as.valid_average_scores(vase);
        std::cout << "vase " << vase << ", valid average scores " << valid_avg << std::endl;
    }

    return 0;
}