#include "../include/Octal.hpp"

Octal::Octal()
{
    arr = new unsigned char[1]{0};
    size = 1;
}

Octal::Octal(const std::initializer_list<unsigned char> &t)
{
    size = t.size();
    arr = new unsigned char[size];
    int i = 0;

    for (auto it = t.begin(); it != t.end(); ++it)
    {
        arr[i++] = *it;
    }
}

Octal::Octal(const size_t &n, unsigned char t)
{
    if (t >= 8)
        throw std::invalid_argument("Invalid octal digit");
    if (t == 0)
    {
        arr = new unsigned char[1]{0};
        size = 1;
    }
    else
    {
        arr = new unsigned char[n];
        for (size_t i = 0; i < n; i++)
        {
            arr[i] = t;
        }
        size = n;
    }
}

Octal::Octal(const std::string &t)
{
    size_t leadingZeros = 0;
    bool skipLeadingZeros = true;
    for (char ch : t)
    {
        if (ch < '0' || ch > '7')
            throw std::invalid_argument("Invalid octal number");
        if (skipLeadingZeros && ch == '0')
        {
            leadingZeros++;
        }
        else
        {
            skipLeadingZeros = false;
        }
    }

    size = t.size() - leadingZeros;

    if (size == 0)
    {
        arr = new unsigned char[1]{0};
        size = 1;
    }
    else
    {
        arr = new unsigned char[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = static_cast<unsigned char>(t[t.size() - 1 - i] - '0');
        }
    }
}

Octal::Octal(const Octal &other)
{
    size = other.size;
    arr = new unsigned char[size];
    for (size_t i = 0; i <= size; i++)
    {
        arr[i] = other.arr[i];
    }
}

Octal::Octal(Octal &&other) noexcept
{
    size = other.size;
    arr = other.arr;

    other.size = 0;
    other.arr = nullptr;
}

bool Octal::operator==(const Octal &other) const
{
    if (size != other.size)
        return false;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] != other.arr[i])
            return false;
    }
    return true;
}

bool Octal::operator!=(const Octal &other) const
{
    return !(*this == other);
}

bool Octal::operator<(const Octal &other) const
{
    if (size == other.size)
    {
        for (size_t i = size; i-- > 0;)
        {
            if (arr[i] < other.arr[i])
                return true;
            if (arr[i] > other.arr[i])
                return false;
        }
        return false;
    }
    return size < other.size;
}

bool Octal::operator>(const Octal &other) const
{
    return other < *this;
}

Octal &Octal::operator=(const Octal &other)
{
    if (this != &other)
    {
        delete[] arr;
        size = other.size;
        arr = new unsigned char[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

Octal &Octal::operator+=(const Octal &other)
{
    std::string result = "";
    int carry = 0;
    for (size_t i = 0; i < std::max(size, other.size); i++)
    {
        int num1 = i < size ? arr[i] : 0;
        int num2 = i < other.size ? other.arr[i] : 0;
        int sum = num1 + num2 + carry;

        if (sum >= 8)
        {
            carry = 1;
            sum -= 8;
        }
        else
        {
            carry = 0;
        }
        result += static_cast<char>(sum + '0');
    }

    if (carry)
        result += '1';

    delete[] arr;
    size = result.size();
    arr = new unsigned char[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = static_cast<unsigned char>(result[i] - '0');
    }

    return *this;
}

Octal &Octal::operator-=(const Octal &other)
{
    if (*this < other)
        throw std::logic_error("Result can't be negative");
    std::string result = "";
    int borrow = 0;

    for (size_t i = 0; i < size; i++)
    {
        int num1 = i < size ? arr[i] : 0;
        int num2 = i < other.size ? other.arr[i] : 0;
        int diff = num1 - num2 - borrow;

        if (diff < 0)
        {
            borrow = 1;
            diff += 8;
        }
        else
        {
            borrow = 0;
        }

        result += static_cast<char>(diff + '0');
    }

    while (result.size() > 1 && result.back() == '0')
    {
        result.pop_back();
    }

    delete[] arr;
    size = result.size();
    arr = new unsigned char[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = static_cast<unsigned char>(result[i] - '0');
    }

    return *this;
}

std::ostream &Octal::print(std::ostream &os) const
{
    for (size_t i = size; i > 0; i--)
    {
        os << static_cast<char>(arr[i - 1] + '0');
    }
    return os;
}

Octal::~Octal()
{
    delete[] arr;
    size = 0;
    arr = nullptr;
}
