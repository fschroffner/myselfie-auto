// Test: auto with a comparison infers uint64_t (0 or 1)
uint64_t main() {
    auto n = 10;
    auto flag = (n > 0);
    auto zero = (n < 0);
    if (flag == 1)
        if (zero == 0)
            return 0;
    return 1;
}
