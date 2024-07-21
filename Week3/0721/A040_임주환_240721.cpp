class Solution {
public:
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    bool halvesAreAlike(string s) {
        int left_vowel = 0;
        int right_vowel = 0;

        for(int i = 0 ; i < s.size() / 2 ; i++)
        {
            for(int j = 0 ; j < vowels.size() ; j++)
            {
                if(s[i] == vowels[j])
                    left_vowel++;
            }
        }

        for(int i = s.size() / 2 ; i < s.size() ; i++)
        {
            for(int j = 0 ; j < vowels.size() ; j++)
            {
                if(s[i] == vowels[j])
                    right_vowel++;
            }
        }

        return left_vowel == right_vowel ? true : false;
    }
}; 