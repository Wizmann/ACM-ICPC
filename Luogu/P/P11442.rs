#[warn(unused_imports)]
use std::io::{self, Read, Write};

struct Scanner {
    buf: Vec<u8>,
    idx: usize,
}

impl Scanner {
    fn new() -> Self {
        let mut input = String::new();
        io::stdin().read_to_string(&mut input).unwrap();
        Self {
            buf: input.into_bytes(),
            idx: 0,
        }
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

macro_rules! read {
    ($sc:expr, $t:ty) => {
        $sc.next::<$t>()
    };
}

macro_rules! scan {
    ($sc:expr, $($t:ty),+) => {
        ( $( $sc.next::<$t>(), )+ )
    };
}

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
    let (n, m) = scan!(sc, i32, i32);

    for _ in 0..m {
        let (t, p) = scan!(sc, char, i64);

        if t == 'Z' {
            let mut y: i64 = 0;
            let mut x: i64 = 0;
            let mut line: i64 = 2i64.pow(n as u32);
            let mut base: i64 = 0;
            let p: i64 = p as i64;

            while line >= 1 {
                let qua: i64 = line * line / 4;
                if p < base + qua {
                    // pass
                } else if p < base + qua * 2 {
                    x += line / 2;
                    base += qua;
                } else if p < base + qua * 3 {
                    y += line / 2;
                    base += qua * 2;
                } else {
                    x += line / 2;
                    y += line / 2;
                    base += qua * 3;
                }
                line /= 2;
            }
            println!("{}", y * 2i64.pow(n as u32) + x);
        } else {
            let n64 = 2i64.pow(n as u32);
            let p64 = p as i64;
            let mut y: i64 = p64 / n64;
            let mut x: i64 = p64 % n64;

            let mut base: i64 = 0;
            let mut line: i64 = 2i64.pow(n as u32);

            while line >= 1 {
                if x < line / 2 && y < line / 2 {
                    // pass
                } else if x >= line / 2 && y < line / 2 {
                    base += line * line / 4;
                    x -= line / 2;
                } else if x < line / 2 && y >= line / 2 {
                    base += line * line / 4 * 2;
                    y -= line / 2;
                } else {
                    base += line * line / 4 * 3;
                    x -= line / 2;
                    y -= line / 2;
                }
                line /= 2;
            }
            println!("{}", base);
        }
    }
}

/*
^^^^TEST^^^^
3 2
Z 37
R 37
-----------
35
49
$$$TEST$$$$$
*/

