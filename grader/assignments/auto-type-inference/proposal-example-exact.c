// Example with auto inferring procedure return types (uint64_t and uint64_t*).
uint64_t  factorial(uint64_t n)   { if (n == 0) return 1; return n * factorial(n - 1); }
uint64_t* greet(uint64_t* name)   { return name; }

uint64_t main() {
    auto n    = 10;            // uint64_t  -- integer literal
    auto res  = factorial(n);  // uint64_t  -- procedure return type
    auto msg  = greet("Selfie");  // uint64_t* -- procedure return type (pointer)
    auto flag = (res > 0);     // uint64_t  -- comparison

    if (res == 3628800)
        if (flag == 1)
            return 0;
    return 1;
}
