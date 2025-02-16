#include <bits/stdc++.h>
using namespace std;

template <typename T> T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a, swap(a, m);
        u -= t * v, swap(u, v);
    }
    assert(m == 1);
    return u;
}

template <typename T> class Modular {
  public:
    using Type = typename decay<decltype(T::value)>::type;

    constexpr Modular() : value() {}
    template <typename U> Modular(const U &x) { value = normalize(x); }

    template <typename U> static Type normalize(const U &x) {
        Type v;
        if (-mod() <= x && x < mod())
            v = static_cast<Type>(x);
        else
            v = static_cast<Type>(x % mod());
        if (v < 0)
            v += mod();
        return v;
    }

    const Type &operator()() const { return value; }
    template <typename U> explicit operator U() const { return static_cast<U>(value); }
    constexpr static Type mod() { return T::value; }

    Modular &operator+=(const Modular &other) {
        if ((value += other.value) >= mod())
            value -= mod();
        return *this;
    }
    Modular &operator-=(const Modular &other) {
        if ((value -= other.value) < 0)
            value += mod();
        return *this;
    }
    template <typename U> Modular &operator+=(const U &other) { return *this += Modular(other); }
    template <typename U> Modular &operator-=(const U &other) { return *this -= Modular(other); }
    Modular &operator++() { return *this += 1; }
    Modular &operator--() { return *this -= 1; }
    Modular operator++(int) {
        Modular result(*this);
        *this += 1;
        return result;
    }
    Modular operator--(int) {
        Modular result(*this);
        *this -= 1;
        return result;
    }
    Modular operator-() const { return Modular(-value); }

    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type &operator*=(const Modular &rhs) {
#ifdef _WIN32
        uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
        uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
        asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod()));
        value = m;
#else
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
        return *this;
    }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type &
    operator*=(const Modular &rhs) {
        long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }
    template <typename U = T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type &operator*=(const Modular &rhs) {
        value = normalize(value * rhs.value);
        return *this;
    }

    Modular &operator/=(const Modular &other) { return *this *= Modular(inverse(other.value, mod())); }

    friend const Type &abs(const Modular &x) { return x.value; }

    template <typename U> friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);

    template <typename U> friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);

    template <typename V, typename U> friend V &operator>>(V &stream, Modular<U> &number);

  private:
    Type value;
};

template <typename T> bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T> &lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T> &lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T> &rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) {
    return Modular<T>(lhs) += rhs;
}
template <typename T, typename U> Modular<T> operator+(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) {
    return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U> Modular<T> operator-(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) {
    return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U> Modular<T> operator*(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) {
    return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U> Modular<T> operator/(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

template <typename T, typename U> Modular<T> power(const Modular<T> &a, const U &b) {
    assert(b >= 0);
    Modular<T> x = a, res = 1;
    U p = b;
    while (p > 0) {
        if (p & 1)
            res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

template <typename T> bool IsZero(const Modular<T> &number) { return number() == 0; }

template <typename T> string to_string(const Modular<T> &number) { return to_string(number()); }

// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T> U &operator<<(U &stream, const Modular<T> &number) { return stream << number(); }

// U == std::istream? but done this way because of fastinput
template <typename U, typename T> U &operator>>(U &stream, Modular<T> &number) {
    typename common_type<typename Modular<T>::Type, long long>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}

/*
using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

constexpr int mod = (int)998244353;
using Mint = Modular<std::integral_constant<decay<decltype(mod)>::type, mod>>;

/*vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}*/

constexpr int N = 1 << 7;
using Mat = array<array<Mint, N>, N>;
Mat operator*(const Mat &lhs, const Mat &rhs) {
    Mat ret;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                ret[i][j] += lhs[i][k] * rhs[k][j];
            }
        }
    }
    return ret;
}
Mat operator+(const Mat &lhs, const Mat &rhs) {
    Mat ret;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ret[i][j] = lhs[i][j] + rhs[i][j];
        }
    }
    return ret;
}

Mat qm(Mat a, int b) {
    Mat ret;
    for (int i = 0; i < N; i++) {
        ret[i][i] = 1;
    }
    for (; b; b >>= 1, a = a * a) {
        if (b & 1) {
            ret = ret * a;
        }
    }
    return ret;
}
void print(Mat &m) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}
Mint sum(Mat &m) {
    Mint ret = 0;
    for (int i = 0; i < N; i++) {
        ret += m[0][i];
    }
    return ret;
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int k, n;
    cin >> k >> n;
    set<int> S;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        S.insert(a);
    }

    Mat m;

    for (int U = 0; U < N; U++) {
        bool conflict = false;
        for (int i = 0; i < 7; i++) {
            if ((U & 1 << i) && S.count(i + 1) > 0) {
                conflict = true;
            }
        }

        int V = U << 1;
        if (V & (1 << 7)) {
            V -= 1 << 7;
        }
        m[U][V] = 1;
        if (!conflict)
            m[U][V + 1] = 1;
    }

    m = qm(m, n);
    cout << sum(m) - 1;
    return 0;
}