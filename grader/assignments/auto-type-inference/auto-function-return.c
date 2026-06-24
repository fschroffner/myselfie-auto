// Test: auto infers a procedure's return type
uint64_t increment(uint64_t i) {
    return i + 1;
}
uint64_t main() {
    auto n = 10;
    auto result = increment(n);
    if (result == 11)
        return 0;
    return 1;
}
