const INF = 0x3f3f3f3f

func gcd(a int, b int) (int) {
    if a % b == 0 {
        return b
    }
    return gcd(b, a % b)
}

func abs(a int) (int) {
    if a < 0 {
        return -a
    }
    return a
}

func getSlope(y1 int, x1 int, y2 int, x2 int) (int, int, bool) {
    dy := y1 - y2
    dx := x1 - x2
    
    s := 1
    if dy < 0 {
        s *= -1
        dy = -dy
    }
    
    if dx < 0 {
        s *= -1
        dx = -dx
    }
    
    if dx == 0 && dy == 0 {
        return INF, INF, true
    }
    
    if dx == 0 {
        return INF * s, 1, false
    }
    
    if dy == 0 {
        return 0, 1, false
    }
    
    g := gcd(dx, dy)
    return s * dy / g, s * dx / g, false
}

func isBoomerang(points [][]int) bool {
    y1 := points[0][0]
    x1 := points[0][1]
    y2 := points[1][0]
    x2 := points[1][1]
    y3 := points[2][0]
    x3 := points[2][1]
    
    k1a, k1b, sp1 := getSlope(y1, x1, y2, x2)
    k2a, k2b, sp2 := getSlope(y1, x1, y3, x3)
    
    return !(abs(k1a) == abs(k2a) && k1b == k2b) && !(sp1 || sp2)
}
