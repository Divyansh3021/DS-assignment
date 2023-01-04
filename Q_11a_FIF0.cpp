#include<bits/stdc++.h>
using namespace std;
 
// Function to find page faults using FIFO
int pageFaults(int pages[], int n, int capacity)
{
    unordered_set<int> s;
 
    // To store the pages in FIFO manner
    queue<int> indexes;
 
    // Start from initial page
    int page_faults = 0;
    for (int i=0; i<n; i++)
    {
        // Check if the set can hold more pages
        if (s.size() < capacity)
        {
            // Insert it into set if not present
            // already which represents page fault
            if (s.find(pages[i])==s.end())
            {
                // Insert the current page into the set
                s.insert(pages[i]);
 
                // increment page fault
                page_faults++;
 
                // Push the current page into the queue
                indexes.push(pages[i]);
            }
        }
       else
        {
            if (s.find(pages[i]) == s.end())
            {
                
                int val = indexes.front();
                 
                // Pop the first page from the queue
                indexes.pop();
 
                // Remove the indexes page from the set
                s.erase(val);
 
                // insert the current page in the set
                s.insert(pages[i]);
 
                // push the current page into
                // the queue
                indexes.push(pages[i]);
 
                // Increment page faults
                page_faults++;
            }
        }
    }
 
    return page_faults;
}
 
// Driver code
int main()
{
    system("cls");
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4,2, 3, 0, 3, 2};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 4;
    cout << pageFaults(pages, n, capacity);
    return 0;
}