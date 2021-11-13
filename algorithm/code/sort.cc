#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void Swap(vector<int> &A, int i, int j) {
  int temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

void Print(string sort_name, vector<int> A) {
  cout << endl << sort_name << " ";
  for (auto ele : A) {
    cout << ele << " ";
  }
}

void Shell_Sort(vector<int> A) {
  int N = A.size();
  int i;
  for (int D = N / 2; D > 0; D /= 2) {
    for (int P = D; P < N; P++) {
      int temp = A[P];
      for (i = P; i >= D && temp < A[i - D]; i -= D) {
        A[i] = A[i - D];
      }
      A[i] = temp;
    }
  }

  cout << endl << "Shell_Sort ";
  for (auto ele : A) {
    cout << ele << " ";
  }
}

void Bubble_Sort(vector<int> A) {
  int N = A.size();
  for (int P = N - 1; P > 0; P--) {
    for (int i = 0; i < P; i++) {
      int flag = 0;
      if (A[i] > A[i + 1]) {
        int temp = A[i];
        A[i] = A[i + 1];
        A[i + 1] = temp;
        flag = 1;
      }
      if (flag == 1) {
        break;
      }
    }
  }

  cout << endl << "Bubble_Sort ";
  for (auto ele : A) {
    cout << ele << " ";
  }
}

void Insertion_Sort(vector<int> A) {
  int N = A.size();
  int j;
  for (int i = 1; i < N; i++) {
    int temp = A[i];
    for (j = i; j > 0 && A[j - 1] > temp; j--) {
      A[j] = A[j - 1];
    }
    A[j] = temp;
  }
  cout << endl << "Insert_Sort ";
  for (auto ele : A) {
    cout << ele << " ";
  }
}

void Selection_Sort(vector<int> A) {
  int N = A.size();
  int min;
  for (int i = 0; i < N; i++) {
    min = i;
    for (int j = i + 1; j < N; j++) {
      if (A[min] > A[j]) {
        min = j;
      }
    }
    if (min != i) {
      int temp = A[min];
      A[min] = A[i];
      A[i] = temp;
    }
  }

  cout << endl << "Selection_Sort ";
  for (auto ele : A) {
    cout << ele << " ";
  }
}

void Adjust_Heap(vector<int> &A, int i, int N) {
  int temp = A[i];
  for (int k = 2 * i + 1; k < N; k = 2 * k + 1) {
    if (k + 1 < N && A[k] < A[k + 1]) {
      k++;
    }

    if (temp < A[k]) {
      A[i] = A[k];
      i = k;
    } else {
      break;
    }
  }
  A[i] = temp;
}

void Heap_Sort(vector<int> A) {
  int N = A.size();
  for (int i = N / 2 - 1; i >= 0; i--) {
    Adjust_Heap(A, i, N);
  }
  for (int j = N - 1; j > 0; j--) {
    Swap(A, 0, j);
    Adjust_Heap(A, 0, j);
  }
  cout << endl << "Heap_Sort ";
  for (auto ele : A) {
    cout << ele << " ";
  }
}

void Merge(vector<int> &A, int tempA[], int L, int R, int RightEnd) {
  int LeftEnd = R - 1;
  int NumsEle = RightEnd - L + 1;
  int temp = L;
  while (L <= LeftEnd && R <= RightEnd) {
    if (A[L] <= A[R]) {
      tempA[temp++] = A[L++];
    } else {
      tempA[temp++] = A[R++];
    }
  }
  while (L <= LeftEnd) {
    tempA[temp++] = A[L++];
  }
  while (R <= RightEnd) {
    tempA[temp++] = A[R++];
  }

  for (int i = 0; i < NumsEle; i++, RightEnd--) {
    A[RightEnd] = tempA[RightEnd];
  }
}

void MSort(vector<int> &A, int tempA[], int L, int RightEnd) {
  int Center;
  if (L < RightEnd) {
    Center = (L + RightEnd) / 2;
    MSort(A, tempA, L, Center);
    MSort(A, tempA, Center + 1, RightEnd);
    Merge(A, tempA, L, Center + 1, RightEnd);
  }
}
void Merge_Sort(vector<int> &A) {
  int N = A.size();
  int *tempA = new int[N - 1];
  MSort(A, tempA, 0, N - 1);
  cout << endl << "Merge_Sort ";
  for (auto a : A) {
    cout << a << " ";
  }
}

int partition(vector<int> &A, int low, int high) {
  int i = low - 1;
  int j = high;
  int pivot = A[high];
  while (1) {
    while (A[++i] < pivot)
      ;
    while (A[--j] > pivot)
      ;

    if (i < j) {
      Swap(A, i, j);
    } else {
      break;
    }
  }

  Swap(A, i, high);
  return i;
}

void QSort(vector<int> &A, int low, int high) {
  if (low < high) {
    int mid = partition(A, low, high);
    QSort(A, low, mid - 1);
    QSort(A, mid + 1, high);
  }
}

void Quick_Sort(vector<int> &A) {
  int N = A.size();
  QSort(A, 0, N - 1);
  Print("Quick_Sort", A);
}

void Count_Sort(vector<int> &A) {
  int N = A.size();
  auto min_ = std::min_element(std::begin(A), std::end(A));
  auto max_ = std::max_element(std::begin(A), std::end(A));
  int min = *min_;
  int max = *max_;

  int *count = new int[max - min + 1];
  for (auto num : A) {
    count[num - min]++;
  }
  int index = 0;
  int *result = new int[N];
  for (int i = 0; i < N; i++) {
    while (count[i] > 0) {
      result[index++] = i + min;
      count[i]--;
    }
  }

  for (int i = 0; i < N; i++) {
    A[i] = result[i];
  }

  Print("Count_Sort", A);
}
void Bucket_Sort(vector<int> &A) {
  auto min = *std::min_element(std::begin(A), std::end(A));
  auto max = *std::max_element(std::begin(A), std::end(A));

  int N = A.size();
  int bucket_len = max - min + 1;
  int *bucket = new int[bucket_len];
  int *res = new int[N];

  for (int i = 0; i < N; i++) {
    bucket[A[i] - min] += 1;
  }

  int start = 0;
  for (int i = 0; i < bucket_len; i++) {
    for (int j = start; j < start + bucket[i]; j++) {
      A[j] = min + i;
      res[j] = min + i;
    }
    start += bucket[i];
  }
  Print("Bucket_Sort", A);
  delete []bucket;
  
}
void Sort(vector<int> A) {
  Shell_Sort(A);
  Bubble_Sort(A);
  Insertion_Sort(A);
  Selection_Sort(A);
  Heap_Sort(A);
  Merge_Sort(A);
  Quick_Sort(A);
  Count_Sort(A);
  Bucket_Sort(A);
}

int main() {
  vector<int> Array = {81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15};
  Sort(Array);
  return 0;

  cout<<"good"<<endl;
}