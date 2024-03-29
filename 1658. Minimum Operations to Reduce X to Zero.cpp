int minOperations (int *nums, int numsSize, int x) {
	int  i, j, left = 0, right = 0, min = INT_MAX;

	for (i = 0; i < numsSize; i++) {
		left += nums[i];
		if (left >= x) {
			if (left == x) min = i + 1;
			break;
		}
	}

	if (i == numsSize) {
		return -1;
	}

	for (j = numsSize-1; 0 < j && numsSize-j < min && right <= x; j--) {
		right += nums[j];
		while (right + left >= x) {
			if (right + left == x && min > i+1+numsSize-j) {
				min = i+1+numsSize-j;
			}
			if (i >= 0) {
				left -= nums[i];
				i--;
			} else {
				break;
			}
		}
	}

	return min == INT_MAX ? -1 : min;
}