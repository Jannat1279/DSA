class Solution {
public:
    int fib(int n) {
        if(n<=1)return n;
        return fib(n-1)+fib(n-2);
    }
};

/*
🔍 Example:
fib(4)

🧩 Recursive Tree:
fib(4)
= fib(3) + fib(2)
= (fib(2) + fib(1)) + (fib(1) + fib(0))
= ((fib(1) + fib(0)) + 1) + (1 + 0)
= ((1 + 0) + 1) + (1 + 0)
= (1 + 1) + 1
= 2 + 1
= 3

✅ Final Answer:
fib(4) = 3
*/
