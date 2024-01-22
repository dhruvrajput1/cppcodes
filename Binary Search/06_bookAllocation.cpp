#include<iostream>
#include<climits>
using namespace std;

bool canPlace(int* books, int n, int m, int currentMin) {

    int studentsUsed = 1;
    int pagesRead = 0;

    for(int i = 0; i < n; i++) {
        if(pagesRead + books[i] > currentMin) {
            studentsUsed++;

            pagesRead = books[i];

            if(studentsUsed > m) {
                return false;
            }
        }
        else {
            pagesRead += books[i];
        }
    }

    return true;

}

int main() {

    int n = 4; // no of books
    
    int m = 2; // no of students to read books
    

    int books[] = {10, 20, 30, 40}; // represents the number of pages in ith book

    // search space will be of pages.
    // min no of pages that one student have to read is 40 and the maximum number is sum of all pages i.e., 100

    int sumOfPages = 0;
    for(int i = 0; i < n; i++) {
        sumOfPages += books[i];
    }

    int s = books[n-1];
    int e = sumOfPages;

    int ans = INT_MAX; // instead of -1 use INT_MAX

    while(s <= e) {
        int mid = (s + e)/2;

        if(canPlace(books, n, m, mid)) {
            ans = min(ans, mid);
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }

    }

    cout<<ans<<endl;

    return 0;
}