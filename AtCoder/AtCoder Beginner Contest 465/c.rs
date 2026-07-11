use std::io::{self, Read};
use std::collections::VecDeque;

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

// Appending then reversing on every `o` can be represented by a deque plus a
// logical orientation flag, so no element is ever moved.
fn solve(s: &[u8]) -> (VecDeque<usize>, bool) {
    let mut result = VecDeque::with_capacity(s.len());
    let mut reversed = false;

    for (i, &ch) in s.iter().enumerate() {
        // Append `i + 1` to the logical back.
        if reversed {
            result.push_front(i + 1);
        } else {
            result.push_back(i + 1);
        }

        if ch == b'o' {
            reversed = !reversed;
        }
    }

    (result, reversed)
}

fn main() {
    let mut sc = Scanner::new();
    let n: usize = sc.next();
    let s: String = sc.next();
    assert_eq!(n, s.len());

    let (res, reversed) = solve(s.as_bytes());
    let output = if reversed {
        res.iter().rev()
            .map(|x| x.to_string())
            .collect::<Vec<_>>()
            .join(" ")
    } else {
        res.iter()
            .map(|x| x.to_string())
            .collect::<Vec<_>>()
            .join(" ")
    };
    println!("{output}");

}

/*
^^^^TEST^^^^
5
ooxoo
--------
5 2 1 3 4
$$$$TEST$$$$$

^^^^^TEST^^^^
7
ooooooo
----------
7 5 3 1 2 4 6
$$$$TEST$$$$

^^^^^TEST^^^^
15
xooxoxoxoxoxxoo
----------
15 11 10 7 6 3 1 2 4 5 8 9 12 13 14
$$$$TEST$$$$
*/
