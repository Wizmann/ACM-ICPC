use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let parts: Vec<i32> = input
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    let a : i64 = parts[0].into();
    let b : i64 = parts[1].into();
    println!("{}", a + b);
}

