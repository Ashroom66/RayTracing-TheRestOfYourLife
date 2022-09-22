#include "rtweekend.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>

int main() {
    int runs = 0;
    int inside_circle = 0;
    double r = 1;
    std::cout << std::fixed << std::setprecision(12);                           // 表示する桁数, set::fixedとセットで小数部分の桁数を指定
    while (true) {
        runs ++;
        auto x = random_double(-r, r);
        auto y = random_double(-r, r);
        if (x*x + y*y < r*r) {inside_circle++;}
        if (runs % 100000 == 0) {
            std::cout << "Estimate of Pi = " << 4*double(inside_circle) / runs << "\t runs=" << runs << '\n';    // 10億あたりから3.1415でほぼ確定。次の桁はオーバーフローして収束せず
        }
    }
}