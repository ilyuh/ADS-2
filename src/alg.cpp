// Copyright 2021 NNTU-CS

// функция бинарного поиска
int cbinsearch(int *arr, int size, int value) {
  int left = 0;
  int right = size - 1;
  int counter = 0;

  while (left < right) {
    int mid = (left + right) / 2;
    if (arr[mid] < value) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  if (arr[left] == value) {
    while (arr[left] == value) {
      counter++;
      left++;
    }
  }

  if (counter != 0) {
    return counter;
  } else {
    return 0;
  }
}

int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        counter++;
      }
    }
  }

  return counter;
}

int countPairs2(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; i++) {
    int checker = value - arr[i];
    for (int j = len-1; j > i; j--) {
      if (arr[j] == checker) {
        counter++;
      }
    }
  }

  return counter;
}

int countPairs3(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; i++) {
    int checker = value - arr[i];
    counter = counter + cbinsearch(arr, len, checker);
    if (arr[i] == checker) {
      counter--;
    }
    arr[i] = -1;
  }

  return counter;
}
