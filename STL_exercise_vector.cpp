#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
// 用了vector,stringstream,一个string split函数,insert,unique
/* http://cxsjsxmooc.openjudge.cn/test/S/
编程题＃1 List

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 4000ms 内存限制: 65536kB
描述

写一个程序完成以下命令：

new id ——新建一个指定编号为id的序列(id<10000)

add id num——向编号为id的序列加入整数num

merge id1 id2——合并序列id1和id2中的数，并将id2清空

unique id——去掉序列id中重复的元素

out id ——从小到大输出编号为id的序列中的元素，以空格隔开
输入

第一行一个数n，表示有多少个命令( n＜＝２０００００)。以后n行每行一个命令。
输出

按题目要求输出。

样例输入

16
new 1
new 2
add 1 1
add 1 2
add 1 3
add 2 1
add 2 2
add 2 3
add 2 4
out 1
out 2
merge 1 2
out 1
out 2
unique 1
out 1

样例输出

1 2 3
1 2 3 4
1 1 2 2 3 3 4

1 2 3 4
*/
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}


int main() {
    stringstream str_buf;
    vector< vector<int>* > vec_arr;
    int num_instruct;
    int num_vec = 0;
    cin >> num_instruct;
    cin.ignore(256, '\n');
    for(int i = 0; i < num_instruct; ++i) {
        string instruct;
        getline(cin, instruct);
        vector<string> instruct_para = split(instruct, ' ');
        //cout << instruct_para[0] << endl;
        if (instruct_para[0] == "new") {
            vec_arr.push_back(new vector<int>);
        }
        if (instruct_para[0] == "add") {
            vec_arr[stoi(instruct_para[1]) - 1]->push_back(stoi(instruct_para[2]));
        }
        if (instruct_para[0] == "out") {
            vector<int>::const_iterator i = vec_arr[stoi(instruct_para[1]) - 1]->begin();
            for (; i != vec_arr[stoi(instruct_para[1]) - 1]->end(); i++) {
                str_buf << *i << " ";
            }
            str_buf << endl;
        }
        if (instruct_para[0] == "merge") {
            vec_arr[stoi(instruct_para[1]) - 1]->insert(
                vec_arr[stoi(instruct_para[1]) - 1]->end(),
                vec_arr[stoi(instruct_para[2]) - 1]->begin(),
                vec_arr[stoi(instruct_para[2]) - 1]->end()
            );
            sort(vec_arr[stoi(instruct_para[1]) - 1]->begin(),vec_arr[stoi(instruct_para[1]) - 1]->end());
            vec_arr[stoi(instruct_para[2]) - 1]->clear();
        }
        if (instruct_para[0] == "unique") {
            vector<int>::iterator it =
                unique(vec_arr[stoi(instruct_para[1]) - 1]->begin(), vec_arr[stoi(instruct_para[1]) - 1]->end());
            // unique以后的向量长度没变,只是里面内容调整成了unique的,返回值是新的range,从begin到这个range里的内容是unique的
            // 所以需要重新调整大小
            // unique参考 http://www.cplusplus.com/reference/algorithm/unique/?kw=unique
            vec_arr[stoi(instruct_para[1]) - 1]->resize(distance(vec_arr[stoi(instruct_para[1]) - 1]->begin(), it));
        }
    }
    cout << str_buf.str();
    return 0;
}
