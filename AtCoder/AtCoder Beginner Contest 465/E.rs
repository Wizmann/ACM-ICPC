use std::collections::HashMap;
use std::io::{self, Read};

struct Scanner {
    input: Vec<String>,
}

impl Scanner {
    fn new() -> Self {
        let mut input = String::new();
        io::stdin().read_to_string(&mut input).unwrap();
        let input = input
            .split_whitespace()
            .rev()
            .map(String::from)
            .collect();
        Self { input }
    }

    fn next<T: std::str::FromStr>(&mut self) -> T {
        self.input.pop().unwrap().parse().ok().unwrap()
    }
}

const MOD: i64 = 998244353;

fn dfs(
    pos: usize,
    ns: &Vec<usize>,
    lt: bool,
    rem: usize,
    contain3: bool,
    mask: usize,
    dp: &mut HashMap<(usize, bool, usize, bool, usize), i64>,
) -> i64 {
    if pos == ns.len() {
        if mask == 0 {
            return 0;
        }

        let mut cnt = 0;
        if rem == 0 {
            cnt += 1;
        }
        if contain3 {
            cnt += 1;
        }
        if mask.count_ones() == 3 {
            cnt += 1;
        }

        if cnt == 1 {
            return 1;
        } else {
            return 0;
        }
    }

    let key = (pos, lt, rem, contain3, mask);
    if let Some(&value) = dp.get(&key) {
        return value;
    }

    let upper = if lt { 9 } else { ns[pos] };
    let mut ans = 0;

    for d in 0..=upper {
        let nlt = lt || d < ns[pos];
        let leading_zero = mask == 0 && d == 0;
        let nmask;
        let nrem;

        if leading_zero {
            nmask = 0;
            nrem = 0;
        } else {
            nmask = mask | (1 << d);
            nrem = (rem * 10 + d) % 3;
        }

        ans += dfs(
            pos + 1,
            ns,
            nlt,
            nrem,
            contain3 || d == 3,
            nmask,
            dp,
        );
        ans %= MOD;
    }

    dp.insert(key, ans);
    ans
}

fn solve(n: &str) -> i64 {
    let ns: Vec<usize> = n.bytes().map(|c| (c - b'0') as usize).collect();
    let mut dp = HashMap::new();
    dfs(0, &ns, false, 0, false, 0, &mut dp)
}

fn main() {
    let mut sc = Scanner::new();
    let n: String = sc.next();
    println!("{}", solve(&n));
}

/*
^^^^TEST^^^^
45
--------
19
$$$$TEST$$$$$

^^^^TEST^^^^
1013
--------
424
$$$$TEST$$$$$

^^^^TEST^^^^
2
--------
0
$$$$TEST$$$$$

^^^^TEST^^^^
314159265358979323846264338327950
--------
658111391
$$$$TEST$$$$$
*/
