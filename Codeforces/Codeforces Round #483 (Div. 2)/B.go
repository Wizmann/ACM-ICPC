package main;

import (
	"fmt"
)

func main() {
	var my = [...]int{-1, -1, -1, 0, 0, 1, 1, 1};
	var mx = [...]int{-1, 0, 1, -1, 1, -1, 0, 1};

	var n int;
	var m int;

	fmt.Scan(&n);
	fmt.Scan(&m);

	board := make([]string, n);

	for i, _ := range board {
		fmt.Scan(&board[i]);
	}

	var flag bool = true;

	for i, line := range board {
		for j, ch := range line {
			if ch != '*' {
				var num = -1;
				if ch == '.' {
					num = 0;
				} else {
					num = int(ch) - int('0')
				}

				cnt := 0;
				for k := 0; k < 8; k++ {
					ny := i + my[k];
					nx := j + mx[k];

					if ny < 0 || ny >= n || nx < 0 || nx >= m {
						continue;
					}

					if board[ny][nx] == '*' {
						cnt++;
					}
				}
				// fmt.Println(i, j, cnt, num);
				if cnt != num {
					flag = false;
				}
			}
		}
	}

	if flag {
		fmt.Println("YES");
	} else {
		fmt.Println("NO");
	}
}
