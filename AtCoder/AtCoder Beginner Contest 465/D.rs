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

fn depth(mut x: u64, k: u64) -> usize {
    let mut result = 0;
    while x > 0 {
        x /= k;
        result += 1;
    }
    result
}

fn go_up(mut x: u64, k: u64, steps: usize) -> u64 {
    for _ in 0..steps {
        x /= k;
    }
    x
}

fn solve(x: u64, y: u64, k: u64) -> usize {
    let x_depth = depth(x, k);
    let y_depth = depth(y, k);
    let max_lca_depth = x_depth.min(y_depth);

    // Binary-search the greatest depth at which X and Y have the same
    // ancestor. That ancestor is their LCA.
    let mut l = 0;
    let mut r = max_lca_depth;
    while l < r {
        let m = l + (r - l + 1) / 2;
        let xx = go_up(x, k, x_depth - m);
        let yy = go_up(y, k, y_depth - m);

        if xx == yy {
            l = m;
        } else {
            r = m - 1;
        }
    }

    let lca = go_up(x, k, x_depth - l);
    let lca_depth = depth(lca, k);

    let x_steps = x_depth - lca_depth;
    let y_steps = y_depth - lca_depth;
    x_steps + y_steps
}

fn main() {
    let mut sc = Scanner::new();
    let t: usize = sc.next();

    for _ in 0..t {
        let x: u64 = sc.next();
        let y: u64 = sc.next();
        let k: u64 = sc.next();
        
        let res = solve(x, y, k);
        println!("{res}");
    }
}

/*
^^^^TEST^^^^
4
11 9 3
0 0 2
842 180 7
1948706013487601 48019760148910476 89014537
--------
2
0
7
5
$$$$TEST$$$$$
*/
