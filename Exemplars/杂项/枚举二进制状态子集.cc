for (int i = 1; i < (1 << n); ++i) {
    for (int j = i; j; j = (j - 1) & i) {
        // ...
    }
}
