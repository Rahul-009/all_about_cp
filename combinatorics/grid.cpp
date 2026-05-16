// Grid Problems
	
// Count Squares
	// sum of square of natural number 
	// n(n+1)(2*n+1) / 6

// Count Rectangles
	// select any 2 horizontal line = nC2
	// select any 2 vertical line = nC2
	// rectangle possible = nC2 * nC2
	
	// variations
		// count rect without square
		// count rect of odd length
			// 1-4, 3-6  || both length odd
			// horizontal line duitar 1ta odd position | 1ta even position
			// vertical line duitar odd position | 1ta even position
			// (nC1 * mC1) * (nC1 * mC1) | n = odd pos , m = even pos 
		// count rect of even length
	
		// count 1-1 square so that no 2 square have same row and column
			// n^2C1 * (n^2-2*n-+1) |  1,2 ; 2,1 both same
			// n^2 can become n*m if(n != m)
			// double count hobe | 2 diye bhaag


// A to B shortest path
	// (n+m)Cn == (c+m)Cm [nCr = nC(n-r)]

	// if majhe kono cell block thake
		// suppose C point is block
		// A->C + C->B 
	