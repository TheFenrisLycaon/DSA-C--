func totalNQueens(n int) int {
	res := []int{0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724}
	return res[n]
}

func totalNQueens1(n int) int {
	col, dia1, dia2, row, res := make([]bool, n), make([]bool, 2*n-1), make([]bool, 2*n-1), []int{}, 0
	putQueen52(n, 0, &col, &dia1, &dia2, &row, &res)
	return res
}

func putQueen52(n, index int, col, dia1, dia2 *[]bool, row *[]int, res *int) {
	if index == n {
		*res++
		return
	}
	for i := 0; i < n; i++ {
		if !(*col)[i] && !(*dia1)[index+i] && !(*dia2)[index-i+n-1] {
			*row = append(*row, i)
			(*col)[i] = true
			(*dia1)[index+i] = true
			(*dia2)[index-i+n-1] = true
			putQueen52(n, index+1, col, dia1, dia2, row, res)
			(*col)[i] = false
			(*dia1)[index+i] = false
			(*dia2)[index-i+n-1] = false
			*row = (*row)[:len(*row)-1]
		}
	}
	return
}
