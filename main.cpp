#include <iostream>
#include <set>

bool validateMagicString(std::string string)
{
    for(int i = 0; i < (int)string.length() - 1; i++)
    {
        switch(string[i])
        {
            case 'a':
                switch(string[i + 1])
                {
                    case 'e':
                        continue;
                }
                break;
            case 'e':
                switch(string[i + 1])
                {
                    case 'a':
                    case 'i':
                        continue;
                }
                break;
            case 'i':
                switch(string[i + 1])
                {
                    case 'a':
                    case 'e':
                    case 'o':
                    case 'u':
                        continue;
                }
                break;
            case 'o':
                switch(string[i + 1])
                {
                    case 'i':
                    case 'u':
                        continue;
                }
                break;
            case 'u':
                switch(string[i + 1])
                {
                    case 'a':
                        continue;
                }
                break;
        }
        return false;
    }
    return true;
}

void recursive(std::set<std::string> &list, const std::string &string, size_t length)
{
    const char characters[] = {'a', 'e', 'i', 'o', 'u'};


    if(string.length() == length)
    {
        if(validateMagicString(string))
        {
            list.insert(string);
        }
    }
    else
    {
        for (const char &c : characters)
        {
            const std::string child = string + c;

            if(validateMagicString(child))
            {
                recursive(list, child, length);
            }
        }
    }
}

size_t validStrings(size_t length)
{
    std::set<std::string> set;
    recursive(set, "", length);
    return set.size();
}

int main()
{
    for(size_t i = 0; i <= 20; i++)
    {
        std::cout << "Number of valid strings of length " << i << ": " << validStrings(i) << std::endl;
    }
    return 0;
}