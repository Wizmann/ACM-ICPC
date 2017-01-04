package main
import (
    "fmt"
    "sort"
    "strings"
)

type People struct {
    name, email string
}

type ByName []People

func (s ByName) Len() int {
    return len(s)
}

func (s ByName) Swap(i, j int) {
    s[i], s[j] = s[j], s[i]
}

func (s ByName) Less(i, j int) bool {
    return s[i].name < s[j].name
}

func main() {
    n := 0
    fmt.Scanf("%d", &n)
    
    var peoples []People
    
    for i := 0; i < n; i++ {
        name := ""
        email := ""
        fmt.Scanf("%s %s", &name, &email)
        peoples = append(peoples, People{name, email})
    }
    
    sort.Sort(ByName(peoples))
    
    for i := 0; i < n; i++ {
        if !strings.HasSuffix(peoples[i].email, "@gmail.com") {
            continue
        }
        fmt.Println(peoples[i].name)
    }
}
