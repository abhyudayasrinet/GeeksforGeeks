//https://practice.geeksforgeeks.org/problems/box-stacking/1

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct box
{
    int base1;
    int base2;
    int h;
    box(int base1,int base2, int h)
    {
        this->base1 = base1;
        this->base2 = base2;
        this->h = h;
    }

    bool operator < (const box &rhs)
    {
        return base1*base2 < rhs.base1*rhs.base2;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int len,w,h;
        vector <box> boxes;
        for(int i=0;i<n;i++)
        {
            cin>>len>>w>>h;
            boxes.push_back(box(len, w, h));
            boxes.push_back(box(w, h, len));
            boxes.push_back(box(len, h, w));
        }
        sort(boxes.rbegin(), boxes.rend());

        // for(int i=0;i<boxes.size();i++)
        // {
        //     cout<<boxes[i].base1<<"x"<<boxes[i].base2<<endl;
        // }
        int max_ = 0;
        vector <int> val(boxes.size());
        for(int i=0;i<boxes.size();i++)
        {
            val[i] = boxes[i].h;
            for(int j=0;j<i;j++)
            {
                if( (boxes[i].base1 < boxes[j].base2 && boxes[i].base2 < boxes[j].base1) ||
                    (boxes[i].base1 < boxes[j].base1 && boxes[i].base2 < boxes[j].base2) )
                {
                    if(val[i] < val[j] + boxes[i].h)
                        val[i] = val[j] + boxes[i].h;
                }
            }
            if(val[i] > max_)
                max_ = val[i];
        }
        cout<<max_<<endl;
    }
    return 0;
}