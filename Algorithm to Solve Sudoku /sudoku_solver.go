package main

import "fmt"

func isValid(board *[9][9]int,row,col,num int) bool {
    for i:=0;i<9;i++ {
        if board[row][i]==num || board[i][col]==num { return false }
    }
    startRow, startCol := row/3*3, col/3*3
    for i:=0;i<3;i++ {
        for j:=0;j<3;j++ {
            if board[startRow+i][startCol+j]==num { return false }
        }
    }
    return true
}

func solveSudoku(board *[9][9]int) bool {
    for row:=0;row<9;row++{
        for col:=0;col<9;col++{
            if board[row][col]==0 {
                for num:=1;num<=9;num++{
                    if isValid(board,row,col,num){
                        board[row][col]=num
                        if solveSudoku(board){ return true }
                        board[row][col]=0
                    }
                }
                return false
            }
        }
    }
    return true
}

func printBoard(board *[9][9]int){
    for i:=0;i<9;i++{
        for j:=0;j<9;j++{
            fmt.Print(board[i][j]," ")
        }
        fmt.Println()
    }
}

func main(){
    board:=[9][9]int{
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9},
    }
    fmt.Println("Original Board:")
    printBoard(&board)
    if solveSudoku(&board){
        fmt.Println("\nSolved Board:")
        printBoard(&board)
    }else{
        fmt.Println("No solution exists.")
    }
}
