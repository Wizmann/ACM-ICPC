import "fmt";

func doBackspace(S string, p int) int {
    if p < 0 || S[p] != '#' {
        return p;
    }
    q := p
    for p >= 0 && q >= 0 {
        for q >= 0 && S[q] == '#' {
            q--;
        }

        for p >= 0 && p > q && S[p] != '#' {
            p--;
        }
        
        if p == q {
            return p;
        }
        
        p--;
        q--;
    }
    return q;
}

func backspaceCompare(S string, T string) bool {
    p := len(S) - 1
    q := len(T) - 1
    
    for p >= 0 && q >= 0 {
        p = doBackspace(S, p);
        q = doBackspace(T, q);
        
        fmt.Println(p, q);
                
        if p < 0 && q < 0 {
            return true;
        } else if p >= 0 && q >= 0 && S[p] == T[q] {
            p--;
            q--;
        } else {
            return false;
        }
    }
    p = doBackspace(S, p);
    q = doBackspace(T, q);
    return p < 0 && q < 0;
}
