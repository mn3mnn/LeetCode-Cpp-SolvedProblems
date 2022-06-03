class Solution {
public:
   
string capture(string s, int i) {

    string myDigits = "";

    if (48 <= s[i] && s[i] <= 57)
    {
        myDigits.push_back(s[i]);

        int j = i + 1;
        
        while (48 <= s[j] && s[j] <= 57 && j < s.length())
        {
            myDigits.push_back(s[j]);
            j++;
        }
    }

    return myDigits;
}


int myAtoi(string s) {
    #define LONG_MAX 2147483647L
    #define LONG_MIN -2147483647L - 1

    long long res = 0;
    int sign = 1;
    string myDigits = "";
    

    for (int i = 0; i <= s.length() - 1; i++) {

        if (s[i] == ' ') {
            continue;
        }

        if (s[i] == '+' && s[i + 1] == '-' )
        {
            return 0;
        }
        if (s[i] == '-' && s[i + 1] == '+')
        {
            return 0;
        }

        else if (s[i] == '-' && 48 <= s[i + 1] && s[i + 1] <= 57) {
            sign = -1;
            myDigits = capture(s, i);
       
        }

        else if (s[i] == '+' && 48 <= s[i + 1] && s[i + 1] <= 57)
        {
            myDigits = capture(s, i);
        }

        else if (48 <= s[i] && s[i] <= 57)
        {
             myDigits = capture(s, i);
             break;
        }

        else break;
 
    }


    for (int i = 0; i < myDigits.length() ; i ++)

    {
        res = abs(res);

        // myDigits[i] - 48   that's to convert the number from char to int
        // the expression     res * 10 + (myDigits[i] - 48)    to convert all the number to int
        res = (res * 10) + (myDigits[i] - 48);

        res *= sign;

        res = (res >= LONG_MAX ? LONG_MAX : res);
        res = (res <= LONG_MIN ? LONG_MIN : res);

    }
    
    return res;
}
};