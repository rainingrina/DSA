bool isPossible(vector<int>& arr, int n, int m, long long mid) {
    int painters = 1;
    long long sum = 0;
    long long maxBoard = -999999;

    for (int i = 0; i < n; i++) {
        maxBoard = max(maxBoard, (long long)arr[i]);

        sum += arr[i];

        if (sum > mid) {
            painters++;
            sum = arr[i]; // Start a new painter with the current board
        }

        if (painters > m || arr[i] > mid) {
            return false;
        }
    }
    return true;
}

int findLargestMinDistance(vector<int>& board, int k) {
    int n = board.size();
    long long s = 0;
    long long e = 0;

    for (int i = 0; i < n; i++) {
        s = max(s, (long long)board[i]);
        e += board[i];
    }

    long long ans = -1;

    while (s <= e) {
        long long mid = s + (e - s) / 2;

        if (isPossible(board, n, k, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}
