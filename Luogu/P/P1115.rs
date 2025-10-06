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

    let n  = read!(sc, usize);
    let ns = read_vec!(sc, n, i32);

    let mut pre : i64 = 0;
    let mut cnt : i32 = 0;
    let mut maxi : i64 = i64::MIN;
    for i in 0..n {
        pre += ns[i] as i64;
        cnt += 1;

        if cnt > 0 && pre > maxi {
            maxi = pre;
        }
        if pre < 0 {
            pre = 0;
            cnt = 0;
        }
    }

    puts!("{}", maxi);
}

/*
^^^^TEST^^^^
7
2 -4 3 -1 2 -4 3
-----------
4
$$$TEST$$$$$

^^^^TEST^^^^
3
-1 -2 -3
-----------
-1
$$$TEST$$$$$
*/
