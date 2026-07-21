use std::io::{self, Read};

fn solve(s: &str) -> i32 {
    if s.contains("lv") {
        0
    } else if s.contains('l') || s.contains('v') {
        1
    } else {
        2
    }
}

fn main() {
    assert_eq!(solve("l"), 1);
    assert_eq!(solve("lv"), 0);
    assert_eq!(solve("vl"), 1);
    assert_eq!(solve("lfoobarvvvvvv"), 1);

    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut tokens = input.split_whitespace();

    let _n: usize = tokens.next().unwrap().parse().unwrap();
    let s = tokens.next().unwrap();
    println!("{}", solve(s));
}

/*
^^^^TEST^^^^
7
lovable
----
1
$$$$$TEST$$$

^^^^TEST^^^^
6
google
----
1
$$$$$TEST$$$

^^^^TEST^^^^
6
lvable
----
0
$$$$$TEST$$$
*/
