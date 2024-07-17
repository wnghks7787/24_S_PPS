#include <iostream>
#include <vector>

using namespace std;

void check_section(vector<string> *section, int start_w, int start_h, char color);
vector<string> color_blindness(vector<string> v);

int main()
{
    int n;
    cin >> n;

    vector<string> section(n);

    for(int i = 0 ; i < n ; i++)
        cin >> section[i];

    vector<string> section2 = color_blindness(section);

    int count = 0;

    // 섬 확인
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(section[i][j] != 'X')
            {
                count++;
                check_section(&section, j, i, section[i][j]);
            }
        }
    }
    cout << count << " ";

    count = 0;

    // 섬 확인
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(section2[i][j] != 'X')
            {
                count++;
                check_section(&section2, j, i, section2[i][j]);
            }
        }
    }

    cout << count << endl;
    
    return 0;
}

void check_section(vector<string> *section, int start_w, int start_h, char color)
{
    // 지도 사이즈
    int n;
    n = (*section).size();

    // 현재 위치 0으로 만들기
    (*section)[start_h][start_w] = 'X';

    // 오른쪽 하단(한칸짜리 섬 포함)
    if(start_h == n - 1 && start_w == n - 1)
    {
        return;
    }

    // 왼쪽 하단
    if(start_h == n - 1 && start_w == 0)
    {
        if((*section)[start_h - 1][start_w] == color)
            check_section(section, start_w, start_h - 1, color);
        // if((*section)[start_h - 1][start_w + 1] == color)
        //     check_section(section, start_w + 1, start_h - 1, color);
        if((*section)[start_h][start_w + 1] == color)
            check_section(section, start_w + 1, start_h, color);

        return;
    }

    // 오른쪽 상단
    if(start_h == 0 && start_w == n - 1)
    {
        if((*section)[start_h][start_w - 1] == color)
            check_section(section, start_w - 1, start_h, color);
        // if((*section)[start_h + 1][start_w - 1] == color)
        //     check_section(section, start_w - 1, start_h + 1, color);
        if((*section)[start_h + 1][start_w] == color)
            check_section(section, start_w, start_h + 1, color);

        return;
    }

    // 왼쪽 상단
    if(start_h == 0 && start_w == 0)
    {
        if((*section)[start_h][start_w + 1] == color)
            check_section(section, start_w + 1, start_h, color);
        // if((*section)[start_h + 1][start_w + 1] == color)
        //     check_section(section, start_w + 1, start_h + 1, color);
        if((*section)[start_h + 1][start_w] == color)
            check_section(section, start_w, start_h + 1, color);

        return;
    }

    // 오른쪽 중단
    if(start_w == n - 1)
    {
        if((*section)[start_h - 1][start_w] == color)
            check_section(section, start_w, start_h - 1, color);
        // if((*section)[start_h - 1][start_w - 1] == color)
        //     check_section(section, start_w - 1, start_h - 1, color);
        if((*section)[start_h][start_w - 1] == color)
            check_section(section, start_w - 1, start_h, color);
        // if((*section)[start_h + 1][start_w - 1] == color)
        //     check_section(section, start_w - 1, start_h + 1, color);
        if((*section)[start_h + 1][start_w] == color)
            check_section(section, start_w, start_h + 1, color);

        return;
    }

    // 중간 하단
    if(start_h == n - 1)
    {
        if((*section)[start_h][start_w - 1] == color)
            check_section(section, start_w - 1, start_h, color);
        // if((*section)[start_h - 1][start_w - 1] == color)
        //     check_section(section, start_w - 1, start_h - 1, color);
        if((*section)[start_h - 1][start_w] == color)
            check_section(section, start_w, start_h - 1, color);
        // if((*section)[start_h - 1][start_w + 1] == color)
        //     check_section(section, start_w + 1, start_h - 1, color);
        if((*section)[start_h][start_w + 1] == color)
            check_section(section, start_w + 1, start_h, color);

        return;
    }

    // 중간 상단
    if(start_h == 0)
    {
        if((*section)[start_h][start_w - 1] == color)
            check_section(section, start_w - 1, start_h, color);
        // if((*section)[start_h + 1][start_w - 1] == color)
        //     check_section(section, start_w - 1, start_h + 1, color);
        if((*section)[start_h + 1][start_w] == color)
            check_section(section, start_w, start_h + 1, color);
        // if((*section)[start_h + 1][start_w + 1] == color)
        //     check_section(section, start_w + 1, start_h + 1, color);
        if((*section)[start_h][start_w + 1] == color)
            check_section(section, start_w + 1, start_h, color);

        return;
    }

    // 왼쪽 중단
    if(start_w == 0)
    {
        if((*section)[start_h - 1][start_w] == color)
            check_section(section, start_w, start_h - 1, color);
        // if((*section)[start_h - 1][start_w + 1] == color)
        //     check_section(section, start_w + 1, start_h - 1, color);
        if((*section)[start_h][start_w + 1] == color)
            check_section(section, start_w + 1, start_h, color);
        // if((*section)[start_h + 1][start_w + 1] == color)
        //     check_section(section, start_w + 1, start_h + 1, color);
        if((*section)[start_h + 1][start_w] == color)
            check_section(section, start_w, start_h + 1, color);
        
        return;
    }

    // 중간 중단
    // if((*section)[start_h - 1][start_w - 1] == color)
    //     check_section(section, start_w - 1, start_h - 1, color);
    if((*section)[start_h - 1][start_w] == color)
        check_section(section, start_w, start_h - 1, color);
    // if((*section)[start_h - 1][start_w + 1] == color)
    //     check_section(section, start_w + 1, start_h - 1, color);
    if((*section)[start_h][start_w - 1] == color)
        check_section(section, start_w - 1, start_h, color);
    if((*section)[start_h][start_w + 1] == color)
        check_section(section, start_w + 1, start_h, color);
    // if((*section)[start_h + 1][start_w - 1] == color)
    //     check_section(section, start_w - 1, start_h + 1, color);
    if((*section)[start_h + 1][start_w] == color)
        check_section(section, start_w, start_h + 1, color);
    // if((*section)[start_h + 1][start_w + 1] == color)
    //     check_section(section, start_w + 1, start_h + 1, color);

    return;
}

vector<string> color_blindness(vector<string> v)
{
    for(int i = 0 ; i < v.size() ; i++)
    {
        for(int j = 0 ; j < v.size() ; j++)
        {
            if(v[i][j] == 'R')
                v[i][j] = 'G';
        }
    }

    return v;
}