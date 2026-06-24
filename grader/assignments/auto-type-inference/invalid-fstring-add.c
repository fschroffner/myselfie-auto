// Test: pointer + pointer is undefined and must not compile.
uint64_t main() {
    auto s = "Hello";
    auto t = "World";
    auto err = s + t;
    return 0;
}
