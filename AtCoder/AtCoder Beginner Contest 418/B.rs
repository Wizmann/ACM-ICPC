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
    // 读取整行字符串 S
    let s1 = input!(String);
    let s = s1.trim().as_bytes(); // 只包含小写字母
    let n = s.len();

    // 前缀和：pref[i] 表示 s[..i] 中 't' 的个数
    let mut pref = vec![0usize; n + 1];
    for i in 0..n {
        pref[i + 1] = pref[i] + if s[i] == b't' { 1 } else { 0 };
    }

    let mut best = 0f64;

    // 枚举所有子串 [i..=j]，要求长度>=3、首尾都是 't'
    for i in 0..n {
        if s[i] != b't' { continue; }
        for j in (i + 2)..n {
            if s[j] != b't' { continue; }
            let len = (j - i + 1) as i32;

            // 该子串中 't' 的总数 x
            let x = (pref[j + 1] - pref[i]) as i32;

            // 内部的 't' 个数：x - 2。若为 0 则分母为 0，按题意该子串填充率记为 0
            let internal_t = x - 2;
            if internal_t <= 0 {
                continue; // rate = 0，不会更新 best
            }

            let rate = (internal_t as f64) / ((len - 2) as f64);
            if rate > best {
                best = rate;
            }
        }
    }

    // 高精度输出（评测允许 1e-9 误差）
    // 直接用默认格式即可，也可以手动指定更多小数位
    println!("{:.12}", best);
}

