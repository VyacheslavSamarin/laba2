#pragma once

#include <iostream>
#include <string>

class Octal
{
private:
    size_t size;
    unsigned char *arr;

public:
    Octal();
    Octal(const std::initializer_list<unsigned char> &t);
    Octal(const size_t &n, unsigned char t);
    Octal(const std::string &t);
    Octal(const Octal &other);
    Octal(Octal &&other) noexcept;

    bool operator==(const Octal &other) const;
    bool operator!=(const Octal &other) const;
    bool operator<(const Octal &other) const;
    bool operator>(const Octal &other) const;

    Octal &operator=(const Octal &other);
    Octal &operator+=(const Octal &other);
    Octal &operator-=(const Octal &other);

    std::ostream &print(std::ostream &os) const;

    virtual ~Octal();
};