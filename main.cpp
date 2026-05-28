#include <iostream>
#include <map>
using namespace std;

map<long long, long long> factorize(long long x) {
    map<long long, long long> f;

    for (long long i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            f[i]++;
            x /= i;
        }
    }

    if (x > 1)
        f[x]++;

    return f;
}

int main() {
    long long A, B;
    cin >> A >> B;

    // Данные автора
    cout << "Автор: зиани мохаммед" << endl;
    cout << "Группа: 090304-РПИа-о25" << endl;

    map<long long, long long> fa = factorize(A);
    map<long long, long long> fb = factorize(B);

    long long ans = 0;

    for (auto p : fa) {
        long long prime = p.first;
        long long need = p.second;

        if (fb.find(prime) == fb.end()) {
            cout << -1;
            return 0;
        }

        long long have = fb[prime];

        long long n = (need + have - 1) / have;

        if (n > ans)
            ans = n;
    }

    cout << ans;

    return 0;
}
