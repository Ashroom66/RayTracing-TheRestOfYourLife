#include "rtweekend.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>

int main() {
    int N = 10000000;
    int inside_circle = 0;
    double r = 1;
    for (int i=0; i<N; i++) {
        auto x = random_double(-r, r);
        auto y = random_double(-r, r);
        if (x*x + y*y < r*r) {inside_circle++;}
    }
    std::cout << std::fixed << std::setprecision(12);                           // 表示する桁数, set::fixedとセットで小数部分の桁数を指定
    std::cout << "Estimate of Pi = " << 4*double(inside_circle) / N << '\n';    // Estimate of Pi = 3.088000000000 (N=1000)
}