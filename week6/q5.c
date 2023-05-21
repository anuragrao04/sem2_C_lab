int readArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
}

int sumDigits(int n) {
  int sum = 0;
  while (n) {
    sum += (n % 10);
    n /= 10;
  }
  return sum;
}

int EvenNoSymDigits(int arr[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      sum += sumDigits(arr[i]);
    }
  }
  printf("%d", sum);
}

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  readArray(arr, n);
  EvenNoSymDigits(arr, n);
}
