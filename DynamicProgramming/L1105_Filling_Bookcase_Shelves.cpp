class Solution
{
public:
    int helper(vector<vector<int>> &books, int shelfWidth, int index, int currentHeight, int totalHeight, int remainingWidth)
    {
        if (index == books.size())
            return totalHeight + currentHeight;
        int bookWidth = books[index][0];
        int bookHeight = books[index][1];
        // two options -->  first one is put the book on new shelf
        int placeOnNewShelf = totalHeight + currentHeight + helper(books, shelfWidth, index + 1, bookHeight, 0, shelfWidth - bookWidth);
        int placeOnCurrentShelf = INT_MAX;
        // second one is to place the book on current shelf if it fits
        if (remainingWidth >= bookWidth)
            placeOnCurrentShelf = helper(books, shelfWidth, index + 1, max(currentHeight, bookHeight), totalHeight, remainingWidth - bookWidth);

        return min(placeOnNewShelf, placeOnCurrentShelf);
    }
    unordered_map<int, unordered_map<int, unordered_map<int, int>>> memo;
    int memohelper(vector<vector<int>> &books, int shelfWidth, int index, int currentHeight, int totalHeight, int remainingWidth)
    {
        if (index == books.size())
            return totalHeight + currentHeight;
        int bookWidth = books[index][0];
        int bookHeight = books[index][1];

        // check if result is already there
        if (memo[index][currentHeight].count(remainingWidth))
            return memo[index][currentHeight][remainingWidth];

        // two options -->  first one is put the book on new shelf
        int placeOnNewShelf = totalHeight + currentHeight + helper(books, shelfWidth, index + 1, bookHeight, 0, shelfWidth - bookWidth);
        int placeOnCurrentShelf = INT_MAX;
        // second one is to place the book on current shelf if it fits
        if (remainingWidth >= bookWidth)
            placeOnCurrentShelf = helper(books, shelfWidth, index + 1, max(currentHeight, bookHeight), totalHeight, remainingWidth - bookWidth);

        // return min(placeOnNewShelf, placeOnCurrentShelf);
        return memo[index][currentHeight][remainingWidth] = min(placeOnNewShelf, placeOnCurrentShelf);
    }

    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        // return memohelper(books,shelfWidth, 0,0,0,shelfWidth);

        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; // no books no height needed
        for (int i = 1; i <= n; i++)
        {
            int width = 0, height = 0;

            for (int j = i - 1; j >= 0; j--)
            {
                width += books[j][0];
                if (width > shelfWidth)
                    break;
                height = max(height, books[j][1]);
                dp[i] = min(dp[i], dp[j] + height);
            }
        }
        return dp[n];
    }
};