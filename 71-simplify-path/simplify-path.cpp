class Solution {
public:
    string simplifyPath(string path) {
        string token = "";     // To store each directory or command token
        stringstream ss(path); // String stream to split the input path by '/'
        stack<string> st;      // Stack to keep track of valid directory names

        // Parse the path string by splitting on '/'
        while (getline(ss, token, '/')) {

            // Ignore empty tokens (caused by consecutive slashes)
            // and current directory symbol '.'
            if (token == "" || token == ".")
                continue;

            if (token != "..") {
                // If token is a valid directory name, push it onto the stack
                st.push(token);
            } else if (!st.empty()) {
                // If token is '..', pop from stack to go up one directory,
                // but only if stack is not empty (can't go above root)
                st.pop();
            }
            // If token is '..' and stack is empty, do nothing (already at root)
        }

        string result = "";

        // Build the simplified path by concatenating all directory names
        // in stack from bottom to top
        while (!st.empty()) {
            result = "/" + st.top() + result; // Prepend each directory with '/'
            st.pop();
        }

        // If result is empty, it means simplified path is root "/"
        if (result.length() == 0)
            result = "/";

        return result;
    }
};

/*
Example:
string path = "/a/./b/../../c/";
Goal:
Simplify the given absolute path to its canonical form by resolving ".", "..", and redundant slashes.

Step-by-Step Trace:
Input path tokens when split by '/':

["", "a", ".", "b", "..", "..", "c", ""]

Step	Token	Action	                        Stack content (bottom → top)
1	    ""	   Empty, ignore	                    (empty)
2	    "a"	   Push "a" onto stack	                a
3	    "."    Current directory, ignore	        a
4	    "b"	   Push "b" onto stack	                a, b
5	    ".."   Parent directory, pop top "b"	    a
6	    ".."   Parent directory, pop top "a"	    (empty)
7	    "c"	   Push "c" onto stack	c
8	    ""	   Empty, ignore	c
Building the result:
Stack contains: c

Construct path by popping stack and prepending /:

result = "/c"

Final Output:
"/c"
*/
