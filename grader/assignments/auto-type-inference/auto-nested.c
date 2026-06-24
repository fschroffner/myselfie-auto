// Test: nested auto declarations
uint64_t main() {
    auto a = 5;
    auto b = a * 2;
    auto c = b + a;
    if (c == 15)
        return 0;
    return 1;
}
