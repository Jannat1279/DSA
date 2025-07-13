class Solution {
public:
    int myAtoi(string s) {
        // Edge case: empty string
        if (s.length() == 0)
            return 0;

        int i = 0;

        // Step 1: Skip leading whitespaces
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // Remove the leading spaces by creating a substring
        s = s.substr(i);

        // Step 2: Set default sign to positive
        int sign = +1;

        // To store the result
        long ans = 0;

        // Step 3: Handle optional '+' or '-' sign
        if (s[0] == '-')
            sign = -1;

        // Constants for integer limits
        int MAX = INT_MAX;
        int MIN = INT_MIN;

        // Step 4: Start parsing digits (skip sign if present)
        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;

        while (i < s.length()) {
            // Step 5: Break if non-digit is encountered
            if (!isdigit(s[i]))
                break;

            // Step 6: Convert char to digit and append to result
            ans = ans * 10 + (s[i] - '0');

            // Step 7: Check for overflow and clamp
            if (sign == -1 && -1 * ans < MIN)
                return MIN;
            if (sign == +1 && ans > MAX)
                return MAX;

            i++;
        }

        // Step 8: Return final result with sign applied
        return (int)(sign * ans);
    }
};

// OR(using recursion)

int length(char input[]){
	int len=0;
	for(int i=0;input[i]!='\0';i++){
		len++;
	}
	return len;
}

int stringToNumber(char input[], int last){
	//Base Case
	if(last==0){
		return input[last]-'0';
	}
	//Recursive Call
	int smallAns=stringToNumber(input, last-1);
	
	//small work
	int a=input[last]-'0'; 
	return smallAns*10+a;
}

int stringToNumber(char input[]){
	int len=length(input);
	return stringToNumber(input, len-1);//last index
}

/*
Example:
char input[] = "1234";

stringToNumber(input, 3)
Calls: stringToNumber(input, 2)
a = input[3] - '0' = 4
Returns: smallAns * 10 + a = 123 * 10 + 4 = 1234

📌 stringToNumber(input, 2)
Calls: stringToNumber(input, 1)
a = input[2] - '0' = 3
Returns: smallAns * 10 + a = 12 * 10 + 3 = 123

📌 stringToNumber(input, 1)
Calls: stringToNumber(input, 0)
a = input[1] - '0' = 2
Returns: smallAns * 10 + a = 1 * 10 + 2 = 12

📌 stringToNumber(input, 0) ✅ Base Case
Returns: input[0] - '0' = 1

🔁 Backtracking and Final Answer:
stringToNumber(input, 3) → 1234 ✅


| Call                       | `last` | `input[last]` | Returns             | `smallAns` value |
| -------------------------- | ------ | ------------- | ------------------- | ---------------- |
| `stringToNumber(input, 0)` | 0      | `'1'`         | 1                   | —                |
| `stringToNumber(input, 1)` | 1      | `'2'`         | `1*10 + 2 = 12`     | 1                |
| `stringToNumber(input, 2)` | 2      | `'3'`         | `12*10 + 3 = 123`   | 12               |
| `stringToNumber(input, 3)` | 3      | `'4'`         | `123*10 + 4 = 1234` | 123              |

*/
