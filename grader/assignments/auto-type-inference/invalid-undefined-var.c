// Test: referring to an undefined variable must not compile.
uint64_t main() {
    auto x = undefined;
    return 0;
}
