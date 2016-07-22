// http://www.mytechinterviews.com/equal-probability-between-1-and-7
//
// Given rand5() function, write rand7().
// This is very interesting question.
// 
// SOLUTION:
// Thing to think about is that rand5() produces numbers between 1 & 5 uniformly.
// For generating any other random series, we need to have produce numbers from rand5() uniformly.
//
// If we do, rand5() * 5 + rand5(). Then would generate, all number between 1 & 25 uniformly.
// Then all we have to do is ignore number above 21 and for rest just take mod 7.

int rand7() {
	int ans = 22;
	while(ans > 21) {
		ans = rand5() * 5 + rand5();
	}
	return ans % 7;
}
