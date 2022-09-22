#include "rtweekend.h"

#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>

inline double pdf(double x) {
    return 0.5 * x;
}

inline double f(double x) {
    return x*x;
}

int main() {
    int N = 1000000;
    auto sum = 0.0;
    for (int i=0; i<N; i++) {
        // auto x = random_double(0, 2);                // 一様乱数。効率悪い
        auto x = sqrt(random_double(0, 4));             // 工夫した乱数。一様乱数より効率よくなる
        while (x==0.0) {x = sqrt(random_double(0, 4));} // (zero divisionを回避)
        sum += f(x) / pdf(x);                           // 一様乱数じゃないので、サンプルされる確率から重みづけする
    }
    std::cout << std::fixed << std::setprecision(12);
    std::cout << "I = " << sum/N << '\n';               // 一様サンプリングと異なり、ここで関数の範囲を気にする必要が無くなる
}