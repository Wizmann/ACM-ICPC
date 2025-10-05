use std::io::{self, Read, Write};

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
macro_rules! puts {
    ($($arg:tt)*) => {{
        let mut out = std::io::BufWriter::new(std::io::stdout());
        writeln!(out, $($arg)*).unwrap();
    }};
}

fn main() {
    let mut sc = Scanner::new();

    let (n, w) = scan!(sc, usize, usize);
    let a: Vec<usize> = read_vec!(sc, n, usize);

    let inf = w + 1; // 作为“无穷大”
    let mut dp = vec![inf; w + 1];
    dp[0] = 0;

    for x in 1..=w {
        for &c in &a {
            if x >= c {
                let cand = dp[x - c] + 1;
                if cand < dp[x] {
                    dp[x] = cand;
                }
            }
        }
    }

    puts!("{}", dp[w]);
}

/*
^^^^TEST^^^^
6 15
1 5 10 20 50 100
-----------
2
$$$TEST$$$$$

^^^^TEST^^^^
3 15
1 5 11
-----------
3
$$$TEST$$$$$
*/

