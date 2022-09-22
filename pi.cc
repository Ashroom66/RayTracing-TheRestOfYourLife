#include "rtweekend.h"
#include <iostream>
#include <iomanip>

int main() {
    int sqrt_N = 10000;     // 総サンプル数はこの2乗
    int inside_circle = 0;
    int inside_circle_stratified = 0;
    double r = 1;
    for (int i=0; i<sqrt_N; i++) {
        for (int j=0; j<sqrt_N; j++) {
            // 通常のサンプリング手法
            auto x = random_double(-r, r);
            auto y = random_double(-r, r);
            if (x*x + y*y < r*r) {inside_circle++;}

            // jittering
            // sqrt_N分割したうちの1区間からランダムにサンプリング
            x = 2*r*((i + random_double()) / sqrt_N) - r;
            y = 2*r*((j + random_double()) / sqrt_N) - r;
            if (x*x + y*y < r*r) {inside_circle_stratified++;}
        }
    }

    auto N = static_cast<double>(sqrt_N) * sqrt_N;
    std::cout << std::fixed << std::setprecision(12);   // 表示する桁数, set::fixedとセットで小数部分の桁数を指定
    std::cout   << "Regular    Estimate of Pi = " << 4*double(inside_circle) / N << '\n'
                << "Stratified Estimate of Pi = " << 4*double(inside_circle_stratified)/N << '\n';
}