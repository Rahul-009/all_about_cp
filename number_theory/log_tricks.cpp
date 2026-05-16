// log functions are very important
// https://www.geeksforgeeks.org/logarithm-tricks-for-competitive-programming/


// Multiplication, Division using log
	// what if we need to multiply big number without mod ?
	// we store the logs of all values | and find the sum
	// if antilog(sum) > 1e9 print something | other wise print -1(question wise)
	// https://codeforces.com/gym/102694/problem/E | check this problem
		// store the logs in double | it can have decimal values