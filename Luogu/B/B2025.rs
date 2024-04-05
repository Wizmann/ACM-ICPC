fn main() {
    const N: usize = 3;

    for i in 0..N {
        println!("{}{}", " ".repeat(N - 1 - i),
                         "*".repeat(i * 2 + 1));
    }

    for i in (0..N - 1).rev() {
        println!("{}{}", " ".repeat(N - 1 - i),
                         "*".repeat(i * 2 + 1));
    }
}
