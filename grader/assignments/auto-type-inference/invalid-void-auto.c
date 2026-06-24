// Test: auto on a void expression must not compile.
void doNothing() {
    return;
}
uint64_t main() {
    auto x = doNothing();
    return 0;
}
