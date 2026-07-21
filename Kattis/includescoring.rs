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

#[derive(Clone, Copy)]
struct Contestant {
    solved: i64,
    penalty: i64,
    last: i64,
    extra: i64,
    original_index: usize,
}

fn rank_score(rank: usize) -> i64 {
    // The table is indexed by rank - 1.  Ranks after 30 get zero points.
    const SCORES: [i64; 30] = [
        100, 75, 60, 50, 45, 40, 36, 32, 29, 26,
        24, 22, 20, 18, 16, 15, 14, 13, 12, 11,
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1,
    ];

    if rank <= SCORES.len() {
        SCORES[rank - 1]
    } else {
        0
    }
}

fn main() {
    let mut scanner = Scanner::new();
    let n: usize = scanner.next();
    let mut contestants = Vec::with_capacity(n);

    for original_index in 0..n {
        contestants.push(Contestant {
            solved: scanner.next(),
            penalty: scanner.next(),
            last: scanner.next(),
            extra: scanner.next(),
            original_index,
        });
    }

    contestants.sort_by(|a, b| {
        b.solved
            .cmp(&a.solved)
            .then_with(|| a.penalty.cmp(&b.penalty))
            .then_with(|| a.last.cmp(&b.last))
    });

    let mut answer = vec![0_i64; n];
    let mut left = 0;

    while left < n {
        let mut right = left + 1;
        while right < n
            && contestants[right].solved == contestants[left].solved
            && contestants[right].penalty == contestants[left].penalty
            && contestants[right].last == contestants[left].last
        {
            right += 1;
        }

        let mut sum = 0_i64;
        for rank in (left + 1)..=right {
            sum += rank_score(rank);
        }
        let count = (right - left) as i64;
        let shared_score = (sum + count - 1) / count;

        for contestant in &contestants[left..right] {
            answer[contestant.original_index] = shared_score + contestant.extra;
        }

        left = right;
    }

    let mut output = String::new();
    for score in answer {
        output.push_str(&format!("{}\n", score));
    }
    print!("{}", output);
}
