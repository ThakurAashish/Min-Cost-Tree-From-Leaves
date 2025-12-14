#include <bits/stdc++.h>
#include <vector>
using namespace std;

int MinCostTree(int arr[], int n)
{
    int ans = 0;

    // stack
    vector<int> st = {INT_MAX};

    // loop to traverse the array element
    for (int i = 0; i < n; i++)
    {

        // Keep array element in decreasing order by poping out
        // the element from stack till the top element is less than current element
        while (st.back() <= arr[i])
        {

            // Get top element
            int x = st.back();

            // remove it
            st.pop_back();

            // get the min. cost to remove x
            ans += x * min(st.back(), arr[i]);
        }
        // Push current element
        st.push_back(arr[i]);
    }
    for (int i = 2; i < st.size(); i++)
        ans += st[i] * st[i - 1];

    return ans;
}
int main()
{
    int arr[] = {3, 6, 4, 7, 2, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << MinCostTree(arr, n);

    return 0;
}