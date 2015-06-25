//将十进制数转换为excel数
string decToExcel(int decNum) {
    string res;
    while (decNum) {
        int u = decNum % 26;
        if (u == 0) {
            u = 26;
        }
        res += 'A' + u - 1;
        decNum -= u;
        decNum /= 26;
    }
    reverse(res.begin(), res.end());
    return res;
}
//将excel数转换为十进制数
int excelToDec(string excelNum) {
    reverse(excelNum.begin(), excelNum.end());
    int u = 1;
    int ans = 0;
    for (auto c: excelNum) {
        int v = c - 'A' + 1;
        ans += v * u;
        u *= 26;
    }
    return ans;
}
