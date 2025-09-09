macro_rules! input {
    // 单行读取多个变量
    ($($t:ty),*) => {{
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        let mut iter = s.split_whitespace();
        ($(iter.next().unwrap().parse::<$t>().unwrap()),*)
    }};
}

fn main() {
    // 读取一个整数
    let _n = input!(usize);

    // 再读一个字符串
    let s = input!(String);

    // 判断是否以 tea 结尾
    if s.ends_with("tea") {
        println!("Yes");
    } else {
        println!("No");
    }
}
