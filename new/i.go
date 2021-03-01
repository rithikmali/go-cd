package main

import "fmt"

func main() {

    i := 1
    for i <= 3 {
        fmt.Println(i)
        i = i + 1
    }

    for j := 7; j <= 9; j++ {
        fmt.Println(j)
    }

    for {
        fmt.Println("loop")
        break
    }

    switch i {
    case 1:
        fmt.Println("one")
    case 2:
        fmt.Println("two")
    case 3:
        fmt.Println("three")
    default:
        aaaa
    }

    switch q:= value.(type) { 
        case bool: 
        fmt.Println("value is of boolean type") 
        case float64: 
        fmt.Println("value is of float64 type") 
        case int: 
        fmt.Println("value is of int type") 
        default: 
        fmt.Printf("value is of type: %T", q) 
          
    } 
};