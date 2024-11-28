int* fun(int n) {

    int* ptr = &n;
    return ptr;
}
int main() {

    int n = 5;
    fun(n);

    return 0;
}