use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    const N: usize = 3;
    let c : &str = input.trim();

    for i in 0..N {
        println!("{}{}", " ".repeat(N - 1 - i),
                         c.repeat(i * 2 + 1));
    }
}

