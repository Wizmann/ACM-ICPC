use std::io::{self, Read, Write};
use std::collections::VecDeque;

struct Scanner {
    buf: Vec<u8>,
    idx: usize,
}
impl Scanner {
    fn new() -> Self {
        let mut input = String::new();
        io::stdin().read_to_string(&mut input).unwrap();
        Self { buf: input.into_bytes(), idx: 0 }
    }
    fn is_whitespace(b: u8) -> bool {
        matches!(b, b' ' | b'\n' | b'\r' | b'\t')
    }
    fn next<T: std::str::FromStr>(&mut self) -> T {
        while self.idx < self.buf.len() && Self::is_whitespace(self.buf[self.idx]) {
            self.idx += 1;
        }
        let start = self.idx;
        while self.idx < self.buf.len() && !Self::is_whitespace(self.buf[self.idx]) {
            self.idx += 1;
        }
        std::str::from_utf8(&self.buf[start..self.idx])
            .unwrap()
            .parse::<T>()
            .ok()
            .expect("parse error")
    }
}

#[allow(unused_macros)]
macro_rules! read { ($sc:expr, $t:ty) => { $sc.next::<$t>() }; }

#[allow(unused_macros)]
macro_rules! scan { ($sc:expr, $($t:ty),+) => { ( $( $sc.next::<$t>(), )+ ) }; }

#[allow(unused_macros)]
macro_rules! read_vec {
    ($sc:expr, $n:expr, $t:ty) => {{
        let mut v = Vec::with_capacity($n as usize);
        for _ in 0..$n {
            v.push($sc.next::<$t>());
        }
        v
    }};
}

#[allow(unused_macros)]
macro_rules! puts {
    ($($arg:tt)*) => {{
        let mut out = std::io::BufWriter::new(std::io::stdout());
        writeln!(out, $($arg)*).unwrap();
    }};
}

fn main() {
    let mut sc = Scanner::new();
    let n = read!(sc, usize);
    let l = read!(sc, usize);
    let r = read!(sc, usize);

    // A[0..=N], 题意给了 N+1 个数，且 A[0] = 0
    let mut a: Vec<i64> = Vec::with_capacity(n + 2);
    for _ in 0..=n {
        let x = read!(sc, i64);
        a.push(x);
    }
    a.push(0);

    // dp[i]：以 i 为最后停留格的最大冰冻指数
    let mut dp = vec![i64::MIN; n + 2];
    dp[0] = 0;

    // 单调队列存的是候选下标 j，按 dp[j] 递减
    let mut deq: VecDeque<usize> = VecDeque::new();

    // 遍历 i = 1..=N，维护窗口 [i-R, i-L] 的最大值
    for i in 1..=n+1 {
        // 1) 新进入窗口的下标 j = i - L（若 >= 0）
        if i >= l {
            let j = i - l;
            // 入队前弹出所有 dp[back] <= dp[j]，保持递减
            while let Some(&back) = deq.back() {
                if dp[back] <= dp[j] { deq.pop_back(); } else { break; }
            }
            deq.push_back(j);
        }

        // 2) 移出窗口左侧：去掉所有 < i - R 的下标
        while let Some(&front) = deq.front() {
            if front + r < i { deq.pop_front(); } else { break; }
        }

        // 3) 队首即窗口最大 dp[j]
        if let Some(&jmax) = deq.front() {
            // 若窗口非空，则 i 可达
            dp[i] = dp[jmax].saturating_add(a[i]);
        }
        // 若窗口为空，dp[i] 维持为 -inf（不可达）
    }

    // 终点：最后停在 i，使得下一跳一定能出界：i + L > N
    // 等价 i ∈ [max(0, N - L + 1) ..= N]
    let mut ans = i64::MIN;
    let lower = if n + 1 >= r { n + 1 - r } else { 0 };
    for i in lower..=n {
        if dp[i] > ans { ans = dp[i]; }
    }

    // 保险起见（当所有都不可达时，至少可以从 0 直接出界，得分 A0=0）
    if ans == i64::MIN {
        ans = 0;
    }

    puts!("{}", ans);
}

/*
^^^^TEST^^^^
5 2 3
0 12 3 11 7 -2
-----------
11
$$$TEST$$$$$
*/
