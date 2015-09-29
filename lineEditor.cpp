#include <iostream>
#include <string>

using namespace std;
// 行编辑器,碰到#删除前一个字符,碰到@删除前面所有字符
// 要注意的是string的find,要是找不到,返回的是string::npos
void line_edit(string inputs[], int lines)
{
    for (size_t i = 0; i < lines; i++)
    {
        // handle #
        int pos;
        while ((pos = inputs[i].find('#')) != string::npos)
        {
            inputs[i].erase(pos-1,2);
        }
        // handle @
        while ((pos = inputs[i].find('@')) != string::npos)
        {
            inputs[i].erase(0, pos+1);
        }
    }
}
int main() {
    int lines;
    cin >> lines;
    string inputs[lines];
    for (size_t i = 0; i < lines; i++)
        cin >> inputs[i];
    line_edit(inputs, lines);
    for (size_t i = 0; i < lines; i++)
        cout << inputs[i] << endl;
}
