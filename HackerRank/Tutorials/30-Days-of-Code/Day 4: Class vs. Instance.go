package main
import "fmt"

type person struct {
	age int
}

func max(a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

func (p person) NewPerson(initialAge int) person {
    if initialAge < 0 {
        fmt.Println("Age is not valid, setting age to 0.")
    }
    p.age = max(0, initialAge)
	return p
}

func (p person) amIOld() {
    switch {
        case p.age < 13:
            fmt.Println("You are young.")
        case p.age < 18:
            fmt.Println("You are a teenager.")
        default:
            fmt.Println("You are old.")
    }
}

func (p person) yearPasses() person {
    p.age += 1
	return p
}

func main() {
    var T,age int

    fmt.Scan(&T)

    for i := 0; i < T; i++ {
        fmt.Scan(&age)
        p := person{age: age}
        p = p.NewPerson(age)
        p.amIOld()
        for j := 0; j < 3; j++ {
            p = p.yearPasses()
        }
        p.amIOld()
        fmt.Println()
    }
}
