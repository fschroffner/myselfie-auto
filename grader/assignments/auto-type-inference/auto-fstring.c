// Test: auto with a string literal infers uint64_t* (pointer arithmetic allowed)
uint64_t main() {
    auto s = "Selfie";
    auto t = s + 1;
    return 0;
}
