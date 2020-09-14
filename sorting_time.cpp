#include <bits/stdc++.h>
using namespace std;

int random_array[100000];
int N;

void fill_array()
{
    int i,random_value;
    srand(time(0));
    for(i=0;i<N;i++)
    {
        random_value = 1 + rand() % 10001;
        random_array[i] = random_value;
        //cout << random_value << " ";
    }
    cout << endl;
}

void bubble_sort()
{
    int i,j,val_saved;
    bool state=true;
    unsigned t0, t1;

    t0=clock();
    // Code to execute
    //cout << "\nt0: " << t0;
    while(state)
    {
        state = false;
        for(i=0;i<N;i++)
        {
            if(random_array[i]>random_array[i+1])
            {
                val_saved = random_array[i];
                random_array[i] = random_array[i+1];
                random_array[i+1] = val_saved;
                state = true;
            }
        }
    }
    t1 = clock();
    //cout << "\n" << "t1: " << t1;

    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Bubble sort";
    cout << "\nExecution Time: " << time << endl;

    cout << endl;
    /*for(i=1;i<=N;i++)
    {
        cout << random_array[i] << " ";
    }*/
}

void insertion()
{
    int i,j,current;
    unsigned t0, t1;

    t0=clock();
    // Code to execute
    //cout << "\nt0: " << t0;

    for (i = 1; i < N; i++)
    {
        current = random_array[i];
        for (j = i; j > 0 && random_array[j - 1] > current; j--) {
            random_array[j] = random_array[j - 1];
        }
        random_array[j] = current;
    }
    t1 = clock();
    //cout << "\n" << "t1: " << t1;

    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Insertion";
    cout << "\nExecution Time: " << time << endl;

    cout << endl;
    /*for(i=0;i<N;i++)
    {
        cout << random_array[i] << " ";
    }*/
}

void selection()
{
    int i,j,aux,min;
    unsigned t0, t1;

    t0=clock();
    // Code to execute
    //cout << "\nt0: " << t0;

    for(i=0;i<N;i++)
    {
        min = i;
        for(j=i+1;j<N;j++)
        {
            if(random_array[j]<random_array[min])
            {
                min = j;
            }
        }
        aux = random_array[i];
        random_array[i] = random_array[min];
        random_array[min] = aux;
    }

    t1 = clock();
    //cout << "\n" << "t1: " << t1;

    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Selection";
    cout << "\nExecution Time: " << time << endl;

    cout << endl;
    /*for(i=0;i<N;i++)
    {
        cout << random_array[i] << " ";
    }*/
}

int main()
{
    cout << "Enter the length of the array to be ordered: ";
    cin >> N;
    fill_array();
    bubble_sort();
    cout << "\n" << endl;
    fill_array();
    insertion();
    cout << "\n" << endl;
    fill_array();
    selection();

    return 0;
}
