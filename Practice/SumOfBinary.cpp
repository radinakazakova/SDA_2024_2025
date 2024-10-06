class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    int carry = 0; //наум
    int i = a.length() - 1; //индекси отзад напред
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) { //изпълняваме докато не преминем през всички цифри и махнем наум
      if (i >= 0)
        carry += a[i--] - '0';
      if (j >= 0)
        carry += b[j--] - '0';
      ans += carry % 2 + '0'; //carry e сумата на цифрите, тоест двоично резулатът е carry % 2, конкатенираме го към финалния резултат
      carry /= 2; // ако сумата е 2 имаме 1 наум
    }

    reverse(begin(ans), end(ans)); 
    return ans;
  }
};
