#include<cstdio>
#include<stdint.h>
#include<algorithm>
#include<set>
#include<iostream>

int64_t gcd(int64_t a, int64_t b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int64_t lcm(int64_t a, int64_t b) {
    return a / gcd(a, b) * b;
}

struct number_t {
    int64_t integer;
    int64_t numerator;
    int64_t denominator;
    bool negative;
    bool is_inf;

    number_t() : integer(0), numerator(0), denominator(0), negative(false), is_inf(false) {
    }

    void int_to_negative() {
        if (integer < 0) {
            negative = !negative;
            integer = -integer;
        }
        if (numerator < 0) {
            negative = !negative;
            numerator = -numerator;
        }
        if (denominator < 0) {
            negative = !negative;
            denominator = -denominator;
        }
    }

    void negative_to_int() {
        if (negative) {
            negative = false;
            numerator = -numerator;
        }
    }

    void to_simple() {
        if (numerator == 0 || denominator == 0 || is_inf) {
            numerator = 0;
            denominator = 0;
        } else {
            int_to_negative();
            int64_t t = gcd(numerator, denominator);
            numerator /= t;
            denominator /= t;
            negative_to_int();
        }
    }

    void parse_integer() {
        if (denominator == 0) {
            return;
        }
        int_to_negative();
        integer += numerator / denominator;
        numerator = numerator % denominator;
    }

    number_t &operator+=(number_t other) {
        other.to_simple();
        to_simple();
        if (denominator == 0) {
            *this = other;
        } else if (other.denominator != 0) {
            int64_t t = gcd(denominator, other.denominator);
            int64_t t1 = denominator / t;
            int64_t t2 = other.denominator / t;
            denominator *= t2;
            numerator = numerator * t2 + other.numerator * t1;
        }
        to_simple();
        return *this;
    }

    number_t &operator-=(number_t other) {
        other.negative = !other.negative;
        return *this += other;
    }

    number_t &operator*=(number_t other) {
        other.to_simple();
        to_simple();
        if (denominator == 0 || other.denominator == 0) {
            denominator = 0;
        } else {
            int64_t t = gcd(numerator, other.denominator);
            numerator /= t;
            other.denominator /= t;
            t = gcd(denominator, other.numerator);
            denominator /= t;
            other.numerator /= t;
            denominator *= other.denominator;
            numerator *= other.numerator;
        }
        to_simple();
        return *this;
    }

    number_t &operator/=(number_t other) {
        other.to_simple();
        if (other.denominator == 0) {
            is_inf = true;
            to_simple();
            return *this;
        }else {
            std::swap(other.denominator,other.numerator);
            return *this *= other;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, number_t number) {
        number.to_simple();
        number.parse_integer();
        if (number.is_inf) {
            os << "Inf";
        } else {
            if (number.integer != 0) {
                if (number.numerator != 0 && number.denominator != 0) {
                    if (number.negative) {
                        os << '(' << '-'
                           << number.integer << ' '
                           << number.numerator << '/'
                           << number.denominator << ')';
                    } else {
                        os << number.integer << ' '
                           << number.numerator << '/'
                           << number.denominator;
                    }

                } else {
                    if (number.negative) {
                        os << '(' << '-' << number.integer << ')';
                    } else {
                        os << number.integer;
                    }

                }
            } else {
                if (number.numerator != 0 && number.denominator != 0) {
                    if (number.negative) {
                        os << '(' << '-'
                           << number.numerator << '/'
                           << number.denominator << ')';
                    } else {
                        os << number.numerator << '/' << number.denominator;
                    }
                } else {
                    os << '0';
                }
            }
        }
        return os;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    number_t number, number1, number2;
    std::string str;
    std::getline(std::cin, str);
    bool flag = true;
    for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        char &c = *it;
        switch (c) {
            case ' ': {
                number1 = number;
                number = number2;
                flag = true;
                break;
            }
            case '/': {
                flag = false;
                break;
            }
            case '-': {
                number.negative = true;
                break;
            }
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9': {
                if (flag) {
                    number.numerator *= 10;
                    number.numerator += c - '0';
                } else {
                    number.denominator *= 10;
                    number.denominator += c - '0';
                }
                break;
            }
        }
    }
    number2 = number;
    number = number1;
    number += number2;
    std::cout << number1 << " + " << number2 << " = " << number << std::endl;
    number = number1;
    number -= number2;
    std::cout << number1 << " - " << number2 << " = " << number << std::endl;
    number = number1;
    number *= number2;
    std::cout << number1 << " * " << number2 << " = " << number << std::endl;
    number = number1;
    number /= number2;
    std::cout << number1 << " / " << number2 << " = " << number << std::endl;

//    std::cout.flush();
    return 0;
}
/*
1088 Rational Arithmetic （20 分）
For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference, product and quotient.

Input Specification:
Each input file contains one test case, which gives in one line the two rational numbers in the format a1/b1 a2/b2. The numerators and the denominators are all in the range of long int. If there is a negative sign, it must appear only in front of the numerator. The denominators are guaranteed to be non-zero numbers.

Output Specification:
For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. The format of each line is number1 operator number2 = result. Notice that all the rational numbers must be in their simplest form k a/b, where k is the integer part, and a/b is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. If the denominator in the division is zero, output Inf as the result. It is guaranteed that all the output integers are in the range of long int.

Sample Input 1:
2/3 -4/2
Sample Output 1:
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
Sample Input 2:
5/3 0/6
Sample Output 2:
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
作者: CHEN, Yue
单位: 浙江大学
时间限制: 200 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/
