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