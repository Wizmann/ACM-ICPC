int get_nr(int y, int x) {
    return y * 9 + x;
}

bool is_valid_block(int arr[], int y, int x) {
    set<int> st;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int yy = y + i;
            int xx = x + j;
            int nr = get_nr(yy, xx);
            st.insert(arr[nr]);
        }
    }
    return st.size() == 9;
}

bool is_valid_line(int arr[], int y) {
    set<int> st;
    for (int i = 0; i < 9; i++) {
        int yy = y;
        int xx = i;
        int nr = get_nr(yy, xx);
        st.insert(arr[nr]);
    }
    return st.size() == 9;
}

bool is_valid_col(int arr[], int x) {
    set<int> st;
    for (int i = 0; i < 9; i++) {
        int yy = i;
        int xx = x;
        int nr = get_nr(yy, xx);
        st.insert(arr[nr]);
    }
    return st.size() == 9;
}

int isValidSudoku(int arr[]) {
    int res = 1;
    
    for (int i = 0; i < 81; i++) {
        if (arr[i] > 9 || arr[i] <= 0) {
            return 0;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res &= is_valid_block(arr, i * 3, j * 3);
        }
    }
    
    for (int i = 0; i < 9; i++) {
        res &= is_valid_line(arr, i);
        res &= is_valid_col(arr, i);
    }
    return res;
}
