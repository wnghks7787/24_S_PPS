#include <iostream>
#include <vector>

using namespace std;

void check_island(vector<vector<int> > *land, int start_w, int start_h);

int main()
{
    int w, h;

    vector<int> count_all;

    for(;;)
    {
        cin >> w >> h;

        if(w == 0 && h == 0)
            break;

        vector<vector<int> > land(h);
        vector<int> rows(w);

        // 섬 입력
        for(int i = 0 ; i < h ; i++)
        {
            for(int j = 0 ; j < w ; j++)
                cin >> rows[j];

            land[i] = rows;
        }

        int count = 0;

        // 섬 확인
        for(int i = 0 ; i < h ; i++)
        {
            for(int j = 0 ; j < w ; j++)
            {
                if(land[i][j] != 0)
                {
                    count++;
                    check_island(&land, j, i);
                }
            }
        }

        land.clear();
        rows.clear();

        count_all.push_back(count);
    }

    for(int i = 0 ; i < count_all.size() ; i++)
        cout << count_all[i] << endl;
    return 0;
}

void check_island(vector<vector<int> > *land, int start_w, int start_h)
{
    // 지도 사이즈
    int w, h;
    w = (*land)[0].size();
    h = (*land).size();

    // 현재 위치 0으로 만들기
    (*land)[start_h][start_w] = 0;

    // 가로로 긴 섬(완료)
    if(h == 1)
    {
        // 오른쪽
        if(start_w == w - 1)
            return;

        // 왼쪽 및 가운데
        if((*land)[start_h][start_w + 1] != 0)
            check_island(land, start_w + 1, start_h);

        return;
    }

    // 세로로 긴 섬 (완료)
    if(w == 1)
    {
        // 하단
        if(start_h == h - 1)
            return;

        // 상단 및 중단
        if((*land)[start_h + 1][start_w] != 0)
            check_island(land, start_w, start_h + 1);

        return;
    }

    // 오른쪽 하단(한칸짜리 섬 포함)
    if(start_h == h - 1 && start_w == w - 1)
    {
        return;
    }

    // 왼쪽 하단
    if(start_h == h - 1 && start_w == 0)
    {
        if((*land)[start_h - 1][start_w] != 0)
            check_island(land, start_w, start_h - 1);
        if((*land)[start_h - 1][start_w + 1] != 0)
            check_island(land, start_w + 1, start_h - 1);
        if((*land)[start_h][start_w + 1] != 0)
            check_island(land, start_w + 1, start_h);

        return;
    }

    // 오른쪽 상단
    if(start_h == 0 && start_w == w - 1)
    {
        if((*land)[start_h][start_w - 1] != 0)
            check_island(land, start_w - 1, start_h);
        if((*land)[start_h + 1][start_w - 1] != 0)
            check_island(land, start_w - 1, start_h + 1);
        if((*land)[start_h + 1][start_w] != 0)
            check_island(land, start_w, start_h + 1);

        return;
    }

    // 왼쪽 상단
    if(start_h == 0 && start_w == 0)
    {
        if((*land)[start_h][start_w + 1] != 0)
            check_island(land, start_w + 1, start_h);
        if((*land)[start_h + 1][start_w + 1] != 0)
            check_island(land, start_w + 1, start_h + 1);
        if((*land)[start_h + 1][start_w] != 0)
            check_island(land, start_w, start_h + 1);

        return;
    }

    // 오른쪽 중단
    if(start_w == w - 1)
    {
        if((*land)[start_h - 1][start_w] != 0)
            check_island(land, start_w, start_h - 1);
        if((*land)[start_h - 1][start_w - 1] != 0)
            check_island(land, start_w - 1, start_h - 1);
        if((*land)[start_h][start_w - 1] != 0)
            check_island(land, start_w - 1, start_h);
        if((*land)[start_h + 1][start_w - 1])
            check_island(land, start_w - 1, start_h + 1);
        if((*land)[start_h + 1][start_w] != 0)
            check_island(land, start_w, start_h + 1);

        return;
    }

    // 중간 하단
    if(start_h == h - 1)
    {
        if((*land)[start_h][start_w - 1] != 0)
            check_island(land, start_w - 1, start_h);
        if((*land)[start_h - 1][start_w - 1] != 0)
            check_island(land, start_w - 1, start_h - 1);
        if((*land)[start_h - 1][start_w] != 0)
            check_island(land, start_w, start_h - 1);
        if((*land)[start_h - 1][start_w + 1] != 0)
            check_island(land, start_w + 1, start_h - 1);
        if((*land)[start_h][start_w + 1] != 0)
            check_island(land, start_w + 1, start_h);

        return;
    }

    // 중간 상단
    if(start_h == 0)
    {
        if((*land)[start_h][start_w - 1] != 0)
            check_island(land, start_w - 1, start_h);
        if((*land)[start_h + 1][start_w - 1] != 0)
            check_island(land, start_w - 1, start_h + 1);
        if((*land)[start_h + 1][start_w] != 0)
            check_island(land, start_w, start_h + 1);
        if((*land)[start_h + 1][start_w + 1] != 0)
            check_island(land, start_w + 1, start_h + 1);
        if((*land)[start_h][start_w + 1] != 0)
            check_island(land, start_w + 1, start_h);

        return;
    }

    // 왼쪽 중단
    if(start_w == 0)
    {
        if((*land)[start_h - 1][start_w] != 0)
            check_island(land, start_w, start_h - 1);
        if((*land)[start_h - 1][start_w + 1] != 0)
            check_island(land, start_w + 1, start_h - 1);
        if((*land)[start_h][start_w + 1] != 0)
            check_island(land, start_w + 1, start_h);
        if((*land)[start_h + 1][start_w + 1] != 0)
            check_island(land, start_w + 1, start_h + 1);
        if((*land)[start_h + 1][start_w] != 0)
            check_island(land, start_w, start_h + 1);
        
        return;
    }

    // 중간 중단
    if((*land)[start_h - 1][start_w - 1] != 0)
        check_island(land, start_w - 1, start_h - 1);
    if((*land)[start_h - 1][start_w] != 0)
        check_island(land, start_w, start_h - 1);
    if((*land)[start_h - 1][start_w + 1] != 0)
        check_island(land, start_w + 1, start_h - 1);
    if((*land)[start_h][start_w - 1] != 0)
        check_island(land, start_w - 1, start_h);
    if((*land)[start_h][start_w + 1] != 0)
        check_island(land, start_w + 1, start_h);
    if((*land)[start_h + 1][start_w - 1] != 0)
        check_island(land, start_w - 1, start_h + 1);
    if((*land)[start_h + 1][start_w] != 0)
        check_island(land, start_w, start_h + 1);
    if((*land)[start_h + 1][start_w + 1] != 0)
        check_island(land, start_w + 1, start_h + 1);

    return;
}