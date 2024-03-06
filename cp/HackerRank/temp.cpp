long maxSum(vector<long> a, long m) {
    long sum = 0, max = LONG_MIN, result = LONG_MAX;
    set<long> s;

    for (int i = 0; i < a.size(); i++) {
        sum = (sum + a[i]) % m;
        a[i] = sum;
        max = std::max(max, sum);
    }

    for (auto x: a) {
        auto p = s.insert(x);
        if (++p.first != s.end()) {
            result = min(*p.first - x, result);
        }
    }

    return std::max(max, m - result);
}