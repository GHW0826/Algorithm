bool solution(int x) {
    int copy = x;
    int divisor = 0;
    while (copy > 0) {
        divisor += copy % 10;
        copy /= 10;
    }
    return x % divisor == 0 ? true : false;
}
