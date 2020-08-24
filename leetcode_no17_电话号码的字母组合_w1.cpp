/*------------------------------------------------------------------------------|
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。					|
																				|
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。				|
																				|
																				|
																				|
示例:																			|
																				|
输入："23"																		|
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].					|
																				|
来源：力扣（LeetCode）															|
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number    |
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。			|
-------------------------------------------------------------------------------*/

/*	递归调用
* 
*	执行用时：4 ms, 在所有 C++ 提交中击败了48.58%的用户
*	内存消耗：7.2 MB, 在所有 C++ 提交中击败了5.12%的用户
*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> result;
string current;

map<char, string > M = {
	{'2',"abc"},{'3',"def"},{'4',"ghi"},
	{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
	{'8',"tuv"},{'9',"wxyz"}
};


void plus_digits(int index, string digits)
{
	if (index == digits.size())																/*	递归出口	*/
	{
		result.push_back(current);
		return;
	}

	for (int i = 0; i < M[digits[index]].size(); i++)
	{
		current.push_back(M[digits[index]][i]);												/*	压入带处理的字符，例：M['2'][0]是a	*/
		plus_digits(index + 1, digits);														/*	逐一添加，不断递归	*/
		current.pop_back();																	/*	清空处理过的字符	*/
	}

}




vector<string> letterCombinations(string digits) 
{
	if (digits.size() == 0)
	{
		return result;
	}

	plus_digits(0, digits);

	return result;
}

int main()
{
	string digits = "23";

	vector<string> result;

	result = letterCombinations(digits);

}