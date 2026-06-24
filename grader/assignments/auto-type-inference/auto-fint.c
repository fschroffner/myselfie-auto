// Test: auto with an integer literal infers uint64_t
uint64_t main() {
    auto n = 10;
    auto m = n + 5;
    if (m == 15)
        return 0;
    return 1;
}
