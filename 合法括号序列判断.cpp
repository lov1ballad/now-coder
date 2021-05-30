#define _CRT_SECURE_NO_WARNINGS 1
class Parenthesis {
public:
	stack<char> st;
	bool chkParenthesis(string A, int n)
	{
		int i = 0;
		while (i<n)
		{
			if (A[i] == '(')
			{
				st.push(A[i]);
				i++;
			}
			else if (A[i] == ')')
			{
				if ((!st.empty()) && st.top() == '(')
				{
					st.pop();
					i++;
				}
				else{
					return false;
				}
			}
			else
			{
				i++;
			}
		}
		if (st.empty())
			return true;
		return false;
	}
};