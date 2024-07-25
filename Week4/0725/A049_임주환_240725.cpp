#include <iostream>

using namespace std;

bool checkVowel(char c);

int main()
{
    for(;;)
    {
        string s;

        cin >> s;

        if(s == "end")
            break;

        bool include_vowels = false;
        bool not_three_in_row = true;
        bool not_three_in_row_vowel = true;
        bool not_same_char = true;

        int vowel_count = 0;
        int nonvowel_count = 0;

        for(int i = 0 ; i < s.size() ; i++)
        {

            if(checkVowel(s[i]))
            {
                nonvowel_count = 0;
                vowel_count++;
                include_vowels = true;
            }
            else
            {
                vowel_count = 0;
                nonvowel_count++;
            }

            if(vowel_count >= 3)
            {
                not_three_in_row_vowel = false;
                break;
            }
            else if(nonvowel_count >= 3)
            {
                not_three_in_row = false;
                break;
            }

            if(i == 0)
                continue;

            if(s[i-1] == s[i] && (s[i] != 'e' && s[i] != 'o'))
            {
                not_same_char = false;
                break;
            }
        }

        if(include_vowels && not_three_in_row_vowel && not_three_in_row && not_same_char)
            cout << "<" << s << "> is acceptable." << endl;
        else
            cout << "<" << s << "> is not acceptable." << endl;
    }
    return 0;
}

bool checkVowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;

    return false;
}