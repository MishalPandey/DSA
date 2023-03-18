// 1.Selection Sort
void Selection_Sort(int a[n], int n)
{
        for (int i = 0; i < n; ++i)
        {
                int minIndex= i;

                for (int j = i+1; j < n; ++j)
                {
                    if(a[j]< a[minIndex])
                    {
                        minIndex= j;
                    }
                }
                swap(a[i], a[minIndex]);
        }
}

// 2.Bubble Sort
void Bubble_Sort(int a[n], int n)
{
    
        for (int i = n-1; i >= 0; --i)
        {
                int flag=1; // Only for Improving T.C
                
                for (int j = 0; j < i; ++j)
                {
                    if(a[j]> a[j+1])
                    {
                        swap(a[j], a[j+1]);
                        flag=0;
                    }
                }

                if(flag) break;
             
        }
}

// 3.Insertion Sort
void Bubble_Sort(int a[n], int n)
{
    
        for (int i = 0; i < n; ++i)
        {
            int j=i;
                while(j>0 && a[j]<a[j-1])
                {
                    swap(a[j], a[j-1]);
                    j--;
                }
             
        }
}



// 4. Merge sort Algorithm

int a[N];// global array
const int N= 1e5 + 10;
void merge(int l, int r, int mid)
{
        int l_sz = mid -l +1;
        int L[l_sz + 1];
        int r_sz = r - mid;
        int R[r_sz + 1];

        for(int i=0; i<l_sz; i++)
        {
            L[i]= a[i+l];
        }

        for(int i=0; i<r_sz; i++)
        {
            R[i]= a[i + mid + 1];
        }

        L[l_sz]= R[r_sz] = INT_MAX;
        int l_i =0;
        int r_i=0;

        for(int i=l; i<=r; i++)
        {
                if(L[l_i]<= R[r_i])
                {
                    a[i]= L[l_i];
                    l_i++;
                }
                else
                {
                a[i] = R[r_i];
                r_i++;
                }
        }
}       
void mergeSort(int l, int r)
{
        if(l==r) return;
        int mid = (l+r)/2;

        mergeSort(l, mid);
        mergeSort(mid+1, r);
        merge(l, r, mid);

}


//5. Quick sort
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    // we are choosing pivot as 1st element of array
    int i = low;
    int j = high;

    while(i< j)
    {
          while(arr[i] <= pivot && i <= high -1)
          {
            i++;
          }
          while(arr[j] > pivot && j >= low +1)
          {
            j--;
          }
          if(i< j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void Quick_Sort(vector<int> & arr, int low, int high){
  
    if(low< high)
    {
       int part_Idx = partition( arr, low, high);
       Quick_Sort(arr, low, part_Idx -1);
       Quick_Sort(arr, part_Idx+1 , high);
    }  
  
}
// for Randomized quick sort
//#include<ctime>
//#include<cstdlib>

 void shuffle( vector<int> &arr)
 {
    srand(time(NULL));

    int i, j, temp;
    for (int i = arr.size() -1 ; i > 0; --i)
    {
        // create random index
        j= rand()%(i+1);
        swap(arr[i], arr[j]);
    }

 } 

 //6.Count Sort

 void Count_sort(vector<int>& arr, int max, int min) {
        int n= arr.size();
        int range = max - min + 1;
        // min is the minimum element of the array arr
        // max is the maximum element of the array arr
        vector<int> freq_arr(range, 0);

        for (int i = 0; i < n; ++i)
        {
            int idx = arr[i] - min;
            freq_arr[idx]++;
        }

        //prefix sum me convert kardenge freq_arr ko
        for (int i = 1; i < range; ++i)
        {
            freq_arr[i]= freq_arr[i] + freq_arr[i-1];
        }
        // reverse loop laga ke prefix sum ke last indx se value sort karlenge

        vector<int> Sorted_arr(n, 0);

        for (int i = n-1; i >=0 ; --i)
        {
            int val = arr[i];
            int pos = freq_arr[val - min];
            int idx = pos -1;
            Sorted_arr[idx] = val;
            freq_arr[val - min]--;

        }

        for (int i = 0; i < n; ++i)
        {
            arr[i]= Sorted_arr[i];
        }
}

