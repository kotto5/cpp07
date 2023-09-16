#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T   min(const T &a, const T &b)
{
    if (b <= a) // if a equal b, return b
        return (b);
    else
        return (a);
}

template <typename T>
T   max(const T &a, const T &b)
{
    if (b >= a) // if a equal b, return b
        return (b);
    else
        return (a);
}

#endif