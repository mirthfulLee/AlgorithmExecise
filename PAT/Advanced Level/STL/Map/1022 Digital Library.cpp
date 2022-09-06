// 1022 Digital Library
#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

map<string, set<int>> titleIndex, authorIndex, keywordIndex, pubisherIndex;
map<int, set<int>> yearIndex;

int main()
{
    int n, year, id, m;
    string author, title, keyword, publisher, allkw, query, input;
    char c, d;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> id;
        getchar();
        getline(cin, title);
        getline(cin, author);
        getline(cin, allkw);
        getline(cin, publisher);
        cin >> year;
        titleIndex[title].insert(id);
        authorIndex[author].insert(id);
        pubisherIndex[publisher].insert(id);
        yearIndex[year].insert(id);
        while (allkw.size())
        {
            int k = allkw.find_first_of(' ');
            keyword = allkw.substr(0, k);
            if (k < 0)
                allkw.clear();
            else
                allkw = allkw.substr(k + 1);
            keywordIndex[keyword].insert(id);
        }
    }
    cin >> m;
    getchar();
    for (int i = 0; i < m; i++)
    {
        set<int> result;
        getline(cin, query);
        input = query.substr(3);
        switch (query[0])
        {
        case '1':
            if (titleIndex.find(input) != titleIndex.end())
                result = titleIndex[input];
            break;
        case '2':
            if (authorIndex.find(input) != authorIndex.end())
                result = authorIndex[input];
            break;
        case '3':
            while (input.size())
            {
                int k = input.find_first_of(' ');
                keyword = input.substr(0, k);
                if (k < 0)
                    input.clear();
                else
                    input = input.substr(k + 1);
                if (keywordIndex.find(keyword) != keywordIndex.end())
                    for (int t : keywordIndex[keyword])
                        result.insert(t);
            }
            break;
        case '4':
            if (pubisherIndex.find(input) != pubisherIndex.end())
                result = pubisherIndex[input];
            break;
        case '5':
            year = stoi(input);
            if (yearIndex.find(year) != yearIndex.end())
                result = yearIndex[year];
            break;

        default:
            break;
        }
        cout << query << endl;
        if (result.empty())
        {
            cout << "Not Found" << endl;
        }
        else
        {
            for (int resultId : result)
            {
                printf("%07d\n", resultId);
            }
        }
    }
}