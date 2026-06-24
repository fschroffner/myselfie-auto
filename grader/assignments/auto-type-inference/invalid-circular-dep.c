// Test: a forward/circular auto dependency is a compile error.
// 'y' is not yet declared when 'x' is inferred from it.
uint64_t main() {
    auto x = y;
    auto y = x;
    return 0;
}
