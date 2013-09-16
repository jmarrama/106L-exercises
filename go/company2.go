/*
   Interview 1 -

Input: a1 through an
Output: s1 through sn, such that s1 <= s2 >= s3 <= s4 >=s5 ….

O(nlog n) solution - sort, swap 2/3, 4/5, etc
O(n) solution - find median, handle edge cases

2 - sorted array that has been cirularly shifted
implement find in O(log n) time

  Interview 2 -

  implement binary search tree using an array
*/

package main

import ( "fmt" )

func main() {
	fmt.Println("hello world")
	do_interview_one()
}

func do_interview_one() {
	// NOTE: i don't implement the median-find algo here, just hand select it instead
	arr1 := []int{1,2,3,4,5,6,7,8,9}
	med1 := 5
	move_and_sort_arr(arr1, med1)

	arr2 := []int{1,2,2,2,3}
	med2 := 2
	move_and_sort_arr(arr2, med2)

	arr3 := []int{1,2,3,4}
	med3 := 2
	move_and_sort_arr(arr3, med3)
}

func move_and_sort_arr(arr []int, med int) {
	fmt.Println("the original array is")
	print_array(arr)

	res := make([]int, len(arr))
	lower_pos := 0
	upper_pos := 1
	med_pos := true // true = lower, false = higher
	for i := 0; i < len(arr); i++ {
		if arr[i] > med {
			res[upper_pos], upper_pos = increment_arrpos(arr[i], upper_pos)
		} else if arr[i] < med {
			res[lower_pos], lower_pos = increment_arrpos(arr[i], lower_pos)
		} else {
			if med_pos {
				res[lower_pos], lower_pos = increment_arrpos(arr[i], lower_pos)
			} else {
				res[upper_pos], upper_pos = increment_arrpos(arr[i], upper_pos)
			}
			med_pos = !med_pos
		}
	}

	fmt.Println("the resulting array is")
	print_array(res)
	if verify_array(res) {
		fmt.Println("the array is all good!")
	} else {
		fmt.Println("the array is WRONG")
	}
}

func increment_arrpos(arrval, arrpos int) (newval, newpos int) {
	return arrval, arrpos + 2
}

func verify_array(arr []int) bool {
	for i := 0; i < len(arr) -1; i++ {
		if i % 2 == 0 && arr[i] > arr[i+1] {
			return false
		} else if i % 2 == 1 && arr[i] < arr[i+1] {
			return false
		}
	}
	return true
}

func print_array(arr []int) {
	for i := 0; i < len(arr); i++ {
		fmt.Print(arr[i])
		fmt.Print(" ")
	}
	fmt.Println("")
}


