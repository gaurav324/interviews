// Write a function to check whether the given integer is palindrome or not.

// Though this problem looks to be an easy one, but its not.
// Why?
// Because there is a better way to solve this problem.
// What I did was, started looking from start and end until numbers met in
// middle. However, I could have just kept taking mod off and keep building
// another number from it and at the moment when new no became bigger, just use
// the new number.
bool isPalindrome(int x) {
  if (x < 0) {
    return false;
  }
  long base = 1;
  while ((x / base) > 9) {
    base = base * 10;
  }
  while (x > 0) {
    if (x / base != x % 10) {
      return false;
    }
    x = x % base;
    x = x / 10;
    base = base / 100;
  }
  return true;
}

bool isPalindromeOptimal(int x) {
  if (x < 0 || (x != 0 && x % 10 == 0)) return false;
  int sum = 0;
  while (x > sum) {
    sum = sum * 10 + x % 10;
    x = x / 10;
  }
  return (x == sum) || (x == sum / 10);
}
