// Test: auto with a dereference infers uint64_t
uint64_t main() {
    auto p = malloc(8);
    *p = 42;
    auto x = *p;
    if (x == 42)
        return 0;
    return 1;
}
